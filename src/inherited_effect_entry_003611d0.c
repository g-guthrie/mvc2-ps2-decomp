typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } B3c;
typedef struct { u8 pad[0x7C]; s16 f7c[]; } G3c;
extern G3c *D_004C2794;

void func_003611D0(u8 *a, u8 *b) {
    extern int func_001757E0(u8 *, s32, s32);
    extern void func_00361310(u8 *, u8 *);
    u32 t;
    t = a[4];
    a[4] = t + 1;
    *(B3c *)(a + 0xEC) = *(B3c *)(b + 0xEC);
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
    a[0x13C] = 1;
    *(s8 *)(a+0x31) = -1;
    *(f32 *)(a + 0x3C) = *(f32 *)(b + 0x3C);
    a[0x1B5] = 14;
    a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
    *(s32 *)(a + 0x1D8) = 0;
    { s32 x = a[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    a[0x1B0] = 0x42;
    a[0x1B1] = 0x42;
    func_001757E0(a, 23, 20);
    *(u16 *)(a + 0x1C)=1;
    func_00361310(a, b);
}
