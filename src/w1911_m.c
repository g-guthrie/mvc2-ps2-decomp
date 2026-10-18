typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef short s16;
typedef float f32;
typedef int s32;
typedef struct { f32 x, y, z; } V3;
typedef struct { V3 r[3]; } Row;
typedef struct { u8 pad[0x29]; s8 b29; } Cfg;
extern Row D_00440090[];
extern Cfg *D_004C2840;
extern s32 D_004C2830;
extern void func_0013ADA0(void);
extern void func_0013AE00(void);
void func_0013A760(u8 *p) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00152550(u8 *, void (*)(void));
    u8 *o;
    if ((o = func_003DA750(0, 6, 1)) != 0) {
        *(u8 **)(o + 0x18) = p;
        *(s32 *)(o + 0xC8) = *(s32 *)(p + 0xC8);
        *(s32 *)(o + 0x14) = *(s32 *)(p + 0x14);
        o[0x13C] = 1;
        *(void **)(o + 0x10) = (void *)func_0013ADA0;
        o[0x20] = p[0x20];
        o[0x21] = p[0x21];
        o[0x01] = p[0x01];
        if (D_004C2840->b29 != 0) {
            *(s16 *)(o + 0xCC) = 0x6C;
            *(s32 *)(o + 0x84) = D_004C2830;
        } else {
            *(s16 *)(o + 0xCC) = 0x66;
            *(s32 *)(o + 0x84) = D_004C2830;
        }
        *(V3 *)(o + 0x34) = D_00440090[o[0x20]].r[o[0x21]];
        *(s32 *)(o + 0x40) = 0x2000;
        *(s32 *)(o + 0xD0) = 0x813;
        *(u32 *)(o + 0x50) = 0x3F800000;
        *(u32 *)(o + 0x54) = 0x3C23D70A;
        *(u32 *)(o + 0x58) = 0x3F800000;
        func_00152550(o, func_0013AE00);
    }
}
