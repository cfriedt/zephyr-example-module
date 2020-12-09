/*
 * Copyright (c) 2109 Friedt Professional Engineering Services, Inc
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DEBUG

#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#ifdef __ZEPHYR__
#include <zephyr.h>
#include <posix/unistd.h>
#else
#include <unistd.h>
#endif

extern int greybus_service_init(struct device *bus);

int main(int argc, char *argv[])
{
	int r = greybus_service_init(NULL);
	if (r < 0) {
		printf("gb_service_deferred_init() failed: %d\n", r);
		return r;
	}

	for(;;) {
		usleep(1000000);
	}

	return 0;
}
