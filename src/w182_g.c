typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef float f32;

typedef struct { u8 pad[0x88]; u8 b[0x10]; } S3C;
typedef struct { s32 x[0x31]; } Blk31;
typedef struct { f32 x, y, z; } V3;
#pragma padloop on
extern u8 D_004B8730[];

void func_0039CB60(u8 *p)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_0039CC90(u8 *);
    u32 t;
    u8 *r;
    t = p[4];
    r = ((S3C *)p)->b;
    p[4] = t + 1;
    *(Blk31 *)(p + 0xEC) = *(Blk31 *)(*(u8 **)(p + 0x18) + 0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    p[0x30] = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    p[0x24] = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    p[0x13C] = 1;
    if (r[0xD] != 0) {
        p[0x24] = 7;
        *(s16 *)(p + 0x1C) = 7;
    } else {
        p[0x24] = 0;
        *(s16 *)(p + 0x1C) = 0;
    }
    func_001757E0(p, 0x17, D_004B8730[r[0xD]]);
    func_0039CC90(p);
}

void func_001D0A70(u8 *p, u8 *q)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern s8 func_00175700(u8 *);
    extern void func_003DAA40(u8 *);
    if (p[4] == 0) {
        p[4]++;
        p[0x151] = 0;
        p[6] = 0;
        *(Blk31 *)(p + 0xEC) = *(Blk31 *)(q + 0xEC);
        p[0x13C] = 1;
        p[2] = q[2];
        p[1] = q[1];
        *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
        p[0x1B7] = q[0x1B7];
        p[0x1B8] = q[0x1B8];
        p[0x30] = *(s8 *)(q + 0x30);
        *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
        p[0x24] = *(s8 *)(q + 0x24);
        *(s8 *)(p + 0x31) = -1;
        p[0x13C] = 1;
        func_001757E0(p, 0x17, 4);
    }
    p[0x24] = *(s8 *)(q + 0x24);
    if (q[0x169] == 0x15) {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
        if (func_00175700(p) < 0) {
            func_003DAA40(p);
        }
    } else {
        func_003DAA40(p);
    }
}

typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G94;
extern G94 *D_004C2794;
extern u8 *D_004C2938;

void func_003464A0(u8 *p)
{
    extern void func_00346110(u8 *);
    u8 *r;
    p[4]++;
    *(Blk31 *)(p + 0xEC) = *(Blk31 *)(*(u8 **)(p + 0x18) + 0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    p[0x30] = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    p[0x24] = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    r = p + 2;
    if (p[1] != (*(u8 **)(p + 0x18))[1]) {
        p[4] = 2;
        p[0x13C] = 0;
    } else {
        p[0x13C] = 0;
        p[0x22] = 0xC;
        p[0x1B0] = 0x42;
        p[0x1B1] = 0x42;
        p[0x24] = 0xB;
        *(s8 *)D_004C2938 = -1;
        D_004C2938[5] = 0;
        D_004C2938[1] = 1;
        p[0x1B5] = 0x56;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[r[0]]++;
        func_00346110(p);
    }
}
