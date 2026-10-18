typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 D_004BFA4C[4];

void func_001CA8F0(u8 *p) {
    extern void func_001CAC90();
    extern s32 func_00174170();
    extern void func_001CAB00();
    extern void func_001CAD80();
    extern void func_001CABF0();
    u8 *q = *(u8 **)(p + 0x18);
    f32 z = 0.0f;
    f32 d;
    s16 t;
    *(s16 *)(p + 0x1E) = 2;
    func_001CAC90();
    p[0x22] = (*(s8 *)(p + 0x22) + D_004BFA4C[func_00174170() & 3]) & 0x1F;
    t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t < 0) p[5] = 2;
    d = 6.666666507720947f + (*(f32 *)(q + 0x34) + *(f32 *)(p + 0x5C) - *(f32 *)(p + 0x34));
    if (d < z) d = -d;
    if (d < 13.333333015441895f) p[5] = 2;
    func_001CAB00(p);
    func_001CAD80(p);
    func_001CABF0(p);
}
