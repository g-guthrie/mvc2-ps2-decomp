typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s8 b0; u8 pad[7]; f32 f8, fC; } G;
extern G *D_004C299C;
extern s16 D_00464300[];

void func_0037F2C0(u8 *p) {
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x34) += D_004C299C->f8;
    *(f32 *)(p + 0x38) += D_004C299C->fC;
    if (*(s16 *)(p + 0x140) == 0) {
        *(f32 *)(p + 0x34) += 1.6666666269302368f * (f32)D_00464300[D_004C299C->b0];
    } else {
        *(f32 *)(p + 0x34) -= 1.6666666269302368f * (f32)D_00464300[D_004C299C->b0];
    }
}
