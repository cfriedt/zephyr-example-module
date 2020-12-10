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

#ifndef CONFIG_ZTEST
static void zephyr_example_module_entry(void *arg0, void *arg1, void *arg2)
{
	int n2 = 0;
	int n1 = 1;
	int r;
	printk("0\n1\n");
	for(int i = 2; i < 8; ++i, n2 = n1, n1 = r) {
		r = n2 + n1;
		printk("%d\n", r);
	}
}

K_THREAD_DEFINE(zephyr_example_module_thread, 512,
	zephyr_example_module_entry, NULL, NULL, NULL,
	CONFIG_APPLICATION_INIT_PRIORITY, 0, 0);
#endif /* CONFIG_ZTEST */
