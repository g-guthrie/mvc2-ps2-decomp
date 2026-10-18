typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_0044C350[], D_0044C351[];

void func_001BE2A0(u8 *p) {
    extern u8 *func_001BC660(u8 *, s32);
    u8 *q;
    u8 *o;
    s16 h;
    u32 t;
    f32 f, k = 0.20000000298023224f;
    q = *(u8 **)(p + 0x18);
    f = *(f32 *)(p + 0x118) + k;
    *(f32 *)(p + 0x118) = f;
    if (!(f < 1.0f)) *(f32 *)(p + 0x118) = 1.0f;
    *(f32 *)(p + 0x34) += (*(f32 *)(q + 0x34) - *(f32 *)(p + 0x34)) / 2.0f;
    *(f32 *)(p + 0x38) += (*(f32 *)(q + 0x38) - *(f32 *)(p + 0x38)) / 2.0f;
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h == 0) {
        t = p[5];
        p[5] = t + 1;
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
        o = func_001BC660(q, 0xE);
        if (o != 0) *(u8 **)(o + 0x14) = p;
        if (D_0044C350[p[0x20] * 2] != 0) {
            o = func_001BC660(q, D_0044C350[p[0x20] * 2]);
            if (o != 0) {
                *(u8 **)(o + 0x14) = p;
                o[0x23] = D_0044C351[p[0x20] * 2];
            }
        }
    }
}
