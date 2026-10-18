typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { f32 x, y, z, w; } V4;
extern s8 D_004F7F31[];
extern V3 D_00476800[];
extern V3 D_00476700[];
extern V4 D_004767F0;
extern s8 D_004C2190[2];
extern u32 D_004C283C;

u8 *func_003CE780(void) {
    extern u8 *func_003DA780(s32, s32, s32);
    extern void func_003CE8B0(void);
    u8 *o = func_003DA780(0, 0x10, 1);
    if (o != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_003CE8B0;
        *(V3 *)(o + 0x34) = D_00476800[D_004F7F31[0]];
        *(V3 *)(o + 0x50) = D_00476700[D_004C2190[D_004F7F31[0]]];
        *(u32 *)(o + 0xD0) = 0x800031;
        *(V4 *)(o + 0x74) = D_004767F0;
        *(s16 *)(o + 0xCC) = 8;
        *(u32 *)(o + 0x84) = D_004C283C;
        *(u32 *)(o + 0xD8) = 0;
    }
    return o;
}
