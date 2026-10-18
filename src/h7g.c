typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern s32 func_003BCFB0(void *p);
extern void func_003BB910(void *p);
extern s32 func_003BD4C0(void *p);
extern void func_003BD4A0(void *p);
extern void (*D_004C2098[2])(void *);
void func_003BB530(u8 *p) {
    if (func_003BCFB0(p)) {
        func_003BB910(p);
    } else if (func_003BD4C0(p)) {
        func_003BD4A0(p);
    } else {
        D_004C2098[p[5]](p);
    }
}
typedef struct { f32 x, y, z; } V3;
extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_00330CE0(void);
extern u32 D_004C283C;
extern V3 D_0045E868;
void func_00330C60(void) {
    u8 *o = func_003DA750(0, 6, 1);
    if (o) {
        o[0x13C] = 1;
        *(void (**)(void))(o + 0x10) = func_00330CE0;
        *(s16 *)(o + 0xCC) = 5;
        *(u32 *)(o + 0x84) = D_004C283C;
        *(u32 *)(o + 0xD0) = 0x805;
        *(V3 *)(o + 0x34) = D_0045E868;
        *(u32 *)(o + 0x44) = 0xDD29;
    }
}
extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_002F44F0(void *p, void *q);
extern u8 D_004C12F0[2];
void func_002F4470(u8 *p, u16 *q) {
    s32 v;
    u32 t;
    *(s8 *)(p + 0x1B1) = -0x80;
    p[0x201] = 0;
    p[0x206] = 0;
    v = *q;
    func_001757E0(p, 0x15, D_004C12F0[v / 2]);
    t = p[6];
    p[6] = t + 1;
    func_002F44F0(p, q);
}
extern void func_0039F020(void);
void func_0039EF90(u8 *p, s32 a, s32 b) {
    u8 *o = func_003DA750(0, 1, 0);
    if (o) {
        *(void (**)(void))(o + 0x10) = func_0039F020;
        o[0x20] = a;
        o[0x21] = b;
        *(u8 **)(o + 0x18) = p;
        o[1] = p[1];
        *(f32 *)(o + 0x34) = *(f32 *)(p + 0x34);
        *(f32 *)(o + 0x38) = *(f32 *)(p + 0x38);
        *(s16 *)(o + 0x26) = 0x2900;
    }
}
extern void func_003424F0(void);
extern u32 D_004C283C;
void func_00342880(V3 *p, s32 a) {
    u8 *o = func_003DA750(0, 6, 0);
    if (o) {
        o[0x13C] = 1;
        *(void (**)(void))(o + 0x10) = func_003424F0;
        *(s16 *)(o + 0xCC) = a + 1;
        *(u32 *)(o + 0x84) = D_004C283C;
        *(u32 *)(o + 0xD0) = 0x80B;
        o[0x20] = a;
        *(V3 *)(o + 0x34) = *p;
    }
}
extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_0037D9C0(void);
extern void func_0037DC60(void *o, void *p);
u8 *func_0037D930(u8 *p, s32 a) {
    u8 *o;
    if (!(o = func_003DA750(0, 3, 0))) return 0;
    *(void (**)(void))(o + 0x10) = func_0037D9C0;
    *(u8 **)(o + 0x18) = p;
    *(s16 *)(o + 0x26) = 0x1705;
    *(s16 *)(o + 0x140) = *(s16 *)(*(u8 **)(o + 0x18) + 0x140);
    o[0x23] = a;
    func_0037DC60(o, p);
    return o;
}
extern s8 func_00175700(void *p);
extern void func_001843A0(void *p);
void func_0024F420(u8 *p) {
    if (*(s8 *)(p + 0x151) == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
    if (func_00175700(p) < 0) func_001843A0(p);
}
extern s32 func_001864a0(void *p);
extern void func_001E3710(void *p, s32 a);
void func_00205710(u8 *p) {
    u32 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_001864a0(p)) {
        t = p[6];
        p[6] = t + 1;
        func_001E3710(p, 0x2F);
        func_00175700(p);
    }
}
extern void func_00163240(void);
extern u32 D_004C2838;
void func_001631B0(V3 *p) {
    u8 *o = func_003DA750(0, 9, 1);
    if (o) {
        o[0x13C] = 1;
        *(void (**)(void))(o + 0x10) = func_00163240;
        *(u32 *)(o + 0xD0) = 0x409;
        *(u32 *)(o + 0xD4) = 2;
        *(s16 *)(o + 0xCC) = 0x22;
        *(u32 *)(o + 0x84) = D_004C2838;
        *(V3 *)(o + 0x34) = *p;
        *(u32 *)(o + 0x48) = 0;
        *(u32 *)(o + 0x78) = 0;
        *(u32 *)(o + 0x7C) = 0;
        *(u32 *)(o + 0x80) = 0;
    }
}
