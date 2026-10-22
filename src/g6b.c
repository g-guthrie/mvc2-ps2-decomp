typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void func_0018F1A0(u8, s32, f32 *);
void func_0018ED20(u8 *p, s32 q) {
    f32 v[2];
    func_0018F1A0(p[0x242], q, v);
    if (p[0x1BA]) v[0] = -v[0];
    *(f32 *)(p + 0x22C) = v[0];
    *(u32 *)(p + 0x68) = 0;
    *(f32 *)(p + 0x230) = v[1];
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
}
extern int func_003DA750(s32, s32, s32);
extern void func_00399790();
void func_00399720(s32 a, u8 b) {
    u8 *o = (u8 *)func_003DA750(0, 1, 0);
    if (o) {
        *(void **)(o + 0x10) = func_00399790;
        *(s32 *)(o + 0x18) = a;
        o[0x20] = 1;
        o[0x21] = b;
        *(s16 *)(o + 0x26) = 0x2600;
    }
}
extern void func_00175700();
extern int func_00174470(const void *);
void func_001A9E60(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (func_00174470(p) == 0) {
        p[6] = 5; p[7] = 0; p[0] = 0; p[0x13C] = 0;
    }
}
extern void func_001E3210(u8 *, s32);
extern void func_00175700();
void func_002466E0(u8 *p) {
    s16 v;
    u32 t;
    if (*(s16 *)(p + 0x1C) == 0x3C) func_001E3210(p, 0x21);
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        func_001E3210(p, 0x2B);
        t = p[6];
        p[6] = t + 1;
    }
}
extern u8 *func_00147870(s32, s32);
u8 *func_00148AA0(s32 x) {
    u8 *o = 0;
    if (x == 13) {
        o = func_00147870(4, 5); o[0x21] = x;
        o = func_00147870(4, 6); o[0x21] = x;
    } else if (x < 9) {
        o = func_00147870(0, 5); o[0x21] = x;
        o = func_00147870(0, 6); o[0x21] = x;
    }
    return o;
}
extern void func_00175670(u8 *);
extern int func_00174240(u8 *);
void func_001B4F30(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175670(p);
    if (func_00174240(p) == 0) p[4] = 2;
}
extern void func_00175580(u8 *, s32, s32, s32);
extern u8 D_0044C0E0[];
void func_001BDD10(u8 *p, void *q_context) {
    u8 *q = (u8 *)q_context;
    if (q[4] >= 2) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else {
        s8 v = *(s8 *)(q + 0x151);
        p[0x13C] = v;
        if (v != 0) {
            u8 *tb;
            *(s32 *)(p + 0x48) = *(s32 *)(q + 0x48);
            tb = D_0044C0E0 + p[0x20] * 6;
            func_00175580(p, 0x1B, tb[5], *(s8 *)(q + 0x150));
        }
    }
}
extern void func_001266A0(u8 *, s32, s32);
extern void func_0015D010(u8 *, u32 *);
extern void func_0018C6E0(void *);
extern void func_001757E0(u8 *, s32, s32);
void func_001F64B0(u8 *p) {
    u32 v[4];
    p[7] = 0;
    p[6] = 0;
    *(s16 *)(p + 0x1C) = 0x3C;
    *(s16 *)(p + 0x1E) = 0;
    func_001266A0(p, 5, 5);
    v[0] = 0xC3200000;
    v[1] = 0x432B6DB6;
    func_0015D010(p, v);
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 6);
}
extern void func_0018C6E0(void *);
extern void (*D_004510F8[])(u8 *, u8 *);
void func_0021B900(u8 *p) {
    u8 *q = *(u8 **)(p + 0x1DC);
    func_0018C6E0(p);
    p[0x201] = 3;
    p[0x2C4] = 0;
    *(s16 *)(q + 0x140) = *(s16 *)(p + 0x140);
    *(s16 *)(q + 0x140) ^= 1;
    q[0x1E6] = *(s8 *)(q + 0x140);
    D_004510F8[p[0x20B]](p, q);
}
extern int func_003DA750(s32, s32, s32);
extern void func_001DAFB0();
void func_001DAF30(u8 *p, u8 b) {
    u8 *o = (u8 *)func_003DA750(0, 3, 0);
    if (o) {
        *(void **)(o + 0x10) = func_001DAFB0;
        *(u8 **)(o + 0x18) = p;
        o[1] = p[1];
        o[0x20] = b;
        *(s16 *)(o + 0x26) = 0x3500;
        *(f32 *)(o + 0x34) = *(f32 *)(p + 0x34);
        *(f32 *)(o + 0x38) = *(f32 *)(p + 0x38);
        *(u16 *)(o + 0x1C) = *(u16 *)(p + 0x168);
    }
}
extern void func_00178F20(u8 *, u8 *);
void func_00207E90(u8 *p) {
    u8 *q = *(u8 **)(p + 0x1DC);
    s8 *r;
    p[0x13C] = 1;
    r = (s8 *)(q + 0x160);
    if (*r == 2) p[0x13C] = 0;
    func_00178F20(q, p);
    if (r[1] == 0x24) *(f32 *)(p + 0x34) += *(f32 *)(q + 0x64);
}
extern void func_002CEC90(u8 *);
extern void func_002CEC40();
extern void func_00183d50();
extern void func_002CF190(u8 *);
void func_002CF110(u8 *p) {
    func_002CEC90(p);
    func_002CEC40();
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00183d50();
        func_002CF190(p);
    } else if (*(s8 *)(p + 0x151) == 0) {
        func_00175700();
    }
}
extern void func_0015B200(u8 *, f32 *, s32, s32);
extern void func_001E3710(u8 *, s32);
void func_00386570(u8 *p, u8 *q) {
    f32 v[3];
    v[2] = 0.0f;
    v[1] = 0.0f;
    v[0] = 0.0f;
    p[4] = (u32)p[4] + 1;
    q[0x2BD] = 0;
    if (*(s16 *)(p + 0x140) == 0) v[0] = *(f32 *)(p + 0x34);
    else v[0] = *(f32 *)(p + 0x34);
    v[1] = *(f32 *)(p + 0x38);
    func_0015B200(p, v, 1, 8);
    func_001E3710(p, 0x49);
}
extern void func_0016B0C0(u8 *, u8 *, s32);
extern u32 func_00174170();
extern void func_00166C80(u8 *, u8 *, s32);
void func_001665C0(u8 *p, u8 *q) {
    u32 r;
    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 1);
    r = func_00174170();
    func_00166C80(p, q, *(u32 *)(p + 0x4C8) >= (r & 0x1F));
}
extern void func_00186A60(u8 *, s32);
void func_002C4F50(u8 *p) {
    p[5] = 0; p[7] = 0; p[6] = 0;
    switch (*(s8 *)(p + 0x4DD)) {
    case 0: p[0x1FD] = 0; p[0x1B7] = 1; break;
    case 1: p[0x1FD] = 1; p[0x1B7] = 0; break;
    case 2: p[0x1FD] = 2; p[0x1B7] = 0; break;
    }
    func_00186A60(p, 0x15);
}
