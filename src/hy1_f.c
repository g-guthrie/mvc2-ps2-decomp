typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_0045DA60[];

void func_0031FFE0(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001830D0(u8 *, f32 *, s32);
    f32 v[4];
    s32 t;
    u32 u;
    s32 *q;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    t = *(s8 *)(p + 0x151);
    if (t & 2) {
        u = p[6];
        p[6] = u + 1;
        p[7] = 0;
        *(s8 *)(p + 0x151) ^= 2;
        *(s16 *)(p + 0x1C) = 8;
        *(s16 *)(p + 0x1E) = 0;
        q = D_0045DA60;
        if (p[0x20D] == 2) q += 2;
        *(f32 *)(p + 0x5C) = 1.6666666269302368f * (f32)q[0] / 65536.0f;
        *(f32 *)(p + 0x60) = 2.142857074737549f * (f32)q[1] / 65536.0f;
        if (p[0x1E6] != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
        p[0x20D] = 2;
    } else if (t & 1) {
        p[0x404] = 0;
        p[0x405] = 0;
        *(s8 *)(p + 0x151) ^= 1;
        if (p[0x20D] == 2) {
            v[0] = -26.66666603088379f;
            v[1] = 171.42855834960938f;
        } else {
            v[0] = -120.0f;
            v[1] = 111.4285659790039f;
        }
        func_001830D0(p, v, 1);
    }
}
