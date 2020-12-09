# CMakeLists.txt for Zephyr Example Module
#
# Copyright (c) 2020 Friedt Professional Engineering Services, Inc
#
# SPDX-License-Identifier: Apache-2.0

zephyr_library()

zephyr_library_sources_ifdef(CONFIG_ZEPHYR_EXAMPLE_MODULE  zephyr_example_module.c)
