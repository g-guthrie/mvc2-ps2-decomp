typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 x[0x31]; } Blk;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad[0x7C]; s16 h7C[8]; } G57;
extern G57 *D_004C2794;

typedef struct {
    u8 pad0[1]; u8 b1; u8 b2; u8 pad3; u8 b4; u8 pad5[0x13]; u8 *src;
    u8 pad1c[4]; u8 b20; s8 b21; u8 pad22[2]; s8 b24;
} S57;

void func_00357DF0(u8 *p)
{
    extern void func_00357940();
    extern void func_00357A40();
    u32 t;
    t = p[4];
    p[4] = t + 1;
    *(Blk *)(p + 0xEC) = *(Blk *)(*(u8 **)(p + 0x18) + 0xEC);
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
    p[0x24] = 0xB;
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x1B5] = *(s8 *)(p + 0x21) + 0x34;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    { u32 i = p[2]; s16 v = D_004C2794->h7C[i] + 1; D_004C2794->h7C[i] = v; }
    func_00357940(p);
    func_00357A40();
}
