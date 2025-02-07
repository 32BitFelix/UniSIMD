#include "SSEext.h"

#include <xmmintrin.h>


char SSE_GET_REG_SIZE()
{
    return 0x10;
}

void SSE_FADD(float* dst, float* a, float* b)
{
    __m128 mA = _mm_loadu_ps(a);


    __m128 mB = _mm_loadu_ps(b);


    __m128 mDST = _mm_add_ps(mA, mB);

    _mm_storeu_ps(dst, mDST);
}

void SSE_FSUB(float* dst, float* a, float* b)
{
    __m128 mA = _mm_loadu_ps(a);


    __m128 mB = _mm_loadu_ps(b);


    __m128 mDST = _mm_sub_ps(mA, mB);

    _mm_storeu_ps(dst, mDST);
}

void SSE_FMUL(float* dst, float* a, float* b)
{
    __m128 mA = _mm_loadu_ps(a);


    __m128 mB = _mm_loadu_ps(b);


    __m128 mDST = _mm_mul_ps(mA, mB);

    _mm_storeu_ps(dst, mDST);
}

void SSE_FDIV(float* dst, float* a, float* b)
{
    __m128 mA = _mm_loadu_ps(a);


    __m128 mB = _mm_loadu_ps(b);


    __m128 mDST = _mm_div_ps(mA, mB);

    _mm_storeu_ps(dst, mDST);
}