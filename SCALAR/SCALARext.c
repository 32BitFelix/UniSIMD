#include "SCALARext.h"

char SCALAR_GET_REG_SIZE()
{
    return 0x10;
}

void SCALAR_FADD(float* dst, float* a, float* b)
{
    for(int i = 0; i < 4; i++)
        dst[i] = a[i] + b[i];
}

void SCALAR_FSUB(float* dst, float* a, float* b)
{
    for(int i = 0; i < 4; i++)
        dst[i] = a[i] - b[i];
}

void SCALAR_FMUL(float* dst, float* a, float* b)
{
    for(int i = 0; i < 4; i++)
        dst[i] = a[i] * b[i];
}

void SCALAR_FDIV(float* dst, float* a, float* b)
{
    for(int i = 0; i < 4; i++)
        dst[i] = a[i] / b[i];
}