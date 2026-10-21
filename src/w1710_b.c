typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad0[0x34]; f32 f34, f38; u8 pad3c[0x14]; f32 f50, f54, f58; u8 pad5c[0x74]; u8 b4; } Q3;
void func_003BE4E0(u8 *p) {
    extern void func_003BE5C0(u8 *);
    extern int func_00175670(u8 *);
    s16 s;
    u8 *q;
    q = *(u8 **)(p + 0xDC);
    if (q[4] > 1) { func_003BE5C0(p); return; }
    p[0x13C] = *(s8 *)(q + 0x13C);
    s = *(s16 *)(p + 0xD0);
    if (*(s16 *)(p + 0x140) != 0) s = -s;
    *(V3 *)(p + 0x50) = *(V3 *)(q + 0x50);
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + 1.6666666269302368f * s * *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + 2.142857074737549f * *(s32 *)(p + 0xD4) * *(f32 *)(q + 0x54);
    if (*(s8 *)(q + 0x1B4) == 0) func_00175670(p);
}
