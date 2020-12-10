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

#ifndef sfa3x_H
#define sfa3x_H

#ifdef __cplusplus
extern "C" {
#endif

#include "sensirion_config.h"

/**
 * sfa3x_start_continuous_measurement() - Default output format 0.
 *
 * @note This command is only available in idle mode.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sfa3x_start_continuous_measurement(void);

/**
 * sfa3x_stop_measurement() - Leaves the measurement mode and returns to idle
 * mode.
 *
 * @note This command is only available in measurement mode.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sfa3x_stop_measurement(void);

/**
 * sfa3x_read_measured_values_output_format_2() - Read measured values integer.
 *
 * @param hcho Formaldehyde concentration in ppb as a 16-bit signed integer.
 * Positive values only, negative values are coerced to zero. Scale factor 5
 * ppb^(-1).
 *
 * @param relative_humidity Relative humidity in %. Values between 0 and 100
 * only. With internal correction for temperature offset (if configured). Scale
 * factor 100 %^(-1).
 *
 * @param temperature Temperature in °C. With internal correction for
 * temperature offset (if configured). Scale factor 200 °C^(-1).
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sfa3x_read_measured_values_output_format_2(int16_t* hcho,
                                                   int16_t* relative_humidity,
                                                   int16_t* temperature);

/**
 * sfa3x_device_reset() - Executes a reset on the device.
 *
 * @note The device will reply before executing the reset.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sfa3x_device_reset(void);

#ifdef __cplusplus
}
#endif

#endif /* sfa3x_H */
