// Guard for compiler
#ifndef MSIMD_H
#define MSIMD_H


// METHODS


// Initialises
// the library
void _INIT_SIMD();

// Loads the methods
// that hold the
// AVX extensions
void _LOAD_AVX();

// Loads the methods
// that hold the
// SSE42 extensions
void _LOAD_SSE42();

// Loads the methods
// that hold the
// SSE41 extensions
void _LOAD_SSE41();

// Loads the methods
// that hold the
// SSE3 extensions
void _LOAD_SSE3();

// Loads the methods
// that hold the
// SSE2 extensions
void _LOAD_SSE2();

// Loads the methods
// that hold the
// SSE extensions
void _LOAD_SSE();

// Loads the methods
// that hold the
// MMX extensions
void _LOAD_MMX();

// Loads the methods
// that hold the
// Scalar operations
void _LOAD_SCALAR();


// FUNCTION POINTERS


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


// FIELDS


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

#endif