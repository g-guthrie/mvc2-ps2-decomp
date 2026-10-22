typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad[0x7C];
    s16 f7c[0x100];
} HX1B_G;

extern HX1B_G *D_004C2794;

void func_0026D0D0(u8 *p)
{
    u8 *s0 = p + 0x2B8;
    u8 *s1;
    u8 *s2;
    s32 v;

    if (p[0x20D] == 2) {
        p[0x209] = 3;
    }
    {
        s32 t = *(s8 *)(p + 0x1B2);
        if (t != 0 && !((s8)t & 0x80)) {
            s0[2]++;
        }
    }
    s1 = p + 0x5C;
    s2 = p + 0x68;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    {
        extern void func_00175700(u8 *);
        func_00175700(p);
    }
    if (p[0x15B] != 0) {
        u32 b = p[0x15B];
        if ((s32)b < 0x80) {
            p[0x1B5] = b + 0x33;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(s32 *)(p + 0x1D8) = 0;
            D_004C2794->f7c[p[2]]++;
            p[0x15B] = 0;
        }
    }
    *(s16 *)(p + 0x1C) -= 1;
    v = *(s16 *)(p + 0x1C);
    if (v > 0 && *(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) <= 0.0f) {
        return;
    }
    p[6]++;
    if (p[0x20D] == 2) {
        p[0x209] = 0;
    }
    {
        extern void func_001757E0(u8 *, s32, u8);
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + 8));
    }
    *(s32 *)s1 = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)s2 = 0;
    *(s32 *)(p + 0x6C) = 0;
    s0[3] = 1;
}
