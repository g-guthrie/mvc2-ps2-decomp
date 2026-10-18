typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3d;

void func_001D05E0(u8 *p, u8 *q)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_00175700(u8 *);
    extern void func_003DAA40(u8 *);
    u32 t;
    if (p[4] == 0) {
        t = p[4];
        p[4] = t + 1;
        *(B3d *)(p + 0xEC) = *(B3d *)(q + 0xEC);
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
        func_001757E0(p, 0x17, 1);
    }
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    *(s8 *)(p + 0x31) = -1;
    if (q[0x169] == 0x16 && q[0x168] == 0) {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
        func_00175700(p);
    } else {
        func_003DAA40(p);
    }
}
