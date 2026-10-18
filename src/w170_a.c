typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *D_004C26D8;

s32 func_001AF3F0(u8 *p) {
    extern void func_00175670();
    extern void func_001AF4A0();
    extern s32 func_001AFC90();
    f32 v;
    func_00175670(p);
    func_001AF4A0(p);
    if (D_004C26D8[2] == 0) {
        return func_001AFC90(p);
    }
    if (p[5] == 0) {
        if (*(s8 *)(D_004C26D8 + 0xD) != 0) {
            p[5]++;
            *(u32 *)(p + 0x118) = 0x3F800000;
        }
    } else {
        v = *(f32 *)(p + 0x118) - 0.05f;
        *(f32 *)(p + 0x118) = v;
        if (v <= 0.0f) return func_001AFC90(p);
    }
}
