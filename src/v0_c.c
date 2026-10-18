typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


void func_0015B660(u8 *p, s32 flag) {
    extern void func_0015B000(s32, u8 *, f32, s32, s32, s32);
    extern void func_0015AD80(s32, u8 *, f32, s32, s32, s32);
    extern void func_0015AA90(s32, u8 *, f32, s32, s32, s32);
    extern void func_0015A720(s32, u8 *, f32, s32, s32, s32);
    extern s8 D_004D1917;
    f32 sc;
    if (D_004D1917 < 6) {
        D_004D1917 = D_004D1917 + 1;
        if (flag != 0) sc = 1.5f;
        else sc = 1.0f;
        func_0015B000(0, p, sc, 1, 0, 0x79);
        func_0015AD80(0, p, sc, 1, 0, 0x79);
        func_0015AA90(0, p, sc, 1, 0, 0x79);
        func_0015A720(0, p, sc, 1, 0, 0x79);
    }
}
