#ifndef HAL_HALMAILBOX_H_
#define HAL_HALMAILBOX_H_

/* a properly aligned buffer */
extern volatile unsigned int mbox[36];

#define MBOX_REQUEST    0x00000000
#define MBOX_RESPONSE   0x80000000
#define MBOX_FULL       0x80000000
#define MBOX_EMPTY      0x40000000

/* channels */
#define MBOX_CH_POWER   0
#define MBOX_CH_FB      1
#define MBOX_CH_VUART   2
#define MBOX_CH_VCHIQ   3
#define MBOX_CH_LEDS    4
#define MBOX_CH_BTNS    5
#define MBOX_CH_TOUCH   6
#define MBOX_CH_COUNT   7
#define MBOX_CH_PROP    8

/* tags */
#define MBOX_TAG_GETSERIAL      0x10004
#define MBOX_TAG_SETCLKRATE     0x38002
#define MBOX_TAG_LAST           0

int mbox_call(unsigned char ch);

#endif /* HAL_HALMAILBOX_H_ */