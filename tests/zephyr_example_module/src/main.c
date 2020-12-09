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
	static const int n_exp[] = {
		-1, -EINVAL,
		48, -E2BIG,
		0, 0,
		1, 1,
		2, 1,
		3, 2,
		4, 3,
		5, 5,
		6, 8,
		7, 13,
		47, 2971215073,
	};
	int i;
	int act;

	for(i = 0; i < ARRAY_SIZE(n_exp); i += 2) {
		act = fib(n_exp[i]);
		zassert_equal(n_exp[i + 1], act,
			"fib(%d): exp: %d: act: %d",
			n_exp[i], n_exp[i + 1], act);
	}
}

void test_main(void)
{
	ztest_test_suite(
		zephyr_example_module,
		ztest_unit_test(test_zephyr_example_module)
	);

	ztest_run_test_suite(zephyr_example_module);
}
