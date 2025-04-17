#include <stdio.h>
#include <time.h>
#include "esp_timer.h"

void app_main() {
    const int var_1 = 233;
    const int var_2 = 128;
    volatile int result_0, result_1, result_2, result_3, result_4;

    int X_values[] = {10, 100, 1000, 10000}; // Podés extenderlo
    int freq_mhz = 160; // Cambiá esto si tu ESP32 corre a otro clock

    for (int t = 0; t < sizeof(X_values)/sizeof(int); t++) {
        int X = X_values[t];

        int64_t start_time = esp_timer_get_time();

        for (int i = 0; i < X; i++) {
            //result_0 = var_1 + var_2;
            //result_1 = var_1 + 10;
            //result_2 = var_1 % var_2;
            //result_3 = var_1 * var_2;
            result_4 = var_1 / var_2;
        }

        int64_t end_time = esp_timer_get_time();
        int64_t duration_us = end_time - start_time;

        int total_instr = 5 * X;
        double cycles = duration_us * freq_mhz; // microsegundos * MHz = ciclos
        double cpi = cycles / total_instr;

        printf("X=%d, Tiempo=%lld us, Ciclos=%.0f, Instrucciones=%d, CPI=%.2f\n",
               X, duration_us, cycles, total_instr, cpi);
    }
}
