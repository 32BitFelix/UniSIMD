#ifndef AVXEXT_H
#define AVXEXT_H

char AVX_GET_REG_SIZE();

void AVX_FADD(float* dst, float* a, float* b);

void AVX_FSUB(float* dst, float* a, float* b);

void AVX_FMUL(float* dst, float* a, float* b);

void AVX_FDIV(float* dst, float* a, float* b);

#endif