.. _zephyr_example_module_sample:

Zephyr Example Module Sample
############################

Overview
********

A sample application that prints the Fibonacci Sequence.

Building and Running
********************

This application can be built and executed as follows:

.. zephyr-app-commands::
   :zephyr-app: ../zephyr-sample-module.git/samples/zephyr_sample_module
   :host-os: unix
   :board: native_posix
   :goals: run
   :compact:

Sample Output
=============

.. code-block:: console

    0
    1
    1
    2
    3
    5
    8
    13
