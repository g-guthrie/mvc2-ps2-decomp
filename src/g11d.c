typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* func_0035AE70 (src/grok_r1_0030.c) takes (u8 *, s32); its second argument is unused. */
extern void func_0035AE70(u8 *, s32);
void func_00358FD0(u8 *a, s32 b) {
    u8 *s = *(u8 **)(a + 0x18);
    if (s[5] != 0) {
        func_0035AE70(a, b);
    }
    if (s[0x1E4] != 0x15) {
        func_0035AE70(a, b);
    }
    if (s[0x1FD] != 3 && s[0x1FD] != 8) {
        func_0035AE70(a, b);
    }
}

extern s32 func_001688C0(u8 *, u8 *);
s32 func_0016B360(u8 *a, u8 *b) {
    s32 v = *(s8 *)(a + 0x4A9);
    s8 w;
    if (v == 0) {
        return 1;
    }
    w = v;
    if (w > 0) {
        a[0x4A9] = 0;
        func_001688C0(a, b);
        return 0;
    }
    if (!(w & 2)) {
        a[0x4A9] = v & 0x11;
        return 1;
    }
    if (w & 0x10) {
        a[0x4A9] = 0;
        func_001688C0(a, b);
        return 0;
    }
    a[0x4A9] = v & 0x7F;
    return 1;
}
