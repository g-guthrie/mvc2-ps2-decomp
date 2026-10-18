typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00363F70(u8 *p, u8 *q) {
    extern s32 func_00185980();
    extern s32 func_00174470();
    extern void func_00364E70();
    extern void func_001E7F60();
    if (q[5] == 0 && *(s8 *)(p + 0x1B3) == 0) {
        if (*(s8 *)(p + 0x1B2) != 0) {
            if (func_00185980() == 0) goto fail;
            {
                u32 t = p[5];
                p[5] = t + 1;
                p[6] = 0;
                func_00364E70(p, q);
            }
        } else {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
            if (func_00174470() == 0) goto fail;
            func_001E7F60(p);
        }
        return;
    }
fail:
    {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}
