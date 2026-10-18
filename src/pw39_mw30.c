typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern s32 func_001041F0(s32);
extern void func_00104260(void);
s32 func_0010C060(void) {
    if (func_001041F0(4) & 0x40000) {
        func_00104260();
        return 1;
    }
    return 0;
}
