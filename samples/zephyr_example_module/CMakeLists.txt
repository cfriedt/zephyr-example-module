# CMakeLists.txt for Zephyr Example Module sample
#
# Copyright (c) 2020, Friedt Professional Engineering Services, Inc
#
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)
include($ENV{ZEPHYR_BASE}/cmake/app/boilerplate.cmake NO_POLICY_SCOPE)
project(zephyr_sample_module)

target_sources(app PRIVATE src/main.c)
