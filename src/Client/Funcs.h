#ifndef CC_FUNCS_H
#define CC_FUNCS_H
#include "Typedefs.h"
/* Simple function implementations
   NOTE: doing min(x++, y) etc will increment x twice!
   Copyright 2017 ClassicalSharp | Licensed under BSD-3
*/

/* returns a bit mask for the nth bit in an integer */
#define bit(x) (1 << x)
/* returns smallest of two numbers */
#define min(x, y) ((x) < (y) ? (x) : (y))
/* returns largest of two numbers */
#define max(x, y) ((x) > (y) ? (x) : (y))
/* returns number of elements in given array. */
#define Array_NumElements(arr) (sizeof(arr) / sizeof(arr[0]))

/* returns whether character is uppercase letter */
bool Char_IsUpper(UInt8 c);
/* Converts uppercase letter to lowercase */
UInt8 Char_ToLower(UInt8 c);
#endif