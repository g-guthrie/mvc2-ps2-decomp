typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x7C]; s16 h[8]; } G;

extern V3 D_0043DFA0[];
extern u8 D_004BF338[8];
extern u8 *D_004C2834;
extern G *D_004C2794;
extern u16 * volatile D_004C29C8;
extern u8 *D_004C2840;

void func_001324F0(u8 *s0) {
    extern u8 *func_003DA750(void *, s32, s32);
    extern void func_001331A0(void);
    u8 *o;
    if ((o = func_003DA750(s0, 0xD, 2)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_001331A0;
        *(s16 *)(o + 0xCC) = D_004BF338[s0[2]];
        *(u8 **)(o + 0x84) = D_004C2834;
        *(V3 *)(o + 0x34) = D_0043DFA0[s0[2]];
        *(u32 *)(o + 0xD0) = 0x10801;
        *(u8 **)(o + 0x18) = s0;
    }
}

void func_003131E0(u8 *s1, u8 *s0) {
    extern void func_00185490(void *);
    extern void func_00175C00(void *, s32);
    extern void func_00183D10(void *);
    extern void func_001757E0(void *, s32, s32);
    extern void func_003132E0(void *, void *);
    u32 t;
    if (s1[0x269] == 6) {
        s1[0x404] = 0xFF;
        s1[0x405] = 0x10;
    }
    t = s1[6];
    s1[6] = t + 1;
    func_00185490(s1);
    func_00175C00(s1, 0);
    func_00183D10(s1);
    *(u32 *)(s1 + 0x5C) = 0;
    *(u32 *)(s1 + 0x60) = 0;
    *(u32 *)(s1 + 0x68) = 0;
    *(u32 *)(s1 + 0x6C) = 0;
    s1[0x20D] = 0;
    *(f32 *)(s1 + 0x38) = *(f32 *)(s1 + 0x430);
    s0[0xC] = 0;
    s0[0xD] = 0;
    s0[0] = 0;
    s0[1] = 0;
    s0[0xE] = 0;
    s0[0xF] = 0;
    s0[0x1E] = 0;
    s1[0x1B5] = 0x36;
    s1[0x1B2] = *(u16 *)(s1 + 0x1C0) = 0;
    *(u32 *)(s1 + 0x1D8) = 0;
    D_004C2794->h[s1[2]]++;
    func_001757E0(s1, 0x16, 0);
    func_003132E0(s1, s0);
}

void func_003919F0(u8 *s0) {
    extern void func_00175700(void *);
    extern void func_001757E0(void *, s32, s32);
    extern void func_001E7F60(void *);
    u8 *q;
    u16 *g;
    func_00175700(s0);
    *(f32 *)(s0 + 0x34) += *(f32 *)(s0 + 0x5C);
    *(f32 *)(s0 + 0x5C) += *(f32 *)(s0 + 0x68);
    *(f32 *)(s0 + 0x38) += *(f32 *)(s0 + 0x60);
    *(f32 *)(s0 + 0x60) += *(f32 *)(s0 + 0x6C);
    g = D_004C29C8;
    q = *(u8 **)(s0 + 0x18);
    if (*g != *(u16 *)(q + 0x168)) {
        u32 t = s0[5];
        s0[5] = t + 2;
        return;
    }
    if (*(s8 *)(s0 + 0x1B3) != 0) {
        u32 t = s0[5];
        s0[5] = t + 1;
        func_001757E0(s0, 0x17, 2);
        return;
    }
    if (*(f32 *)(s0 + 0x38) <= *(f32 *)(q + 0x430)) {
        u32 t = s0[5];
        u32 t2;
        s0[5] = t + 2;
        t2 = s0[6];
        s0[6] = t2 + 1;
        *(f32 *)(s0 + 0x38) = *(f32 *)(*(u8 **)(s0 + 0x18) + 0x430);
        func_001757E0(s0, 0x17, 1);
    } else {
        func_001E7F60(s0);
    }
}

void func_003C6700(u8 *s1, u8 *s0) {
    extern void func_00175700(void *);
    extern s32 func_00118FA8(f32);
    extern void func_003C80B0(void *, void *);
    s32 s2;
    f32 *s3, *s4;
    s16 v;
    func_00175700(s1);
    s2 = func_00118FA8(*(f32 *)(s1 + 0x5C));
    s3 = (f32 *)(s1 + 0x5C);
    *(f32 *)(s1 + 0x34) += *(f32 *)(s1 + 0x5C);
    *(f32 *)(s1 + 0x5C) += *(f32 *)(s1 + 0x68);
    *(f32 *)(s1 + 0x38) += *(f32 *)(s1 + 0x60);
    *(f32 *)(s1 + 0x60) += *(f32 *)(s1 + 0x6C);
    s4 = (f32 *)(s1 + 0x68);
    if ((s2 ^ func_00118FA8(*(f32 *)(s1 + 0x5C))) < 0) {
        *(u32 *)s3 = 0;
        *(u32 *)s4 = 0;
    }
    v = *(s16 *)(s1 + 0x1C) - 1;
    *(s16 *)(s1 + 0x1C) = v;
    if (v < 0) {
        func_003C80B0(s1, s0);
        return;
    }
    if (*(s16 *)(s1 + 0x1C) < 0x1E) {
        if (*(u32 *)(D_004C2840 + 0x1C) & 1) {
            s1[0x13C] = 0;
        } else {
            s1[0x13C] = 1;
        }
    }
}
