
// Guard for compiler
#ifndef SSEEXT_H
#define SSEEXT_H


char SSE_GET_REG_SIZE();

void SSE_FADD(float* dst, float* a, float* b);

void SSE_FSUB(float* dst, float* a, float* b);

void SSE_FMUL(float* dst, float* a, float* b);

void SSE_FDIV(float* dst, float* a, float* b);


#endif