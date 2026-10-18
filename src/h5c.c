typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
extern void func_001757E0(u8 *, s32, s32);
void func_0036CB60(u8 *p) {
    p[0x13C] = 1;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x18) + 0x3C);
    p[0x24] = 9;
    *(f32 *)(p + 0x50) += 0.015625f;
    *(f32 *)(p + 0x54) += 0.015625f;
    func_001757E0(p, 0x17, (u8)((*(u8 **)(p + 0x18))[7] + 8));
}
extern u16 D_0058C020[];
u32 func_0038CB20(void) {
    u16 *q = D_0058C020;
    u32 i = 0;
    u16 sum = 0;
    for (; i < 936; i++) {
        sum += *q++;
    }
    return sum;
}
