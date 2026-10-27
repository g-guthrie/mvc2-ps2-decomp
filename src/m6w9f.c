typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;


typedef struct { u8 pad[0x3A]; s16 x; u8 pad2[0x88 - 0x3C]; } E;
extern void *D_004C2A68;
extern u32 D_004773F0[];
u32 func_003D6850(s32 i) {
    u32 f = 0;
    E *devices = (E *)D_004C2A68;
    s16 x = devices[i].x;
    u32 old;
    if (x < -0x32) { f |= 0x2000; }
    if (x > 0x32) { f |= 0x1000; }
    old = D_004773F0[i]; D_004773F0[i] = f; return f & ~old;
}
