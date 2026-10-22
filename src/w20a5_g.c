typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad0[4];
    u8 b4;
    u8 pad5[0x1C - 5];
    s16 h1C;
    u8 pad1E[0x78 - 0x1E];
    f32 f78, f7c, f80;
} P33E8E0;

void func_0033E8E0(P33E8E0 *p)
{
    extern s32 func_003D90A0(s32);
    extern f32 func_00417440(s32);
    switch (p->b4) {
    case 0:
        if (func_003D90A0(0) != 0) {
            p->b4++;
            p->h1C = -90;
        }
        break;
    case 1:
        p->f78 = 0.5f + 0.5f * func_00417440((s32)(0.5 + 65536.0 * (double)p->h1C / 360.0) & 0xFFFF);
        p->f7c = 0.5f + 0.5f * func_00417440((s32)(0.5 + 65536.0 * (double)p->h1C / 360.0) & 0xFFFF);
        p->f80 = 0.5f + 0.5f * func_00417440((s32)(0.5 + 65536.0 * (double)p->h1C / 360.0) & 0xFFFF);
        p->h1C += 2;
        if (p->h1C >= 0x10E) {
            p->b4 = 0;
            p->h1C = -90;
        }
        break;
    }
}
