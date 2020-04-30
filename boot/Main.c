#include "HalUart.h"

static void Hw_init(void);

void main(void)
{
  Hw_init();

  unsigned int i = 100;
  while (i--)
    Hal_uart_put_char('A');
}

static void Hw_init(void)
{
  Hal_uart_init();
}