typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void func_00175700();
extern void func_00365F50(u8 *);
extern u8 *D_004C2970;
void func_00365EE0(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x118) -= 0.0500000007450581f;
    if (*(f32 *)(p + 0x118) <= 0.0f) {
        u32 t = p[4]; p[4] = t + 1;
        D_004C2970[1] = 0;
        func_00365F50(p);
    }
}
extern s8 D_004C286C;
extern u8 *func_0012ABC0(s32, s32);
extern s8 func_0012A990(u8 *, s32, s32, s32);
extern void func_001E4260(s32);
void func_0012A210(u8 *p) {
    D_004C286C = func_0012A990(func_0012ABC0(3, 0), D_004C286C, 1, 2);
    if (*(s8 *)(p + 4) != D_004C286C) {
        if (D_004C286C != 0) func_001E4260(1); else func_001E4260(0);
        *(s8 *)(p + 4) = D_004C286C;
    }
}
extern u8 *func_003DA750(s32, s32, s32);
extern void func_0016CBD0();
extern u32 D_004C2820;
void func_0016CB50() {
    u8 *v = func_003DA750(0, 0xD, 1);
    if (v != 0) {
        v[0x13C] = 1;
        *(void **)(v + 0x10) = func_0016CBD0;
        *(s16 *)(v + 0xCC) = 0x17;
        *(u32 *)(v + 0x84) = D_004C2820;
        *(u32 *)(v + 0xD0) = 0x811;
        *(f32 *)(v + 0x34) = 0.0f;
        *(f32 *)(v + 0x38) = 0.0f;
        *(f32 *)(v + 0x3C) = -0.5f;
        *(f32 *)(v + 0x50) = 0.0299999993294477f;
        *(f32 *)(v + 0x54) = 0.0299999993294477f;
        *(f32 *)(v + 0x58) = 0.00999999977648258f;
    }
}

extern void func_0035ACA0();
void func_0035A2C0(u8 *p, u8 *q) {
    s32 v = *(u16 *)(q + 8);
    u8 *o = *(u8 **)(p + 0x18);
    if (v < 0) {
        *(u16 *)(q + 8) = 0xFFFF;
        func_0035ACA0();
    } else if (*(u16 *)(o + 0x160) != v) {
        func_0035ACA0();
    } else {
        s16 w = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = w;
        if (w < 0) { *(u16 *)(q + 8) = 0xFFFF; func_0035ACA0(); }
    }
}
extern void (*D_004633D0[])(u8 *, u8 *, u8 *);
void func_0035F1F0(u8 *p, u8 *q) {
    u8 *r = q + 0x2B8;
    if (q[0x1E4] == 0x1C || q[5] != 0 || q[0x1FD] != 4) {
        p[4] = 2; p[0x13C] = 0;
    } else {
        p[0x24] = *(s8 *)(q + 0x24);
        *(s8 *)(p + 0x31) = -8;
        D_004633D0[p[5]](p, q, r);
    }
}
extern void func_00183D10();
extern void func_0022C700(u8 *);
extern void func_00228D50(u8 *);
extern void func_0018C4B0(u8 *, s32);
extern void func_001757E0(u8 *, s32, s32);
extern u16 D_004C0098[4];
void func_00228A60(u8 *p) {
    { u32 t = p[6]; p[6] = t + 1; }
    p[0x20D] = 1;
    func_00183D10();
    func_0022C700(p);
    func_00228D50(p);
    func_0018C4B0(p, 0x10);
    *(s16 *)(p + 0x1C) = *((u8 *)D_004C0098 + p[0x1B7] * 2);
    *(s16 *)(p + 0x1E) = 0;
    func_001757E0(p, 0x15, (u8)(p[0x1B7] * 2 + 0x32));
}
