/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
// #include "esp_timer.h"
#include <stdio.h>
#include "esp_log.h"

#include "main_functions.h"

extern "C" void app_main(void) {
  setup();

  while (true) {
    // int64_t start_time = esp_timer_get_time();

    ESP_LOGI("app_main", "Starting inference...");
    loop();  // Realiza la inferencia
    // int64_t end_time = esp_timer_get_time();

    // int64_t duration = end_time - start_time;
    ESP_LOGI("app_main", "Inference completed.");
    // ESP_LOGI("app_main", "Time taken for inference: %lld microseconds", duration);

    vTaskDelay(pdMS_TO_TICKS(500));  // Espera 500ms antes de la siguiente
  }
}

