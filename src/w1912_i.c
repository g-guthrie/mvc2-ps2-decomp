typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0027FA90(u8 *p) {
    extern void func_0018F320();
    extern void func_00175700(u8 *);
    extern void func_00178E10();
    extern void func_00178E60();
    extern void func_00178F20(u8 *, u8 *);
    f32 z;
    u8 st;
    p[0x24] = *(s8 *)(*(u8 **)(p + 0x1DC) + 0x24) - 1;
    st = p[6];
    if (st == 0) {
        p[6] = st + 1;
        *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x22C);
        *(f32 *)(p + 0x60) = *(f32 *)(p + 0x230);
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0xBFBC9249;
        *(s16 *)(p + 0x1E) = 0;
    } else if (st == 1) {
        func_0018F320();
        func_00175700(p);
        if (*(s16 *)(p + 0x1C) != 0) {
            s16 v = *(s16 *)(p + 0x1C) - 1;
            *(s16 *)(p + 0x1C) = v;
            if (v == 0) func_00178E10(p);
        }
        if (*(s16 *)(p + 0x1E) == 0) {
            z = 0.0f;
            if (*(f32 *)(p + 0x60) < z && *(s16 *)(p + 0x1C) == 0) {
                *(s16 *)(p + 0x1E) = 0xFF;
                func_00178E60(p);
            }
        }
        if (*(s8 *)(p + 0x13C) == 0) {
            u32 t = p[6];
            p[6] = t + 1;
        }
    } else {
        func_00178F20(*(u8 **)(p + 0x1DC), p);
    }
}
