typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

extern s32 D_004C283C;
extern f32 D_00444A78[];

void func_00155670(u8 *p) {
    *(s32 *)(p + 0xD0) = 0x2D;
    *(s16 *)(p + 0xCC) = 0x5A;
    *(s32 *)(p + 0x84) = D_004C283C;
    *(u32 *)(p + 0x74) = 0x3F800000;
    if (p[3] == 8) {
        *(s32 *)(p + 0xD0) |= 0x10;
        *(V3 *)(p + 0x50) = *(V3 *)D_00444A78;
    }
}

extern u8 *D_004C29A4;
extern u8 *D_004C29A0;
extern void (*D_00464560[])();
extern void (*D_00464570[])();

void func_003814D0(u8 *p) {
    if (p[0x20] == 0) {
        D_004C29A4 = p + 0xD0;
        D_00464560[p[4]]();
    } else {
        D_004C29A4 = p + 0xD0;
        D_004C29A0 = *(u8 **)(p + 0x18) + 0xD0;
        D_00464570[p[4]]();
    }
}
