typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 x[49]; } S49;
typedef struct { f32 x, y, z; } V3;

void func_001DFD00(u8 *a, u8 *b) {
    extern void func_001757E0(u8 *, s32, s32);
    extern s32 func_00175700();
    extern void func_003DAA40();
    u32 st = a[4];
    if (st == 0) {
        a[4] = st + 1;
        *(S49 *)(a + 0xEC) = *(S49 *)(b + 0xEC);
        a[0x13C] = 1;
        a[2] = b[2];
        a[1] = b[1];
        *(f32 *)(a + 0x50) = *(f32 *)(b + 0x50);
        *(f32 *)(a + 0x54) = *(f32 *)(b + 0x54);
        a[0x1B7] = b[0x1B7];
        a[0x1B8] = b[0x1B8];
        *(s8 *)(a + 0x30) = *(s8 *)(b + 0x30);
        *(V3 *)(a + 0x50) = *(V3 *)(b + 0x50);
        *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34);
        *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38);
        *(s8 *)(a + 0x31) = -8;
        func_001757E0(a, 0x12, 0xC);
    }
    *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24);
    if ((s8)func_00175700(a) < 0) {
        func_003DAA40(a);
        return;
    }
    if (*(s8 *)(a + 0x151) != 0) {
        a[0x151] = 0;
        b[6] = 3;
    }
}
