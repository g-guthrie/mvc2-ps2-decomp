typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct G { u8 pad[0x7C]; s16 t[1]; } G;
extern G *D_004C2794;
typedef struct V3 { f32 x, y, z; } V3;

void func_003509A0(u8 *p) {
    extern void func_001757E0();
    extern void func_0015B200();
    extern void func_001E3710();
    V3 v;
    u32 t = p[5];
    p[5] = t + 1;
    p[0x1B5] = 0x55;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    D_004C2794->t[p[2]] += 1;
    func_001757E0(p, 0x17, 0x26);
    v = *(V3 *)(p + 0x34);
    v.y += 51.4285698f;
    func_0015B200(p, &v, 1, 0x179);
    func_001E3710(p, 0x4A);
}

typedef struct F25 {
    u8 pad0[6];
    u8 b6;
    u8 pad1[0x34 - 7];
    f32 f34;
    f32 f38;
    u8 pad2[0x5C - 0x3C];
    f32 f5c;
    f32 f60;
    u8 pad3[0x68 - 0x64];
    f32 f68;
    f32 f6c;
    u8 pad4[0x1E6 - 0x70];
    u8 b1e6;
    u8 pad5[0x20D - 0x1E7];
    u8 b20d;
    u8 pad6[0x430 - 0x20E];
    f32 f430;
} F25;

void func_0025BA90(F25 *p) {
    f32 *a1, *a2, *a3, *t0;
    f32 k;
    a1 = &p->f5c;
    a3 = &p->f68;
    a2 = &p->f60;
    t0 = &p->f6c;
    p->f34 += p->f5c;
    p->f5c += p->f68;
    p->f38 += p->f60;
    p->f60 += p->f6c;
    if (p->f38 < p->f430) {
        u32 t = p->b6;
        p->b6 = t + 1;
        p->b20d = 0;
        *(s32 *)a1 = 0;
        *(s32 *)a2 = 0;
        *(s32 *)a3 = 0;
        *(s32 *)t0 = 0;
        p->f5c = (p->b1e6 != 0) ? -12.8571424f : 12.8571424f;
        p->f38 = p->f430;
    }
}

void func_001E7A20(u8 *a0, u8 *a1, u8 *a2) {
    extern s32 D_004C28CC, D_004C28C8, D_004C28C4, D_004C28C0;
    extern void func_001E7CB0(u8 *, u8 *, u8 *, s32, s32 *);
    u8 *h = *(u8 **)(a1 + 0x1D4);
    s32 v;
    v = *(s16 *)(h + 4) & 0x1FFF;
    if (v != 0) func_001E7CB0(a0, a1, a2, v, &D_004C28CC);
    v = *(s16 *)(h + 6) & 0x1FFF;
    if (v != 0) func_001E7CB0(a0, a1, a2, v, &D_004C28C8);
    v = *(s16 *)(h + 8) & 0x1FFF;
    if (v != 0) func_001E7CB0(a0, a1, a2, v, &D_004C28C4);
    v = *(s16 *)(h + 10) & 0x1FFF;
    if ((s16)v > 0) func_001E7CB0(a0, a1, a2, v, &D_004C28C0);
}

