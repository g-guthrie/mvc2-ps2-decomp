typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern s8 D_004747C0[];

s32 func_003BD1D0(u8 *p) {
    u8 *a1, *a2, *a3;
    s32 v0, v1;
    a1 = *(u8 **)(p + 0x18);
    a3 = p + 0xD0;
    v1 = a1[0x2BD];
    v0 = *(s8 *)(p + 0xD7);
    a2 = a1 + 0x2B8;
    if (v1 == v0) {
        u8 *q = *(u8 **)(a1 + 0x220);
        if (*(u16 *)(q + 0x362) & 0x3C00) a3[0xA] += 2;
        if (*(u16 *)(q + 0x362) & 0x360) a3[0xA] += 2;
        if (a3[0xA] > D_004747C0[*(s8 *)(a3 + 7)]) {
            a2[5]++;
            return 1;
        }
        return 0;
    } else {
        if (v0 < v1) {
            a2[5] = v1 + 1;
            return 1;
        }
        return 0;
    }
}
