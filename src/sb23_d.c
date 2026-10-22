typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { s32 x[0x31]; } Blk31;
typedef struct { f32 x, y, z; } V3;

typedef struct { u8 pad[0x7C]; s16 f7c[2]; } G94;
extern G94 *D_004C2794;
extern u8 *D_004C299C;

void func_0037F930(u8 *p)
{
    extern void func_0037F480(u8 *);
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
        if (D_004C299C[6] == 0) {
            p[0x14C] = 0x10;
            p[0x14D] = 0x10;
            p[0x14E] = 0x10;
            p[0x14F] = 0x80;
        } else {
            p[0x14C] = 0x10;
            p[0x14D] = 0x10;
            p[0x14E] = 0x10;
            p[0x14F] = 0x10;
        }
        *(s8 *)D_004C299C = -1;
        D_004C299C[5] = 0;
        D_004C299C[1] = 1;
        p[0x1B5] = 0x35;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        D_004C2794->f7c[r[0]]++;
        func_0037F480(p);
    }
}
