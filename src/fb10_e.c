typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 b0, b1, b2, b3; f32 f4, f8, fC; s32 w10; } E16;

extern u8 *D_00446410[];
extern E16 D_004B49A0[];
extern s32 D_004463C0;
extern f32 D_004463C4, D_004463C8, D_004463CC, D_004463D0, D_004463D4, D_004463D8, D_004463DC, D_004463E0, D_004463E4;
extern f32 D_004F7FD0, D_004F7FD4;

void func_0016DCB0(s32 a, s32 idx) {
    extern s32 func_00153AB0(void *, s32);
    u8 *t;
    u8 *s0;
    s32 n;
    s32 i;
    E16 *e;
    f32 tmp;
    t = D_00446410[idx];
    s0 = t + 2;
    n = t[0];
    a += t[1];
    D_004463CC = 0.949999988079071f;
    D_004463C0 = a;
    for (i = 0; i < n; i++, s0++) {
        e = &D_004B49A0[*s0];
        D_004463C4 = e->f4;
        D_004463C8 = e->f8;
        D_004463C4 += D_004F7FD0;
        D_004463C8 += D_004F7FD4;
        D_004463D8 = (f32)(u32)e->b0 / 256.0f;
        D_004463DC = (f32)(u32)e->b1 / 256.0f;
        D_004463E0 = (f32)(s32)(e->b0 + e->b2) / 256.0f;
        D_004463E4 = (f32)(s32)(e->b1 + e->b3) / 256.0f;
        D_004463D0 = (f32)(u32)e->b2 / 256.0f * e->fC / 100.0f;
        D_004463D4 = (f32)(u32)e->b3 / 256.0f * e->fC / 100.0f;
        if (e->w10 != 0) {
            tmp = D_004463D8;
            D_004463D8 = D_004463E0;
            D_004463E0 = tmp;
        }
        func_00153AB0(&D_004463C0, 0);
        D_004463CC += 0.0010000000474974513f;
    }
}
