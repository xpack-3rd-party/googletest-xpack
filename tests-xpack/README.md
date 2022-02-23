# Tests

## Overview

The µOS++ testing strategy is to compile the sources with as many
toolchains as possible, and run them on as many platforms as possible.

There is a GitHub Actions CI workflow that runs a selection of the
tests on every push; for details see
[CI.yml](../.github/workflows/CI.yml).

A second workflow is triggered manually, and runs all available tests
on all supported platforms; for details see
[test-all.yml](../.github/workflows/test-all.yml)

## Platforms

The supported platforms are:

- `platform-native` - run the test applications as native process
  on the development machine
- `platform-qemu-mps2-an386` - run the tests as fully semihosted applications
  on a QEMU mps2-an386 emulated board (an Arm Cortex-M4 development board)

The tests are performed on GNU/Linux, macOS and Windows.

Exactly the same source files are used on all platforms, without
changes.

It is planned to add more platforms, like RISC-V, but no dates are set.

## Toolchains

For a better portability, the builds are repeated with multiple toolchains,
even with multiple versions of the same toolchain.

For native tests, the toolchains used are:

- GCC 8 (not available on Apple Silicon)
- GCC 11
- clang 12

For Cortex-M tests, the toochain is arm-none-eabi-gcc 11.

## Tests details

### sample-test

Show a simple application exercising the
few primitives available in the library.

### unit-test

Test if all functions in the library
work as expected. Use the µTest++ framework.
