typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0029E620(u8 *p) {
    extern u8 *func_001E7FD0(u8 *);
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_00185770(u8 *, u8 *);
    extern void func_00154790(f32 *, s32, s32, s32);
    extern void func_00179150(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0018FDB0(u8 *);
    extern void func_001E3B70(u8 *, s32);
    u8 *s0;
    u8 *q;
    f32 v[4];
    f32 f20, f21, z, t;
    f32 *a1, *v1, *a2, *a3;

    z = 0.0f;
    a2 = (f32 *)(p + 0x68);
    a3 = (f32 *)(p + 0x6C);
    p[0x40C] = 2;
    p[0x33C] = 5;
    a1 = (f32 *)(p + 0x5C);
    t = *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += t;
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v1 = (f32 *)(p + 0x60);
    if (*(f32 *)(p + 0x5C) * t < z) {
        *a1 = z;
        *v1 = z;
        *a2 = z;
        *a3 = z;
    }
    {
        s16 h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h < 0) {
            p[0x40D] = 0;
            p[0x40C] = 0;
            p[0x33B] = 0;
            p[0x33C] = 0;
            p[6] = 7;
            *(s16 *)(p + 0x1C) = 4;
            return;
        }
    }
    if ((s0 = func_001E7FD0(p)) == 0) return;
    func_001266A0(p, 0xD, 1);
    {
        u32 t6 = p[6];
        p[6] = t6 + 1;
    }
    p[0x151] = 0;
    *(s16 *)(p + 0x1E) = 0;
    p[0x20B] = 0xC3;
    s0[0x20B] = 0xC3;
    func_00185770(p, s0);
    *(u32 *)(p + 0x2F8) = 0;
    *(u32 *)(p + 0x2FC) = 0;
    p[0x1B4] = 10;
    *(u32 *)&v[0] = 0xC3055555;
    if (*(s16 *)(p + 0x140) != 0) v[0] = -v[0];
    v[0] += *(f32 *)(p + 0x34);
    v[1] = 17.142856597900391f + *(f32 *)(p + 0x38);
    func_00154790(v, p[0x1E6], 2, 0);
    f20 = *(f32 *)(p + 0x34);
    f21 = *(f32 *)(p + 0x38);
    *(s8 *)(p + 0x16A) = -1;
    p[0x160] = 0x20;
    s0 = p + 0x160;
    func_00179150(p, *(u8 **)(p + 0x1DC));
    *(f32 *)(p + 0x2B8) = *(f32 *)(p + 0x34);
    *(f32 *)(p + 0x2BC) = *(f32 *)(p + 0x38);
    *(f32 *)(p + 0x5C) = (*(f32 *)(p + 0x34) - f20) / 40.0f;
    *(u32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x60) = (*(f32 *)(p + 0x38) - f21) / 40.0f - (-16.071428298950195f);
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    *(s16 *)(p + 0x1C) = 0x28;
    func_001757E0(p, 0x16, 0x10);
    *(s8 *)(p + 0x16A) = -1;
    *s0 = 0;
    *(f32 *)(p + 0x34) = f20;
    *(f32 *)(p + 0x38) = f21;
    *(s16 *)(*(u8 **)(p + 0x1DC) + 0x1C) = 1;
    *(f32 *)(*(u8 **)(p + 0x1DC) + 0x38) = *(f32 *)(*(u8 **)(p + 0x1DC) + 0x430);
    func_001757E0(*(u8 **)(p + 0x1DC), 0xD, 9);
    q = *(u8 **)(p + 0x1DC);
    if (((*(u32 *)(q + 0x428) & 0x90001010) | (*(u32 *)(q + 0x42C) & 1)) != 0) {
        u32 t6b = q[0x1E6];
        q[0x1E6] = t6b ^ 1;
        q = *(u8 **)(p + 0x1DC);
        *(s16 *)(q + 0x140) = q[0x1E6];
    }
    *(u8 **)(*(u8 **)(p + 0x1DC) + 0x1C8) = p;
    (*(u8 **)(p + 0x1DC))[0x1B5] = 0x3D;
    func_0018FDB0(p);
    func_001E3B70(*(u8 **)(p + 0x1DC), 3);
}
