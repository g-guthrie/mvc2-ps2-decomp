typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C2840; void func_001A17C0(u8 *a0, u8 *a1, s32 a2) {
 u8 *a3;
 s32 t0;
 s32 t1;
    t1 = *(s16*)(a0 + 0x1E);
    a3 = a1 + 0x2B8;
    for (t0 = 0; t0 < t1; t0++, a0 = *(u8**)(a0 + 0xC)) {
        if (a2 == 0) {
            if (*(s8*)(a0 + 0x13C) == 0) break;
        } else if (a2 == 1) {
            *(s8*)(a0 + 0x13C) = *(s8*)(D_004C2840 + 0x1C) & 1;
        } else {
            *(s8*)(a0 + 0x13C) = 0;
        }
    }
    if (a2 == 0) {
        if (t0 < t1) {
            *(s8*)(a0 + 0x13C) = 1;
        } else {
            a3[5] = 1;
        }
    }
}
