typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001757E0();
void func_00184650(u8 *a) {
    a[0x20D] = 2;
    *(u32 *)(a + 0x6C) = 0xBF4DB6DB;
    a[5] = 0;
    if (*(s8 *)(a + 0x1E7) < 0) a[0x168] = 9;
    else if (*(s8 *)(a + 0x1E7) == 1) a[0x168] = 0xB;
    else a[0x168] = 0xA;
    *(s8 *)(a + 0x1E7) = -1;
    func_001757E0(a, 1, a[0x168]);
}

extern void func_003B6CB0();
void func_003B6D30(u8 *a, u8 *b) {
    s16 *c = (s16 *)(a + 0x88);
    s32 v = *(s8 *)(b + 0x150);
    if (v != 0) {
        if ((s8)v == 0x7F) c[1] = -1;
        else c[1] = 1;
        *(s8 *)(b + 0x150) = 0;
    }
    if (c[1] < 0) {
        *(s16 *)(a + 0x1C) = 8;
        { u32 t = a[5]; a[5] = t + 1; }
    }
    func_003B6CB0(a);
}

