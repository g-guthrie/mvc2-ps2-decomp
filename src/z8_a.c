typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern V3 D_004B338C;
extern f32 D_004B3380[];

static void func_00144CB0(u8 *p) {
    f32 *b = D_004B3380 + 3;
    *(f32 *)(p + 0x34) = D_004B3380[0] +
        (f32)*(s16 *)(p + 0x1C) * (b[0] - D_004B3380[0]) / 30.0f;
    *(f32 *)(p + 0x38) = D_004B3380[1] +
        (f32)*(s16 *)(p + 0x1C) * (b[1] - D_004B3380[1]) / 30.0f;
    *(f32 *)(p + 0x3C) = D_004B3380[2] +
        (f32)*(s16 *)(p + 0x1C) * (b[2] - D_004B3380[2]) / 30.0f;
}

void func_00144F50(u8 *p) {
    s16 v = *(s16 *)(p + 0x1C) + 1;
    *(s16 *)(p + 0x1C) = v;
    func_00144CB0(p);
    if (*(s16 *)(p + 0x1C) == 30) {
        u32 t = p[4];
        p[4] = t + 1;
        *(s16 *)(p + 0x1C) = 0;
        *(V3 *)(p + 0x34) = D_004B338C;
    }
}

void func_00247210(u8 *p) {
    extern void func_00175700();
    extern void func_001830D0();
    s32 a;
    u32 v[3];
    *(u8 *)(p + 0x40C) = 2;
    *(u8 *)(p + 0x33C) = 5;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    a = *(s8 *)(p + 0x151);
    if (a & 1) {
        u32 t;
        p[0x151] = a & 0x7E;
        t = p[6] + 1;
        p[6] = t;
        v[0] = 0xC1D55555;
        v[1] = 0x43362492;
        v[2] = 0;
        p[0x404] = 0;
        p[0x405] = 0;
        func_001830D0(p, v, 1, t);
    }
}
