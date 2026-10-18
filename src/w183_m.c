typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 w[49]; } B196;
typedef struct { f32 x, y, z; } V3;
extern u8 *D_004C29C4;

static void func_0038E610(u8 *p) {
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x34) += *(f32 *)(D_004C29C4 + 8);
    *(f32 *)(p + 0x38) += *(f32 *)(D_004C29C4 + 0xC);
}

void func_0038E7B0(u8 *p) {
    extern void func_0038E450(u8 *);
    u32 t = p[4];
    p[4] = t + 1;
    *(B196 *)(p + 0xEC) = *(B196 *)(*(u8 **)(p + 0x18) + 0xEC);
    p[0x13C] = 1;
    p[2] = (*(u8 **)(p + 0x18))[2];
    p[1] = (*(u8 **)(p + 0x18))[1];
    *(f32 *)(p + 0x50) = *(f32 *)(*(u8 **)(p + 0x18) + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(*(u8 **)(p + 0x18) + 0x54);
    p[0x1B7] = (*(u8 **)(p + 0x18))[0x1B7];
    p[0x1B8] = (*(u8 **)(p + 0x18))[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(*(u8 **)(p + 0x18) + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(*(u8 **)(p + 0x18) + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    if (p[1] != (*(u8 **)(p + 0x18))[1]) {
        p[4] = 2;
        p[0x13C] = 0;
    } else {
        p[0x13C] = 0;
        func_0038E610(p);
        p[0x24] = 0;
        D_004C29C4[7] = 0;
        D_004C29C4[0] = 0;
        *(s16 *)(p + 0x1C) = 2;
        p[0x22] = 0xC;
        p[0x1B0] = 0x42;
        p[0x1B1] = 0x42;
        D_004C29C4[2] = 0;
        D_004C29C4[3] = 2;
        func_0038E450(p);
    }
}
