typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s16 x, y; } P2;
extern P2 D_00464580[];
extern P2 D_00464582[];

void func_00381550(u8 *a) {
    u8 *o;
    *(f32 *)(a + 0x34) = *(f32 *)(*(u8 **)(a + 0x18) + 0x34);
    *(f32 *)(a + 0x38) = *(f32 *)(*(u8 **)(a + 0x18) + 0x38);
    o = *(u8 **)(a + 0x18);
    if (*(s16 *)(o + 0x140) == 0) {
        *(f32 *)(a + 0x34) += 1.66666663f * (f32)D_00464580[*(s8 *)(o + 0x150)].x;
    } else {
        *(f32 *)(a + 0x34) -= 1.66666663f * (f32)D_00464580[*(s8 *)(o + 0x150)].x;
    }
    *(f32 *)(a + 0x38) += 2.14285707f * (f32)D_00464582[*(s8 *)(*(u8 **)(a + 0x18) + 0x150)].x;
}

void func_0018F000(u8 *a, s32 b) {
    extern void func_0018F1A0();
    u8 *o = *(u8 **)(a + 0x1DC);
    f32 v[2];
    f32 z = 0.0f;
    f32 lim, t;
    func_0018F1A0(a[0x242], b, v);
    if (o[0x1E6] != 0) v[0] = -v[0];
    t = v[0] + *(f32 *)(o + 0x5C);
    v[0] = t;
    if (t > z) lim = 31.666666f;
    else lim = -31.666666f;
    if (t > z) {
        if (t > lim) v[0] = lim;
    } else {
        if (t < lim) v[0] = lim;
    }
    *(f32 *)(a + 0x22C) = v[0];
    *(s32 *)(a + 0x68) = 0;
    if (o[0x210] != 0) {
        *(f32 *)(a + 0x230) = v[1] + *(f32 *)(o + 0x60) / 2.0f;
    } else {
        *(f32 *)(a + 0x230) = v[1] + *(f32 *)(o + 0x60);
    }
    *(u32 *)(a + 0x6C) = 0xBF4DB6DB;
}
