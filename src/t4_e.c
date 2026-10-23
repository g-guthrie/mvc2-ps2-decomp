typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef float f32;

extern s32 func_00175700();
extern void func_001757E0(void *p, s32 a, s32 b);

extern void func_00126400();

void func_002DFA20(u8 *p, u8 *state_unused) {
    u32 t;
    p[0x33C] = 5;
    p[0x209] = 2;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            t = p[7];
            p[7] = t + 1;
            *(s16 *)(p + 0x1C) = 8;
            *(u32 *)(p + 0x5C) = 0xC1D55555;
            if (p[0x1E6] != 0) {
                *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
            }
            func_00126400();
            p[0x33B] = 0;
            p[0x33C] = 0;
        }
    }
}

extern void func_00183d50();
extern void func_001E3210();

void func_00264760(u8 *p) {
    u32 t;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_001757E0(p, 1, 3);
        func_00183d50(p);
        func_001E3210(p, 0xA);
    }
}


extern f32 D_004F1FD8[];
extern f32 D_004F1FDC[];
extern const u8 *const D_004554E0[];
extern u32 func_00174170();

s32 func_00280F80(u8 *p) {
    u32 r;
    if (*(u32 *)(p + 0x4C4) & 2) return 0;
    if (*(f32 *)(p + 0x34) <= D_004F1FD8[0] || !(*(f32 *)(p + 0x34) < D_004F1FDC[0])) {
        *(u32 *)(p + 0x4C4) |= 2;
        p[0x450] = 2;
        p[0x451] = 0;
        p[0x452] = 0;
        p[0x453] = 0;
        p[0x495] = 1;
        p[0x496] = 1;
        r = func_00174170();
        *(const u8 **)(p + 0x484) = D_004554E0[r & 3];
        return 1;
    }
    return 0;
}

extern void func_003A2AE0();
extern u32 D_004C2794;
extern void (*D_00472B68[])(void *p, void *q);

void func_003A2D60(u8 *p, u8 *q) {
    s16 *e;
    s16 t;
    if (p[4] == 0) {
        func_003A2AE0();
        p[0x1B5] = 0x3A;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        e = (s16 *)((p[2] << 1) + D_004C2794);
        t = e[0x3E];
        e[0x3E] = t + 1;
        func_001757E0(p, 0x16, 3);
        *(s8 *)(p + 0x31) = -8;
    }
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    D_00472B68[p[5]](p, q);
}
