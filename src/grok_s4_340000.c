typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 *D_004C283C;
extern void func_00170E60();
extern void func_003400A0();

typedef struct { u8 *p; u32 z; } A;

void func_00340000(u8 *p)
{
    A a;
    u8 *q;
    if ((s32)(*(u8 **)(p + 0x18))[4] <= 0) {
        p[0x13C] = 1;
    } else {
        p[0x13C] = 0;
        return;
    }
    *(s16 *)(p + 0x1C) += 4;
    if (*(s16 *)(p + 0x1C) >= 360)
        *(s16 *)(p + 0x1C) = 0;
    q = *(u8 **)(p + 0x84);
    a.p = p;
    a.z = 0;
    func_00170E60(*(s32 *)(D_004C283C + 0x14), *(s32 *)(*(u8 **)(q + 0x1C) + 0x54) + 400, *(s32 *)(q + 0x14), ((s32 *)*(u8 **)(q + 0x1C))[*(s16 *)(p + 0xCC)], func_003400A0, (u32)&a);
}
