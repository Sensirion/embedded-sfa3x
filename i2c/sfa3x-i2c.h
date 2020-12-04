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
 * sfa3x_start_continuous_measurement() - Starts continuous measurement in
 * polling mode.
 *
 * @note This command is only available in idle mode.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sfa3x_start_continuous_measurement(void);

/**
 * sfa3x_stop_measurement() - Stops the measurement mode and returns to idle
 * mode.
 *
 * @note This command is only available in measurement mode.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sfa3x_stop_measurement(void);

/**
 * sfa3x_read_measured_values() - Returns the new measurement results as
 * integers.
 *
 * @note This command is only available in measurement mode. The firmware
 * updates the measurement values every second. Polling data with a faster
 * sampling rate will return the same values. The first measurement is available
 * 1 second after the start measurement command is issued. Any readout prior to
 * this will return zero initialized values.
 *
 * @param hcho Formaldehyde concentration in ppb with a scaling of 5.
 *
 * @param humidity Relative humidity in % RH with a scaling of 100.
 *
 * @param temperature Temperature in degrees Celsius with a scaling of 200.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sfa3x_read_measured_values(int16_t* hcho, int16_t* humidity,
                                   int16_t* temperature);

/**
 * sfa3x_get_device_marking() - Read the device marking string from the device.
 *
 * @param device_marking ASCII string containing the serial number. The string
 * has the null-termination character included.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sfa3x_get_device_marking(uint8_t* device_marking,
                                 uint8_t device_marking_size);

/**
 * sfa3x_device_reset() - Executes a reset on the device.
 *
 * @return 0 on success, an error code otherwise
 */
int16_t sfa3x_device_reset(void);

#ifdef __cplusplus
}
#endif

#endif /* sfa3x_H */
