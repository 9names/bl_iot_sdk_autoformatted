/*
 * memcpy.c
 */

#include <stdint.h>
#include <string.h>

void *memcpy(void *dst, const void *src, size_t n) {
  const char *p = src;
  char *q = dst;
  while (n--) {
    *q++ = *p++;
  }
  return dst;
}
