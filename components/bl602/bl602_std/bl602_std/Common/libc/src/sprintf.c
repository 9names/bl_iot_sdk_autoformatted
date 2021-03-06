/*
 * Derived from:
 * http://www.kernel.org/pub/linux/libs/klibc/
 */
/*
 * sprintf.c
 */

#include <stdarg.h>
#include <stdio.h>

int sprintf(char *buffer, const char *format, ...) {
  va_list ap;
  int rv;

  va_start(ap, format);
  rv = vsnprintf(buffer, (~(size_t)0) >> 1, format, ap);
  va_end(ap);

  return rv;
}
