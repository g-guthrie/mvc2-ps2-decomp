typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s8 *D_004C299C;

static void func_0037F440(u8 *p) {
    s16 t = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = t;
    if (t <= 0) {
        *(s16 *)(p + 0x1C) = 1;
        *D_004C299C -= 1;
    }
}

void func_0037F8A0(u8 *p) {
    D_004C299C[7] = 0;
    func_0037F440(p);
    if (*D_004C299C < 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[316] = 0;
    }
}
