typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G;
extern G *D_004C2794;

void func_00352460(u8 *p) {
    extern void func_001757E0();
    u8 *q;
    u8 c;
    p[0x13C] = 1;
    q = *(u8 **)(p + 0x18);
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    *(u32 *)(p + 0x48) = 0x8000;
    *(u32 *)(p + 0x60) = 0x41892492;
    *(f32 *)(p + 0x38) += 171.4285583f;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x5C) = 0;
    p[0x24] = 0;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    *(s16 *)(p + 0x1C) = 0x78;
    p[0x14E] = 0x10;
    p[0x14F] = 0x10;
    p[0x14D] = 0x30;
    p[0x14C] = 0x30;
    c = 0x42;
    if (*(u8 *)(*(u8 **)(p + 0x18) + 0x269) == 3) c = 0x49;
    p[0x1B5] = c;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    func_001757E0(p, 0x14, 1);
}

void func_002CA7E0(u8 *p, u8 *q) {
    extern s8 func_00175700();
    extern void func_001CEA00(u8 *, s32);
    extern void func_0039B7E0(u8 *, s32);
    extern void func_001757E0();
    u32 t;
    f32 v;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (func_00175700(p) < 0) {
        t = p[7];
        p[7] = t + 1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        v = (p[0x1E6] != 0) ? 15.0f : -15.0f;
        *(f32 *)(p + 0x5C) = v;
        p[0x1B5] = 0x41;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(u32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[p[2]]++;
        q[5] = 2;
        *(s16 *)(p + 0x1C) = 0x60;
        *(s16 *)(p + 0x1E) = 7;
        *(u32 *)(p + 0x14) = 0;
        func_001CEA00(p, 0xB);
        func_0039B7E0(p, 0);
        func_001757E0(p, 0x15, 0x19);
    }
}

typedef struct {
    u8 pad[0x34]; f32 f34; f32 f38; u8 pad3c[0x220 - 0x3C]; struct R1 *r220; u8 pad224[0x430 - 0x224]; f32 f430;
} R0;
struct R1 { u8 pad[0x34]; f32 f34; };

void func_003B8290(u8 *p) {
    extern void func_003B9220();
    extern void func_001757E0();
    R0 *q = *(R0 **)(p + 0x14);
    struct R1 *r = q->r220;
    f32 v, w;
    func_003B9220(p);
    p[0x24] = 0xB;
    p[0x13C] = 0;
    *(f32 *)(p + 0x34) = q->f34;
    *(f32 *)(p + 0x38) = 274.28570556640625f + q->f38;
    v = (r->f34 - q->f34) / 8.0f;
    w = v / 2.0f;
    v += w;
    *(f32 *)(p + 0x5C) = v;
    *(u32 *)(p + 0x68) = 0;
    v = (q->f430 - *(f32 *)(p + 0x38)) / 8.0f;
    w = v / 2.0f;
    *(f32 *)(p + 0x60) = v + w;
    *(u32 *)(p + 0x6C) = 0;
    p[0x1B5] = 0x37;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    D_004C2794->f7c[p[2]]++;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    func_001757E0(p, 0x17, 0x16);
}
