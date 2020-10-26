/*
 * Derived from:
 * http://www.kernel.org/pub/linux/libs/klibc/
 */
/*
 * mrand48.c
 */

#include <stdint.h>
#include <stdlib.h>

/* Common with lrand48.c, srand48.c */
extern unsigned short __rand48_seed[3];

long mrand48(void) { return jrand48(__rand48_seed); }
