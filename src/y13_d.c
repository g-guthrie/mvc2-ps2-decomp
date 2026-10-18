typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;


extern u8 D_00458320[];

s32 func_002A0DE0(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    s32 v;
    if (func_00189310(p, D_00458320, p + 0x388) == 0) {
        return 0;
    }
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            v = *(s8 *)(p + 0x1E8);
            if (v != 0) return 0;
            p[0x1E8] = v + 1;
        }
    }
    func_0018A990(p, p + 0x388);
    p[5] = 0;
    if (p[0x20D] == 2) p[6] = 1;
    else p[6] = 0;
    p[7] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 0x15);
    return 1;
}

extern u8 D_004B6A50[];

u8 func_001E3940(u8 *p, s32 n) {
    u32 a, b;
    if (p[1] == 0x14) return 0;
    switch (n & 0xFF) {
    case 4:
    case 5:
    case 6:
    case 0xE:
    case 0xF:
    case 0x10:
        return 0;
    }
    a = *(u32 *)(p + 0x428);
    b = *(u32 *)(p + 0x42C);
    if ((a & 0x1018000) | (b & 0x184000)) n = D_004B6A50[n & 0xFF];
    if (p[0x216] & 0x80) n = D_004B6A50[n & 0xFF];
    return n;
}

extern u8 D_0045BA20[];

s32 func_002F21E0(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    s32 v;
    u8 a;
    if (func_00189310(p, D_0045BA20, p + 0x380) == 0) {
        return 0;
    }
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            v = *(s8 *)(p + 0x1E8);
            if (v != 0) return 0;
            p[0x1E8] = v + 1;
        }
    }
    func_0018A990(p, p + 0x380);
    if (p[0x1B7] == 1) a = 1;
    else a = 2;
    if (p[0x20D] == 2) p[0x1FD] = 3;
    else p[0x1FD] = 2;
    p[0x1B7] = a;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, 0x15);
    return 1;
}
