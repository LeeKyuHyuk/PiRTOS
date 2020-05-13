#include "HalUart.h"
#include "stdio.h"

#define PRINTF_BUF_LEN 1024

static char printf_buf[PRINTF_BUF_LEN]; // 1KB

unsigned int putstr(const char *s)
{
    unsigned int c = 0;
    while (*s)
    {
        if (*s == '\n')
            Hal_uart_put_char('\r');
        Hal_uart_put_char(*s++);
        c++;
    }
    return c;
}

unsigned int debug_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vsprintf(printf_buf, format, args);
    va_end(args);

    return putstr(printf_buf);
}

unsigned int vsprintf(char *buf, const char *format, va_list arg)
{
    unsigned int c = 0;

    char ch;
    char *str;
    unsigned int uint;
    unsigned int hex;

    for (unsigned int i = 0; format[i]; i++)
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
            case 'c':
                ch = (char)va_arg(arg, int);
                buf[c++] = ch;
                break;
            case 's':
                str = (char *)va_arg(arg, char *);
                if (str == NULL)
                {
                    str = "(null)";
                }
                while (*str)
                {
                    buf[c++] = (*str++);
                }
                break;
            case 'u':
                uint = (unsigned int)va_arg(arg, unsigned int);
                c += utoa(&buf[c], uint, utoa_dec);
                break;
            case 'x':
                hex = (unsigned int)va_arg(arg, unsigned int);
                c += utoa(&buf[c], hex, utoa_hex);
                break;
            }
        }
        else
        {
            buf[c++] = format[i];
        }
    }

    if (c >= PRINTF_BUF_LEN)
    {
        buf[0] = '\0';
        return 0;
    }

    buf[c] = '\0';
    return c;
}

unsigned int utoa(char *buf, unsigned int val, utoa_t base)
{
    unsigned int c = 0;
    int idx = 0;
    char tmp[11]; // It is big enough for store 32 bit int

    do
    {
        unsigned int t = val % (unsigned int)base;
        if (t >= 10)
        {
            t += 'A' - '0' - 10;
        }
        tmp[idx] = (t + '0');
        val /= base;
        idx++;
    } while (val);

    // reverse
    idx--;
    while (idx >= 0)
    {
        buf[c++] = tmp[idx];
        idx--;
    }

    return c;
}