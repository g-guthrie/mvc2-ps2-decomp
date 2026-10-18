typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 pad[0x160]; s8 b[8]; } S39;

extern u8 *D_004C2794;

void func_0039B570(u8 *p)
{
    extern s8 func_00175700(u8 *);
    extern void func_001E3710(u8 *, s32);
    extern void func_001E7F60(u8 *);
    S39 *a = (S39 *)p;
    s8 *b0, *q;
    s8 f;
    u32 offset;
    f32 v;
    func_00175700(p);
    b0 = a->b;
    f = b0[1];
    q = b0 + 1;
    if (f != 0) {
        u32 t = p[5];
        p[5] = t + 1;
        *q = 0;
        p[0x1B5] = 0x3F;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (u32)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
        *(s16 *)(p + 0x1E) = 2;
        if (*(s16 *)(p + 0x140) != 0) {
            v = 23.333332061767578f;
        } else {
            v = -23.333332061767578f;
        }
        *(f32 *)(p + 0x5C) = v;
        if (*(s16 *)(p + 0x140) != 0) {
            v = -0.8333333134651184f;
        } else {
            v = 0.8333333134651184f;
        }
        *(f32 *)(p + 0x68) = v;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x6C) = 0;
        func_001E3710(p, 0x29);
    }
    func_001E7F60(p);
}

void func_001D3370(u8 *p, u8 *q)
{
    extern s32 func_00174470(u8 *);
    u32 t;
    switch (p[5]) {
    case 0:
        func_00175700(p);
        if (*(s8 *)(p + 0x151) == 0) {
            return;
        }
        t = p[5];
        p[5] = t + 1;
        p[0x151] = 0;
    case 1:
        if (*(s8 *)(q + 0x151) == 0) {
            return;
        }
        t = p[5];
        p[5] = t + 1;
    case 2:
        func_00175700(p);
        if (*(s8 *)(p + 0x151) != 0) {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
            *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
            *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
            if (func_00174470(p) == 0) {
                p[4] = 2;
                p[5] = 0;
                p[0x13C] = 0;
            }
        }
        break;
    }
}

typedef struct { u8 pad[0x1C]; u32 f1C; } G2840;
extern G2840 *D_004C2840;

void func_00267980(u8 *p, u8 *q)
{
    extern void func_00176160(u8 *, s32, s32, s32);
    extern void func_00175C00(u8 *, s32);
    extern void func_00185490(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00191210(u8 *);
    f32 c = 0.019999999552965164f;
    *(f32 *)(q + 0xC) -= c;
    *(f32 *)(q + 0x14) -= c;
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0xC);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x14);
    if ((D_004C2840->f1C & 1) == 0) {
        func_00176160(p, 0, p[0x25] + 6, 1);
    } else {
        func_00175C00(p, 8);
    }
    if (*(f32 *)(p + 0x54) < 0.5f) {
        u32 t;
        *(f32 *)(q + 0xC) = 1.0f;
        *(f32 *)(q + 0x14) = 1.0f;
        *(f32 *)(p + 0x50) = *(f32 *)(q + 0xC);
        *(f32 *)(p + 0x54) = *(f32 *)(q + 0x14);
        t = p[7];
        p[7] = t + 1;
        func_00185490(p);
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x216] = 0;
        func_00175C00(p, 0);
        func_001757E0(p, 0x16, 0x3D);
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
    } else {
        p[0x216] |= 0x80;
        p[0x1FF] = 2;
        func_00191210(p);
    }
}

void func_003B9930(u8 *p)
{
    extern void func_003BA140(u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *q;
    u32 offset;
    q = *(u8 **)(p + 0x18);
    func_003BA140(p);
    p[0x24] = 10;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x14D] = 0xD4;
    p[0x14C] = 0xD4;
    p[0x14D] = 1;
    p[0x14D] = 1;
    p[0x14D] = 0x40;
    p[0x14E] = 0x40;
    p[0x14F] = 0x40;
    p[0x14F] = 0x40;
    p[0x13C] = 0;
    *(f32 *)(p + 0x38) += 480.0f;
    *(s16 *)(p + 0x1C) = 2;
    if ((*(u8 **)(p + 0x14))[0x269] == 8) {
        p[0x1B5] = 0x32;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (u32)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
    } else {
        p[0x1B5] = 0x31;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        offset = p[2] * 2;
        offset += (u32)D_004C2794;
        ++*(s16 *)(offset + 0x7C);
    }
    if (p[0x21] == 0) {
        func_001757E0(p, 0x15, 0x15);
    } else {
        func_001757E0(p, 0x15, (u8)((u8)p[0x21] + 0x11));
    }
}

void func_002CEEB0(u8 *p)
{
    extern void func_00175700(u8 *);
    extern void func_002CEC90(u8 *);
    f32 v, z, w;
    f32 *q5c, *q68;
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    q5c = (f32 *)(p + 0x5C);
    q68 = (f32 *)(p + 0x68);
    z = 0.0f;
    v = *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x34) += v;
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (*(f32 *)(p + 0x5C) * v < z) {
        *q5c = z;
    }
    *(s32 *)q68 = 0;
    func_00175700(p);
    func_002CEC90(p);
    if (*(s8 *)(p + 0x151) == 2) {
        p[0x151] = 0;
        if (p[0x1E6] != 0) {
            v = 16.666666030883789f;
        } else {
            v = -16.666666030883789f;
        }
        *(f32 *)(p + 0x5C) = v;
        if (p[0x1E6] != 0) {
            w = -0.625f;
        } else {
            w = 0.625f;
        }
        *(f32 *)(p + 0x68) = w;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        t = p[6];
        p[6] = t + 1;
        if (p[0x1E6] != 0) {
            v = 20.0f;
        } else {
            v = -20.0f;
        }
        *(f32 *)(p + 0x5C) = v;
        if (p[0x1E6] != 0) {
            w = -0.625f;
        } else {
            w = 0.625f;
        }
        *(f32 *)(p + 0x68) = w;
        *(u32 *)(p + 0x60) = 0x42092492;
        *(u32 *)(p + 0x6C) = 0xBF892492;
    }
}
