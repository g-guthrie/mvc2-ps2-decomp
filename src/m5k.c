typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern u32 D_004C2838[2];
extern u32 D_004C283C[2];
extern u32 D_004C1938[2];
extern u8 D_004C27D0[2];
extern V3 D_0045EDE0;
extern V3 D_00444998;
extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_0033C8A0(void *p);
extern void func_0033C9E0();
extern void func_00154E10(void *p);

void func_0033C930(void) {
    u8 *o = func_003DA750(0, 5, 1);
    if (o != 0) {
        o[0x13C] = 1;
        *(u32 *)(o + 0x10) = (u32)func_0033C8A0;
        *(s16 *)(o + 0xCC) = 1;
        *(u32 *)(o + 0x84) = D_004C283C[0];
        *(u32 *)(o + 0xD0) = 0x807;
        *(V3 *)(o + 0x34) = D_0045EDE0;
        *(u32 *)(o + 0x44) = D_004C1938[0];
        if ((D_004C27D0[0] & 0x1F) == 4) func_0033C9E0();
    }
}

void func_00154D60(u8 *p, u8 t) {
    u8 k = t == 9 ? 0x16 : 0x3A;
    u8 *o = func_003DA750(0, k, 1);
    if (o != 0) {
        o[0x13C] = 1;
        *(u32 *)(o + 0x10) = (u32)func_00154E10;
        *(s16 *)(o + 0xCC) = 0x54;
        *(u32 *)(o + 0x84) = D_004C2838[0];
        *(V3 *)(o + 0x50) = D_00444998;
        *(u32 *)(o + 0xD0) = 0x800412;
        *(u8 **)(o + 0xC8) = p + 0x88;
    }
}
