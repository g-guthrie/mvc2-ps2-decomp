typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x7C]; s16 h[8]; } G;
typedef struct { s16 a; s16 b; } E2;

extern V3 D_0043DF64[];
extern u8 *D_004C2834;
extern u8 D_004D18A0[];
extern G *D_004C2794;
extern E2 D_004C00B8[2];

void func_00133020(u8 *p) {
    extern void func_003DAA40(void *);
    u8 *q;
    f32 f;
    u32 idx;
    p[0x13C] = 1;
    q = *(u8 **)(p + 0x18);
    idx = (q[2] << 1) + q[0x425];
    *(V3 *)(p + 0x34) = D_0043DF64[idx];
    f = -56.0f * *(f32 *)(*(u8 **)(p + 0x14) + 0x50);
    if (p[0x20] & 1) f = -f;
    *(f32 *)(p + 0x34) = f + *(f32 *)(p + 0x68);
    *(u8 **)(p + 0x84) = *(u8 **)(D_004C2834 + 0x14) + ((*(s16 *)(p + 0x1C) >> 3) + 0x50) * 180;
    *(s16 *)(p + 0xCC) = (*(s16 *)(p + 0x1C) >> 3) + 0x50;
    *(u8 **)(p + 0x84) = D_004C2834;
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    if (*(s16 *)(p + 0x1C) < 0x29 && q[0x425] != 0 && D_004D18A0[0] == 4) {
        return;
    }
    p[0x13C] = 0;
    func_003DAA40(p);
}

void func_001F5C10(u8 *s0) {
    extern void func_00175700(void *);
    extern void func_001757E0(void *, s32, s32, s32);
    s0[0x40C] = 2;
    s0[0x33C] = 5;
    if (s0[0x15B] == 0) {
        s0[0x20D] = 2;
        *(f32 *)(s0 + 0x34) += *(f32 *)(s0 + 0x5C);
        *(f32 *)(s0 + 0x5C) += *(f32 *)(s0 + 0x68);
        *(f32 *)(s0 + 0x38) += *(f32 *)(s0 + 0x60);
        *(f32 *)(s0 + 0x60) += *(f32 *)(s0 + 0x6C);
    }
    if (*(f32 *)(s0 + 0x60) < 0.0f) {
        u32 t;
        s0[0x40D] = 0;
        s0[0x40C] = 0;
        s0[0x33B] = 0;
        s0[0x33C] = 0;
        t = s0[6];
        t++;
        s0[6] = t;
        *(u32 *)(s0 + 0x60) = 0xC1092492;
        *(u32 *)(s0 + 0x6C) = 0xBF092492;
        func_001757E0(s0, 0x15, 0xD, t);
    }
    if (*(s8 *)(s0 + 0x151) != 0) {
        s0[0x1B5] = *(s8 *)(s0 + 0x151);
        s0[0x1B2] = *(u16 *)(s0 + 0x1C0) = 0;
        *(u32 *)(s0 + 0x1D8) = 0;
        D_004C2794->h[s0[2]]++;
        s0[0x151] = 0;
    }
    func_00175700(s0);
}

void func_00229FD0(u8 *s0) {
    extern void func_00175700(void *);
    extern s32 func_0018AB10(void *);
    extern void func_001757E0(void *, s32, s32);
    f32 z = 0.0f;
    func_00175700(s0);
    *(f32 *)(s0 + 0x38) += *(f32 *)(s0 + 0x60);
    *(f32 *)(s0 + 0x60) += *(f32 *)(s0 + 0x6C);
    if (*(f32 *)(s0 + 0x38) > *(f32 *)(s0 + 0x430) + 2.142857074737549f * (f32)*(s16 *)(s0 + 0x1E)) {
        if (*(s8 *)(s0 + 0x539) == 0) {
            if (*(u16 *)(s0 + 0x362) & *(u32 *)(s0 + 0x2E0)) goto body;
        } else {
            if (func_0018AB10(s0)) goto body;
        }
    }
    if (*(f32 *)(s0 + 0x60) <= z) {
body:
        {
            u32 t = s0[6];
            s0[6] = t + 1;
            *(s16 *)(s0 + 0x1C) = D_004C00B8[s0[0x1B7]].a;
            func_001757E0(s0, 0x15, 0x2D);
        }
    }
}
