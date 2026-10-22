typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
/* gp-relative tables read by func_0023C040 / func_0023C360 (D_004C0258..D_004C0270 packed together) */
typedef struct {
    s32 a[2];       /* D_004C0258: s32 (cvt.s.w to float), lw indexed by actor +0x1B7 */
    s8 b[8];        /* D_004C0260: lb indexed by actor +0x1B7 */
    u8 c[4][2];     /* D_004C0268: lbu [actor+0x21 * 2 + actor+0x20] */
    u8 d[4][2];     /* D_004C0270: lbu [actor+0x21 * 2 + actor+0x20] */
} Data004C0258;
typedef char Data004C0258_size_check[(sizeof(Data004C0258) == 32) ? 1 : -1];
Data004C0258 data_u32_004C0258 = {
    { 0x000A0000, 0x000C0000 },
    { 16, 36, 0, 0, 0, 0, 0, 0 },
    { { 0x33, 0x35 }, { 0x36, 0x38 }, { 0x39, 0x3B }, { 0, 0 } },
    { { 4, 5 }, { 6, 7 }, { 8, 9 }, { 0, 0 } },
};
