// adapter for zlib.h -> miniz.h
//
// Adds some definitions required to be compatible enough to zlib
// allowing minizip to compile and link with miniz.

#include "miniz.h"

#define OF(args) args
#define ZEXPORT

#include <sys/types.h>
#define z_off_t off_t

#define NOUNCRYPT
#define NOCRYPT

#define Z_BINARY   0
#define Z_TEXT     1
#define Z_ASCII    Z_TEXT   /* for compatibility with 1.2.2 and earlier */
#define Z_UNKNOWN  2
