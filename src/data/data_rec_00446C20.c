typedef signed char s8;
typedef signed short s16;

/* Scaled step tables and signed-byte step rows of the 0x0018Cxxx-0x0018Fxxx
 * actor motion code. Members are reached through their own addresses (D_00446C20,
 * D_00446C40, and the five D_00446C60/70/90/B0/C8 row pointers in
 * D_00446CE0); nothing addresses the unit start. Reader widths:
 *
 * speed_20[16] (D_00446C20): func_0018F1A0 (0x0018F1A0) indexes it with a byte
 * argument * 2 (sll 0x0018F1B0, lh 0x0018F1DC) and converts the s16 to float.
 * speed_40[16] (D_00446C40): s16 at index * 2 (sll + lh) in func_0018CA30,
 * func_0018CBB0, func_0018CC30, func_0018CCD0, func_0018CD70 (lh at 0x0018CA5C,
 * 0x0018CBC4, 0x0018CC70, 0x0018CD10, 0x0018CD84), func_0018EA00 (0x0018EA44)
 * and func_0018EF20 (0x0018EF48); src/g5d.c and src/h12b.c read it as s16.
 * row_60..row_C8: signed-byte step rows selected by D_00446CE0[k]
 * (src/fb74_c.c stores the pointer at actor+0x228). func_0018CEA0
 * (0x0018CF7C-CFA8) and func_0018D030 (0x0018D058-D080) read lb +0 through the
 * cursor, stop at the first value <= 0 (c.le.s 0x0018CF94) and otherwise advance
 * it by one byte. Bytes after that terminator (-1, or an early 0 in row_C8) are
 * unread; array sizes (16, 32, 32, 24, 24) follow the pointer targets. */
typedef struct {
    s16 speed_20[16];  /* 0x00446C20 */
    s16 speed_40[16];  /* 0x00446C40 */
    s8 row_60[16];     /* 0x00446C60 */
    s8 row_70[32];     /* 0x00446C70 */
    s8 row_90[32];     /* 0x00446C90 */
    s8 row_B0[24];     /* 0x00446CB0 */
    s8 row_C8[24];     /* 0x00446CC8 */
} Data00446C20;
typedef char data_rec_00446C20_size_check[(sizeof(Data00446C20) == 0xC0) ? 1 : -1];

Data00446C20 data_rec_00446C20 = {
    { 400, 500, 600, 700, 800, 900, 1000, 1150,
      1300, 1500, 1700, 2000, 2500, 3000, 3500, 4000 },
    { -1280, -1536, -1792, -2048, -2304, -2560, -2816, -3072,
      -3328, -3584, -3840, -4096, -4352, -4608, -4864, -5120 },
    { 6, 5, 4, 4, 3, 2, 2, 1, 1, 1, 1, -1, 0, 0, 0, 0 },
    { 6, 6, 6, 5, 5, 5, 4, 4, 3, 3, 2, 1, 1, 1, 1, 1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 8, 8, 8, 7, 7, 7, 6, 5, 5, 4, 3, 2, 1, 1, 1, 1, 1, 1, 1, 1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 10, 10, 10, 9, 9, 9, 8, 7, 7, 6, 5, 4, 3, 3, 3, 3, 1, 1, 1, 1, -1, -1, 0, 0 },
    { 11, 11, 9, 9, 7, 7, 5, 5, 2, 2, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};
