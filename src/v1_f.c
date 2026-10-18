typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
void func_00154580(u8 *p, f32 *q, f32 x, f32 y) {
    extern u8 *func_003DA750(); extern void func_00154400();
    u8 *o = func_003DA750(0, 0x13, 1);
    if (o != 0) {
        f32 d;
        o[0x13C] = 1;
        *(void**)(o+0x10) = func_00154400;
        *(u32*)(o+0xD0) = 0x800011;
        *(f32*)(o+0x34) = *(f32*)(p+0x34);
        *(f32*)(o+0x38) = *(f32*)(p+0x38);
        *(u32*)(o+0x3C) = 0;
        if (*(s16*)(p+0x140) != 0) d = q[0]; else d = -q[0];
        *(f32*)(o+0x34) += d;
        *(f32*)(o+0x38) += q[1];
        *(f32*)(o+0x50) = x;
        *(f32*)(o+0x54) = y;
        *(u32*)(o+0x58) = 0;
    }
}

u8 *func_001C54A0(u8 *p, s32 n) {
    extern u8 *func_003DA750(); extern void func_001C5580(); extern void func_00174A40();
    u8 *o;
    if ((o = func_003DA750(0, 3, 0)) != 0) {
        *(void**)(o+0x10) = func_001C5580;
        *(u8**)(o+0x18) = p;
        o[0x20] = n;
        { s32 k = (s8)n; k = k << 1; o[0x22] = k & 0x1F; }
        *(f32*)(o+0x34) = *(f32*)(p+0x34);
        if (*(u16*)(p+0x168) == 0x1305) *(f32*)(o+0x38) = 90.0f + *(f32*)(p+0x38);
        else *(f32*)(o+0x38) = 17.1428566f + *(f32*)(p+0x38);
        func_00174A40(o, 0x320);
    }
    return o;
}

void func_001EC050(u8 *p) {
    extern void func_00175700(); extern void func_00192D60(u8*, u8); extern void func_00345D90(u8*, s32, f32, f32);
    f32 a, b; u8 n; s32 i;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8*)(p+0x151) != 0) {
        u32 t;
        *(s8*)(p+0x151) = 0;
        t = p[6];
        p[6] = t + 1;
        if (p[0x20D] != 2) { a = 195.0f; b = 113.571426f; i = 0; n = 0; }
        else { a = 173.333328f; b = 154.285706f; i = 0; n = 1; }
        func_00192D60(p, n);
        func_00345D90(p, i, a, b);
    }
}

void func_001FE250(u8 *p) {
    extern void func_00175700(); extern void func_001E3270(u8*, s32, f32); extern void func_00184540();
    u8 *q = p + 0x2B8;
    s16 v;
    func_00175700(p);
    *(f32*)(p+0x34) += *(f32*)(p+0x5C);
    *(f32*)(p+0x5C) += *(f32*)(p+0x68);
    *(f32*)(p+0x38) += *(f32*)(p+0x60);
    *(f32*)(p+0x60) += *(f32*)(p+0x6C);
    if (*(f32*)(p+0x38) < *(f32*)(p+0x430)) *(f32*)(p+0x38) = *(f32*)(p+0x430);
    v = *(s16*)(p+0x1C) - 1;
    *(s16*)(p+0x1C) = v;
    if (v == 0) {
        *(u32*)(p+0x68) = 0;
        q[0x1C] = 0;
        q[0x19] = 0;
        func_001E3270(p, 0x1F, 32.0f);
        func_00184540(p);
    }
}

void func_00279880(u8 *p) {
    extern void func_00175700(); extern void func_0037E4A0();
    u32 x;
    func_00175700(p);
    if (*(s8*)(p+0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s8*)(p+0x151) = 0;
        func_0037E4A0(p, 1);
    }
    x = *(u16*)(p+0x160);
    if (x != 0) {
        if (*(s16*)(p+0x140) == 0) *(f32*)(p+0x34) += 1.6666666f * (f32)(s16)x;
        else *(f32*)(p+0x34) -= 1.6666666f * (f32)(s16)x;
        *(s16*)(p+0x160) = 0;
    }
}

