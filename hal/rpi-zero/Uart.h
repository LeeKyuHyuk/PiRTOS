#ifndef HAL_RPI_ZERO_UART_H_
#define HAL_RPI_ZERO_UART_H_

/* Auxilary mini UART registers */
#define AUX_ENABLES (*(volatile unsigned int *)(MMIO_BASE + 0x00215004))
#define AUX_MU_IO (*(volatile unsigned int *)(MMIO_BASE + 0x00215040))
#define AUX_MU_IER (*(volatile unsigned int *)(MMIO_BASE + 0x00215044))
#define AUX_MU_IIR (*(volatile unsigned int *)(MMIO_BASE + 0x00215048))
#define AUX_MU_LCR (*(volatile unsigned int *)(MMIO_BASE + 0x0021504C))
#define AUX_MU_MCR (*(volatile unsigned int *)(MMIO_BASE + 0x00215050))
#define AUX_MU_LSR (*(volatile unsigned int *)(MMIO_BASE + 0x00215054))
#define AUX_MU_CNTL (*(volatile unsigned int *)(MMIO_BASE + 0x00215060))
#define AUX_MU_BAUD (*(volatile unsigned int *)(MMIO_BASE + 0x00215068))

#endif /* HAL_RPI_ZERO_UART_H_ */