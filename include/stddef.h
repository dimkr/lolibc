#include_next <stddef.h>

#ifndef __dead
#define __dead __attribute__((noreturn))
#endif

#ifndef DEF_WEAK
#define DEF_WEAK(x) __asm__("")
#endif
