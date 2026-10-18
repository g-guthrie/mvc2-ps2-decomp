#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 x[0x31]; } S31;
typedef struct { f32 x, y, z; } V3;

void func_0039F080(u8 *p, u8 *q) {
    extern s32 func_00175700();
    extern void func_001757E0();
    extern void func_003DAA40();
    u32 t = p[4];
    if (t == 0) {
        p[4] = t + 1;
        *(S31 *)(p + 0xEC) = *(S31 *)(q + 0xEC);
        p[0x13C] = 1;
        p[2] = q[2];
        p[1] = q[1];
        *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
        p[0x1B7] = q[0x1B7];
        p[0x1B8] = q[0x1B8];
        *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
        *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
        *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
        func_001757E0(p, 0x17, 0);
        *(s8 *)(p + 0x31) = -8;
    }
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    if ((s8)func_00175700(p) < 0) func_003DAA40(p);
}
