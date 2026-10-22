typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x160]; s8 b[8]; } S2a9;

void func_002A9750(u8 *p, u8 *q)
{
    extern s32 func_0018AB10();
    extern s32 func_00175700(u8 *);
    extern void func_002A9950(u8 *, s32);
    extern void func_001E3210(u8 *, s32);
    extern void func_00394780(u8 *, s32, s32);
    s8 *a;
    s8 *r;
    s8 f;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (*q != 0) {
        if (func_0018AB10() != 0 || p[0x269] == 5 || p[0x269] == 4) {
            u32 t = *q;
            *q = t - 1;
            if ((*q & 7) == 0) {
                s32 h = *(s16 *)(p + 0x1E);
                *(s16 *)(p + 0x1E) = h + 1;
            }
        }
    }
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_002A9950(p, 1);
        return;
    }
    a = ((S2a9 *)p)->b;
    f = a[1];
    r = a + 1;
    if ((f & 1) != 0) {
        *r = f & ~1;
        func_001E3210(p, 0x1E);
        func_00394780(p, 0xB, 0);
        func_00394780(p, 0xB, 1);
        func_00394780(p, 0xB, 2);
    }
    if ((u8)*r == 0xFE) {
        if (*(s16 *)(p + 0x1E) != 0) {
            *r = -4;
            p[0x152] = 0x20;
        } else {
            *r = -6;
        }
    }
    if ((u8)*r == 0xFC) {
        s32 h = *(s16 *)(p + 0x1E) - 1;
        s16 g;
        *(s16 *)(p + 0x1E) = h;
        g = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = g;
        *(s16 *)(p + 0x1C) = g & 3;
        func_002A9950(p, 0);
    }
}
