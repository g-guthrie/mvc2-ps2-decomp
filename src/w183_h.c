typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00241800(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001830D0(u8 *, u32 *, s32);
    f32 *t0, *t1, *t2, *t3;
    u32 v[4];
    s16 c;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    p[0x209] = 2;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    t0 = (f32 *)(p + 0x5C);
    t2 = (f32 *)(p + 0x68);
    t1 = (f32 *)(p + 0x60);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    c = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = c;
    t3 = (f32 *)(p + 0x6C);
    if (c == 0) {
        u32 u;
        p[0x404] = 0;
        p[0x405] = 0;
        u = p[6];
        p[6] = u + 1;
        p[7] = 0;
        p[0x152] = 1;
        *t0 = 0;
        *t1 = 0;
        *t2 = 0;
        *t3 = 0;
        v[0] = 0xC1E2AAAA;
        v[1] = 0x4313DB6D;
        func_001830D0(p, v, 1);
    }
}
