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
extern f32 D_00475EA0[];

void func_003C50E0(u8 *a, u8 *b) {
    extern void func_001757E0(u8 *, s32, s32);
    extern void func_003C52B0(u8 *, u8 *);
    u32 t;
    s32 idx;
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
    a[0x1B0] = 0x42;
    a[0x1B1] = 0x42;
    a[0x1B5] = (a[0x1B7] != 0) ? 0x50 : 0x48;
    a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
    *(s32 *)(a + 0x1D8) = 0;
    { s32 x = a[2]; s16 y = D_004C2794->f7c[x]; D_004C2794->f7c[x] = y + 1; }
    if (a[0x21] != 0) {
        *(s16 *)(a + 0x140) ^= 1;
    }
    idx = (b[0x1FD] == 6) ? 2 : a[0x1B7];
    if (*(s16 *)(b + 0x140) == 0) {
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) + D_00475EA0[idx];
    } else {
        *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) - D_00475EA0[idx];
    }
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38);
    func_001757E0(a, 0x16, (u8)(a[0x1B7] * 2 + 0x15));
    func_003C52B0(a, b);
}
