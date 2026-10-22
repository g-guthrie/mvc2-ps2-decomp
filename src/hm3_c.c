typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad0[0x7C]; s16 h7c[1]; } G3A;
extern s8 *D_004C2840;
extern G3A *D_004C2794;

void func_003A2100(u8 *p) {
    extern s8 func_00175700(u8 *);
    extern s32 func_00174170(void);
    u32 t;
    if (func_00175700(p) >= 0) {
        return;
    }
    t = p[5];
    p[5] = t + 1;
    if ((*(s32 *)(D_004C2840 + 0x1C) & 3) != 0) {
        p[0x1B5] = 0x39;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->h7c[p[2]]++;
    } else {
        p[0x1B5] = 0x35;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->h7c[p[2]]++;
    }
    p[0x22] = func_00174170() & 0xF;
    if (*(s16 *)(p + 0x140) == 0) {
        t = p[0x22];
        p[0x22] = t + 0x10;
    }
    if (p[0x20] == 0) {
        *(s32 *)(p + 0xD0) = (func_00174170() & 3) * 100 + 0x3E8;
    } else {
        *(s32 *)(p + 0xD0) = (func_00174170() & 3) * 100 + 0x708;
    }
}

void func_003192C0(u8 *p) {
    extern s32 func_00175700(u8 *);
    extern void func_00183d50(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00319980(u8 *);
    f32 orig;
    f32 prod;
    f32 *pa;
    f32 *pb;
    f32 *pc;
    f32 *pd;
    pd = (f32 *)(p + 0x6C);
    pc = (f32 *)(p + 0x68);
    pb = (f32 *)(p + 0x60);
    pa = (f32 *)(p + 0x5C);
    *(u8 *)(p + 0x40C) = 2;
    *(u8 *)(p + 0x33C) = 5;
    orig = *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += orig;
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    prod = orig * *(f32 *)(p + 0x5C);
    if (prod < 0.0f) {
        *pa = 0.0f;
        *pc = 0.0f;
    }
    func_00175700(p);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        if (*(s8 *)(p + 0x2BD) == 0) {
            *(u8 *)(p + 0x40D) = 0;
            *(u8 *)(p + 0x40C) = 0;
            *(u8 *)(p + 0x33B) = 0;
            *(u8 *)(p + 0x33C) = 0;
        }
        {
            u32 t = p[6];
            p[6] = t + 1;
        }
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(u8 *)(p + 0x20D) = 0;
        func_00183d50(p);
        *(s32 *)pa = 0;
        *(s32 *)pb = 0;
        *(s32 *)pc = 0;
        *(s32 *)pd = 0;
        func_001757E0(p, 1, 3);
    }
    func_00319980(p);
}
