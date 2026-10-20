typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef double f64;

extern f64 litodp(s32);
/* Compatible prefix views used by the existing 00145CD0 callback. */
typedef struct { u8 pad[0xE]; s16 h0E; } G14;
typedef struct { u8 p0[4]; u8 b4; u8 p5[0x19]; s16 h1E; u8 p20[0x20]; s32 w40; u8 p44[0xC]; f32 f50, f54, f58; u8 p5c[0x10]; f32 f6C, f70; u8 p74[4]; f32 f78, f7C, f80; } O14;
extern void func_00145CD0(O14 *);
extern G14 *D_004C2840;
extern f32 D_004B3428 __attribute__((section(".data")));
extern f32 D_004B343C __attribute__((section(".data")));

void func_00145B10(u8 *p)
{
    s32 t;
    double k = 65536.0;

    p[0x13C] = 1;
    *(u32 *)(p + 0x40) = (u16)(u32)(s32)(0.5 + k * (double)D_004B3428 / 360.0);
    *(f32 *)(p + 0x5C) = D_004B3428;
    *(f32 *)(p + 0x68) = (D_004B343C - *(f32 *)(p + 0x5C)) / (f32)(*(s16 *)((signed char *)D_004C2840 + 0xE) / 10);
    t = *(s16 *)((signed char *)D_004C2840 + 0xE) / 10;
    *(f32 *)(p + 0x6C) = (f32)(0.7 / litodp(t));
    t = *(s16 *)((signed char *)D_004C2840 + 0xE) / 10;
    *(f32 *)(p + 0x70) = (f32)(0.5 / litodp(t));
    p[4]++;
    t = *(s16 *)((signed char *)D_004C2840 + 0xE) / 10;
    *(s16 *)(p + 0x1E) = (s16)t;
    func_00145CD0((O14 *)p);
}
