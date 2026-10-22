typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0025AA70(u8 *p)
{
    extern void func_002555E0();
    extern void func_001548D0(u8 *, f32 *, s32);
    extern void func_001E3710(u8 *, s32);
    extern void func_0018FC10(u8 *, s32);
    extern void func_00191480(u8 *, u8 *, s32);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_00175700();
    f32 v[4];
    u8 *s0;
    s32 t;
    f32 f;
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    func_002555E0(p);
    s0 = *(u8 **)(p + 0x1DC);
    if (*(s16 *)(p + 0x1C) == 10) {
        *(u32 *)&v[0] = 0;
        *(u32 *)&v[1] = 0x432B6DB6;
        func_001548D0(s0, v, 10);
        func_001E3710(p, 6);
        func_0018FC10(s0, -1);
        func_00191480(s0, p, 1);
    }
    if (*(s16 *)(p + 0x1C) == 5) {
        *(u32 *)&v[0] = 0;
        *(u32 *)&v[1] = 0x432B6DB6;
        func_001548D0(s0, v, 16);
        func_001E3710(p, 6);
        func_0018FC10(s0, -1);
        func_00191480(s0, p, 1);
    }
    t = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = t - 1;
    if (t == 0) {
        u32 u = p[6];
        p[6] = u + 1;
        func_001266A0(p, 0, 0xD);
        if (p[0x1E6] != 0) f = -20.0f; else f = 20.0f;
        *(f32 *)(p + 0x5C) = f;
        if (p[0x1E6] != 0) f = 0.8333333134651184f; else f = -0.8333333134651184f;
        *(f32 *)(p + 0x68) = f;
        func_001266A0(p, 0, 0);
        p[0x151] = 0;
        *(u8 **)(s0 + 0x1C8) = p;
        s0[0x20A] = 1;
        s0[0x1B5] = 0x24;
    }
    func_00175700(p);
}

typedef struct { u8 pad[0x7C]; s16 s7C[8]; } H8G;
extern H8G *D_004C2794;

void func_00241C40(u8 *p, u8 *q)
{
    extern void func_00175700();
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001A3A10(u8 *, s32, s32);
    u32 t;
    f32 c;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (p[0x15B] != 0) {
        if (*(s8 *)(p + 0x1B2) != 0) {
            p[0x1B5] = p[0x15B];
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            D_004C2794->s7C[p[2]]++;
            *(u16 *)(p + 0x1C0) |= 0x10;
            p[0x15B] = 0;
        } else {
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
            t = p[6];
            p[6] = t + 1;
            p[7] = 1;
            q[3] = 0;
            func_001266A0(p, 0, 0xD);
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x68) = 0;
            *(volatile u32 *)(p + 0x6C) = 0;
            *(u32 *)(p + 0x6C) = 0xBF700000;
            func_001757E0(p, 0x16, 6);
        }
    }
    if (*(s8 *)(p + 0x151) != 0) {
        t = p[7];
        p[7] = t + 1;
        func_001266A0(p, 0, 0xD);
        *(u32 *)(p + 0x5C) = 0xC1200000;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x40892492;
        *(u32 *)(p + 0x6C) = 0xBF700000;
        if (p[0x1E6] != 0) *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        c = 53.33333206176758f;
        if (p[0x1E6] != 0) c = -c;
        *(f32 *)(p + 0x34) += c;
        func_001A3A10(p, 0, 0);
    }
}
