#ifndef LIB_STDIO_H_
#define LIB_STDIO_H_

#include "stdarg.h"

#define NULL ((void *)0)

typedef enum utoa_t
{
    utoa_dec = 10,
    utoa_hex = 16,
} utoa_t;

unsigned int putstr(const char *s);
unsigned int debug_printf(const char *format, ...);
unsigned int vsprintf(char *buf, const char *format, va_list arg);
unsigned int utoa(char *buf, unsigned int val, utoa_t base);

#endif /* LIB_STDIO_H_ */