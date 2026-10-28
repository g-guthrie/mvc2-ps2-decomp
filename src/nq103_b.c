typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_003156E0(u8 *p) {
    extern void func_00175700(u8 *);
    extern s32 func_00182E20(u8 *);
    extern s32 func_00182D30(u8 *);
    extern void func_001549B0(u8 *, u32 *);
    extern void func_001E3B70(u8 *, s32);
    extern void func_0018FDB0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q;
    u32 v[4];
    s16 t;
    u32 b;
    q = *(u8 **)(p + 0x1DC);
    func_00175700(p);
    if (func_00182E20(p)) p[0x152] = 1;
    if (func_00182D30(*(u8 **)(p + 0x1DC))) *(s16 *)(p + 0x1C) = 0;
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        v[0] = 0xC22D5555;
        v[1] = 0x41DEDB6D;
        func_001549B0(p, v);
        func_001E3B70(q, 2);
        *(u8 **)(q + 0x1C8) = p;
        p[0x1B5] = q[0x1B5] = 0x20;
        q[0x1E6] = p[0x1E6];
        q[0x1E6] ^= 1;
        func_0018FDB0(p);
        p[0x1B4] = 8;
    }
    t = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = t - 1;
    if (t == 0) {
        *(u8 **)(q + 0x1C8) = p;
        p[0x1B5] = q[0x1B5] = 0x20;
        q[0x20A] = 3;
        *(u32 *)(p + 0x5C) = 0x40FD5555;
        *(u32 *)(p + 0x68) = 0xBD555555;
        *(u32 *)(p + 0x60) = 0x413C9249;
        *(u32 *)(p + 0x6C) = 0xBF22DB6D;
switch (*(s16 *)(p + 0x140)) { case 0: break; default: *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68); break; }func_001757E0(p, 15, 1);
        b = p[6];
        p[6] = b + 1;
    }
}
