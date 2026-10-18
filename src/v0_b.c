typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

s32 func_002E13D0(u8 *p) {
    extern s32 func_00189310(u8 *, u8 *, u8 *);
    extern u8 D_0045AEA0[], D_0045AEB0[];
    if (func_00189310(p, D_0045AEA0, p + 0x378) != 0) {
        if (**(s8 **)(p + 0x420) != 0) {
            *(s8 *)(p + 0x26C) = 2;
            return 1;
        }
    }
    if (func_00189310(p, D_0045AEB0, p + 0x380) != 0) {
        if (**(s8 **)(p + 0x420) != 0) {
            *(s8 *)(p + 0x26C) = 3;
            return 1;
        }
    }
    return 0;
}

void func_002ECBE0(u8 *p) {
    extern void func_002ECD60(u8 *);
    extern void func_00175700(u8 *);
    extern void func_001E3710(u8 *, s32);
    extern void func_001D5670(u8 *, s32, s32);
    s32 i;
    s16 h;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_002ECD60(p);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_001E3710(p, 0x4C);
        for (i = 0; i < 10; i++) func_001D5670(p, 5, (u8)i);
    }
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        ((s16 *)p)[14] = 0x40;
    }
}

void func_00275950(u8 *p) {
    extern s32 func_00174170();
    extern u8 D_00454C10[];
    if (*(u16 *)(p + 0x4F0) & 0x3F0) {
        u16 b = *(u16 *)(p + 0x354);
        if (b & 0x200) p[0x20] = 5;
        else if (b & 0x100) p[0x20] = 6;
        else if (b & 0x80) p[0x20] = 7;
        else if (b & 0x40) p[0x20] = 8;
        else if (b & 0x20) p[0x20] = 9;
        else p[0x20] = 10;
    } else {
        p[0x20] = D_00454C10[(func_00174170() & 0xF) << 1];
    }
}

s32 func_0030C7E0(u8 *p) {
    extern s32 func_00189310(u8 *, u8 *, u8 *);
    extern void func_0018A990(u8 *, u8 *);
    extern void func_00186A60(u8 *, s32);
    extern u8 D_0045D020[];
    if (func_00189310(p, D_0045D020, p + 0x378) == 0) return 0;
    if (p[0x20D] == 2 && p[0x210] == 0) {
        s32 t = *(s8 *)(p + 0x1E8);
        if (t != 0) return 0;
        p[0x1E8] = t + 1;
    }
    if (p[0x20D] == 2) {
        if (*(s32 *)(p + 0x2C0) > 0) return 0;
    }
    func_0018A990(p, p + 0x378);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 0x15);
    return 1;
}

void func_001874D0(u8 *p) {
    extern s32 func_00174170();
    extern void func_001757E0(u8 *, s32, s32);
    extern u8 *D_004C2840[2];
    s32 w;
    u8 x;
    p[0x20D] = 1;
    p[0x201] = 1;
    p[0x1B1] = 0;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    p[0x168] = 0;
    w = *(s8 *)(p + 0x1E7);
    if (w == 0) {
        if (*(s8 *)(p + 0x539) != 0) p[0x168] = ((*(s8 *)(D_004C2840[0] + 0x1C)) & 1) + 1;
        if (*(s8 *)(p + 0x539) != 0) x = func_00174170() & 1;
        else x = p[0x1B7];
        p[0x168] = (s8)x + 1;
        p[0x168] = 2;
    } else if (w == 1) {
        p[0x168] = 3;
    }
    func_001757E0(p, 0x11, p[0x168]);
}
