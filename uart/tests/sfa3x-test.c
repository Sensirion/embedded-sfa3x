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

#include "sensirion_common.h"
#include "sensirion_shdlc.h"
#include "sensirion_test_setup.h"
#include "sensirion_uart_hal.h"
#include "sfa3x-uart.h"
#include <inttypes.h>
#include <stdio.h>

TEST_GROUP (sfa3x_Tests) {
    void setup() {
        sensirion_uart_hal_init();
    }

    void teardown() {
        int16_t error;
        error = sfa3x_reset_device();
        CHECK_ZERO_TEXT(error, "sfa3x_device_reset");
        sensirion_uart_hal_free();
    }
};

TEST (sfa3x_Tests, sfa3x_Test_start_continuous_measurement) {
    int16_t error;
    error = sfa3x_start_continuous_measurement();
    CHECK_ZERO_TEXT(error, "sfa3x_start_continuous_measurement");
}

TEST (sfa3x_Tests, sfa3x_Test_stop_measurement) {
    int16_t error;
    error = sfa3x_stop_measurement();
    CHECK_ZERO_TEXT(error, "sfa3x_stop_measurement");
}

TEST (sfa3x_Tests, sfa3x_Test_read_measured_values_output_format_2) {
    int16_t error;
    int16_t hcho;
    int16_t relative_humidity;
    int16_t temperature;
    error = sfa3x_read_measured_values_output_format_2(
        &hcho, &relative_humidity, &temperature);
    CHECK_ZERO_TEXT(error, "sfa3x_read_measured_values_output_format_2");
    printf("hcho: %i\n", hcho);
    printf("relative_humidity: %i\n", relative_humidity);
    printf("temperature: %i\n", temperature);
}

TEST (sfa3x_Tests, sfa3x_Test_device_reset) {
    int16_t error;
    error = sfa3x_device_reset();
    CHECK_ZERO_TEXT(error, "sfa3x_device_reset");
}
