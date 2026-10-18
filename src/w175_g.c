typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } BL_003972D0;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G;
extern G *D_004C2794;

void func_003972D0(u8 *a, u8 *b, s32 c)
{
    extern void func_00396FD0(u8 *, u8 *, s32);
    a[4]++;
    *(BL_003972D0 *)(a + 0xEC) = *(BL_003972D0 *)(*(u8 **)(a + 0x18) + 0xEC);
    a[0x13C] = 1;
    a[2] = (*(u8 **)(a + 0x18))[2];
    a[1] = (*(u8 **)(a + 0x18))[1];
    *(f32 *)(a + 0x50) = *(f32 *)(*(u8 **)(a + 0x18) + 0x50);
    *(f32 *)(a + 0x54) = *(f32 *)(*(u8 **)(a + 0x18) + 0x54);
    a[0x1B7] = (*(u8 **)(a + 0x18))[0x1B7];
    a[0x1B8] = (*(u8 **)(a + 0x18))[0x1B8];
    *(s8 *)(a + 0x30) = *(s8 *)(*(u8 **)(a + 0x18) + 0x30);
    *(V3 *)(a + 0x50) = *(V3 *)(*(u8 **)(a + 0x18) + 0x50);
    *(s8 *)(a + 0x24) = *(s8 *)(*(u8 **)(a + 0x18) + 0x24);
    a[0x13C] = 0;
    a[0x1B0] = 0x42;
    a[0x1B1] = 0x42;
    *(s8 *)(a + 0x31) = -0x10;
    *(s8 *)b = -1;
    b[5] = 0;
    b[1] = 1;
    a[0x1B5] = 0x55;
    a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
    *(s32 *)(a + 0x1D8) = 0;
    { u8 i = a[2]; s16 v = D_004C2794->f7c[i]; D_004C2794->f7c[i] = v + 1; }
    func_00396FD0(a, b, c);
}
