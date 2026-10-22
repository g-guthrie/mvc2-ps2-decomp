typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
typedef struct { s32 w[0x31]; } BL_0034FED0;
typedef struct { u8 pad[0x7C]; s16 f7c[1]; } G;
extern G *D_004C2794;

void func_0034FED0(u8 *a)
{
    extern void func_001757E0(u8 *, s32, s32);
    a[0x13C] = 1;
    *(BL_0034FED0 *)(a + 0xEC) = *(BL_0034FED0 *)(*(u8 **)(a + 0x18) + 0xEC);
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
    *(s16 *)(a + 0x140) = *(s16 *)(*(u8 **)(a + 0x18) + 0x140);
    *(s8 *)(a + 0x24) = 0xB;
    *(s16 *)(a + 0x140) = *(s16 *)(*(u8 **)(a + 0x14) + 0x140);
    *(f32 *)(a + 0x34) = *(f32 *)(*(u8 **)(a + 0x14) + 0x34);
    *(f32 *)(a + 0x38) = *(f32 *)(*(u8 **)(a + 0x14) + 0x38);
    a[0x1B0] = 0x44;
    a[0x1B1] = 0x44;
    a[0x1B5] = 0x52;
    a[0x1B2] = *(u16 *)(a + 0x1C0) = 0;
    *(s32 *)(a + 0x1D8) = 0;
    { u8 i = a[2]; s16 v = D_004C2794->f7c[i]; D_004C2794->f7c[i] = v + 1; }
    *(s32 *)(a + 0x5C) = 0;
    *(s32 *)(a + 0x68) = 0;
    *(u32 *)(a + 0x60) = 0xC0CDB6DB;
    *(u32 *)(a + 0x6C) = 0xBE092492;
    func_001757E0(a, 0x17, 0x1A);
}
