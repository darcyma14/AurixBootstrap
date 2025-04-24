#ifndef APP_INC_XHELPER_H_
#define APP_INC_XHELPER_H_

#ifndef __inline
#define __inline inline
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define WRITE8(p, x)    *((volatile unsigned char  *)(p)) = x
#define WRITE16(p, x)   *((volatile unsigned short *)(p)) = x
#define WRITE32(p, x)   *((volatile unsigned int   *)(p)) = x
#define READ8(p)        *((volatile unsigned char  *)(p))
#define READ16(p)       *((volatile unsigned short *)(p))
#define READ32(p)       *((volatile unsigned int   *)(p))

#define WREG(p, x)      *((volatile unsigned       *)(p)) = x
#define RREG(p)         *((volatile unsigned       *)(p))

#define _bigger(x,y)    ((x) > (y) ? (x) : (y))
#define _smaller(x,y)   ((x)<(y)?(x):(y))
#define _swap4(n)       ((((n)&0xFF) << 24) + (((n) & 0xFF00) << 8) + (((n) & 0xFF0000) >> 8) + (((n) & 0xFF000000) >> 24))
#define _swap2(n)       ((((n)&0xFF) << 8) + (((n) & 0xFF00) >> 8))
#define _min(x,y,z)     _bigger(_bigger(x, y), z)
#define _max(x,y,z)     _smaller(_smaller(x, y), z)
#define _absdiff_ulong(o, n)    (((n)>=(o)?(n)-(o):(n)+(0xFFFFFFFF - (o))))

#define __gettick()     xTaskGetTickCount()

#define _zeromem(a)     memset(&(a), 0, sizeof(a))
#define _bend4(b, n)    b[0] = ((n>>24)&0xFF); b[1]=((n>>16)&0xFF); b[2]=((n>>8)&0xFF); b[3]=(n&0xFF);
#define _bend2(b, n)    b[0] = ((n>>8)&0xFF); b[1]=(n&0xFF);
#define _bnum2(n, b)    n = (b[1]&0x00FF); n|=((b[0]<<8)&0xFF00)

#define _YYYY_MM_DD     (4)
#define _YYYY           (2)
#define _MM_DD          (2)
#define _hh_mm          (2)
#define _MM_DD_hh       (3)
#define _hh_mm_ss       (3)
#define _hh_mm_ss_msec  (5)

#ifndef UNUSED_PARAMETER
#define UNUSED_PARAMETER(VariableName)          { if( ( VariableName ) != 0U )\
                                                { /* Do Nothing */ } }
#endif

#define U16PTR(p)   (*(u8 *)(p) & 0xFF) | (((*(u8 *)((p)+1) & 0xFF) << 8) & 0xFF00)
#define U16PTR_R(p) (*(u8 *)((p)+1) & 0xFF) | (((*(u8 *)(p) & 0xFF) << 8) & 0xFF00)

#define IS_AF(c)        ((c>='A')&&(c<='F'))
#define IS_af(c)        ((c>='a')&&(c<='f'))
#define IS_09(c)        ((c>='0')&&(c<='9'))
#define ISVALIDHEX(c)   IS_AF(c) || IS_af(c) || IS_09(c)
#define ISVALIDDEC(c)   IS_09(c)
#define CONVERTDEC(c)   (c-'0')

#define CONVERTHEX_alpha(c)     (IS_AF(c) ? (c-'A'+10) : (c-'a'+10))
#define CONVERTHEX(c)           (IS_09(c) ? (c-'0') : CONVERTHEX_alpha(c))

#ifndef _I64_MAX
    #define _I64_MAX    ((i64)0xFFFFFFFF<<32)|((i64)0xFFFFFFFF)
#endif

#define ByteSwap(A)     (A=(A<<8)+(A>>8))

#define ALTP2   0x03
#define ALTP1   0x02
#define OUTP    0x01
#define INP     0x00

#define rGPxCON(x, p, o)    x &= ~(3<<(p*2));\
                            x |= (o<<(p*2))

#ifndef portTICK_PERIOD_US
#define portTICK_PERIOD_US          ((portTickType)1000000L / configTICK_RATE_HZ)
#endif

__inline static unsigned short join2(unsigned char lo, unsigned char hi);
__inline static unsigned short join2(unsigned char lo, unsigned char hi)
{
    union U_T
    {
        unsigned char c[2];
        unsigned short s;
    }u;

    u.c[0] = lo;
    u.c[1] = hi;
    return u.s;
}

__inline static unsigned long join4(unsigned char lo, unsigned char hi, unsigned char hilo, unsigned char hihi);
__inline static unsigned long join4(unsigned char lo, unsigned char hi, unsigned char hilo, unsigned char hihi)
{
    union U_T
    {
        unsigned char c[4];
        unsigned long l;
    }u;

    u.c[0] = lo;
    u.c[1] = hi;
    u.c[2] = hilo;
    u.c[3] = hihi;
    return u.l;
}

unsigned long uxRand(void);
void grand(void *pBuf, long lAmount);
void mysrand(unsigned long seed);
unsigned short myrand(void);
unsigned long rd32big(void *p);
unsigned long le2be(unsigned char *dat, unsigned char len);
void wr32big(void *p, unsigned long u);
long stricmp(const char *s1, const signed char *s2);
char* strupr(char *s1);
unsigned char Bit_Reverse(unsigned char x);
size_t strnlen(const char *string, size_t maxlen);
int chk_chr(const char *str, int chr);
void* memcpy_P(void* dest, const void* src, size_t count);
unsigned long CLKMicroSecsToTicks(unsigned long usec);
unsigned long CLKMilliSecsToTicks(unsigned long msec);
unsigned long CLKTicksToMilliSecs(unsigned long tick);
unsigned long CLKSecondsToTicks(unsigned long sec);
char* vPrintHexArray1(char *arry, int cnt, char *bufp);
void DWORDToBCD4(unsigned long dwvalue,  unsigned char buffer[4]);
void DWORDToBCD3(unsigned long dwvalue , unsigned char buffer[3]);
void WORDToBCD2(unsigned short wvalue, unsigned char buffer[2]);
unsigned char BYTEToBCD1(unsigned char value);
unsigned char BCD1ToBYTE(unsigned char Bcd);
unsigned short BCD2ToWORD(unsigned char *Bcds);
unsigned long HEX3ToDWORD(unsigned char *hexb);
unsigned int kbhit(void);
typedef void (*fPrintfCallback)(char *pecFmt, ...);
void PrintLongNumThounsandSeparators(unsigned long numbers , char Seperator, int space, char *pszText/*fPrintfCallback PrintFunc*/);

BaseType_t Str2Int(uint8_t *pInputStr, int *iNum);
void Int2Str(uint8_t *pucStr, int iNum);

#ifdef __cplusplus
}
#endif

#endif /* APP_INC_XHELPER_H_ */
