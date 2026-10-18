typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C2840;
extern u8 *D_004C25D0;
extern u8 *D_004C25D4;
extern s32 D_004C283C;
extern void (*D_004BFAA8[2])(void);
extern u8 D_004D1860[];
extern u8 D_00583B9B[];

extern void func_001325A0();
extern void func_00125AF0();
extern void func_00125C90();
extern s32 func_0032C180();
extern void func_00123760();
extern void func_001E3CE0();

s32 func_003CE510(s8 a0, s8 a1) {
    if (*(s8 *)(D_004C2840 + 0x2F) != 0) {
        return *(s8 *)(D_004D1860 + a0 + a1 * 4);
    }
    return 0;
}

void func_00125E20(void) {
    if (*(float *)(D_004C25D4 + 0x38) >= *(float *)(D_004C25D0 + 0x38)) {
        func_00125C90(4);
    } else {
        func_00125AF0(4);
    }
}

typedef struct { float x, y, z, w; } V4;
typedef struct { float x, y, z; } V3;

void func_001557A0(u8 *p) {
    u8 *q = *(u8 **)(p + 8);
    *(s32 *)(p + 0xD0) = *(s32 *)(q + 0xD0);
    *(s16 *)(p + 0xCC) = 0x59;
    *(s32 *)(p + 0x84) = D_004C283C;
    *(V4 *)(p + 0x74) = *(V4 *)(q + 0x74);
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
}

void func_001D94D0(u8 *a0, u8 *a1) {
    a0[0x24] = *(s8 *)(a1 + 0x24);
    if (a1[0x169] != 0) {
        a0[4] += 1;
    } else {
        D_004BFAA8[a0[5]]();
    }
}
