typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_003FFFC0(u8 *p) {
    extern void func_003F81A0();
    func_003F81A0(*(s32 *)(p + 4));
}
