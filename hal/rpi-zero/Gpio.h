#ifndef HAL_RPI_ZERO_GPIO_H_
#define HAL_RPI_ZERO_GPIO_H_

/* GPIO registers */
#define GPFSEL1 (*(volatile unsigned int *)(MMIO_BASE + 0x00200004))
#define GPPUD (*(volatile unsigned int *)(MMIO_BASE + 0x00200094))
#define GPPUDCLK0 (*(volatile unsigned int *)(MMIO_BASE + 0x00200098))

#endif /* HAL_RPI_ZERO_GPIO_H_ */