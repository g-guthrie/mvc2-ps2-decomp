typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 a, b, c, d, e, f, g; } F7;
extern f32 D_00453D60[];
extern F7 D_00453BA0[];

void func_002601B0(u8 *p)
{
    extern u8 func_001748C0(u8 *, u8 *);
    extern void func_001B0F40(u8 *, s32);
    extern s32 func_001757E0(u8 *, s32, s32);
    f32 *t;
    F7 *e;
    f32 x;
    u32 i;

    t = D_00453D60;
    if (*(s16 *)(p + 0x1E) < 4) {
        p[0x23] = func_001748C0(p + 0x34, *(u8 **)(p + 0x220) + 0x34) >> 3;
        p[0x23] = (u32)t[p[0x23]];
        e = D_00453BA0;
        i = p[0x23];
        e += i;
        p[6]++;
        *(s16 *)(p + 0x1C) = 0x1E;
        (*(s16 *)(p + 0x1E))++;
        *(f32 *)(p + 0x5C) = e->a;
        *(f32 *)(p + 0x68) = e->b;
        *(f32 *)(p + 0x60) = e->c;
        *(f32 *)(p + 0x6C) = e->d;
        p[7] = (u32)e->g;
        if (e->f >= 0.0f) {
            x = e->f;
        } else {
            x = *(s16 *)(p + 0x140);
        }
        *(s16 *)(p + 0x140) = (s32)x;
        func_001B0F40(p, 0);
        func_001B0F40(p, 1);
        *(u32 *)(p + 0x48) = 0;
        func_001757E0(p, 0x16, 1);
    }
}
