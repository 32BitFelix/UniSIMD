#include "mSIMD.h"


#include <intrin.h>

#include "AVX/AVXext.c"

#include "SSE/SSEext.c"

#include "SCALAR/SCALARext.c"


// Initialises the
// library to get
// the runtime info
// and prepare
// everything according
// to the cpu's specs
void _INIT_SIMD()
{
    // Allocate a
    // constant
    // int array
    // to hold the
    // function ids
    int info[4];

    // Get the cpu
    // specs
    __cpuid(info, 0);


    // If the info we
    // want exists...
    // (SIMD in this case)
    if(info[0] >= 0x00000001)
    {
        // Get the SIMD
        // sub functions
        __cpuid(info, 0x00000001);


        // AVX SUPPORT
        if((info[2] & ((int)1 << 28)) != 0)
        {
            _LOAD_AVX();

            return;
        }

        // SSE42 SUPPORT
        /*if((info[2] & ((int)1 << 20)) != 0)
        {
            _LOAD_SSE42();

            return;
        }

        // SSE41 SUPPORT
        if((info[2] & ((int)1 <<  9)) != 0)
        {
            _LOAD_SSE41();

            return;
        }

        // SSE3 SUPPORT
        if((info[2] & ((int)1 <<  0)) != 0)
        {
            _LOAD_SSE3();

            return;
        }

        // SSE2 SUPPORT
        if((info[3] & ((int)1 << 26)) != 0)
        {
            _LOAD_SSE2();

            return;
        }*/

        // SSE SUPPORT
        if((info[3] & ((int)1 << 25)) != 0)
        {
            _LOAD_SSE();

            return;
        }

        // MMX SUPPORT
        /*if((info[3] & ((int)1 << 23)) != 0)
        {
            _LOAD_MMX();

            return;
        }*/

    }

    // Get Scalar implementation.
    // Reaching this portion of
    // the code is highly unlikely,
    // but is still kept for the
    // sake of compatibility and
    // safety

    _LOAD_SCALAR();
};

// Loads the methods
// that hold the
// AVX extensions
void _LOAD_AVX()
{
    _CURRENT_SUPPORT = 64;

    _GET_REG_SIZE = &AVX_GET_REG_SIZE;

    _FADD = &AVX_FADD;

    _FSUB = &AVX_FSUB;

    _FMUL = &AVX_FMUL;

    _FDIV = &AVX_FDIV;
}

// Loads the methods
// that hold the
// SSE42 extensions
void _LOAD_SSE42()
{

}

// Loads the methods
// that hold the
// SSE41 extensions
void _LOAD_SSE41()
{

}

// Loads the methods
// that hold the
// SSE3 extensions
void _LOAD_SSE3()
{

}

// Loads the methods
// that hold the
// SSE2 extensions
void _LOAD_SSE2()
{

}

// Loads the methods
// that hold the
// SSE extensions
void _LOAD_SSE()
{
    _CURRENT_SUPPORT = 2;

    _GET_REG_SIZE = &SSE_GET_REG_SIZE;

    _FADD = &SSE_FADD;

    _FSUB = &SSE_FSUB;

    _FMUL = &SSE_FMUL;

    _FDIV = &SSE_FDIV;
}

// Loads the methods
// that hold the
// MMX extensions
void _LOAD_MMX()
{

}

// Loads the methods
// that hold the
// Scalar operations
void _LOAD_SCALAR()
{
    _CURRENT_SUPPORT = 0;

    _GET_REG_SIZE = &SCALAR_GET_REG_SIZE;

    _FADD = &SCALAR_FADD;

    _FSUB = &SCALAR_FSUB;

    _FMUL = &SCALAR_FMUL;

    _FDIV = &SCALAR_FDIV;    
}


// Holds the reference
// to the method that
// returns the size of
// the registers of the
// current extension in bytes
char (*_GET_REG_SIZE)();

// Holds the reference to
// a method that adds the
// register of floats
void (*_FADD)(float*, float*, float*);

// Holds the reference to
// a method that subtracts the
// register of floats
void (*_FSUB)(float*, float*, float*);

// Holds the reference to
// a method that multiplies the
// register of floats
void (*_FMUL)(float*, float*, float*);

// Holds the reference to
// a method that divides the
// register of floats
void (*_FDIV)(float*, float*, float*);


// Methods beyond this
// point have not been
// implemented yet


// Holds the reference to
// a method that calculates the
// remainder from the registers
// of floats
void (*_FMOD)(float*, float*, float*);

// Holds the reference to
// a method that caluclates the
// squareroot from the registers
// of floats
void (*_FSQRT)(float*, float*, float*);

// Holds the reference to
// a method that caluclates the
// reverse squareroot from the registers
// of floats
void (*_FRSQRT)(float*, float*, float*);


// Holds the reference to
// a method that adds the
// register of floats
void (*_IADD)(float*, float*, float*);

// Holds the reference to
// a method that subtracts the
// register of floats
void (*_ISUB)(float*, float*, float*);

// Holds the reference to
// a method that multiplies the
// register of floats
void (*_IMUL)(float*, float*, float*);

// Holds the reference to
// a method that divides the
// register of floats
void (*_IDIV)(float*, float*, float*);

// Holds the reference to
// a method that calculates the
// remainder from the registers
// of floats
void (*_IMOD)(float*, float*, float*);

// Holds the reference to
// a method that caluclates the
// squareroot from the registers
// of floats
void (*_ISQRT)(float*, float*, float*);

// Holds the reference to
// a method that caluclates the
// reverse squareroot from the registers
// of floats
void (*_IRSQRT)(float*, float*, float*);


// Specifies the currently
// used SIMD instructions.
//   0 = SCALAR
//   1 = MMX
//   2 = SSE
//   4 = SSE2
//   8 = SSE3
//  16 = SSE41
//  32 = SSE42
//  64 = AVX
char _CURRENT_SUPPORT;
