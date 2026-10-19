typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern s8 *D_004C2840;
extern u8 D_004D18A6;
extern void func_00161630(u8 *);

void func_001620F0(u8 *p)
{
    s8 v;

    v = D_004C2840[0x9C];
    p[0x13C] = v;
    if (v == 0 || ((D_004C2840[0x9C] & 0xF) == 1 && D_004D18A6 != 0)) {
        p[0x13C] = 0;
        *(s16 *)(p + 0x1C) = 0;
    }
    p[0x13C] = D_004C2840[0x9C];
    func_00161630(p);
    if (*(s16 *)(p + 0x1C) != 0) {
        *(s16 *)(p + 0x1C) -= 1;
        *(f32 *)(p + 0x64) += *(f32 *)(p + 0x70);
        *(f32 *)(p + 0x3C) += *(f32 *)(p + 0x64);
    } else {
        u8 *q = *(u8 **)(p + 0x18);
        q[5] -= 1;
        p[4] += 1;
    }
}
