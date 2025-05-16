#include <esp_log.h>
#include <esp_system.h>
#include <nvs_flash.h>
#include <string.h>
#include <math.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_camera.h"

// ================================ Pines AiThinker ================================
#define CAM_PIN_PWDN 32
#define CAM_PIN_RESET -1
#define CAM_PIN_XCLK 0
#define CAM_PIN_SIOD 26
#define CAM_PIN_SIOC 27
#define CAM_PIN_D7 35
#define CAM_PIN_D6 34
#define CAM_PIN_D5 39
#define CAM_PIN_D4 36
#define CAM_PIN_D3 21
#define CAM_PIN_D2 19
#define CAM_PIN_D1 18
#define CAM_PIN_D0 5
#define CAM_PIN_VSYNC 25
#define CAM_PIN_HREF 23
#define CAM_PIN_PCLK 22

static const char *TAG = "example:hist_eq";

// ================================ Configuración Cámara ============================
static camera_config_t camera_config = {
    .pin_pwdn = CAM_PIN_PWDN,
    .pin_reset = CAM_PIN_RESET,
    .pin_xclk = CAM_PIN_XCLK,
    .pin_sccb_sda = CAM_PIN_SIOD,
    .pin_sccb_scl = CAM_PIN_SIOC,
    .pin_d7 = CAM_PIN_D7,
    .pin_d6 = CAM_PIN_D6,
    .pin_d5 = CAM_PIN_D5,
    .pin_d4 = CAM_PIN_D4,
    .pin_d3 = CAM_PIN_D3,
    .pin_d2 = CAM_PIN_D2,
    .pin_d1 = CAM_PIN_D1,
    .pin_d0 = CAM_PIN_D0,
    .pin_vsync = CAM_PIN_VSYNC,
    .pin_href = CAM_PIN_HREF,
    .pin_pclk = CAM_PIN_PCLK,
    .xclk_freq_hz = 20000000,
    .ledc_timer = LEDC_TIMER_0,
    .ledc_channel = LEDC_CHANNEL_0,
    .pixel_format = PIXFORMAT_GRAYSCALE,
    .frame_size = FRAMESIZE_96X96,
    .fb_location = CAMERA_FB_IN_DRAM,
    .jpeg_quality = 12,
    .fb_count = 1,
    .grab_mode = CAMERA_GRAB_WHEN_EMPTY,
};

// ================================ Filtro Sobel ================================
// Kernel Sobel para detección de bordes en X (horizontal)
int sobel_kernel_x[3][3] = {
    {-1, 0, 1},
    {-2, 0, 2},
    {-1, 0, 1}
};

// Kernel Sobel para detección de bordes en Y (vertical)
int sobel_kernel_y[3][3] = {
    {-1, -2, -1},
    { 0,  0,  0},
    { 1,  2,  1}
};

// Función para aplicar el filtro Sobel
void sobel_filter(uint8_t *image, int width, int height, uint8_t *output)
{
    // Iterar sobre cada píxel de la imagen, excepto los bordes
    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            int gx = 0;
            int gy = 0;

            // Aplicar los kernels de Sobel
            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {
                    int pixel = image[(y + ky) * width + (x + kx)];
                    gx += sobel_kernel_x[ky + 1][kx + 1] * pixel;
                    gy += sobel_kernel_y[ky + 1][kx + 1] * pixel;
                }
            }

            // Calcular el valor del gradiente
            int magnitude = (int)sqrt(gx * gx + gy * gy);

            // Normalizar el valor de magnitud a 255
            if (magnitude > 255) {
                magnitude = 255;
            }

            // Asignar el valor al píxel de salida
            output[y * width + x] = (uint8_t)magnitude;
        }
    }
}

// ================================ Ecualización de Histograma =========================
void equalize_histogram(uint8_t *gray_data, size_t length)
{
    int hist[256] = {0};
    int cdf[256] = {0};

    // Calcular histograma
    for (size_t i = 0; i < length; i++) {
        hist[gray_data[i]]++;
    }

    // Calcular CDF acumulada
    cdf[0] = hist[0];
    for (int i = 1; i < 256; i++) {
        cdf[i] = cdf[i - 1] + hist[i];
    }

    // Buscar el primer valor distinto de 0 en la CDF
    int cdf_min = 0;
    for (int i = 0; i < 256; i++) {
        if (cdf[i] != 0) {
            cdf_min = cdf[i];
            break;
        }
    }

    // Crear LUT (tabla de look-up) para la transformación
    int total_pixels = length;
    uint8_t lut[256];
    for (int i = 0; i < 256; i++) {
        lut[i] = (uint8_t)(((float)(cdf[i] - cdf_min) / (total_pixels - cdf_min)) * 255.0f + 0.5f);
    }

    // Aplicar LUT a la imagen
    for (size_t i = 0; i < length; i++) {
        gray_data[i] = lut[gray_data[i]];
    }
}


// ================================ Buffer Circular para imágenes ============================
#define BUFFER_SIZE 20

// Crear un buffer circular para almacenar las imágenes
camera_fb_t *image_buffer[BUFFER_SIZE]; 
int current_index = 0;  // Índice actual del buffer

// Función para agregar una imagen al buffer circular
void add_to_image_buffer(camera_fb_t *pic)
{
    // Si el buffer está lleno, liberar la memoria de la imagen más antigua
    if (image_buffer[current_index] != NULL) {
        free(image_buffer[current_index]);
    }

    // Almacenar la nueva imagen en la posición correspondiente
    image_buffer[current_index] = pic;

    // Actualizar el índice de manera circular
    current_index = (current_index + 1) % BUFFER_SIZE;
}

// ================================ Inicializar cámara ============================
static esp_err_t init_camera(void)
{
    esp_err_t err = esp_camera_init(&camera_config);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Camera Init Failed");
        return err;
    }
    return ESP_OK;
}

// ================================ Main ==========================================
// ================================ Main ==========================================
void app_main(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());
    if (init_camera() != ESP_OK) {
        return;
    }

    while (1) {
        ESP_LOGI(TAG, "Taking picture...");
        camera_fb_t *pic = esp_camera_fb_get();
        if (!pic) {
            ESP_LOGE(TAG, "Camera capture failed");
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            continue;
        }

        ESP_LOGI(TAG, "Original image length: %d bytes", pic->len);

        // Agregar la imagen al buffer circular
        add_to_image_buffer(pic);

        // Aquí estamos suponiendo que la imagen tiene un tamaño de 96x96
        int width = 96;
        int height = 96;

        // Asumimos que la imagen capturada está en escala de grises
        uint8_t *sobel_output = (uint8_t *)malloc(width * height);

        // Realizar la ecualización de histograma sobre la imagen
        equalize_histogram(pic->buf, pic->len);

        // Aplicar filtro Sobel sobre la imagen ecualizada
        sobel_filter(pic->buf, width, height, sobel_output);

        ESP_LOGI(TAG, "Image after Sobel filter:");

        // Mostrar los resultados de la imagen procesada (salida del filtro Sobel)
        for (int i = 0; i < width * height; i++) {
            printf("0x%02X, ", sobel_output[i]);
            if ((i + 1) % 32 == 0) printf("\n");  // Agrupar en bloques de 32
        }
        printf("\n");

        // Liberar memoria
        free(sobel_output);

        // Devolver la imagen capturada a la memoria
        esp_camera_fb_return(pic);

        vTaskDelay(5000 / portTICK_PERIOD_MS);  // Esperar 5s antes de capturar otra imagen
    }
}
