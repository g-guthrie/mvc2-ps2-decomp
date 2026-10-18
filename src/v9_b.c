typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;typedef signed int s32;typedef float f32;
extern u8 D_00459CD0[];
extern u8 D_00454A80[];
extern u8 D_004598C0[];
extern u8 D_004511E0[];

s32 func_002C58D0(u8 *p) {
    extern s32 func_00189310(); extern void func_0018A990(); extern void func_002CAFC0(); extern void func_00186A60();
    if (func_00189310(p, D_00459CD0, p + 0x3B8) == 0) return 0;
    if (**(s8**)(p+0x420) == 0) return 0;
    func_0018A990(p, p + 0x3B8);
    if (p[0x215] != 0) func_002CAFC0(p);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 5;
    func_00186A60(p, 0x1D);
    return 1;
}

s32 func_00273780(u8 *p) {
    extern s32 func_00189310(); extern s32 func_00273C20(); extern void func_0018A990(); extern void func_00186A60();
    if (func_00189310(p, D_00454A80, p + 0x378) == 0) return 0;
    if (func_00273C20(p) == 0) return 0;
    if (**(s8**)(p+0x420) == 0) return 0;
    if (*(s32*)(p+0x2E4) != 0) return 0;
    func_0018A990(p, p + 0x378);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 0x1D);
    *(s32*)(p+0x2B8) = 0;
    *(s32*)(p+0x2BC) = 0;
    return 1;
}

s32 func_001EE070(u8 *p) {
    extern s32 func_0018AA50(); extern s32 func_0018A580(); extern void func_00186A60();
    u8 buf[0x10];
    u8 *q = p + 0x2B8;
    if (func_0018AA50(p, 0x300, buf + 0xE, 0) == 0) return 0;
    if (func_0018A580(p) == 0) return 0;
    if (p[0x20D] == 2) return 0;
    if ((*(u16*)(p+0x20E) & 0x2000) != 0) return 0;
    *(u16*)q = *(u16*)(p+0x20E);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 0x15);
    return 1;
}

s32 func_002C0110(u8 *p) {
    extern s32 func_00189310(); extern void func_00186A60(); extern void func_0011D8F8();
    if (func_00189310(p, D_004598C0, p + 0x3B0) == 0) return 0;
    if (p[0x20D] == 2 && p[0x210] == 0) {
        if (*(s8*)(p+0x1E8) != 0) return 0;
        p[0x1E8] = *(s8*)(p+0x1E8) + 1;
    }
    p[0x1B7] = 3;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 3;
    func_00186A60(p, 0x1D);
    func_0011D8F8(p + 0x3B8, 0, 8);
    func_0011D8F8(p + 0x3C0, 0, 8);
    return 1;
}

s32 func_0021CD50(u8 *p) {
    extern s32 func_00189310(); extern void func_00186A60();
    if (func_00189310(p, D_004511E0, p + 0x398) == 0) return 0;
    if (**(s8**)(p+0x420) == 0) return 0;
    if (p[0x20D] == 2) {
        s32 t = *(s8*)(p+0x1E8);
        if (t != 0) return 0;
        if (p[0x210] == 0) p[0x1E8] = t + 1;
    }
    p[0x1B7] = 1;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 3;
    *(u16*)(p+0x2E2) = *(u16*)(p+0x20E);
    func_00186A60(p, 0x1D);
    return 1;
}

s32 func_001EE960(u8 *p) {
    extern s32 func_001EE830(); extern s32 func_001EE890(); extern s32 func_001EE900();
    s32 x;
    if ((x = func_001EE830(p)) != 0) return 1;
    if (p[0x216] == 0) { if ((x = func_001EE890(p)) != 0) return 1; }
    else { if ((x = func_001EE900(p)) != 0) return 1; }
    return 0;
}

s32 func_0016A930(u8 *p, u8 *q, s32 r) {
    extern s32 func_0016AA00();
    s32 x;
    u16 *t = *(u16**)(q+0x1D4);
    if (r != 0) {
    if ((x = func_0016AA00(p, q, r, t[2]))) return 1;
    if ((x = func_0016AA00(p, q, r, t[3]))) return 1;
    if ((x = func_0016AA00(p, q, r, t[4]))) return 1;
    if ((x = func_0016AA00(p, q, r, t[5]))) return 1;
    }
    return 0;
}
