typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
static s32 *func_003F1F90(s32 *a, s32 b) { s32 w = a[0]; s32 x = a[1]; s32 y = a[2]; s32 z = a[3]; if (w == x) return 0; return (s32 *)(w+x+y+z+b); }
s32 func_003F2060(void *a, s32 i) {
    s32 p = (s32)func_003F1F90(a, 0x400);
    if (p == 0) return -1;
    return *(s32 *)(p + 0xC + (i << 2));
}
