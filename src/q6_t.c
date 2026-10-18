typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1FC8[];
extern f32 D_004F1FCC[];

void func_00268480(u8 *p, u8 *q) {
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_00175700();
    extern s32 func_00268A60(u8 *);
    extern void func_001E3210(u8 *, s32);
    u32 t;
    func_001266A0(p, 1, 7);
    p[0x209] = 2;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    if (func_00268A60(p) != 0) return;
    if (*(s16 *)(p + 0x140) != 0) {
        if (!(*(f32 *)(p + 0x34) <= 66.666664f + (40.0f + D_004F1FC8[0]))) return;
    } else {
        if (*(f32 *)(p + 0x34) < D_004F1FCC[0] - 40.0f - 66.666664f) return;
    }
    t = p[6];
    p[6] = t + 1;
    *(s16 *)(q + 0x1C) = 0;
    func_001E3210(p, 3);
}
