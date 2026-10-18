typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern u8 *D_004C2840;
extern u8 D_004BF340[2];
extern u32 D_004C2834;
extern V3 D_0043E240[];
extern void func_001332D0();

void func_00132730(u8 *p) {
    extern u8 *func_003DA750();
    u8 *o;
    if (*(s32 *)(D_004C2840 + 0x14) != 0x40) {
        if ((o = func_003DA750(0, 0xD, 0)) != 0) {
            o[0x13C] = 1;
            *(void **)(o + 0x10) = func_001332D0;
            *(s16 *)(o + 0xCC) = D_004BF340[p[2]];
            *(u32 *)(o + 0x84) = D_004C2834;
            *(s16 *)(o + 0x1E) = 0x78;
            *(u32 *)(o + 0xD0) = 0x10801;
            *(u8 **)(o + 0x18) = p;
            *(V3 *)(o + 0x34) = D_0043E240[(p[0x425] << 1) + p[2]];
            o[7] = p[0x425];
        }
    }
}
