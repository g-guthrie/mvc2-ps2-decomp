typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_00448B30[];

void func_0017B800(u8 *a) {
    extern void func_001843A0(u8 *);
    u8 *o = *(u8 **)(a + 0x1CC);
    s16 h;
    f32 z = 0.0f;
    f32 v;
    s16 k;
    if (o == 0) o = *(u8 **)(a + 0x220);
    h = *(s16 *)(a + 0x1C);
    v = 1.6666666269302368f * (f32)D_00448B30[h] / 256.0f;
    if (z == v) {
        func_001843A0(a);
        return;
    }
    *(s16 *)(a + 0x1C) = h + 1;
    k = *(s16 *)(o + 0x140);
    if (k != 0) v = -v;
    if ((*(s8 *)(o + 0x211) & (1 << (s16)k)) == 0) {
        *(f32 *)(o + 0x34) += v;
    }
}
