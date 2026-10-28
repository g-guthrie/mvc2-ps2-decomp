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
extern f32 D_004638F0[];
extern f32 D_004638F4[];
extern f32 D_004638FC[];

typedef struct { u8 pad[0x48]; s32 f48; } S48;
#define PAR (*(u8 **)(p + 0x18))

void residual_00368C50(u8 *p) {
    extern s32 func_00417690(f32, f32);
    extern void func_001757E0(u8 *, s32, s32);
    u32 t;
    f32 a;
    f32 b;
    s32 v;
    t = p[4];
    p[4] = t + 1;
    *(B3c *)(p + 0xEC) = *(B3c *)(PAR + 0xEC);
    p[0x13C] = 1;
    p[2] = PAR[2];
    p[1] = PAR[1];
    *(f32 *)(p + 0x50) = *(f32 *)(PAR + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(PAR + 0x54);
    p[0x1B7] = PAR[0x1B7];
    p[0x1B8] = PAR[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(PAR + 0x30);
    *(V3 *)(p + 0x50) = *(V3 *)(PAR + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(PAR + 0x24);
    p[0x24] = 0;
    p[2] ^= 1;
    p[0x1B0] = 0x44;
    p[0x1B1] = 0x44;
    p[0x1B5] = 0x40;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    { s32 x = p[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    p[0x14E] = 0x30;
    p[0x14F] = 0x30;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    a = *(s16 *)(p + 0x140) ? 15.0f : -15.0f;
    *(f32 *)(p + 0x5C) = a;
    *(f32 *)(p + 0x60) = D_004638FC[0];
    b = *(s16 *)(p + 0x140) ? D_004638F0[0] : -D_004638F0[0];
    *(f32 *)(p + 0x34) = *(f32 *)(PAR + 0x34) + b;
    *(f32 *)(p + 0x38) = *(f32 *)(PAR + 0x38) + D_004638F4[0];
    *(s32 *)(p + 0x48) = func_00417690(*(f32 *)(p + 0x60), *(f32 *)(p + 0x5C));
    if (*(s16 *)(p + 0x140)) {
        v = -((S48 *)p)->f48;
    } else {
        v = (((S48 *)p)->f48 + 0x8000) & 0xFFFF;
    }
    *(s32 *)(p + 0x48) = v;
    *(s16 *)(p + 0x1C) = 0x10;
    func_001757E0(p, 0x17, 0x16);
}
