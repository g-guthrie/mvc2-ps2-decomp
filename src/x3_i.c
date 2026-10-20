typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2840;

static void func_00157250(u8 *p) {
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 60) += *(f32 *)(p + 100);
}

void func_00157470(u8 *p) {
    extern void func_003DAA40();
    f32 c = 0.10000000149011612f;
    func_00157250(p);
    *(f32 *)(p + 0x50) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x54) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x58) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x78) -= c;
    *(f32 *)(p + 0x7C) -= c;
    *(f32 *)(p + 0x80) -= c;
    if (*(s8 *)(D_004C2840 + 0x91) != 0) {
        p[0x13C] = 0;
        func_003DAA40(p);
        return;
    }
    {
        s32 v = *(s16 *)(p + 0x1C);
        if (v >= 10) {
            func_003DAA40(p);
        } else {
            *(s16 *)(p + 0x1C) = v + 1;
        }
    }
}
