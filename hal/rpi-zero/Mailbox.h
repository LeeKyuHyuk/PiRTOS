#ifndef HAL_RPI_ZERO_MAILBOX_H_
#define HAL_RPI_ZERO_MAILBOX_H_

#define VIDEOCORE_MBOX  (MMIO_BASE + 0x0000B880)
#define MBOX_READ       ((volatile unsigned int *)(VIDEOCORE_MBOX + 0x0))
#define MBOX_POLL       ((volatile unsigned int *)(VIDEOCORE_MBOX + 0x10))
#define MBOX_SENDER     ((volatile unsigned int *)(VIDEOCORE_MBOX + 0x14))
#define MBOX_STATUS     ((volatile unsigned int *)(VIDEOCORE_MBOX + 0x18))
#define MBOX_CONFIG     ((volatile unsigned int *)(VIDEOCORE_MBOX + 0x1C))
#define MBOX_WRITE      ((volatile unsigned int *)(VIDEOCORE_MBOX + 0x20))

#endif /* HAL_RPI_ZERO_MAILBOX_H_ */