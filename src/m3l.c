typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_001757E0(u8 *, s32, s32);
extern s32 func_00175700();
extern s32 func_0018AA50(u8 *, s32, s16 *, s32);
extern void func_0011D8F8(u8 *, s32, s32);
extern void func_002AA0E0(u8 *);
extern void func_00394780(u8 *, s32, s32);
extern void func_00186A60(u8 *, s32);
extern s32 func_00189310(u8 *, u8 *, u8 *);
extern u8 D_00457D00[];
extern u8 D_004D18A0;
extern s16 func_00182E80();

s32 func_001882D0(u8 *p) {
    s16 buf;
    if ((s8)p[0x1F1] > 0) {
        if (func_0018AA50(p, 0x300, &buf, 0) == 0) return 1;
        *(s8 *)(p + 0x1F1) = -1;
    }
    func_0011D8F8(p + 0x368, 0, 8);
    return 0;
}

void func_002A9DE0(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    func_002AA0E0(p);
    if ((s8)p[0x161] & 1) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x20D] = 2;
        func_00394780(p, 8, 0);
    }
}

void func_00320E50(u8 *p) {
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    switch ((s8)p[0x4DD]) {
    case 0:
        p[0x1FD] = 0xA;
        p[0x1B7] = 1;
        break;
    case 1:
        p[0x1FD] = 0xB;
        p[0x1B7] = 1;
        break;
    case 2:
        p[0x1FD] = 0xC;
        p[0x1B7] = 1;
        p[0x22] = 2;
        if (p[0x1E6] == 0) p[0x22] = 6;
        break;
    }
    func_00186A60(p, 0x15);
}

void func_00267570(u8 *p) {
    s32 r;
    u32 b;
    r = func_00175700(p);
    if ((s8)r < 0) {
        b = *(u16 *)(p + 0x354);
        if ((b & 0x3000) == 0 || (b & 0x1000) != 0) {
            p[7] = 1;
            func_001757E0(p, 0x16, 0x29);
        } else if ((b & 0x2000) != 0) {
            p[7] = 4;
            func_001757E0(p, 0x16, 0x26);
        }
    }
}

s32 func_00295720(u8 *p) {
    s8 t;
    if (func_00189310(p, D_00457D00, p + 0x3B8) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    if (p[0x210] == 0) {
        t = p[0x1E8];
        if (t != 0) return 0;
        p[0x1E8] = t + 1;
    }
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 5;
    func_00186A60(p, 0x1D);
    return 1;
}
