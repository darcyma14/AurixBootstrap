#ifndef APP_INC_XTYPE_H_
#define APP_INC_XTYPE_H_

#ifndef U32
#define U32 unsigned int
#endif
#ifndef U16
#define U16 unsigned short
#endif
#ifndef S32
#define S32 int
#endif
#ifndef S16
#define S16 short int
#endif
#ifndef U8
#define U8  unsigned char
#endif
#ifndef S8
#define S8  char
#endif

typedef signed long long         i64;
typedef unsigned long            u32;
typedef unsigned short           u16;
typedef unsigned char            u8;

typedef signed long              s32;
typedef signed short             s16;
typedef signed char              s8;

typedef volatile unsigned long   vu32;
typedef volatile unsigned short  vu16;
typedef volatile unsigned char   vu8;

typedef volatile signed long     vs32;
typedef volatile signed short    vs16;
typedef volatile signed char     vs8;

typedef int             SockType_t;
typedef int             DescType_t;
typedef unsigned char   BuffType_t;
typedef int             MsgQType_t;
typedef unsigned char   DateType_t;
typedef int             PDioType_t;
typedef int             FileType_t;

#ifndef FALSE
//typedef enum { FALSE = 0, TRUE  = !FALSE } bool;
#define TRUE    1
#define FALSE   0
#endif

#define INVALID_DEV_HANDLE  0xFFFFFFFF

typedef enum { RESET = 0, SET   = !RESET } FlagStatus, ITStatus;

typedef enum { DISABLE = 0, ENABLE  = !DISABLE} FunctionalState;

typedef enum { ERROR = 0, SUCCESS  = !ERROR} ErrorStatus;

#ifndef OFF
typedef enum { OFF = 0, ON  = !OFF} SwitchStatus;
#endif

#define STX_CHR     ( 0x02 )
#define ETX_CHR     ( 0x03 )
#define ACK_CHR     ( 0x06 )
#define NAK_CHR     ( 0x15 )

#define OK      1
#define NG      0

#define ESC_KEY ('q')   // 0x1B

#endif /* APP_INC_XTYPE_H_ */
