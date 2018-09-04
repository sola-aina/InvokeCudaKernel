#include "InvokeKernel.h"
#include "Unique.hpp"

////////////////////////////////////////////////////////////////////////////////

template<typename ...Args> 
void KernelWrapper<void(Args...)>::Invoke( void kernel(Args...)  , int numBlocks , int numThreads , Args ... args )
{
	kernel<<<numBlocks,numThreads>>>( args ... );
    cudaDeviceSynchronize();     
}

////////////////////////////////////////////////////////////////////////////////

// Creates 'list' of kernel types
#undef DEFINE_KERNEL
#define DEFINE_KERNEL( Kernel ) ,decltype(Kernel)
#define CREATE_TYPELIST #define TypeList KERNEL_REFERENCES
CREATE_TYPELIST

// Explicitly instantiate kernel if unique
#undef DEFINE_KERNEL
#define DEFINE_KERNEL( Kernel ) template struct KernelWrapper<UniqueType<__COUNTER__ TypeList>>;
KERNEL_REFERENCES

////////////////////////////////////////////////////////////////////////////////

