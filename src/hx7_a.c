typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00229210(u8 *p)
{
    extern s8 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0019DB00(u8 *, s32, u8);
    s8 r;
    s32 v;
    s16 t;
    u32 c;
    u32 u;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    r = func_00175700(p);
    if (r < 0) {
        if (p[0x20] != 0) {
            t = *(s16 *)(p + 0x1E) - 1;
            *(s16 *)(p + 0x1E) = t;
            if (t >= 0) {
                *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
            }
            p[0x20] = 0;
            *(u16 *)(p + 0x366) = 0;
        }
        t = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = t;
        if (t <= 0) {
            u = p[6];
            p[6] = u + 1;
            func_001757E0(p, 0x15, 0x35);
        } else {
            u = p[0x21];
            p[0x21] = u ^ 1;
            c = (u8)(*(s8 *)(p + 0x21) + 0x25);
            if (*(s16 *)(p + 0x1C) == 1) {
                c = (u8)(c + 3);
            }
            func_001757E0(p, 0x15, c);
        }
    } else {
        if ((*(u16 *)(p + 0x35C) | *(u16 *)(p + 0x366)) & 0x60) {
            p[0x20] = 1;
        }
        v = *(s8 *)(p + 0x151);
        if (v != 0) {
            func_0019DB00(p, (s8)v, p[0x15B]);
            func_0019DB00(p, *(s8 *)(p + 0x151) - 1, p[0x15B]);
            p[0x151] = 0;
        }
    }
}
