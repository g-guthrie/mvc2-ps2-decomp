typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { u8 p0[0xC]; u16 hc; s16 he; } PWo;
typedef struct PW { u8 b0; u8 p1[4]; u8 b5; u8 p6[0x1B1-6]; s8 b1b1; u8 p1b2[0x1D4-0x1B2]; PWo *w1d4; u8 p1d8[0x1E4-0x1D8]; u8 b1e4; u8 p1e5[0x1FF-0x1E5]; s8 b1ff; u8 p200[0x24E-0x200]; s8 b24e; u8 p24f[0x268-0x24F]; u8 b268; u8 p269[0x425-0x269]; u8 b425; u8 p426[2]; s32 w428; u8 p42c[0x434-0x42C]; s16 h434; } PW;
s32 func_001E81C0(u8 *p, PW *q, s32 index) {
    extern s32 func_001E8300(void *, void *, int, int);
    if (q->w428 & 0x7000000) return 0;
    if (q->b0 == 0 || q->h434 == 0 || q->b1ff != 0 || q->b1b1 == 0 || q->b268 != 0 || q->b425 != 0) return 0;
    {
        if (q->b24e >= 2) return 0;
        if (q->b5 != 0 || q->b1e4 == 0x12 || q->b1e4 == 0x13) return 0;
        if (q->w1d4->hc != 0) {
            if (func_001E8300(p, q, index, (s16)q->w1d4->hc) != 0) return 1;
        }
        if (q->w1d4->he <= 0) return 0;
        return func_001E8300(p, q, index, q->w1d4->he) != 0;
    }
    return 0;
}
