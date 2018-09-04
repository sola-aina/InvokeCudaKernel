// g++ main.cpp -L./ -lCudaKernels -L/usr/local/cuda-8.0/lib64 -lcuda -lcudart  -o prog

#include "Kernel.h"
#include "InvokeKernel.h"

int main()
{
	InvokeKernel( Kernel1 , 1 , 1 , 42 );
}

