typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003C00E0(u8 *p) {
    extern s32 func_00185980(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_001E7F60(u8 *);
    if (*(s8 *)(p + 0x1B2) != 0) {
        if (func_00185980(p) != 0) {
            u32 t = p[5];
            p[5] = t + 1;
            p[0x24] = 8;
            func_001757E0(p, 0x16, 0x15);
        } else {
            goto L;
        }
    } else {
        s16 v = *(s16 *)(p + 0x1E) - 1;
        *(s16 *)(p + 0x1E) = v;
        if (v == 0) {
L:
            p[5] = 3;
            *(s16 *)(p + 0x1E) = 0;
        } else {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
            func_001E7F60(p);
        }
    }
}
