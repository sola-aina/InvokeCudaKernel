#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////

__global__ void Kernel1( int )
{
	printf( "Kernel1\n" );
}

////////////////////////////////////////////////////////////////////////////////

__global__ void Kernel2( int )
{
	printf( "Kernel2\n" );
}

////////////////////////////////////////////////////////////////////////////////

