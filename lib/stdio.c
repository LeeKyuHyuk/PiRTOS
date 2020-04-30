#include "HalUart.h"
#include "stdio.h"


unsigned int putstr(const char* s)
{
    unsigned int c = 0;
    while(*s)
    {
        Hal_uart_put_char(*s++);
        c++;
    }
    return c;
}