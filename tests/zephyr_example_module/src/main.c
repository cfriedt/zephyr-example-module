/*
 * Copyright (c) 2020 Friedt Professional Engineering Services, Inc
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <ztest.h>

#include <zephyr_example_module.h>

static inline int fib(int n)
{
	return zephyr_example_module_fib(n);
}

static void test_zephyr_example_module(void)
{
	zassert_equal(0, fib(0));
	zassert_equal(1, fib(1));
	zassert_equal(1, fib(2));
	zassert_equal(2, fib(3));
	zassert_equal(3, fib(4));
	zassert_equal(5, fib(5));
	zassert_equal(8, fib(6));
	zassert_equal(13, fib(7));
}

void test_main(void)
{
	ztest_test_suite(
		zephyr_example_module,
		ztest_unit_test(test_zephyr_example_module)
	);

	ztest_run_test_suite(zephyr_example_module);
}
