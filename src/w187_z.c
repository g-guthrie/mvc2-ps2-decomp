typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 p0[0x1C]; s16 h1C; s16 h1E; u8 pa[0x30]; f32 f50; u8 pb[8]; f32 f5C; u8 pc[8]; f32 f68; } PF;
extern void func_001458C0();

void func_00145220(u8 *p) {
    s32 h;
    s32 n;
    f32 f;
    PF *q = (PF *)p;
    h = q->h1C;
    if (h != 0) {
        q->h1C = h - 1;
        q->f5C += q->f68;
        *(s32 *)(p + 0x40) = (u16)(u32)(s32)(0.5 + 65536.0 * (double)(q->f5C) / 360.0);
        q->h1E = 1;
    } else {
        q->f5C = q->f50;
        n = q->h1E;
        if (n < 11) {
            if (n % 2 != 0) f = 2.0f / (f32)n;
            else f = -2.0f / (f32)n;
            q->f5C += f;
            q->h1E = q->h1E + 1;
        } else {
            if (*(s32 *)(p + 0xD8) == 0) func_001458C0();
        }
        *(s32 *)(p + 0x40) = (u16)(u32)(s32)(0.5 + 65536.0 * (double)(q->f5C) / 360.0);
    }
}
