#include <stdio.h>
#include <math.h>
#include <esp_timer.h>
#include "weights_bias.h"

#define INPUT_SIZE 1
#define L1_SIZE 16
#define L2_SIZE 16
#define OUTPUT_SIZE 1
#define NUM_RUNS 10

float relu(float x) {
    return x > 0 ? x : 0;
}

void dense1(float input[INPUT_SIZE], float output[L1_SIZE]) {
    for (int i = 0; i < L1_SIZE; i++) {
        output[i] = sequential_dense_BiasAdd_ReadVariableOp[i] + sequential_dense_MatMul[i][0] * input[0];
        output[i] = relu(output[i]);
    }
}

void dense2(float input[L1_SIZE], float output[L2_SIZE]) {
    for (int i = 0; i < L2_SIZE; i++) {
        output[i] = sequential_dense_1_BiasAdd_ReadVariableOp[i];
        for (int j = 0; j < L1_SIZE; j++) {
            output[i] += sequential_dense_1_MatMul[i][j] * input[j];
        }
        output[i] = relu(output[i]);
    }
}

void dense3(float input[L2_SIZE], float output[OUTPUT_SIZE]) {
    for (int i = 0; i < OUTPUT_SIZE; i++) {
        output[i] = sequential_dense_2_BiasAdd_ReadVariableOp[i];
        for (int j = 0; j < L2_SIZE; j++) {
            output[i] += sequential_dense_2_MatMul[i][j] * input[j];
        }
    }
}

float infer(float x_input) {
    float input[1] = { x_input };
    float out1[L1_SIZE];
    float out2[L2_SIZE];
    float out3[OUTPUT_SIZE];

    dense1(input, out1);
    dense2(out1, out2);
    dense3(out2, out3);

    return out3[0];
}

void app_main() {
    for (int i = 0; i < NUM_RUNS; i++) {
        float x = -1.0f + 2.0f * i / (NUM_RUNS - 1); // distribuye entre -1 y 1
        int64_t start_time = esp_timer_get_time();
        float y = infer(x);
        int64_t end_time = esp_timer_get_time();

        printf("x = %.3f -> y = %.6f, tiempo = %lld us\n", x, y, end_time - start_time);
    }
}
