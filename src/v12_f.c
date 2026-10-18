typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 *D_004C2840;
void func_0014D910(u8 *p) {
    extern f32 func_00417500(s32);
    f32 k;
    if (D_004C2840[4] == p[0x20]) {
        p[0x13C] = 1;
        *(s16*)(p + 0x1C) += 9;
        if (*(s16*)(p + 0x1C) >= 0x168) *(s16*)(p + 0x1C) = 0;
        k = 0.5f;
        *(f32*)(p + 0x74) = k + k * func_00417500((u16)(65536.0 * *(s16*)(p + 0x1C) / 360.0 + 0.5));
    } else {
        p[0x13C] = 0;
        *(s16*)(p + 0x1C) = 0;
    }
}

