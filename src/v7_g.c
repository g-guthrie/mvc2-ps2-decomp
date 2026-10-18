typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_0044F5D0[];
extern u8 D_0045BD40[];

s32 func_001EE260(u8 *p) {
    extern s32 func_00189B90();
    extern void func_0018A990();
    extern void func_00186A60();
    if (func_00189B90(p, D_0044F5D0, p + 0x388) == 0) return 0;
    {
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            if (*(s8 *)(p + 0x1E8) != 0) return 0;
            p[0x1E8] = 1;
        }
    }
    func_0018A990(p, p + 0x388);
    p[5] = 0;
    if (p[0x20D] == 2) p[6] = 1;
    else p[6] = 0;
    p[7] = 0;
    p[0x1FD] = 3;
    func_00186A60(p, 0x15);
    return 1;
    }
    return 0;
}

s32 func_002F6D00(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    if (func_00189310(p, D_0045BD40, p + 0x390) == 0) return 0;
    if (p[0x20D] != 2) {
        if (*(u16 *)(p + 0x396) & 0x20) return 0;
    }
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s32 t = *(s8 *)(p + 0x1E8);
            if (t != 0) return 0;
            p[0x1E8] = t + 1;
        }
    }
    func_0018A990(p, p + 0x390);
    p[5] = 0;
    p[6] = p[0x1B7];
    p[7] = 0;
    p[0x1FD] = 2;
    func_00186A60(p, 0x1D);
    return 1;
}


extern u8 D_004511F0[];

s32 func_0021CE10(u8 *p) {
    extern s32 func_00189310();
    extern void func_0018A990();
    extern void func_00186A60();
    u32 s;
    if (func_00189310(p, D_004511F0, p + 0x3A0) == 0) return 0;
    if (p[0x20D] == 2) {
        s32 t = *(s8 *)(p + 0x1E8);
        if (t != 0) return 0;
        if (p[0x210] == 0) p[0x1E8] = t + 1;
    }
    func_0018A990(p, p + 0x3A0);
    {
        u32 a = (*(s8 *)(p + 0x212) << 1) & 0xFF;
        p[0x1B7] = p[0x1B7] + a;
    }
    s = p[0x1B7];
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 4;
    *(u16 *)(p + 0x2E2) = *(u16 *)(p + 0x20E);
    func_00186A60(p, 0x1D);
    p[0x1B7] = s;
    return 1;
}
