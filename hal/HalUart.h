#ifndef HAL_HALUART_H_
#define HAL_HALUART_H_

void Hal_uart_init();
void Hal_uart_put_char(unsigned char ch);
unsigned char Hal_uart_get_char(void);

#endif /* HAL_HALUART_H_ */