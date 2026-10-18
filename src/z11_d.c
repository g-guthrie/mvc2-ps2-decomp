typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { f32 x, y, z, w; } V4;
extern V3 D_004768A0[];
extern V3 D_00476880[1];
extern V4 D_00476890[1];
extern s8 D_004F7F32[];
extern u32 D_004C283C[1];

void func_003CEBC0(void) {
    extern u8 *func_003DA780(s32, s32, s32);
    extern void func_003CECD0(void);
    u8 *o;
    if ((o = func_003DA780(0, 16, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_003CECD0;
        *(V3 *)(o + 0x34) = D_004768A0[D_004F7F32[0]];
        *(V3 *)(o + 0x50) = D_00476880[0];
        *(u32 *)(o + 0xD0) = 0x800031;
        *(V4 *)(o + 0x74) = D_00476890[0];
        *(s16 *)(o + 0xCC) = 0x4E;
        *(u32 *)(o + 0x84) = D_004C283C[0];
        *(u32 *)(o + 0xD8) = 0;
    }
}
