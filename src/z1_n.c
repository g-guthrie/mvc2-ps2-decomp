typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { u8 a, b; } E2;
extern E2 D_004577A0[];
extern u8 D_004D18E6;

void func_00290940(u8 *p) {
    extern s32 func_00174170();
    if ((*(u16 *)(p + 0x4F0) & 0x3F0) != 0) {
        p[0x20] = 5;
        if (*(u16 *)(p + 0x4F0) & 0x100) p[0x20] = 6;
        if (*(u16 *)(p + 0x4F0) & 0x80) p[0x20] = 7;
        if (*(u16 *)(p + 0x4F0) & 0x40) p[0x20] = 8;
        if (*(u16 *)(p + 0x4F0) & 0x20) p[0x20] = 9;
        if (*(u16 *)(p + 0x4F0) & 0x10) p[0x20] = 10;
    } else {
        p[0x20] = D_004577A0[func_00174170() & 0xF].a;
    }
    if (D_004D18E6 == 0) {
        u8 v = p[0x20];
        if (v == 6 || (u32)(v - 8) <= 1 || v == 10) p[0x20] = 5;
    }
}
