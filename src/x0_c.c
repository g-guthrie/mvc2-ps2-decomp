typedef struct SA37_J0 SA37_J0;
typedef struct SA37_R SA37_R;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V1BA1B0;
extern u8 D_004D18A6;
extern void (*D_004727F0[])();

s32 func_00167480(u8 *p, u8 *q) {
    extern s32 func_0016B250();
    extern s32 func_0016B360(u8 *, u8 *);
    extern void func_0016B0C0(SA37_J0 *, SA37_R *, s32);
    u16 a;
    if (func_0016B250(p, 2) == 0) return 0;
    if (func_0016B360(p, q) == 0) return 0;
    func_0016B0C0((SA37_J0 *)p, (SA37_R *)q, 0);
    func_0016B0C0((SA37_J0 *)p, (SA37_R *)q, 1);
    func_0016B0C0((SA37_J0 *)p, (SA37_R *)q, 1);
    a = ((*(s16 *)(p + 0x4C8) << 8) & 0x3C00) | 0x100;
    if ((a & 0xC00) != 0) {
        a = a ^ (p[0x1E6] * 3 << 10);
    }
    *(u16 *)(p + 0x4F0) = a;
    return 0;
}

void func_001BA1B0(u8 *p) {
    extern void func_001B9D40();
    extern void func_003DAA40();
    extern void func_00175580();
    u8 *r, *q;
    s32 v;
    r = *(u8 **)(p + 0x18);
    *(s8 *)(p + 0x24) = *(s8 *)(r + 0x24);
    *(V1BA1B0 *)(p + 0x34) = *(V1BA1B0 *)(*(u8 **)(p + 0x18) + 0x34);
    q = *(u8 **)(p + 0x18);
    if (p[1] != q[1]) {
        func_001B9D40();
        return;
    }
    if (q[0x169] != 0x16 || (q[0x15B] & 0x80) != 0) {
        func_003DAA40();
        return;
    }
    v = q[0x15B];
    if (v != p[0x22]) {
        p[0x22] = v;
        p[0x13C] = 1;
        if (r[0x425] != 0) {
            if (*(s8 *)(p + 0x151) != 0) p[0x13C] = 0;
        }
        func_00175580(p, 0x1B, p[0xD2], p[0x22] - 1);
    }
}

void func_001F6F10(u8 *p) {
    extern s8 func_00175700();
    extern void func_001843A0();
    extern void func_00186CE0();
    extern void func_001E3210();
    extern void func_001548D0();
    u32 v[4];
    u8 *q;
    if (func_00175700(p) < 0) {
        if (*(s8 *)(p + 0x539) != 0) {
            func_001843A0(p);
        } else if ((*(u16 *)(p + 0x35E) & 0x2000) != 0) {
            *(s8 *)(p + 0x1E7) = -1;
            func_00186CE0(p, 0xD);
        } else {
            func_001843A0(p);
        }
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        func_001E3210(p, 5);
        v[0] = 0;
        v[1] = 0x43092492;
        func_001548D0(p, v, 7);
        q = *(u8 **)(p + 0x1DC);
        q[0x20A] = 1;
        q[0x1B5] = 0x22;
        p[0x1B5] = 0x22;
    }
}

void func_0020D130(u8 *p) {
    extern void func_00175700();
    extern void func_001266A0();
    extern void func_00183d50();
    extern void func_001757E0();
    f32 *v1, *a3, *t0, *t1;
    u32 t;
    func_00175700(p);
    v1 = (f32 *)(p + 0x5C);
    t0 = (f32 *)(p + 0x68);
    a3 = (f32 *)(p + 0x60);
    t1 = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        t = p[7];
        p[7] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *(s32 *)v1 = 0;
        *(s32 *)a3 = 0;
        *(s32 *)t0 = 0;
        *(s32 *)t1 = 0;
        func_001266A0(p, 0, 0);
        func_00183d50(p);
        func_001757E0(p, 1, 3);
    }
}

void func_0022AC70(u8 *p) {
    extern void func_00175700();
    extern void func_001830D0();
    f32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t;
        p[0x404] = 0;
        p[0x405] = 0;
        t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        *(u32 *)((u8 *)v) = 0x422D5555;
        *(u32 *)((u8 *)v + 4) = 0x42F00000;
        func_001830D0(p, v, 1, t + 1);
    }
}

void func_002AEEF0(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    extern void func_00183d50();
    f32 *a1, *a2, *a3, *t0;
    func_00175700(p);
    a1 = (f32 *)(p + 0x5C);
    a3 = (f32 *)(p + 0x68);
    a2 = (f32 *)(p + 0x60);
    t0 = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        p[6] = 4;
        *(s32 *)a1 = 0;
        *(s32 *)a2 = 0;
        *(s32 *)a3 = 0;
        *(s32 *)t0 = 0;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 1;
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + 0xA));
        func_00183d50(p);
    }
}

void func_00312050(u8 *p) {
    extern void func_00175700();
    extern void func_001757E0();
    s16 v;
    u32 t;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        t = p[6];
        p[6] = t + 1;
        *(u32 *)(p + 0x5C) = 0x3F12ED55;
        *(u32 *)(p + 0x68) = 0x3D200000;
        *(u32 *)(p + 0x60) = 0x4182B6DB;
        *(u32 *)(p + 0x6C) = 0xBF676DB6;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        }
        func_001757E0(p, 0x12, 1);
    }
}

void func_0039E390(u8 *p) {
    extern void func_0039E450();
    u8 *q = *(u8 **)(p + 0x18);
    if (q[5] != 0 || q[0x1E4] != 0x1D) { func_0039E450(p); return; }
    if ((D_004D18A6 & (1 << (q[2] ^ 1))) != 0) return;
    if ((D_004D18A6 & (1 << q[2])) != 0) {
        if (q[0x404] != 0) { if (*(s8 *)(q + 0x405) != 0) goto call; }
        return;
    }
call:
    D_004727F0[p[4]](p);
}
