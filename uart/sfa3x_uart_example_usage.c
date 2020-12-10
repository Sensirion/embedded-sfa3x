/*
 * Copyright (c) 2020, Sensirion AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Sensirion AG nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>  // printf

#include "sensirion_common.h"
#include "sensirion_uart_hal.h"
#include "sfa3x_uart.h"

/**
 * TO USE CONSOLE OUTPUT (PRINTF) AND PLATFORM
 */
//#define printf(...)

int main(void) {
    int16_t error = 0;

    error = sensirion_uart_hal_init();
    if (error) {
        fprintf(stderr, "Error initializing UART: %i\n", error);
        return -1;
    }

    error = sfa3x_start_continuous_measurement();
    if (error) {
        fprintf(stderr, "Error starting measurement: %i\n", error);
        return -1;
    }

    for (;;) {
        int16_t hcho;
        int16_t relative_humidity;
        int16_t temperature;
        error = sfa3x_read_measured_values_output_format_2(
                &hcho, &relative_humidity, &temperature);

        if (error) {
            fprintf(stderr, "Error reading measurement values: %i\n", error);
        } else {
            printf("Measurement:\n");
            printf("  Formaldehyde concentration: %.1f\n", hcho / 5.0f);
            printf("  Relative humidity: %.2f\n", relative_humidity / 100.0f);
            printf("  Temperature: %.2f\n", temperature / 200.0f);
        }

        sensirion_uart_hal_sleep_usec(500000);
    }

    return 0;
}
