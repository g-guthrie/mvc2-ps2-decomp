typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 x[0x31]; } S1DF;
typedef struct { u8 pad[0x151]; s8 f151; } Q1DF;
typedef struct { f32 x, y, z; } V3c;

void func_001DFAD0(u8 *p, u8 *s)
{
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003DAA40(u8 *);
    u8 *q;
    u32 t = p[4];
    if (t == 0) {
        p[4] = t + 1;
        *(S1DF *)(p + 0xEC) = *(S1DF *)(s + 0xEC);
        p[0x13C] = 1;
        p[2] = s[2];
        p[1] = s[1];
        *(f32 *)(p + 0x50) = *(f32 *)(s + 0x50);
        *(f32 *)(p + 0x54) = *(f32 *)(s + 0x54);
        p[0x1B7] = s[0x1B7];
        p[0x1B8] = s[0x1B8];
        *(s8 *)(p + 0x30) = *(s8 *)(s + 0x30);
        *(V3c *)(p + 0x50) = *(V3c *)(s + 0x50);
        *(s8 *)(p + 0x24) = *(s8 *)(s + 0x24);
        func_001757E0(p, 0x12, 4);
    }
    q = *(u8 **)(p + 0x14);
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    if (((Q1DF *)q)->f151 != 0) {
        *(s8 *)((s32)q + 0x151) = 0;
        func_003DAA40(p);
    }
}
