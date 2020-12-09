/*
 * Copyright (c) 2020 Friedt Professional Engineering Services, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_EXAMPLE_MODULE_H_
#define ZEPHYR_EXAMPLE_MODULE_H_

#include <stdint.h>

/**
 * @brief The maximum input value for valid output.
 *
 * @see <a href="https://stackoverflow.com/questions/15065088/upper-limits-for-fibonnacci">Upper Limits for Fibonacci</a>
 */
#define ZEPHYR_EXAMPLE_MODULE_MIN 0
#define ZEPHYR_EXAMPLE_MODULE_MAX 48

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Calculate the @param n th Fibonacci number.
 *
 * This function calculates the @param n th Fibonacci number.
 *
 * @param n the position in the Fibonacci sequence (beginning at 0).
 *
 * @return the @param n th Fibonacci number, on success
 * @return a negative error code on failure
 */
int zephyr_example_module_fib(int n);

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_EXAMPLE_MODULE_H_ */
