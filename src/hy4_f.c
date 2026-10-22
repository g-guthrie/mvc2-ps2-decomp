typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2794 __attribute__((section(".sdata")));

void func_0039B210(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    u32 counterOffset;
    s16 h;
    u32 t;
    f32 v, w;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        p[0x1B5] = 0x3F;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        counterOffset = p[2] * 2;
        counterOffset += (u32)D_004C2794;
        counterOffset += 0x7C;
        ++*(s16 *)counterOffset;
        *(s16 *)(p + 0x1E) = 2;
    }
    h = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = h;
    if (h == 0) {
        if (*(s8 *)(p + 0x1B2) != 0) {
            p[0x1B5] = 0x3F;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            counterOffset = p[2] * 2;
            counterOffset += (u32)D_004C2794;
            counterOffset += 0x7C;
            ++*(s16 *)counterOffset;
        }
    }
    if (*(f32 *)(p + 0x38) <= *(f32 *)(*(u8 **)(p + 0x18) + 0x430)) {
        t = p[5];
        p[5] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x430);
        p[0x1B5] = 0x3F;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        counterOffset = p[2] * 2;
        counterOffset += (u32)D_004C2794;
        counterOffset += 0x7C;
        ++*(s16 *)counterOffset;
        if (*(s16 *)(p + 0x140) != 0) {
            v = 21.666666030883789f;
        } else {
            v = -21.666666030883789f;
        }
        *(f32 *)(p + 0x5C) = v;
        if (*(s16 *)(p + 0x140) != 0) {
            w = -0.3125f;
        } else {
            w = 0.3125f;
        }
        *(f32 *)(p + 0x68) = w;
        *(u32 *)(p + 0x60) = 0x40CDB6DB;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x15, 0x13);
    }
    func_001E7F60(p);
}
