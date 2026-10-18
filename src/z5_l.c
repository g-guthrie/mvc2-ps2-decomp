typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { f32 a, b, c, d; } V4;
extern s8 D_004F7F32[];
extern s8 D_004C2198[8];
extern V3 D_00476AA0[];
extern V3 D_00476700[];
extern V4 D_00476A90;
extern s32 D_004C283C;

void func_003CF7C0();

void func_003CEE10(void) {
    u8 *o;
    extern u8 *func_003DA780();
    if ((o = func_003DA780(0, 0x10, 1)) != 0) {
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_003CF7C0;
        *(V3 *)(o + 0x34) = D_00476AA0[D_004F7F32[0]];
        *(V3 *)(o + 0x50) = D_00476700[D_004C2198[D_004F7F32[0]]];
        *(u32 *)(o + 0xD0) = 0x800031;
        *(V4 *)(o + 0x74) = D_00476A90;
        *(s16 *)(o + 0xCC) = 8;
        *(s32 *)(o + 0x84) = D_004C283C;
        *(u32 *)(o + 0xD8) = 0;
    }
}
