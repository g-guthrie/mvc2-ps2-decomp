typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_0044DA30[];

void func_001CAB00(u8 *p) {
    extern s32 func_00119098(f32);
    f32 z = 0.0f;
    f32 d;
    u8 *q = p + 0xD0;
    d = *(f32 *)(*(u8 **)(p + 0x18) + 0x34) + *(f32 *)(p + 0x5C);
    d -= *(f32 *)(p + 0x34);
    if (d < z) d = -d;
    if (!(d <= 426.6666564941406f)) d = 425.0f;
    p[6] = (s8)func_00119098(d / 1.6666666269302368f / 16.0f) & 0xF;
    *(s16 *)(q + 4) = D_0044DA30[p[6]];
}
