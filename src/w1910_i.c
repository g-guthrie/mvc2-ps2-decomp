typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
extern V3 D_00460640[][4];
extern s32 D_004606A0[][4];
typedef struct { s16 a, b; } P2_i;
extern P2_i D_00460620[];
extern s32 D_004C283C;

void func_003423E0(u8 *p)
{
    extern s32 func_00417A40();
    s16 v;
    s32 r;
    s32 k;
    v = *(s16 *)(p + 0x1E) + 1;
    *(s16 *)(p + 0x1E) = v;
    if (v >= 2) {
        *(s16 *)(p + 0x1E) = 0;
        v = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = v;
        if ((u32)v >= 8) {
            *(s16 *)(p + 0x1C) = 0;
            r = func_00417A40();
            k = r % 4;
            *(V3 *)(p + 0x34) = D_00460640[p[0x20]][k];
            *(s32 *)(p + 0x44) = D_004606A0[p[0x20]][k];
        }
        *(s16 *)(p + 0xCC) = D_00460620[*(s16 *)(p + 0x1C)].a;
        *(s32 *)(p + 0x84) = D_004C283C;
    }
}
