typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef struct { f32 x, y, z; } V3;
extern s32 D_004C2838;

void func_0015D970(V3 *v, s32 n)
{
    extern u8 *func_003DA750();
    extern void func_0015DD60();
    u8 *o;
    if ((o = func_003DA750(0, 8, 1)) != 0) {
        o[0x13C] = 1;
        *(u32 *)(o + 0x10) = (u32)func_0015DD60;
        *(s16 *)(o + 0xCC) = 0xA9;
        *(s32 *)(o + 0x84) = D_004C2838;
        *(V3 *)(o + 0x34) = *v;
        *(f32 *)(o + 0x38) += 10.0f;
        *(u32 *)(o + 0xD0) = 0x800405;
        *(s16 *)(o + 0x1C) = 0;
        *(s16 *)(o + 0x1E) = 0;
        *(u32 *)(o + 0x74) = 0x3F800000;
        *(s32 *)(o + 0x78) = 0;
        *(s32 *)(o + 0x7C) = 0;
        *(s32 *)(o + 0x80) = 0;
        *(s16 *)(o + 0x140) = n;
        *(s32 *)(o + 0x44) += (*(s16 *)(o + 0x140) != 0) ? 0x8000 : 0;
    }
}
