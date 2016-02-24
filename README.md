# corewar

The corewar assembler and VM.

Build Status: [![Build Status]https://ci.antoine.network/job/Corewar/lastBuild/badge/icon)](https://ci.antoine.network/job/Corewar/lastBuild/)

# Organization

This project is divided in two parts:

* The assembler, which compiles human-readable `.s` files to binary
`.core` files;

* The virtual machine, which runs `.core` files.

The assembler source files are in the `asm` directory, and the virtual
machine source files are in the `vm` directory.

The `libcw` directory contains shared stuff between the assembler and
the VM.
