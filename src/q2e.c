/* MWCCPS2 3.0 (011126): ./try30.sh src/q2e.c */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_003F2EB0();
extern s32 func_003F2BF0();
extern s32 func_003F3190();
s32 func_003F2B70(s32 a0, s32 *a1) {
    switch (*a1 & 0xFFC3FF00) {
    case 0xDF00: return func_003F2EB0(a0, a1); case 0x9F00: return func_003F2BF0(a0, a1); case 0x3DF00: return func_003F3190(a0, a1);
    }
    return 0;
}
