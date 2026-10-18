typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 a, b; } E2;
extern E2 D_004B3CB0[];
extern s32 D_004C2838;
extern s32 func_00153AA0();
extern void func_00170DA0(s32,s32,s32,s16);
extern void func_00179160(u8 *p, u8 *q);
extern s32 func_00393390(u8 *p);
extern void func_003933A0(u8 *p);
extern u8 *D_004C29D4;
extern u8 *D_004C2794;
extern void func_00175C00(u8 *p, s32 a);
extern void func_001757E0(u8 *p, s32 a, s32 b);

void func_0015E9F0(u8 *p) {
    E2 *e = D_004B3CB0;
    s32 v;
    e += *(s16 *)(p + 0x1C);
    if (*(s32 *)(p + 0xDC) != 0) {
        v = func_00153AA0();
        func_00170DA0(D_004C2838, 0x1E, v, *(s16 *)(p + 0xCC));
    } else {
        v = func_00153AA0();
        func_00170DA0(D_004C2838, 0x1A, v, *(s16 *)(p + 0xCC));
    }
    { f32 b = e->b; f32 a = e->a; *(f32 *)(p + 0xE0) = a; *(f32 *)(p + 0xE4) = b; }
    *(u32 *)(p + 0xD0) |= 0x20000;
}

void func_00393230(u8 *p) {
    u8 *q = *(u8 **)(p + 0x1DC);
    u8 *r = *(u8 **)(p + 0x18);
    r[0x1FE] = 1;
    (*(u8 **)(p + 0x18))[0x201] = 2;
    (*(u8 **)(p + 0x18))[0x209] = 2;
    func_00179160(p, q);
    if (func_00393390(p) != 0) {
        func_003933A0(p);
        return;
    }
    if (*(s8 *)(D_004C29D4 + 9) >= 3) {
        func_003933A0(p);
        *(u8 **)(q + 0x1C8) = r;
        q[0x20A] = 1;
        q[0x1B5] = 0x28;
    }
}

void func_00245BE0(u8 *p) {
    u32 t = p[6];
    s16 *q;
    p[6] = t + 1;
    p[0x20D] = 2;
    func_00175C00(p, 0);
    *(u32 *)(p + 0x5C) = 0xC1F00000;
    if (p[0x1E6] != 0) *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0xBE892492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    p[0x1B5] = 0x39;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    q = (s16 *)((p[2] << 1) + (u32)D_004C2794);
    q[0x3E] = q[0x3E] + 1;
    func_001757E0(p, 0x14, 0);
}
