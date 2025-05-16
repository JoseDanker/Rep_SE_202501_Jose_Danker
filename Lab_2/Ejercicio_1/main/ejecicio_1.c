#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_GPIO GPIO_NUM_33         // Cambia este valor si usas otro pin
#define BUTTON_GPIO GPIO_NUM_0      // Botón (por defecto en muchas placas ESP32)
#define BLINK_DELAY_MS 100          // Tiempo base de parpadeo

volatile int hello_count = 0;
volatile int counter = 1;

void hello_task(void *pvParameters) {
    while (1) {
        printf("Hello World\n");
        hello_count++;
        if (hello_count >= 10) {
            hello_count = 0;
            counter = 1; // Reset contador
        }
        vTaskDelay(pdMS_TO_TICKS(2000)); // 2 segundos
    }
}

void blink_task(void *pvParameters) {
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);

    while (1) {
        gpio_set_level(LED_GPIO, 1);
        vTaskDelay(pdMS_TO_TICKS(BLINK_DELAY_MS * counter));
        gpio_set_level(LED_GPIO, 0);
        vTaskDelay(pdMS_TO_TICKS(BLINK_DELAY_MS * counter));
    }
}
void IRAM_ATTR button_isr_handler(void* arg) {
    counter++;
}


void button_task(void *pvParameters) {
    gpio_set_direction(BUTTON_GPIO, GPIO_MODE_INPUT);
    gpio_set_intr_type(BUTTON_GPIO, GPIO_INTR_POSEDGE);
    gpio_install_isr_service(0);
    gpio_isr_handler_add(BUTTON_GPIO, button_isr_handler, NULL);

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}


void app_main(void) {
    xTaskCreate(&hello_task, "hello_task", 2048, NULL, 1, NULL);
    xTaskCreate(&blink_task, "blink_task", 2048, NULL, 1, NULL);
    xTaskCreate(&button_task, "button_task", 2048, NULL, 1, NULL);
}
