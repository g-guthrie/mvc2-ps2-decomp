typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef float f32;


extern u8 D_004D18A0[];
extern void (*D_00477420[])(void *);
extern u8 *D_004C2840;
extern void func_003D94B0();
extern void func_003D9AF0();
void func_003D8080(void) {
    D_00477420[D_004D18A0[0]](D_004D18A0);
    func_003D94B0();
    if (*(s8 *)(D_004C2840 + 0xAA) != 0) func_003D9AF0();
}


extern u8 *D_00444940[];
extern s32 D_00444950[];
extern u8 *D_004C2838;
extern void func_003DAA40();
void func_00154400(u8 *p) {
    s16 i;
    *(s16 *)(p + 0xCC) = *(s16 *)(D_00444940[0] + *(s16 *)(p + 0x1C) * 4);
    *(u8 **)(p + 0x84) = D_004C2838;
    i = *(s16 *)(p + 0x1C) + 1;
    *(s16 *)(p + 0x1C) = i;
    if (i >= D_00444950[0]) func_003DAA40(p);
}

extern void (*D_004C1BA8[2])(void *, void *);
extern s32 func_00174470();
void func_0035FCA0(u8 *p, u8 *q) {
    u8 *r = q;
    u8 k = r[0x169];
    if (k != 0x16) {
        u32 t = p[4];
        p[4] = t + 1;
    } else if (func_00174470(p) == 0) {
        u32 t = p[4];
        p[4] = t + 1;
    } else {
        D_004C1BA8[p[5]](p, r);
    }
}

extern u8 *D_004C2794;
extern void func_002803A0();
extern s32 func_00280350();
extern void func_00175700();
void func_0027FEC0(u8 *p) {
    if (D_004C2794[0] >= 6 && *(s8 *)(p + 0x20C) == 0) {
        p[0x20C] = 1;
        func_002803A0(p, 0x16);
    } else if (func_00280350(p, 0) == 0) {
        func_00175700(p);
        if (*(f32 *)(p + 0x38) > *(f32 *)(p + 0x430)) *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    }
}
