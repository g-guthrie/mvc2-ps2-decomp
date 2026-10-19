typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern f32 D_004439B0[];
extern f32 D_00442AB0[];
extern u32 D_004C2804 __attribute__((section(".sdata")));
extern u8 *D_004C2840 __attribute__((section(".sdata")));
typedef signed int s32;
extern void func_00147750(u8 *, s32, s32);

void residual_001487D0(u8 *p)
{
    f32 *vec;

    p[4] = p[4] + 1;
    p[0x13C] = 1;
    *(u32 *)(p + 0xD0) |= 0x420;
    *(f32 *)(p + 0x74) = D_004439B0[0];
    *(f32 *)(p + 0x78) = D_004439B0[1];
    *(f32 *)(p + 0x7C) = D_004439B0[2];
    *(f32 *)(p + 0x80) = D_004439B0[3];
    if (p[0x23] == 0) {
        vec = (f32 *)((u8 *)D_00442AB0 + (p[0x20] << 4));
        *(s16 *)(p + 0xCC) = *(u16 *)((u8 *)vec + 0xC);
        *(u32 *)(p + 0x84) = D_004C2804;
        *(f32 *)(p + 0x34) = vec[0];
        *(f32 *)(p + 0x38) = vec[1];
        *(f32 *)(p + 0x3C) = vec[2];
        func_00147750(p, 2, p[0x20]);
    } else if (p[0x23] == 1) {
        *(s16 *)(p + 0xCC) = 0x8E;
        *(u32 *)(p + 0x84) = D_004C2804;
        *(u32 *)(p + 0xD8) = *(s16 *)(D_004C2840 + 8);
        *(s16 *)(p + 0x1E) = 0;
    }
}
