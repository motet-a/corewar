# corewar

[![Build Status](https://ci.antoine.network/job/Corewar/lastBuild/badge/icon)](https://ci.antoine.network/job/Corewar/lastBuild/)

The corewar assembler and VM.

## Organization

This project is divided in two parts:

* The assembler, which compiles human-readable `.s` files to binary
`.cor` files;

* The virtual machine, which runs `.cor` files.

The assembler source files are in the `asm` directory, and the virtual
machine source files are in the `corewar` directory.

The `libcw` directory contains shared stuff between the assembler and
the VM.

# Delivering

In the Makefile, don't forget to remove the `-g` compiler option, and
enable the `-D NDEBUG` option to disable the `assert` macro from `assert.h`.

# Project Stats

* 423 build
* 393 commits
* 1200 coffee
