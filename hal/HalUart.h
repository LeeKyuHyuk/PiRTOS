#ifndef HAL_HALUART_H_
#define HAL_HALUART_H_

void uart_init();
void uart_send(unsigned int c);
char uart_getc();
void uart_puts(char *s);

#endif /* HAL_HALUART_H_ */