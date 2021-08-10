# droidports:
A repository for experimenting with elf loading and in-place patching of android native libraries on non-android operating systems.

### Disclaimers:
-----
This repository contains a lot of incomplete, experimental and untested code, and behavior is not guaranteed to match specifications, specially when it comes to the fake JNI implementation.

PSVita ports are currently under heavy wip, and are known to be non-functional.

Corrections, fixes, issue reports and optimizations are always welcome.

### Dependencies:
-----
Varies on a port-by-port basis, but you're required to have at least zlib and OpenGL ES 1.x/2.x available.

### Building and Deploying [example]:
-----

We're going to use the "gmloader" port as an example, targetting the "linux" platform for HardFP ABI toolchains (e.g. linux-gnueabihf):

```bash
mkdir build-gmloader
cd build-gmloader
cmake -DCMAKE_TOOLCHAIN_FILE=~/your-toolchain-definitions.cmake -DCMAKE_BUILD_TYPE=Release -DPLATFORM=linux -DPORT=gmloader -DARMHF=ON
make -j$(($(nproc)+1))
```

### Debugging:
-----
When the loader is built with `-DCMAKE_BUILD_TYPE=Debug`, the 'so_load' function will dump object files that are loaded, these files can be loaded into gdb using a breakpoint trick - check out [the provided debugging example](debug.gdb).

### License:
-----
This is free software. The source files in this repository are released under the [GPLv3 License](LICENSE.md), see the license file for more information.