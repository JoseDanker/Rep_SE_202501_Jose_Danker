#include <stdio.h>
#include <stdlib.h>
#include "esp_system.h"
#include "esp_attr.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "esp_heap_caps.h"

#define VECTOR_SIZE 20

// Función para medir tiempo
void init_cycle_count(uint64_t *start) {
    *start = esp_timer_get_time();
}

void end_cycle_count(uint64_t start, const char* label) {
    uint64_t end = esp_timer_get_time();
    printf("%s took %llu microseconds\n", label, end - start);
}

// Multiplicación escalar de vectores
void multiply_vector_scalar(const int *vector, int scalar, int *result) {
    for (int i = 0; i < VECTOR_SIZE; i++) {
        result[i] = vector[i] * scalar;
    }
}

// Memoria estática
DRAM_ATTR static int vector_dram[VECTOR_SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
DRAM_ATTR static int num_dram = 5;
DRAM_ATTR static int result_dram[VECTOR_SIZE];

IRAM_ATTR static int vector_iram[VECTOR_SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
IRAM_ATTR static int num_iram = 5;
IRAM_ATTR static int result_iram[VECTOR_SIZE];

RTC_DATA_ATTR static int vector_rtc[VECTOR_SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
RTC_DATA_ATTR static int num_rtc = 5;
RTC_DATA_ATTR static int result_rtc[VECTOR_SIZE];

const __attribute__((section(".rodata"))) int vector_flash_ext[VECTOR_SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
const __attribute__((section(".rodata"))) int num_int = 5;

void app_main(void) {
    printf("Proyecto 4: Comparación de tipos de memoria\n");

    // Memoria dinámica
    int *vector_dram_dyn = malloc(VECTOR_SIZE * sizeof(int));
    int *result_dram_dyn = malloc(VECTOR_SIZE * sizeof(int));
    int *num_dram_dyn = malloc(sizeof(int));

    int *vector_iram_dyn = heap_caps_malloc(VECTOR_SIZE * sizeof(int), MALLOC_CAP_EXEC);
    int *result_iram_dyn = heap_caps_malloc(VECTOR_SIZE * sizeof(int), MALLOC_CAP_EXEC);
    int *num_iram_dyn = heap_caps_malloc(sizeof(int), MALLOC_CAP_EXEC);

    int *vector_psram = heap_caps_malloc(VECTOR_SIZE * sizeof(int), MALLOC_CAP_SPIRAM);
    int *result_psram = heap_caps_malloc(VECTOR_SIZE * sizeof(int), MALLOC_CAP_SPIRAM);
    int *num_psram = heap_caps_malloc(sizeof(int), MALLOC_CAP_SPIRAM);

    for (int i = 0; i < VECTOR_SIZE; i++) {
        vector_dram_dyn[i] = i + 1;
        vector_iram_dyn[i] = i + 1;
        vector_psram[i] = i + 1;
    }
    *num_dram_dyn = 5;
    *num_iram_dyn = 5;
    *num_psram = 5;

    uint64_t start;

    init_cycle_count(&start);
    multiply_vector_scalar(vector_dram, num_dram, result_dram);
    end_cycle_count(start, "Static DRAM");

    init_cycle_count(&start);
    multiply_vector_scalar(vector_iram, num_iram, result_iram);
    end_cycle_count(start, "Static IRAM");

    init_cycle_count(&start);
    multiply_vector_scalar(vector_rtc, num_rtc, result_rtc);
    end_cycle_count(start, "Static RTC");

    init_cycle_count(&start);
    multiply_vector_scalar(vector_flash_ext, num_int, result_dram); // result_dram solo como destino
    end_cycle_count(start, "Flash .rodata");

    init_cycle_count(&start);
    multiply_vector_scalar(vector_dram_dyn, *num_dram_dyn, result_dram_dyn);
    end_cycle_count(start, "Dynamic DRAM");

    init_cycle_count(&start);
    multiply_vector_scalar(vector_iram_dyn, *num_iram_dyn, result_iram_dyn);
    end_cycle_count(start, "Dynamic IRAM");

    init_cycle_count(&start);
    multiply_vector_scalar(vector_psram, *num_psram, result_psram);
    end_cycle_count(start, "Dynamic PSRAM");

    // Liberar memoria
    free(vector_dram_dyn);
    free(result_dram_dyn);
    free(num_dram_dyn);
    heap_caps_free(vector_iram_dyn);
    heap_caps_free(result_iram_dyn);
    heap_caps_free(num_iram_dyn);
    heap_caps_free(vector_psram);
    heap_caps_free(result_psram);
    heap_caps_free(num_psram);
}
