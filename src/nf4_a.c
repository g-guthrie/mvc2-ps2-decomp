typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

void residual_0017F1F0(u8 *p) {
    extern void func_00191430(u8 *);
    extern void func_0018F730(u8 *);
    extern void func_00178E10(u8 *);
    extern void func_0018EF20(u8 *);
    u32 t = p[6];
    p[6] = t + 1;
    p[0x24E] = p[0x24E] + 1;
    p[0x24C] = 0;
    func_00191430(p);
    *(u8 **)(p + 0x1D0) = (u8 *)(((p[0x1B5] & 0x7F) * 28) + (u32)*(u8 **)(*(u8 **)(p + 0x1DC) + 0x184));
    func_0018F730(p);
    if (((*(u8 **)(p + 0x1D0))[1] & 0x20) != 0) p[0x249] = 1;
    p[0x24D] = *(s8 *)(p + 0x246);
    *(s16 *)(p + 0x140) = p[0x1E6];
    p[0x20D] = 2;
    p[0x13C] = 1;
    *(u32 *)(p + 0x48) = 0;
    *(V3 *)(p + 0x50) = *(V3 *)(p + 0x298);
    *(u32 *)(p + 0x118) = 0x3F800000;
    func_00178E10(p);
    func_0018EF20(p);
    *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x22C);
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0x230);
    *(u32 *)(p + 0x6C) = 0xBF9A4924;
    *(s16 *)(p + 0x1C) = 0;
    *(s16 *)(p + 0x1E) = 0x140;
}

void residual_0017F600(u8 *p) {
    extern void func_00191430(u8 *);
    extern void func_0018F730(u8 *);
    extern s32 func_001757E0(u8 *, s32, s32);
    extern void func_0018EF20(u8 *);
    extern void func_0017F750(u8 *);
    u32 t = p[6];
    p[6] = t + 1;
    p[0x24E] = p[0x24E] + 1;
    p[0x24C] = 0;
    func_00191430(p);
    *(u8 **)(p + 0x1D0) = (u8 *)(((p[0x1B5] & 0x7F) * 28) + (u32)*(u8 **)(*(u8 **)(p + 0x1DC) + 0x184));
    func_0018F730(p);
    if (((*(u8 **)(p + 0x1D0))[1] & 0x20) != 0) p[0x249] = 1;
    p[0x24D] = *(s8 *)(p + 0x246);
    *(s16 *)(p + 0x140) = p[0x1E6];
    p[0x20D] = 2;
    p[0x242] = (p[0x242] + 8) & 0x10;
    p[0x168] = p[0x242] ? 0x1D : 0x1C;
    p[0x13C] = 1;
    *(u32 *)(p + 0x48) = 0;
    *(V3 *)(p + 0x50) = *(V3 *)(p + 0x298);
    *(u32 *)(p + 0x118) = 0x3F800000;
    func_001757E0(p, 0xD, p[0x168]);
    func_0018EF20(p);
    *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x22C);
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0x230);
    *(u32 *)(p + 0x6C) = 0xBF9A4924;
    *(s16 *)(p + 0x1C) = (*(f32 *)(p + 0x60) <= 0.0f) ? 1 : 0;
    func_0017F750(p);
}
