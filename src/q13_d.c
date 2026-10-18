typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern double func_00119058(f32 x);
typedef struct { u8 p0[5]; u8 b5; u8 b6; u8 p7[0x15]; s16 h1c; u8 p1e[0x22]; s32 w40; u8 p44[0xC]; f32 f50; u8 p54[0x80]; s32 wd4; } S_00332EC0;

void func_00332EC0(S_00332EC0 *p) {
    p->h1c = p->h1c + 1;
    p->w40 += (u16)(65536.0 * func_00119058(p->f50) / 360.0 + 0.5);
    if (p->h1c > p->wd4) {
        p->h1c = 0;
        p->b5 = 1;
        { u32 t = p->b6;
        p->b6 = t + 1; }
    }
}
