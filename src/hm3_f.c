typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_004B573A[];
extern s16 D_004B573C[];
extern s16 D_004B573E[];

void func_001B3AC0(u8 *p) {
    extern void func_001B3D90(u8 *, u8 *);
    extern void func_001754A0(u8 *, s32, s32);
    u8 *s0;
    s32 v;
    u32 t;
    s0 = *(u8 **)(p + 0x18);
    if (*(s8 *)(s0 + 0x151) != 0) {
        t = p[6];
        p[6] = t + 1;
        *(u8 *)(p + 0x13C) = 1;
        func_001B3D90(s0, p);
        func_001754A0(p, 0x1B, (u8)(*(s8 *)(s0 + 0x151) + 0x23));
        func_001B3D90(s0, p);
        if (*(s16 *)(s0 + 0x140) != 0) {
            v = D_004B573A[*(s8 *)(s0 + 0x151) * 3];
        } else {
            v = -D_004B573A[*(s8 *)(s0 + 0x151) * 3];
        }
        *(f32 *)(p + 0x34) += (f32)v;
        *(f32 *)(p + 0x38) += (f32)D_004B573C[*(s8 *)(s0 + 0x151) * 3];
        *(s32 *)(p + 0x48) = D_004B573E[*(s8 *)(s0 + 0x151) * 3];
        *(s8 *)(p + 0x24) = *(s8 *)(s0 + 0x24);
        *(s8 *)(p + 0x31) = -1;
    }
}

void func_0017B5D0(u8 *p) {
    extern void func_0017B8E0(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_00175700(u8 *);
    extern s32 func_00187D70(u8 *);
    extern s32 func_001884C0(u8 *);
    extern void func_00186CE0(u8 *, s32);
    extern void func_00159A40(u8 *, s32);
    extern s32 func_00184B30(u8 *);
    extern s32 func_00184720(u8 *);
    extern s32 func_00184C60(u8 *);
    extern s32 func_00185EC0(u8 *);
    u32 t;
    s32 st;
    if (*(s8 *)(p + 0x1F1) < 0) {
        if (*(s8 *)(p + 0x1F2) != 0) {
            func_0017B8E0(p);
            return;
        }
    }
    if (p[0x20D] != 1) {
        if ((*(u16 *)(p + 0x354) & 0x1000) != 0) {
            p[0x20D] = 1;
            func_001757E0(p, 5, 5);
        }
    } else {
        if ((*(u16 *)(p + 0x354) & 0x1000) == 0) {
            p[0x20D] = 0;
            func_001757E0(p, 5, 1);
        }
    }
    func_00175700(p);
    if (*(s8 *)(p + 0x1F2) != 0) {
        *(s8 *)(p + 0x1F2) = *(s8 *)(p + 0x1F2) - 1;
        return;
    }
    p[0x225] = 0;
    if (func_00187D70(p) != 0) {
        return;
    }
    if (func_001884C0(p) != 0) {
        t = p[6];
        func_00186CE0(p, 0x13);
        func_00159A40(p + 0x34, 0);
        p[6] = t;
        return;
    }
    if (func_00184B30(p) != 0) {
        return;
    }
    if (func_00184720(p) != 0) {
        return;
    }
    if (func_00184C60(p) != 0) {
        t = p[6];
        func_00186CE0(p, 0x13);
        p[6] = t;
        return;
    }
    if (func_00185EC0(p) != 0) {
        return;
    }
    p[6] = 2;
    st = 2;
    if (p[0x20D] == 1) {
        st = 6;
    }
    p[0x168] = st;
    func_001757E0(p, 5, p[0x168]);
}
