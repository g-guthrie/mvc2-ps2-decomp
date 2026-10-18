typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern s32 func_00188860();
extern s32 func_0018AC30();
s32 func_00188ED0(u8 *p) {
    if (*(s8 *)(p + 0x539) != 0) {
        if (p[0x471] != 0) {
            if (*(s8 *)(p + 0x45C) == 0x7B) {
                if (func_00188860(p, (u8)((u8)func_0018AC30() + 2))) return 1;
            }
        }
    } else {
        if (func_00188860(p, 3)) return 1;
        if (func_00188860(p, 4)) return 1;
    }
    return 0;
}
