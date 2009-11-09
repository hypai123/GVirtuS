/* 
 * File:   CudaRt.cpp
 * Author: cjg
 * 
 * Created on October 9, 2009, 3:55 PM
 */

#include <cstdio>
#include <iostream>
#include <string.h>
#include <__cudaFatFormat.h>
#include <fstream>
#include "Frontend.h"
#include "CudaUtil.h"
#include "CudaRt.h"

using namespace std;

/*
 Routines not found in the cuda's header files.
 KEEP THEM WITH CARE
 */

void** __cudaRegisterFatBinary(void *fatCubin) {
    /* Fake host pointer */
    void ** handler = (void **) &fatCubin;
    Buffer * input_buffer = new Buffer();
    input_buffer->AddString(CudaUtil::MarshalHostPointer(handler));
    input_buffer = CudaUtil::MarshalFatCudaBinary((__cudaFatCudaBinary *) fatCubin, input_buffer);

    Frontend *f = Frontend::GetFrontend();
    f->Execute("cudaRegisterFatBinary", input_buffer);
    if(f->Success())
        return handler;
    return NULL;
}

void __cudaUnregisterFatBinary(void **fatCubinHandle) {
    /* FIXME: implement */
    cerr << "*** Error: __cudaUnregisterFatBinary() not yet implemented!" << endl;
}

void __cudaRegisterFunction(void **fatCubinHandle, const char *hostFun, char *deviceFun,
        const char *deviceName, int thread_limit, uint3 *tid,
        uint3 *bid, dim3 *bDim, dim3 *gDim, int *wSize) {
    Frontend *f = Frontend::GetFrontend();
    f->AddStringForArguments(CudaUtil::MarshalHostPointer(fatCubinHandle));
    f->AddStringForArguments(hostFun);
    f->AddStringForArguments(deviceFun);
    f->AddStringForArguments(deviceName);
    f->AddVariableForArguments(thread_limit);
    f->AddHostPointerForArguments(tid);
    f->AddHostPointerForArguments(bid);
    f->AddHostPointerForArguments(bDim);
    f->AddHostPointerForArguments(gDim);
    f->AddHostPointerForArguments(wSize);

    f->Execute("cudaRegisterFunction");

    deviceFun = f->GetOutputString();
    tid = f->GetOutputHostPointer<uint3>();
    bid = f->GetOutputHostPointer<uint3>();
    bDim = f->GetOutputHostPointer<dim3>();
    gDim = f->GetOutputHostPointer<dim3>();
    wSize = f->GetOutputHostPointer<int>();
}

void __cudaRegisterVar(void **fatCubinHandle, char *hostVar, char *deviceAddress,
        const char *deviceName, int ext, int size, int constant,
        int global) {
    /* FIXME: implement */
    cerr << "*** Error: __cudaRegisterVar() not yet implemented!" << endl;
}

void __cudaRegisterShared(void **fatCubinHandle, void **devicePtr) {
    /* FIXME: implement */
    cerr << "*** Error: __cudaRegisterShared() not yet implemented!" << endl;
}

void __cudaRegisterSharedVar(void **fatCubinHandle, void **devicePtr, size_t size,
        size_t alignment, int storage) {
    /* FIXME: implement */
    cerr << "*** Error: __cudaRegisterSharedVar() not yet implemented!" << endl;
}

/* */


extern int CUDARTAPI __cudaSynchronizeThreads(void** x, void* y) {
    /* FIXME: implement */
    cerr << "*** Error: __cudaSynchronizeThreads() not yet implemented!" << endl;
    return 0;
}

extern void CUDARTAPI __cudaTextureFetch(const void *tex, void *index, int integer, void *val) {
    /* FIXME: implement */
    cerr << "*** Error: __cudaTextureFetch() not yet implemented!" << endl;
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpy2DFromArray(void *dst, size_t dpitch, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t width, size_t height, enum cudaMemcpyKind kind) {
    /* FIXME: implement */
    return cudaErrorUnknown;
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpy2DFromArrayAsync(void *dst, size_t dpitch, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream) {
    /* FIXME: implement */
    return cudaErrorUnknown;
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpy2DToArray(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind) {
    /* FIXME: implement */
    return cudaErrorUnknown;
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpy2DToArrayAsync(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t spitch, size_t width, size_t height, enum cudaMemcpyKind kind, cudaStream_t stream) {
    /* FIXME: implement */
    return cudaErrorUnknown;
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpy3D(const struct cudaMemcpy3DParms *p) {
    /* FIXME: implement */
    return cudaErrorUnknown;
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpy3DAsync(const struct cudaMemcpy3DParms *p, cudaStream_t stream) {
    /* FIXME: implement */
    return cudaErrorUnknown;
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpyArrayToArray(struct cudaArray *dst, size_t wOffsetDst, size_t hOffsetDst, const struct cudaArray *src, size_t wOffsetSrc, size_t hOffsetSrc, size_t count, enum cudaMemcpyKind kind __dv(cudaMemcpyDeviceToDevice)) {
    /* FIXME: implement */
    return cudaErrorUnknown;
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpyAsync(void *dst, const void *src, size_t count, enum cudaMemcpyKind kind, cudaStream_t stream) {
    /* FIXME: implement */
    return cudaErrorUnknown;
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpyFromArray(void *dst, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t count, enum cudaMemcpyKind kind) {
    /* FIXME: implement */
    return cudaErrorUnknown;
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpyFromArrayAsync(void *dst, const struct cudaArray *src, size_t wOffset, size_t hOffset, size_t count, enum cudaMemcpyKind kind, cudaStream_t stream) {
    /* FIXME: implement */
    return cudaErrorUnknown;
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpyFromSymbol(void *dst, const char *symbol, size_t count, size_t offset __dv(0), enum cudaMemcpyKind kind __dv(cudaMemcpyDeviceToHost)) {
    /* FIXME: implement */
    return cudaErrorUnknown;
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpyFromSymbolAsync(void *dst, const char *symbol, size_t count, size_t offset, enum cudaMemcpyKind kind, cudaStream_t stream) {
    /* FIXME: implement */
    return cudaErrorUnknown;
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpyToArray(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t count, enum cudaMemcpyKind kind) {
    /* FIXME: implement */
    return cudaErrorUnknown;
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpyToArrayAsync(struct cudaArray *dst, size_t wOffset, size_t hOffset, const void *src, size_t count, enum cudaMemcpyKind kind, cudaStream_t stream) {
    /* FIXME: implement */
    return cudaErrorUnknown;
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpyToSymbol(const char *symbol, const void *src, size_t count, size_t offset __dv(0), enum cudaMemcpyKind kind __dv(cudaMemcpyHostToDevice)) {
    /* FIXME: implement */
    return cudaErrorUnknown;
}

extern __host__ cudaError_t CUDARTAPI cudaMemcpyToSymbolAsync(const char *symbol, const void *src, size_t count, size_t offset, enum cudaMemcpyKind kind, cudaStream_t stream) {
    /* FIXME: implement */
    return cudaErrorUnknown;
}

extern __host__ cudaError_t CUDARTAPI cudaMemset(void *mem, int c, size_t count) {
    /* FIXME: implement */
    return cudaErrorUnknown;
}

extern __host__ cudaError_t CUDARTAPI cudaMemset2D(void *mem, size_t pitch, int c, size_t width, size_t height) {
    /* FIXME: implement */
    return cudaErrorUnknown;
}

extern __host__ cudaError_t CUDARTAPI cudaMemset3D(struct cudaPitchedPtr pitchDevPtr, int value, struct cudaExtent extent) {
    /* FIXME: implement */
    return cudaErrorUnknown;
}
