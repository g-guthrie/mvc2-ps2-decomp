typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { s32 w[49]; } S1AFE30;
typedef struct { f32 x, y, z; } V1AFE30;
void func_001AFE30(u8 *p)
{
    extern void func_001754A0();
    u8 *q;
    s32 k;
    f32 f;
    u32 t = p[4];
    p[4] = t + 1;
    q = *(u8 **)(p + 0x18);
    *(S1AFE30 *)(p + 0xEC) = *(S1AFE30 *)(q + 0xEC);
    p[0x13C] = 1;
    p[2] = q[2];
    p[1] = q[1];
    *(f32 *)(p + 0x50) = *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = *(f32 *)(q + 0x54);
    p[0x1B7] = q[0x1B7];
    p[0x1B8] = q[0x1B8];
    *(s8 *)(p + 0x30) = *(s8 *)(q + 0x30);
    *(V1AFE30 *)(p + 0x50) = *(V1AFE30 *)(q + 0x50);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    p[0x13C] = 1;
    p[0x24] = 0xE;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    k = (*(s16 *)(*(u8 **)(p + 0x18) + 0x140) != 0) ? -0x30 : 0x30;
    *(f32 *)(p + 0x34) += (f32)k;
    func_001754A0(p, 0x1B, (*(u8 **)(p + 0x18))[0x1C]);
}
