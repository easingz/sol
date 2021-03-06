#ifndef S_DEBUG_H_
#define S_DEBUG_H_
#if S_DEBUG

#include <sol/common.h>

// Debug: Function prototype for the DBGINSPECT instruction
#if S_DEBUG
typedef void (*SDebugVMCallback)(SVM*, SSched*, STask*, SInstr* arpc);
#endif

// Binary representation of integer `x` of length `bitcount`
S_UNUSED static const char*
SDFormatBin(uintmax_t x, size_t bitcount) {
  static char buf[9 * sizeof(uintmax_t) + 1] = {0}; // 9=8C+1SP
  char *s = buf + ((9 * sizeof(uintmax_t)) - bitcount - 2);
  size_t count = 0;
  *--s = 0;
  if (!x) {
    ++count;
    *--s = '0';
  }
  for (; x && s > buf+1; x /= 2) {
    if (count++ % 8 == 0) {
      *--s = ' ';
    }
    *--s = '0' + x % 2;
  }
  while (s > buf+1) {
    if (count++ % 8 == 0) {
      *--s = ' ';
    }
    *--s = '0';
  }
  return s;
}

#endif // S_DEBUG
#endif // S_DEBUG_H_
