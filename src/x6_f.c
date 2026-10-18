typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C283C;
s32 func_00334E20(u8 *p) {
    f32 z = 0.0f;
    if (*(s16 *)(p + 0x1E) > 7) {
        u32 t;
        *(s16 *)(p + 0x1C) = 0;
        *(s16 *)(p + 0x1E) = 0;
        t = p[7];
        p[7] = t + 1;
        if (p[7] > 0x13) {
            p[6] = 0;
            return 1;
        }
    }
    if (*(s16 *)(p + 0x1C) == 0) {
        s16 v = *(s16 *)(p + 0x1E) + 0x1B;
        if (v > 0x22) {
            v = 0x22;
        }
        *(s16 *)(p + 0xCC) = v;
        *(s32 *)(p + 0x84) = D_004C283C;
    }
    {
        s16 c = *(s16 *)(p + 0x1C);
        *(s16 *)(p + 0x1C) = c + 1;
        *(f32 *)(p + 0x74) -= 0.006250000093132257f;
        if (*(f32 *)(p + 0x74) < z) {
            *(f32 *)(p + 0x74) = z;
        }
    }
    {
        s32 r = 0;
        if (*(s16 *)(p + 0x1C) > 0) {
            *(s16 *)(p + 0x1C) = 0;
            *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 1;
        }
        return r;
    }
}
