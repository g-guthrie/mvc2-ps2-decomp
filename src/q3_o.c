typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_001AA340(u8 *p, u8 *q) {
    extern void func_001757E0();
    extern void func_00175700();
    s16 h;
    if (q[0x1E4] != 0x1D || q[0x1FD] != 5) {
        *(u32 *)(p + 0xD0) = p[6];
        *(u32 *)(p + 0xD4) = p[7];
        p[6] = 0x10;
        p[7] = 0;
    } else {
        *(f32 *)(p + 0x34) += (*(f32 *)(p + 0x64) - *(f32 *)(p + 0x34)) / (f32)*(s16 *)(p + 0x1C);
        *(f32 *)(p + 0x38) += (*(f32 *)(p + 0x70) - *(f32 *)(p + 0x38)) / (f32)*(s16 *)(p + 0x1C);
        h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h == 0) {
            u32 t = p[7];
            p[7] = t + 1;
            *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140) ^ 1;
            func_001757E0(p, 0x17, 0x40);
        }
        func_00175700(p);
    }
}
