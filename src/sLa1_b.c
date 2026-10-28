#pragma opt_lifetimes off
#pragma opt_propagation off
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00376FC0(u8 *p, u8 *r) {
    extern s32 func_003777B0(u8 *);
    extern s32 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_00185980(u8 *);
    extern void func_00185870(u8 *, u8 *);
    extern void func_001E3210(u8 *, s32);
    extern void func_001E7F60(u8 *);
    u8 *s0;
    f32 sx;
    f32 a;
    f32 d;
    f32 z;
    s32 t;
    u32 u;
    if (func_003777B0(p) == 0) {
        s8 rr = func_00175700(p);
        if (rr < 0) {
            p[4] = 2;
            p[5] = 2;
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
            func_001757E0(p, 0x17, 0xC);
        } else {
        if (*(s8 *)(p + 0x151) != 0) {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        }
        t = *(s8 *)(p + 0x1B2);
        if (t != 0) {
            if ((s8)t & 1) {
                p[4] = 2;
                p[5] = 1;
                *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C) / 2.0f;
                *(u32 *)(p + 0x60) = 0x40892492;
                func_001757E0(p, 0x17, 0xD);
            } else if (func_00185980(p) != 0) {
                s0 = *(u8 **)(p + 0x1C4);
                if (s0[0x20D] == 2) {
                    p[4] = 2;
                    p[5] = 1;
                    *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C) / 2.0f;
                    *(u32 *)(p + 0x60) = 0x40892492;
                    func_001757E0(p, 0x17, 0xD);
                } else {
                    u = p[5];
                    p[5] = u + 1;
                    p[6] = 0;
                    *(s16 *)(p + 0x1C) = 0x1E;
                    func_001E3210(p, 0x30);
                    d = *(f32 *)(p + 0x34);
                    sx = *(f32 *)(s0 + 0x34);
                    z = 0.0f;
                    d = d - sx;
                    if (d < z) d = -d;
                    z = 26.666666030883789f;
                    if (!(d <= z)) {
                        a = z + sx;
                        if (*(s16 *)(p + 0x140) != 0) {
                            *(f32 *)(p + 0x34) = -26.666666030883789f + sx;
                        } else {
                            *(f32 *)(p + 0x34) = a;
                        }
                    }
                    func_001757E0(p, 0xF, 1);
                    r[0x20B] = 0xC1;
                    func_00185870(p, s0);
                    *(f32 *)(p + 0x64) = *(f32 *)(p + 0x34) - *(f32 *)(s0 + 0x34);
                    if (*(u8 *)(*(u8 **)(p + 0x1E0) + 1) != 0x3A) {
                        *(f32 *)(p + 0x60) = *(f32 *)(p + 0x38) - *(f32 *)(s0 + 0x38);
                    } else {
                        *(u32 *)(p + 0x60) = 0;
                    }
                }
            } else {
                p[4] = 2;
                p[5] = 1;
                func_001757E0(p, 0x17, 0xD);
            }
        } else {
            func_001E7F60(p);
        }
        }
    }
}
