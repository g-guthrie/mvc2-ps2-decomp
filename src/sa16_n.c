typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x7C]; s16 h7c[8]; } GN;
extern GN *D_004C2794;
extern u8 *D_004C2840;
extern f32 D_00474740[];
extern f32 D_00474744[];

void func_003BCB30(u8 *p) {
    extern void func_003BD840(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_00174170(void);
    extern void func_003BCE40(u8 *);
    u8 *q;
    s8 z;
    u8 *a2;
    u16 *a3;
    u8 *t0;
    s32 *t1;
    u8 *t2;
    f32 v;
    u32 t;
    s32 r;
    t = p[4];
    p[4] = t + 1;
    q = *(u8 **)(p + 0x18);
    func_003BD840(p);
    v = 55.0f;
    if (*(s16 *)(p + 0x140) == 0) v = -v;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + v;
    *(f32 *)(p + 0x38) = 205.7142791748047f + *(f32 *)(q + 0x38);
    p[0x1B0] = 0x44;
    p[0x1B1] = 0x44;
    p[0x1B5] = 0x2A;
    p[0x1B2] = z = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->h7c[p[2]] += 1;
    a2 = p + 0x1B5;
    a3 = (u16 *)(p + 0x1C0);
    t0 = p + 0x1B2;
    t1 = (s32 *)(p + 0x1D8);
    t2 = p + 2;
    if (*(u32 *)(D_004C2840 + 0x1C) & 1) {
        *a2 = 0x28;
        *a3 = 0;
        *t0 = z;
        *t1 = 0;
        D_004C2794->h7c[*t2] += 1;
    } else {
        *a2 = 0x2A;
        *a3 = 0;
        *t0 = z;
        *t1 = 0;
        D_004C2794->h7c[*t2] += 1;
    }
    *(s16 *)(p + 0x1C) = 0x60;
    func_001757E0(p, 0x19, 0x15);
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    r = func_00174170();
    v = D_00474740[(r & 7) * 2];
    if (*(s16 *)(p + 0x140) == 0) v = -v;
    *(f32 *)(p + 0x5C) = v;
    r = func_00174170();
    *(f32 *)(p + 0x60) = D_00474744[(r & 7) * 2];
    func_003BCE40(p);
}
