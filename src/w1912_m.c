typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_00236B90(u8 *a, u8 *b) {
    extern s32 func_00175700();
    extern void func_001266A0(u8 *, s32, s32);
    extern void func_001A0B20(u8 *, s32);
    extern void func_0018FCA0(u8 *, s32);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *c;
    s32 n;
    s32 m;
    a[0x1FE] = 1;
    a[0x206] = 3;
    c = *(u8 **)(a + 0x1DC);
    c[0x208] = 2;
    if ((s8)func_00175700(a) < 0) {
        u32 t;
        *(u8 **)(c + 0x1C8) = a;
        c[0x20A] = 1;
        c[0x1E6] = a[0x1E6];
        c[0x20D] = 2;
        c[0x1B5] = 0x23;
        c[6] = 0;
        c[0x211] = 0;
        a[0x22] = 7;
        if (a[0x1E6] != 0) a[0x22] = 0x20 - *(s8 *)(a + 0x22);
        func_001266A0(a, 0, 0);
        func_001A0B20(a, 3);
        func_0018FCA0(c, *(s16 *)(b + 0xC));
        t = a[6];
        a[6] = t + 1;
        a[7] = 0;
        a[0x206] = 1;
        func_001757E0(a, 0x15, 0x18);
        return;
    }
    m = *(s16 *)(b + 0xA) >> 1;
    if (m < 0) {
        *(s16 *)(b + 0xA) = 0;
        m = 0;
    }
    n = *(s8 *)(a + 0x152);
    if (!(m < n)) m = n - 1;
    a[0x152] = *(volatile s8 *)(a + 0x152) - m;
}
