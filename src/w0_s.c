typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

s32 func_003F7FC8(u8 *a, u16 *b, s32 c) {
    extern s32 func_003F7D98(u8 *, u8 *, s32);
    extern s32 func_003F8D68(void *);
    extern s32 func_003F8AF8(u8 *, u8 *, s32);
    extern s32 func_003F9568(char *);
    extern s32 func_003F8FB8(u8 *, u8 *, s32);
    extern s32 func_003F68A0();
    extern s32 func_003F6A18(u8 *, u8 *, s32);
    extern s32 func_003F7188();
    extern s32 func_003F72F0();
    s32 recognized;
    u16 h = *b;
    if ((u16)((h << 8) | (h >> 8)) == 0x8000) return func_003F7D98(a, (u8 *)b, c);
    if (func_003F8D68(b)) return func_003F8AF8(a, (u8 *)b, c);
    if (func_003F9568((char *)b)) return func_003F8FB8(a, (u8 *)b, c);
    if (func_003F68A0(b)) return func_003F6A18(a, (u8 *)b, c);
    recognized = func_003F7188(b);
    if (recognized) return func_003F72F0(a, b, c);
    return recognized;
}
