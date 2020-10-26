/*
 * Derived from:
 * http://www.kernel.org/pub/linux/libs/klibc/
 */
/*
 * strchr.c
 */

#include <compat_attribute.h>
#include <string.h>

__WEAK__
char *strchr(const char *s, int c) {
  while (*s != (char)c) {
    if (!*s)
      return NULL;
    s++;
  }

  return (char *)s;
}
