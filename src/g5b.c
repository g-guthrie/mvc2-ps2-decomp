typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00189310(u8 *p, void *a, void *b);
extern u8 D_0045DD90[];

s32 func_00322870(u8 *p) {
    if (!func_00189310(p, D_0045DD90, p + 0x390)) {
        return 0;
    }
    if (*(s8 *)(*(u8 **)(p + 0x420)) == 0) {
        return 0;
    }
    p[0x13C] = 1;
    p[0x26C] = 3;
    return 1;
}

extern void func_001B5350(u8 *a, u8 *b);
extern void func_001754A0(u8 *a, s32 b, s32 c);

void func_001B4370(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (*(s8 *)(q + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x13C] = 1;
        func_001B5350(q, p);
        func_001754A0(p, 0x1B, p[0x20]);
        p[0x24] = 7;
    }
}

extern s8 D_004D1917;
extern void func_003DAA40(void);

void func_0015AF90(u8 *p) {
    s16 v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v == 0) {
        s16 w;
        p[4] = 0;
        w = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = w;
        if (w >= 0x11) {
            D_004D1917 = D_004D1917 - 1;
            func_003DAA40();
        }
    }
}

extern void func_00186A60(u8 *p, s32 a);

void func_0031B0D0(u8 *p) {
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    switch (*(s8 *)(p + 0x4DD)) {
    case 0:
        p[0x1FD] = 1;
        p[0x1B7] = 1;
        break;
    case 1:
        p[0x1FD] = 2;
        p[0x1B7] = 1;
        break;
    case 2:
        p[0x1FD] = 0xC;
        p[0x1B7] = 1;
        break;
    }
    func_00186A60(p, 0x15);
}
