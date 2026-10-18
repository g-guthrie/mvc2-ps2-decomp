typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* EE GCC 2.96: ./tryee.sh src/w190_a.c sn */

extern u8 D_004BD430[], D_004BD458[], D_004BD480[];
extern void func_00405DC8(u8 *);
extern u8 *func_00406128(s32);
extern void func_0011D8F8(s32 *, s32, s32);
void func_004079F8(s32 a, s32 b) {
    s32 buf[5];
    u8 *o;
    if (a == 0) {
        func_00405DC8(D_004BD430);
        return;
    }
    if (b == 0) {
        func_00405DC8(D_004BD458);
        return;
    }
    o = func_00406128(a);
    if (o == 0) {
        func_00405DC8(D_004BD480);
        return;
    }
    func_0011D8F8(buf, 0, 20);
    buf[1] = b;
    if (*(void **)(o + 0x60) != 0)
        ((void (*)(s32 *, s32, s32, s32))*(void **)(o + 0x60))(buf, 6, 0, 0);
}
