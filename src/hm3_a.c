typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

void func_0037B670(u8 *p) {
    extern void func_00175670(u8 *);
    extern void func_0037B400(u8 *, s32, s32);
    *(s8 *)(p + 0x13C) = 1;
    if (*(s16 *)(p + 0x1C) != 0) {
        f32 a = *(f32 *)(p + 0x118);
        *(f32 *)(p + 0x118) = a - 0.125f;
        func_00175670(p);
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
        *(f32 *)(p + 0x50) += -0.1124999970f;
        *(f32 *)(p + 0x54) += 0.3125f;
    } else {
        *(s8 *)(p + 0x13C) = 0;
        func_0037B400(p, 0, 0);
    }
}

void func_001F34F0(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0018FDB0(u8 *);
    extern void func_001548D0(u8 *, f32 *, s32);
    extern void func_0015B660(f32 *, s32);
    extern void func_001E3710(u8 *, s32);
    u8 *q;
    u8 *v3;
    f32 l[3];
    u8 *s;
    s = p + 0x2B8;
    if (func_00175700(p) < 0) {
        u32 t = p[7];
        p[7] = t + 1;
        func_001757E0(p, 0xF, 4);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        *(u8 *)(p + 0x1B5) = *(s8 *)(s + 2) / 4 + 0x48;
        q[0x1B5] = *(s8 *)(s + 2) / 4 + 0x48;
        func_0018FDB0(p);
        *(u8 *)(p + 0x219) = 0;
        v3 = *(u8 **)(p + 0x1DC);
        if (*(u8 *)(p + 0x216) == 0) {
            *(u32 *)&l[0] = 0xC2D55555;
            *(u32 *)&l[1] = 0;
            func_001548D0(p, l, 2);
        } else {
            l[0] = *(f32 *)(v3 + 0x34);
            l[1] = *(f32 *)(p + 0x430);
            func_0015B660(l, 1);
            func_001E3710(p, 0x49);
        }
    }
}

