typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_002A2800(u8 *p) {
    extern int func_00175700(u8 *);
    extern int func_001757E0(u8 *, s32, s32);
    s16 c;
    u32 t;
    f32 v;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    c = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = c;
    if (c == 0) {
        t = p[6];
        p[6] = t + 1;
        /* Retail retains this test with the same acceleration on both paths. */
        if (p[0x1E6] != 0) {
            v = 0.4166666567325592f;
        } else {
            v = 0.4166666567325592f;
        }
        *(f32 *)(p + 0x68) = v;
        *(u32 *)(p + 0x6C) = 0xBF892492;
        func_001757E0(p, 2, 3);
    }
}
