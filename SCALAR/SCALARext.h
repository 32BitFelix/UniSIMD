
// Guard for compiler
#ifndef SCALAREXT_H
#define SCALAREXT_H


char SCALAR_GET_REG_SIZE();

void SCALAR_FADD(float* dst, float* a, float* b);

void SCALAR_FSUB(float* dst, float* a, float* b);

void SCALAR_FMUL(float* dst, float* a, float* b);

void SCALAR_FDIV(float* dst, float* a, float* b);

#endif