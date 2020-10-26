/*
 * Derived from:
 * http://www.kernel.org/pub/linux/libs/klibc/
 */
/*
 * strtox.c
 *
 * strto...() functions, by macro definition
 */

#include <bl_utils.h>
#include <inttypes.h>
#include <stddef.h>
#include <stdlib.h>

WEAK TYPE NAME(const char *nptr, char **endptr, int base) {
  return (TYPE)strntoumax(nptr, endptr, base, ~(size_t)0);
}
