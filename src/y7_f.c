typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_004000D0(s32 a0) { return a0 + 0x58; }

s32 func_001044C8(s32 descriptor) { return -1; }

s32 func_001044D0(void) { return -1; }

void func_0031AE80(u8 *a, u8 *b) {
    extern s8 func_00175700();
    extern void func_0031AF50();
    extern void func_00154790();
    if (func_00175700(a) < 0) {
        func_0031AF50(a);
        return;
    }
    if (*(s8 *)(a + 0x150) != 0) {
        *(s8 *)(a + 0x150) = 0;
        *(u8 **)(b + 0x1C8) = a;
        b[0x1B5] = 0x23;
        b[0x20A] = 10;
    }
    if (*(s8 *)(a + 0x151) != 0) {
        f32 v[4];
        f32 x = -85.0f;
        *(s8 *)(a + 0x151) = 0;
        if (*(s16 *)(a + 0x140) != 0) x = -x;
        v[0] = x + *(f32 *)(a + 0x34);
        v[1] = 240.0f + *(f32 *)(a + 0x38);
        func_00154790(v, a[0x1E6], 2, 0);
    }
}
