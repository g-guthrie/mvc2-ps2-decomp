typedef unsigned char u8; typedef signed char s8; typedef signed short s16; typedef unsigned int u32; typedef signed int s32; typedef float f32;
extern u8 *D_004C2700;
extern f32 D_004F1FC8[];
extern f32 D_004F1FCC[];
static void func_001BF4E0(u8 *a0) {
    f32 f;
    *(f32 *)(a0 + 52) = *(f32 *)(*(u8 **)(a0 + 24) + 52);
    *(f32 *)(a0 + 56) = *(f32 *)(*(u8 **)(a0 + 24) + 56);
    f = 1.6666666f * (f32)(s32)(a0[35] << 6);
    if (*(s16 *)(a0 + 320) == 0) f = -f;
    *(f32 *)(a0 + 52) += f;
    *(f32 *)(a0 + 80) = *(f32 *)(*(u8 **)(a0 + 24) + 80);
    *(f32 *)(a0 + 84) = *(f32 *)(*(u8 **)(a0 + 24) + 84);
}
static s32 func_001BF5C0(u8 *p)
{
    s32 r = 1;
    s16 h = *(s16 *)(p + 0x140);
    if ((h == 0 && *(f32 *)(p + 0x34) < D_004F1FC8[0] - 1.6666666269302368f * (f32)(u32)p[0x14F]) ||
        (h != 0 && !(*(f32 *)(p + 0x34) <= D_004F1FCC[0] + 1.6666666269302368f * (f32)(u32)p[0x14F])))
        r = 0;
    return r;
}
void func_001BF9E0(u8 *p) {
    extern void func_001754A0(u8 *, s32, u8);
    u8 a3;
    u8 v;
    if (*(*(u8 **)(p + 0x18) + 4) >= 2) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
        return;
    }
    v = p[0x23];
    if (v == 0) {
        a3 = 8;
    } else {
        s32 m = *D_004C2700;
        if (m < v) {
            p[0x13C] = 0;
            return;
        }
        if (v == m) a3 = 10; else a3 = 9;
    }
    p[0x13C] = func_001BF5C0(p);
    if (*(s8 *)(p + 0x13C) != 0) {
        func_001754A0(p, 0x1B, a3);
    }
    func_001BF4E0(p);
}
