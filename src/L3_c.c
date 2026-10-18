typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3c;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G3c;
extern G3c *D_004C2794;

#define PAR (*(u8 **)(o + 0x18))

u8 *func_00375890(u8 *a, s32 b, s32 c) {
    extern u8 *func_003DA750(s32, s32, s32);
    extern void func_00375AB0();
    extern void func_00375CA0(u8 *, u8 *);
    extern void func_001757E0(u8 *, s32, s32);
    u8 *o;
    u32 t;
    u32 z;
    if ((o = func_003DA750(0, 1, 0)) != 0) {
        *(s32 *)(o + 0x10) = (s32)func_00375AB0;
        o[1] = a[1];
        *(s16 *)(o + 0x26) = 0x1406;
        *(u8 **)(o + 0x18) = a;
        *(s32 *)(o + 0x14) = b;
        *(u16 *)(o + 0xD0) = *(u16 *)(a + 0x168);
        o[0xD1] = a[0x169];
        o[0xD0] = a[0x168];
        t = o[4];
        o[4] = t + 1;
        *(B3c *)(o + 0xEC) = *(B3c *)(PAR + 0xEC);
        o[0x13C] = 1;
        o[2] = PAR[2];
        o[1] = PAR[1];
        *(f32 *)(o + 0x50) = *(f32 *)(PAR + 0x50);
        *(f32 *)(o + 0x54) = *(f32 *)(PAR + 0x54);
        o[0x1B7] = PAR[0x1B7];
        o[0x1B8] = PAR[0x1B8];
        *(s8 *)(o + 0x30) = *(s8 *)(PAR + 0x30);
        *(V3 *)(o + 0x50) = *(V3 *)(PAR + 0x50);
        *(s8 *)(o + 0x24) = *(s8 *)(PAR + 0x24);
        o[0x14D] = 0x20;
        o[0x14C] = 0x20;
        o[0x14F] = 0x24;
        o[0x14E] = 0x24;
        o[0x24] = 0;
        *(f32 *)(o + 0x34) = *(f32 *)(a + 0x34);
        *(f32 *)(o + 0x38) = *(f32 *)(a + 0x38);
        *(s16 *)(o + 0x140) = *(s16 *)(a + 0x140);
        o[0x20] = c;
        o[0x1B0] = 0x42;
        o[0x1B1] = 0x42;
        o[0x1B5] = 0x45;
        z = o[0x1B2] = *(u16 *)(o + 0x1C0) = 0;
        *(s32 *)(o + 0x1D8) = 0;
        { s32 x = o[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
        a[0x1B5] = 0x45;
        *(u16 *)(a + 0x1C0) = 0;
        a[0x1B2] = z;
        *(s32 *)(a + 0x1D8) = 0;
        D_004C2794->f7c[a[2]]++;
        o[0x13C] = 0;
        func_00375CA0(a, o);
        func_001757E0(o, 0x16, 0x42);
    }
    return o;
}
