typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 f7c[2]; } G36;
extern G36 *D_004C2794;

void func_0036EC40(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_00190660(u8 *, s32, s32);
    extern void func_0015F4B0(u8 *, s32);
    extern void func_001E3710(u8 *, s32);
    extern void func_00131AB0(u8 *, u8 *, s32);
    extern void func_001E7F60(u8 *);
    u8 *q;
    u8 *r;
    s32 v;
    s16 h;
    s32 t;

    q = *(u8 **)(p + 0x18);
    func_00175700(p);
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    v = (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) ? 0x70 : -0x70;
    *(f32 *)(p + 0x34) += (f32)v;
    if (*(s8 *)(p + 0x1B2) != 0) {
        if (((q = r = *(u8 **)(p + 0x1C4)))[0x425] == 0) {
            func_00190660(r, 0x12C, 0x28);
            func_0015F4B0(*(u8 **)(p + 0x1C4), 0);
            func_001E3710(p, 0x2A);
            t = p[4];
            p[4] = t + 1;
            p[0x13C] = 0;
            func_00131AB0(*(u8 **)(p + 0x1C4), q + 0x3FA, 0);
            return;
        }
        p[0x1B5] = 0x32;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        p[2] ^= 1;
        *(s8 *)(p + 0x1B0) = 0x66;
        p[0x1B1] = 6;
    }
    func_001E7F60(p);
    h = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = h - 1;
    if (h == 0) {
        t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}
