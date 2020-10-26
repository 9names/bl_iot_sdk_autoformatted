/*
 * memset.c
 */

#include <stdint.h>
#include <string.h>

void *memset(void *dst, int c, size_t n) {
  char *q = dst;
  while (n--) {
    *q++ = c;
  }
  return dst;
}
