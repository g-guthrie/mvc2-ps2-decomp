typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern u8 *func_003DA750();
extern s32 func_00175700();
extern void func_001757E0();
extern void func_0033CC20();
extern void func_0033D040();
extern void func_0033D6E0();
extern void func_0033D910();
extern s32 D_004C283C;

void func_0033CBC0(void) {
    u8 *o;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0033CC20;
        *(s16 *)(o + 0xCC) = 4;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x80F;
        *(s16 *)(o + 0x1E) = 1;
        func_0033D040(o);
    }
}

void func_0033D680(void) {
    u8 *o;
    if ((o = func_003DA750(0, 5, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_0033D6E0;
        *(s16 *)(o + 0xCC) = 8;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x80F;
        *(s16 *)(o + 0x1E) = 1;
        func_0033D910(o);
    }
}

extern s8 *D_004C299C;
extern u16 D_004C1C88[2];
extern void func_001757E0();

void func_0037F3F0(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        ((s16 *)p)[14] = 1;
        D_004C299C[0]++;
        if (D_004C299C[0] >= 7) D_004C299C[0] = 4;
    }
}

void func_0036D730(u8 *p) {
    p[0x13C] = 1;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x14) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x14) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x14) + 0x3C);
    p[0x24] = 9;
    *(u32 *)(p + 0x50) = 0x3FC00000;
    *(u32 *)(p + 0x54) = 0x3FC00000;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(u16 *)(p + 0x1C) = D_004C1C88[(*(u8 **)(p + 0x18))[0x1B7]];
    p[0x169] = 0x17;
    func_001757E0(p, p[0x169], 0x3B);
}

typedef struct { f32 x, y, z; } V3;
extern V3 D_004B7CE4;
extern void func_00334580();
extern void func_003344F0();

void func_00334940(u8 *p) {
    u8 *o;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00334580;
        *(s16 *)(o + 0xCC) = 0x18;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(s32 *)(o + 0xD0) = 0x801;
        *(V3 *)(o + 0x34) = D_004B7CE4;
        *(u8 **)(o + 0x18) = p;
        func_003344F0(o);
    }
}

extern void (*D_0045B080[])(u8 *);
extern u8 *D_004C2794;

void func_002E30E0(u8 *p) {
    u8 *g;
    u32 t, i;
    D_0045B080[p[6]](p);
    t = p[0x15B];
    if (t != 0) {
        p[0x1B5] = t;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        i = p[2] * 2; g = (u8 *)(i + (u32)D_004C2794);
        *(s16 *)(g + 0x7C) = *(s16 *)(g + 0x7C) + 1;
        p[0x15B] = 0;
    }
}

extern s32 func_00189310();
extern void func_0018A990();
extern u8 D_0045B730[];
extern u8 D_004C1214[2];

s32 func_002EE200(u8 *p) {
    if (func_00189310(p, D_0045B730, p + 0x380) == 0) return 0;
    if (**(s8 **)(p + 0x420) == 0) return 0;
    func_0018A990(p, p + 0x380);
    p[0x26C] = D_004C1214[*(s32 *)(p + 0x2D4)];
    return 1;
}
