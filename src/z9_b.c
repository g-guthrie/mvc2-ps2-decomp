typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00178A40(u8 *p) {
    extern void func_00185490();
    extern s32 func_00178B00();
    extern void func_00178D80(u8 *, unsigned int);
    func_00185490(p);
    if (func_00178B00(p) == 0) {
        u32 h = *(u16 *)(p + 0x354);
        if (h & 0x2000) {
            func_00178D80(p, 3); return;
        }
        if (h & 0x1000) {
            func_00178D80(p, 2); return;
        } else if (*(s8 *)(p + 0x539) != 0) {
            p[0x1E7] = 1;
        } else {
            p[0x1E7] = (*(u16 *)(p + 0x35E) & 0x400) >> 10;
            if ((*(u16 *)(p + 0x354) & 0xC00) == 0) { func_00178D80(p, 1); return; }
        }
    }
}
