all: libCudaKernels.a

SOURCES=$(wildcard *.cu)
CUDA_PATH =/usr/local/cuda-8.0
NVCC_FLGS = -G -lineinfo

libCudaKernels.a: $(SOURCES:%.cu=%.o) $(SOURCES:%.cu=%.dlink.o)
	ar rvs -o ./$@ $^

%.a : %.dlink.o %.o
	$(CUDA_PATH)/bin/nvcc $(NVCC_FLGS) -ccbin g++-5 -m64 -gencode arch=compute_30,code=sm_30 -lib -o $@ $^

%.dlink.o : %.o
	$(CUDA_PATH)/bin/nvcc $(NVCC_FLGS) -ccbin g++-5 -m64 -gencode arch=compute_30,code=sm_30 -dlink -o $@ $<

%.o: %.cu
	$(CUDA_PATH)/bin/nvcc $(NVCC_FLGS) -ccbin g++-5 -std=c++11 -g -m64 -gencode arch=compute_30,code=sm_30 -dc -o $@ -c $<

clean:
	rm -f *.o *.dlink.o *.a *.i *.ii *.gpu *.cubin *.fatbin *.fatbin.c *.module_id *.cudafe* *.ptx

