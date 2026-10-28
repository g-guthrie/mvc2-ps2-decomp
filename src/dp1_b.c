/* func_00141130: MW 3.0.3 -O3 -Op -fp off -sdatathreshold 8, warmed by src/xl9_b.c (MWWARM) */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct {
    u8 _p0[4];
    u8 b4;
    u8 _p1[0x17];
    s16 h1c;
    u8 _p2[0x5A];
    f32 f78;
    f32 f7c;
    f32 f80;
} OB;

extern f32 func_00417440(u32);

void func_00141130(OB *p)
{
    f32 f;
    switch (p->b4) {
    case 0:
        f = p->f78;
        f += 0.01f;
        if (!(f < 0.75f)) {
            f = 0.75f;
            p->b4++;
        }
        p->f78 = f;
        p->f7c = f;
        p->f80 = f;
        break;
    case 1:
        f = 0.75f + 0.25f * func_00417440((s32)(0.5 + 65536.0 * (double)p->h1c / 360.0) & 0xFFFF);
        p->f78 = f;
        p->f7c = f;
        p->f80 = f;
        p->h1c += 5;
        if (p->h1c >= 360) p->h1c = 0;
        break;
    }
}
