#include <errno.h>
#include <logging/log.h>
#include <zephyr.h>
#include <zephyr_example_module.h>

LOG_MODULE_REGISTER(zephyr_example_module, CONFIG_ZEPHYR_EXAMPLE_MODULE_LOG_LEVEL);

static inline int fib(int n2, int n1)
{
	return n2 + n1;
}

int zephyr_example_module_fib(int n)
{
	int i;  /* iterator */
	int r;  /* result */
	int n2; /* F[n-2] */
	int n1; /* F[n-1] */

	if (n == 0) {
		return 0;
	}

	if (n == 1) {
		return 1;
	}

	if (n < ZEPHYR_EXAMPLE_MODULE_MIN) {
		LOG_ERR("argument %d is invalid", n);
		return -EINVAL;
	}

	if (n > ZEPHYR_EXAMPLE_MODULE_MAX) {
		LOG_ERR("argument %d is too large", n);
		return -E2BIG;
	}

	for(n2 = 0, n1 = 1, i = 2; i <= n; ++i, n2 = n1, n1 = r) {
		r = fib(n2, n1);
	}

	return r;
}
