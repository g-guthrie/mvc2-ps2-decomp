typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_004C27A4[2];
void func_001A01C0();
void func_001A4C30();

s32 func_001A00E0(s32 a, s32 n, s32 b, s32 c) {
    extern u8 *func_003DA750();
    s32 i;
    u8 *o;
    if (D_004C27A4[0] <= n) return 0;
    if (n > 12) n = 12;
    for (i = 0; i < n; i++) {
        if ((o = func_003DA750(0, 3, 1)) != 0) {
            *(s16 *)(o + 0x26) = 0xC02;
            o[0x23] = i;
            o[0x20] = b;
            o[0x21] = c;
            *(s16 *)(o + 0x1E) = n;
            *(void **)(o + 0x10) = func_001A01C0;
            *(s32 *)(o + 0x18) = a;
        }
        if (c != 0) c--;
    }
    return i;
}

s32 func_001A4B50(s32 a, s32 n, s32 b, s32 c) {
    extern u8 *func_003DA750();
    s32 i;
    u8 *o;
    if (D_004C27A4[0] <= n) return 0;
    if (n > 12) n = 12;
    for (i = 0; i < n; i++) {
        if ((o = func_003DA750(0, 3, 1)) != 0) {
            *(s16 *)(o + 0x26) = 0xE03;
            o[0x23] = i;
            o[0x20] = b;
            o[0x21] = c;
            *(s16 *)(o + 0x1E) = n;
            *(void **)(o + 0x10) = func_001A4C30;
            *(s32 *)(o + 0x18) = a;
        }
        if (c != 0) c--;
    }
    return i;
}
