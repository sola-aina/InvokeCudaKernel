# InvokeCudaKernel

## Overview
In the most common use case, CUDA kernels are called using a triple chevron syntax <<<>>> that specifies the kernel launch configuration (i.e. number of threads, thread blocks, shared memory use and stream identifier), in addition to the arguments to the kernel.

Because the triple chevron syntax is CUDA-specific, and therefore can only be handled by the NVIDIA compiler driver (nvcc), any translation unit that calls a CUDA kernel using this syntax must be saved as a CUDA file (*.cu). Thus, calling CUDA kernels 'pollutes' C/C++ translation units.

This is at best a minor annoyance. The more serious problem is that, on some platforms, the nvcc compiler driver does not invoke the latest C/C++ compiler in order to 'handle' non-CUDA code in a CUDA file. For example, on the Linux platform nvcc calls/requires the now-ancient gcc version 5. This means that the use of C++14 and C++17 is impossible in CUDA files.

My InvokeKernel is a simple C++ template for invoking CUDA kernels in a way that solves the 'pollution' problem; so that C++ translation units that call CUDA kernels do not need to be saved as CUDA files, and can use C++14 and C++17 language features. 

## Note
In contrast to the version of this talk presented at Meeting C++ London (see slides), the latest version of this code template introduces a pair of macros `KERNEL_REFERENCES` and `DEFINE_KERNEL` (see Kernels.h) uses [xmacros](https://en.wikipedia.org/wiki/X_Macro) so that users do not have to edit the InvokeKernel.h and InvokeKernel.cu at multiple points every time a new kernel is introduced (see [shotgun surgery](https://en.wikipedia.org/wiki/Shotgun_surgery)).

## Instructions:
1. Build library libCudaKernels by running make command
2. Build main.cpp and link with the library e.g. `g++ main.cpp -L./ -lCudaKernels -L/usr/local/cuda-8.0/lib64 -lcuda -lcudart  -o prog`

