typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 D_004C27FC;
extern s32 D_004C27E8;

void func_0014C3D0(u8 *p)
{
    u32 t = p[0x23];
    if (t != 8 && t != 1) {
        *(u32 *)(p + 0xD0) = 0x11;
        *(u32 *)(p + 0x34) = 0xBF800000;
        *(u32 *)(p + 0x38) = 0x3F99999A;
        *(u32 *)(p + 0x3C) = 0;
        *(u32 *)(p + 0x50) = 0x3F99999A;
        *(u32 *)(p + 0x54) = 0x3F99999A;
        *(u32 *)(p + 0x58) = 0x3F800000;
        *(s16 *)(p + 0xCC) = p[0x23] + 0xAA;
        *(s32 *)(p + 0x84) = D_004C27FC;
    } else if (t == 1) {
        *(u32 *)(p + 0xD0) = 1;
        *(u32 *)(p + 0x34) = 0x40B65E35;
        *(u32 *)(p + 0x38) = 0xC0B65E35;
        *(u32 *)(p + 0x3C) = 0xC146624E;
        *(s16 *)(p + 0xCC) = 0xF;
        *(s32 *)(p + 0x84) = D_004C27E8;
    } else if (t == 8) {
        *(u32 *)(p + 0xD0) = 1;
        *(u32 *)(p + 0x34) = 0x40B65E35;
        *(u32 *)(p + 0x38) = 0xC0B65E35;
        *(u32 *)(p + 0x3C) = 0xC146624E;
        *(s16 *)(p + 0xCC) = 0xE;
        *(s32 *)(p + 0x84) = D_004C27E8;
    }
}
