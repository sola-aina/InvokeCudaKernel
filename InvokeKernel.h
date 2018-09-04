#pragma once

#include "Kernel.h"
#include <type_traits>

////////////////////////////////////////////////////////////////////////////////

template<typename T> 
struct KernelWrapper
{
};

////////////////////////////////////////////////////////////////////////////////

template<typename ...Args>
struct KernelWrapper<void(Args...)>
{
    static void Invoke( void kernel(Args...) , int numBlocks , int numThreads , Args ... args );
};

////////////////////////////////////////////////////////////////////////////////

#undef DEFINE_KERNEL
#define DEFINE_KERNEL( Kernel ) extern template struct KernelWrapper<decltype(Kernel)>;
KERNEL_REFERENCES

////////////////////////////////////////////////////////////////////////////////

template<typename K , typename ...Args> 
void InvokeKernel( K k , int n , int m , Args ... args )
{
    typedef typename std::remove_pointer<K>::type KernelType;	// type of K is a _pointer_ to a function
    KernelWrapper<KernelType>::Invoke( k , n , m , args ... );
}

////////////////////////////////////////////////////////////////////////////////

