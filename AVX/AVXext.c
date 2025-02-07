#include "AVXext.h"

#include <string.h>

#include <immintrin.h>

char AVX_GET_REG_SIZE()
{
    return 0x20;
}

void AVX_FADD(float* dst, float* a, float* b)
{
    __m256 mA = _mm256_loadu_ps(a);


    __m256 mB = _mm256_loadu_ps(b);


    __m256 mDST = _mm256_add_ps(mA, mB);

    _mm256_storeu_ps(dst, mDST);
}

void AVX_FSUB(float* dst, float* a, float* b)
{
    __m256 mA = _mm256_loadu_ps(a);


    __m256 mB = _mm256_loadu_ps(b);


    __m256 mDST = _mm256_sub_ps(mA, mB);

    _mm256_storeu_ps(dst, mDST);
}

void AVX_FMUL(float* dst, float* a, float* b)
{
    __m256 mA = _mm256_loadu_ps(a);


    __m256 mB = _mm256_loadu_ps(b);


    __m256 mDST = _mm256_mul_ps(mA, mB);

    _mm256_storeu_ps(dst, mDST);
}

void AVX_FDIV(float* dst, float* a, float* b)
{
    __m256 mA = _mm256_loadu_ps(a);


    __m256 mB = _mm256_loadu_ps(b);


    __m256 mDST = _mm256_div_ps(mA, mB);

    _mm256_storeu_ps(dst, mDST);
}