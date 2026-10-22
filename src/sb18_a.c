typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_003B3ED0(u8 *a, u8 *b) {
    extern void func_00175700(u8 *), func_001E7F60(u8 *);
    extern int func_00174470(const void *);
    extern s32 func_003B4030(u8 *, u8 *);
    u32 t;
    a[0x24] = b[0x24] + a[0x31];
    if ((s8)a[0x24] > 7) a[0x24] = 7;
    if ((s8)a[0x24] < 0) a[0x24] = 0;
    *(f32 *)(a + 0x34) += *(f32 *)(a + 0x5C);
    *(f32 *)(a + 0x5C) += *(f32 *)(a + 0x68);
    func_00175700(a);
    if (*(s8 *)(a + 0x1B3) != 0) {
        t = a[4];
        a[4] = t + 1;
    } else {
        func_001E7F60(a);
        if (*(s8 *)(a + 0x1B2) != 0) {
            t = a[4];
            a[4] = t + 1;
        } else {
            if (func_00174470(a) == 0) return func_003B4030(a, b);
        }
    }
}
