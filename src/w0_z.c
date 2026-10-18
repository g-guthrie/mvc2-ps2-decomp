typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct { s8 a; s8 b; } C2;
extern C2 D_004895D8;
extern C2 D_004BE128;
void func_0040CAA0(s8 *p) {
    extern void func_0011FE88();
    if (p == 0) {
        D_004895D8.a = 0;
    } else {
        if (*p != 0x2F && *p != 0x5C) {
            D_004895D8 = D_004BE128;
        } else {
            D_004895D8.a = 0;
        }
        func_0011FE88(&D_004895D8, p);
        __asm__ volatile("");
    }
}
