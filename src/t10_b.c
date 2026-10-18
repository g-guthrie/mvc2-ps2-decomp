typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700();
extern void func_00175910(u8 *p, u8 a, u8 b, s32 c);
extern u8 D_004521D0[];
extern u8 D_0045A8C0[];
extern s32 func_00189310(void *p, void *q, void *r);
extern void func_0018A990();
extern void func_00186A60(void *p, s32 a);
extern void func_0039E450(void);
extern void func_001830D0(void *p, void *v, s32 a, s32 b);
extern u8 D_004D3170[];
extern s8 D_004C2798[2];
extern void func_001757E0();
extern void func_00183d50();
extern s32 func_00189B40();
extern s8 D_004F7FC8[];
typedef struct { u8 pad0[0x34]; f32 f34; f32 f38; u8 pad1[0x1C]; f32 f58; f32 f5c; f32 f60; u8 pad2[4]; f32 f68; f32 f6c; u8 pad3[0x430 - 0x70]; f32 f430; } F;
typedef struct { u8 *e[94]; } T;
typedef struct { f32 x, y, z; } V3;
extern s32 D_004C283C;
extern V3 D_0045ECD0;
extern V3 D_00460CC0[];
extern u8 *func_003DA750();
extern void func_0033C300();
extern void func_0033C250();
extern void func_00343B10();
extern void func_00170DF0();
extern void func_003B3880();
extern void func_001E7F60();
extern s32 func_00174470();
extern void func_003B3870();
extern void func_0016B0C0();
extern void func_00166C80();
extern void func_001863F0();
extern void func_0022FFB0();
extern void func_00231D70();
extern void func_00313BF0();
extern void func_00313B80();
extern void func_00313C40();
extern void func_00313C70();
extern void func_001E3710();
extern void func_001843A0();
extern s32 func_003CE510();
extern void func_0035B160();
extern u8 D_004F1F45;
extern u8 D_004F1F46;

s32 func_00189A70(u8 *a0, u8 *a1, u8 *a2) {
    s8 c = *(s8 *)(a2 + 1) - 1;
    u32 m;
    *(s8 *)(a2 + 1) = c;
    if (c <= 0) return a2[0] = 0;
    m = *(u16 *)(a0 + 0x362) & *(u16 *)(a1 + 8);
    if (m == 0) return 0;
    if (*(u16 *)(a2 + 6) != m) return 0;
    {
        u32 t = a2[2];
        a2[2] = t + 1;
        a2[1] = *(s8 *)(a1 + 2);
    }
    if (*(u16 *)a1 == a2[2]) {
        a2[0] = 2;
        a2[1] = D_004F7FC8[a0[2]] * 10 + 0xE;
        return func_00189B40(a0, a1, a2);
    }
    return 0;
}

void func_00207460(u8 *p) {
    u32 v[4];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x404] = 0;
        p[0x405] = 0;
        v[0] = 0xC2555555;
        v[1] = 0x43BC9249;
        v[2] = 0;
        func_001830D0(p, v, 1, t + 1);
    }
}

void func_002FAF40(u8 *p) {
    u32 v[3];
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t;
        *(s8 *)(p + 0x151) = 0;
        t = p[6];
        p[6] = t + 1;
        v[0] = 0x413AAAAA;
        v[1] = 0x43092492;
        p[0x404] = 0;
        p[0x405] = 0;
        func_001830D0(p, v, 1, t + 1);
        *(s16 *)(p + 0x1C) = 10;
        *(s16 *)(p + 0x1E) = 3;
    }
}

void func_003135D0(u8 *p, u8 *a1) {
    u8 *q;
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
    func_00313BF0(p);
    func_00313B80(p, a1);
    if (a1[0xF] == 0) func_00313C40(p, a1);
    else func_00313C70(p, a1);
    q = *(u8 **)(p + 0x14);
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x13C] = 0;
    }
}

void func_0035B440(u8 *p, u8 *a1) {
    u8 *q = *(u8 **)(p + 0x18);
    if (p[0x21] != 0) {
        p[0x13C] = 0;
        return;
    }
    if (*(u16 *)(a1 + 0x160) == 0) {
        p[0x13C] = 0;
        return;
    }
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
    *(s32 *)(p + 0x48) = *(s32 *)(q + 0x48);
    if (func_003CE510(0, 9) != 0) {
        p[0x13C] = 0;
    } else {
        p[0x13C] = 1;
        p[0x169] = 0x1C;
        p[0x168] = 1;
        func_00175910(p, p[0x169], p[0x168], *(u16 *)(a1 + 0x160));
    }
    func_0035B160(p, a1);
}

