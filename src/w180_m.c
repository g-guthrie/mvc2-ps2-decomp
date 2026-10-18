typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern V3 D_00440300[];
extern s32 D_004C2830;

void func_0013B1C0(u8 *p) {
    u8 *o;
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_0013B2B0();
    o = func_003DA750(0, 6, 1);
    if (o != 0) {
        o[0x13C] = 1;
        *(u8 **)(o + 0x18) = p;
        *(u8 **)(o + 0xC8) = p + 0x88;
        o[0x20] = p[0x20];
        o[0x21] = p[0x21];
        *(void **)(o + 0x10) = func_0013B2B0;
        *(s16 *)(o + 0xCC) = p[0x20] + 2;
        *(s32 *)(o + 0x84) = D_004C2830;
        *(V3 *)(o + 0x34) = D_00440300[p[0x20]];
        *(s32 *)(o + 0x48) = 0;
        if (o[0x20] != 0) {
            *(u32 *)(o + 0xD0) = 0x800819;
        } else {
            *(u32 *)(o + 0xD0) = 0x800819;
        }
        *(u32 *)(o + 0x50) = 0x3F800000;
        *(u32 *)(o + 0x54) = 0x3F800000;
        *(u32 *)(o + 0x58) = 0x3F800000;
        o[0x22] = p[0x20];
    }
}
