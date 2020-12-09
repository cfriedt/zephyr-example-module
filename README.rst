.. _zephyr_example_module:

Zephyr Example Module
#####################

Build Status
************
Badges indicating build status and test coverage appear here.

Overview
********
This repository contains an example module for the `Zephyr Real-Time Operating System <https://zephyrproject.org/>`.

The functionality of the example module itself is quite trivial - all that it does is calculate and print the `Fibonacci Sequence <https://en.wikipedia.org/wiki/Fibonacci_number/>`, updating once per second.

Requirements
************

Please follow the steps outlined in Zephyr's `Getting Started Guide <https://docs.zephyrproject.org/latest/getting_started/index.html>` to ensure that all of the required tools are present in the environment.

Usage
*****

This repository is designed to be cloned, modified, and then pushed to a separate repository with a minimal number of steps.

To achieve that, we first set up a few environment variables (please modify ``<values>`` as necessary, removing the leading ``<`` and trailing ``>``).

.. code-block:: bash
    export ORGANIZATION=<github account>
    export PROJECT_DASH=<github project name with dashes>
    export PROJECT_UNDERSCORE=${PROJECT_DASH//-/_}
    export PROJECT_NAME="<The Module Name>"

.. code-block:: bash
    git clone https://github.com/cfriedt/zephyr-example-module.git

Building and Running
********************

Adjust this section as necessary.

To build the latest development version of this module, start with the following line.

.. code-block:: bash

   west init -m https://github.com/cfriedt/zephyr-example-module.git zephyrproject

Otherwise, to build a version of this module for a specific Zephyr LTS Release, for example 2.4.0, start with the following line.

.. code-block:: bash

   west init -m https://github.com/cfriedt/zephyr-example-module.git --mr v2.4.0 zephyrproject

Then, run the following.

.. code-block:: bash

    cd zephyrproject
    west update
    cd zephyr
    export ZEPHYR_EXTRA_MODULES=$PWD/../zephyr-example-module.git
    source zephyr-env.sh

Enter the following commands to run the sample application with the ``native_posix`` board.

.. code-block:: bash

    west build -p always -b native_posix -t run $PWD/../zephyr-example-module.git/samples/zephyr_example_module

Enter the following commands to run the test suite with the ``native_posix`` board.

.. code-block:: bash

    west build -p always -b native_posix -t run $PWD/../zephyr-example-module.git/tests/zephyr_example_module

Details
*******

This example module provides a number of different templates that to fulfill the `Zephyr Module Requirements <https://docs.zephyrproject.org/latest/guides/modules.html>`:

* a *module.yml* file in a ``zephyr/`` directory
* a top-level ``README.rst`` (this document)
* additional documentation in the ``doc/`` directory
* `CI <https://en.wikipedia.org/wiki/Continuous_integration>` via `GitHub Actions <https://docs.github.com/en/free-pro-team@latest/actions>` under ``.github/actions/module.yml
* a ``CODEOWNERS`` file to keep track of which contributors are responsible for code review
* a ``LICENSE`` file that referse to a permissive, OSI-compliant license
* build files, including ``CMakeLists.txt`` and ``Kconfig``
* a ``west.yml`` file that refers to a specific release of the Zephyr Project RTOS
* an ``include/`` directory at the root of the repository for public API (which may or may not be required)
* a ``subsys/fibonacci`` directory for example code (other suitable locations could be under ``drivers``, or ``lib``)
* a ``tests/`` directory for tests
* a ``samples/`` directory for samples
* a ``dts/`` directory that contains `Device Tree <https://docs.zephyrproject.org/latest/guides/dts/index.html>` bindings (typically only required for hardware configuration)
* a ``scripts/`` directory that contains scripts for CI (which may or may not be required)

The directory and file structure of the example module is as shown below (generated with `tree https://linux.die.net/man/1/tree`).

::
    .
    ├── CMakeLists.txt
    ├── CODEOWNERS
    ├── dts
    │   └── bindings
    │       └── zephyr_example_module
    │           └── zephyr,zephyr-example-module.yaml
    ├── include
    │   └── zephyr_example_module.h
    ├── Kconfig
    ├── LICENSE
    ├── README.rst
    ├── samples
    │   └── zephyr_example_module
    │       ├── CMakeLists.txt
    │       ├── README.rst
    │       ├── sample.yaml
    │       └── src
    │           └── main.c
    ├── scripts
    ├── subsys
    │   └── zephyr_example_module
    │       ├── CMakeLists.txt
    │       └── Kconfig
    ├── tests
    │   └── zephyr_example_module
    │       ├── CMakeLists.txt
    │       ├── src
    │       │   └── main.c
    │       └── testcase.yaml
    ├── west.yml
    └── zephyr
        └── module.yml
    
    14 directories, 18 files


For more information on configuring a GitHub repository to comply with Zephyr external module requirements, see :ref:`configure_github_repository`.

For more information on fulfilling Continuous Integration requirements, see :ref:`continuous_integration_requirements`.

For more information on Zephyr's Devicetree implementation, see `Devicetree Guide <https://docs.zephyrproject.org/latest/guides/dts/index.html>`.
