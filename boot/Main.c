#include "HalUart.h"

void main(void)
{
  // UART 초기화
  uart_init();

  // "Hello World!"를 UART로 출력
  uart_puts("Hello PiRTOS!\n");
  uart_puts("Raspberry Pi Zero UART\n");

  // UART 입력되는 것을 UART로 출력 (Echo 기능)
  while (1)
  {
    uart_send(uart_getc());
  }
}
