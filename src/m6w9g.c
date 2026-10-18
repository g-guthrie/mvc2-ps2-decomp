typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;


extern V3 D_00442890[];
extern f32 D_0043DD10[];
extern f32 D_004F7FD0[];
extern f32 D_004F7FD4[];
extern s32 D_004F7FD8[];
extern s32 D_004C2804[1];
void func_00147320(u8 *p) {
    u32 t = p[4];
    p[4] = t + 1;
    p[0x13C] = 1;
    *(V3 *)(p + 0x50) = D_00442890[0];
    *(s16 *)(p + 0xCC) = 0x43;
    *(s32 *)(p + 0x84) = D_004C2804[0];
    *(s32 *)(p + 0xD0) = 0x439;
    *(f32 *)(p + 0x34) = D_004F7FD0[0] / 10.0f;
    *(f32 *)(p + 0x38) = -(D_004F7FD4[0] / 10.0f);
    *(f32 *)(p + 0x50) = *(f32 *)(p + 0x54) = D_0043DD10[D_004F7FD8[0]];
}
