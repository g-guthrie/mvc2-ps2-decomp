typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00175700(u8 *);
extern void func_003CE3D0(u8 *, u8 *);
extern void func_003CE2D0(u8 *, u8 *);
extern u8 *D_004C2840;

void func_003CE160(u8 *p, u8 *q)
{
    u8 *o;
    s16 t;
    o = *(u8 **)(p + 0x14);
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(o + 0x430)) {
        if (p[5] == 0) {
            p[5] = p[5] + 1;
            *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x5C) / 4.0f;
            *(f32 *)(p + 0x60) = -*(f32 *)(p + 0x60) / 2.0f;
        } else {
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x6C) = 0;
        }
        *(f32 *)(p + 0x38) = *(f32 *)(o + 0x430);
        p[0x23] = 1;
    }
    if (*(s16 *)(p + 0x1C) < 0x3D) {
        p[0x13C] = 0;
        if (((p[0x21] + *(s32 *)(D_004C2840 + 0x1C)) & 1) != 0)
            p[0x13C] = 1;
    }
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t <= 0) {
        *(u32 *)(p + 0x118) = 0;
        func_003CE3D0(p, q);
    } else {
        func_003CE2D0(p, q);
    }
}
