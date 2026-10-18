typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_003BA500(u8 *p) {
    extern void func_003BD4A0();
    extern void func_003BD410();
    extern void (*D_004C2060[2])();
    s32 a1 = *(s8 *)(p + 0x1B2);
    if (a1 != 0) {
        u8 *c = *(u8 **)(p + 0x1C4);
        if (c[3] == 0) {
            if (c[0x425] != 0 || (c[1] >= 0x18 && c[1] < 0x1B)) {
                func_003BD4A0(p);
            } else if (((s8)a1 & 0x7F) != 0) {
                func_003BD4A0(p);
            } else {
                func_003BD410(p);
            }
        } else {
            func_003BD4A0(p);
        }
    } else {
        D_004C2060[p[6]](p);
    }
}
