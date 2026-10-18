typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004516B0[];
extern s32 func_00189EE0();
extern void func_00186A60(u8 *, s32);
s32 func_002265B0(u8 *p) {
    if (func_00189EE0(p, D_004516B0, p + 0x3C0) == 0) return 0;
    if (*(s32 *)(p + 0x2BC) != 0x1E) return 0;
    if (**(s8 **)(p + 0x420) < 3) return 0;
    p[0x1FD] = 0x17;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, 0x1D);
    return 1;
}

extern u8 D_00453950[];
extern s32 func_00189310();
extern void func_0018A990(u8 *, u8 *);
s32 func_0025C450(u8 *p) {
    if (func_00189310(p, D_00453950, p + 0x380) == 0) return 0;
    {
        u8 *q = p + 0x2B8;
        if (q[0] != 0) return 0;
        if (q[1] != 0) return 0;
    }
    func_0018A990(p, p + 0x380);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[0x1FD] = 1;
    func_00186A60(p, 0x15);
    return 1;
}

extern u8 D_0045B0A8[];
extern s32 func_00189660();
s32 func_002E3F80(u8 *p) {
    s8 *q = (s8 *)(p + 0x2B8);
    if (func_00189660(p, D_0045B0A8, p + 0x380) == 0) return 0;
    if (q[3] || q[9]) {
        return 0;
    }
    func_0018A990(p, p + 0x380);
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[0x1FD] = 0;
    func_00186A60(p, 0x15);
    return 1;
}

extern void func_001830D0(u8 *, u32 *, s32);
void func_00271EA0(u8 *p) {
    u32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (((s8 *)p)[0x151] == 0) return;
    {
        u32 t = p[6];
        p[6] = t + 1;
        *(s8 *)(p + 0x151) = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = 0x41855555;
        v[1] = 0x43430000;
        v[2] = 0;
        func_001830D0(p, v, 1);
    }
}

extern u8 D_004B74A0[];
extern s32 func_00280D10();
extern s32 func_00174170();
void func_00280840(u8 *p) {
    u32 st = p[0x452];
    switch (st) {
    case 0:
        p[0x452] = st + 1;
        if (p[0x472] == 0) {
            s32 tb = (s32)D_004B74A0 + ((u8)func_00280D10() << 4);
            s32 r = func_00174170() & 0xF;
            p[0x472] = *(s8 *)(r + tb);
        }
    case 1:
        {
            u32 t = p[0x472];
            t = t - 1;
            p[0x472] = t;
            if ((t & 0xFF) == 0) p[0x451] = 1;
        }
    }
}

extern u8 *D_004C2840;
extern s32 D_004C27FC;
static void func_0014E770(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    if (*(s32 *)(q + 0xDC) != 0) {
        if (q[4] == 1) {
            *(s16 *)(p + 0x1E) = *(s16 *)(q + 0x1E);
        } else {
            *(s16 *)(p + 0x1E) = *(s16 *)(q + 0x1E);
        }
    }
}
void func_0014E840(u8 *p) {
    s32 idx;
    func_0014E770(p);
    ((s8 *)p)[0x13C] = (*(s8 **)(p + 0x18))[0x13C];
    idx = ((s8 *)D_004C2840)[6] + *(s16 *)(p + 0x1E);
    {
        s16 v;
        if (idx < 3) {
            switch (idx) {
            case 0: v = 0x16; break;
            case 1: v = 0x17; break;
            case 2: v = 0x18; break;
            }
        } else {
            v = 0x19;
        }
        *(s16 *)(p + 0xCC) = v;
    }
    *(s32 *)(p + 0x84) = D_004C27FC;
    *(f32 *)(p + 0x74) = *(f32 *)(*(u8 **)(p + 0x18) + 0x74);
}
