typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3a;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3a;
typedef struct { u8 b0; u8 b1; s16 h2; s16 h4; s16 h6; } E8a;
extern G3a *D_004C2794;
extern s16 D_004C27A4;
extern u8 D_004C1F28[8];
extern E8a D_004731D0[];
extern E8a D_004731F0[];
extern u8 D_00473320[];
extern s16 D_00473220[];
extern s16 D_00473222[];
extern s16 D_00473224[];
extern s16 D_00473226[];

void func_003AA500(u8 *o, u8 *w) {
    extern void func_00175580(u8 *, s32, s32, u8);
    extern void func_003AA2E0(u8 *, u8 *, s32);
    extern void func_003DAA40(u8 *);
    u8 *q;
    u8 *pp;
    E8a *e;
    f32 f;
    u8 b;
    s32 k;
    s32 kk;
    u32 t;
    q = *(u8 **)(o + 0x18);
    *(B3a *)(o + 0xEC) = *(B3a *)(q + 0xEC);
    o[0x13C] = 1;
    o[2] = q[2];
    o[1] = q[1];
    *(f32 *)(o + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(o + 0x54) = *(f32 *)(q + 0x54);
    o[0x1B7] = q[0x1B7];
    o[0x1B8] = q[0x1B8];
    *(s8 *)(o + 0x30) = *(s8 *)(q + 0x30);
    *(V3 *)(o + 0x50) = *(V3 *)(q + 0x50);
    *(s8 *)(o + 0x24) = *(s8 *)(q + 0x24);
    *(s8 *)(o + 0x31) = 0x64;
    o[0x13C] = 0;
    *(V3 *)(o + 0x34) = *(V3 *)(q + 0x34);
    *(s8 *)(o + 0x16A) = -1;
    pp = o + 2;
    if (o[0x20] != 0) {
        t = o[4];
        o[4] = t + 1;
        *(u8 **)(*(u8 **)(o + 0x18) + 0xA8) = o;
        return;
    }
    q[0x1FE] = 1;
    *(s16 *)(q + 0x2CA) = 0;
    w[0x34] = 0;
    e = D_004731D0;
    if (q[0x1FD] != 2) {
        e = D_004731F0;
    }
    e = &e[q[0x1B7]];
    f = 1.6666666269302368f * (f32)e->h2;
    b = e->b0;
    if (*(s16 *)(q + 0x140) != 0) {
        b = -(s8)b;
        f = -f;
    }
    o[0x22] = b;
    *(f32 *)(w + 0x18) = f;
    *(f32 *)(w + 0x1C) = 2.142857074737549f * (f32)e->h4;
    *(f32 *)(o + 0x34) += f;
    *(f32 *)(o + 0x38) += *(f32 *)(w + 0x1C);
    *(f32 *)(w + 0x10) = *(f32 *)(o + 0x34);
    *(f32 *)(w + 0x14) = *(f32 *)(o + 0x38);
    *(s32 *)(o + 0x60) = 0;
    *(s32 *)(o + 0x5C) = 0;
    *(s16 *)(o + 0x140) = *(s8 *)(o + 0x1B4) = 0;
    o[0x1B0] = 0x45;
    o[0x1B1] = 0;
    o[0x1B5] = D_004C1F28[q[0x1B7]];
    o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
    *(s32 *)(o + 0x1D8) = 0;
    { s32 x = *pp; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    w[0x32] = 0;
    k = (u8)(((o[0x22] + 4) & 0xF8) / 8);
    func_00175580(o, 0x1B, 1, k);
    *(u8 **)(o + 0x164) = D_00473320;
    kk = (u8)k * 8;
    *(u32 *)(o + 0x1D4) = *(u32 *)(o + 0x17C) + (*(u16 *)(*(u8 **)(o + 0x164) + 0x12) << 4);
    *(s16 *)(w + 0) = 1.6666666269302368f * (f32)*(s16 *)((u8 *)D_00473220 + kk);
    *(s16 *)(w + 2) = 2.142857074737549f * (f32)*(s16 *)((u8 *)D_00473222 + kk);
    *(s16 *)(w + 4) = 1.6666666269302368f * (f32)*(s16 *)((u8 *)D_00473224 + kk);
    *(s16 *)(w + 6) = 2.142857074737549f * (f32)*(s16 *)((u8 *)D_00473226 + kk);
    w[0xE] = 0;
    w[0xF] = 0;
    *(s32 *)(w + 0x28) = 0;
    if (D_004C27A4 >= 0xE) {
        func_003AA2E0(o, w, 0xE);
        t = o[4];
        o[4] = t + 1;
        w[0x34] = 1;
        return;
    }
    q[6] = 3;
    func_003DAA40(o);
}
