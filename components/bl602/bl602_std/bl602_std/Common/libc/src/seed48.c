/*
 * Derived from:
 * http://www.kernel.org/pub/linux/libs/klibc/
 */
/*
 * seed48.c
 */

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

extern unsigned short __rand48_seed[3];

unsigned short *seed48(unsigned short int xsubi[3]) {
  static unsigned short oldseed[3];
  memcpy(oldseed, __rand48_seed, sizeof __rand48_seed);
  memcpy(__rand48_seed, xsubi, sizeof __rand48_seed);

  return oldseed;
}
