typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void func_00175700();
extern void func_001757E0();

extern void func_00186A20();
extern void func_00183D10(u8 *);
void func_002D4D60(u8 *p) {
    u32 t;
    *(u8 *)(p + 0x40C) = 2;
    *(u8 *)(p + 0x33C) = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        p[0x209] = 0x23;
        t = p[6];
        p[6] = t + 1;
        func_00186A20(p);
    }
}

extern void func_001D0500();
extern void func_002D7260();
void func_002D74B0(u8 *p) {
    u32 t;
    if (p[7] == 0) {
        *(s16 *)(p + 0x1C) = 0x3C;
        t = p[7];
        p[7] = t + 1;
        func_001757E0(p, 0x13, 7);
    } else {
        func_00175700(p);
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            func_001D0500(p, 7);
        }
    }
    func_002D7260(p);
}

void func_0018E790(u8 *p) {
    u32 t;
    u8 a;
    p[0x168] = 0xA;
    a = p[0x245];
    a &= 0x70;
    if (a != 0x10) {
        t = p[0x168];
        p[0x168] = t + 1;
        if (a != 0x20) {
            t = p[0x168];
            p[0x168] = t + 1;
        }
    }
    func_001757E0(p, 0xD, p[0x168]);
    *(s16 *)(p + 0x1C) = 0xA;
    p[0x20D] = 2;
}

void func_0029F910(u8 *p) {
    u32 t;
    func_00175700(p);
    if (*(s32 *)(p + 0x308) != 0) {
        t = p[6];
        p[6] = t + 1;
        if (p[0x1FD] == 0xC) {
            func_001757E0(p, 0x15, (u8)(p[0x1B7] + 0x11));
        } else {
            func_001757E0(p, 0x15, (u8)(p[0x1B7] + 0xF));
        }
    }
}

void func_002B0F60(u8 *p) {
    s16 v;
    *(u8 *)(p + 0x40C) = 2;
    *(u8 *)(p + 0x33C) = 5;
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    v = *(s16 *)(p + 0x1C) & 0xF;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) func_00183D10(p);
    func_00175700(p);
}
