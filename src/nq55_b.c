typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

void residual_0017E1D0(u8 *p) {
    extern void func_00178E10();
    extern void func_0018F130();
    extern void func_0017E2E0();
    u32 t = p[6];
    p[6] = t + 1;
    *(s8 *)(p + 0x24E) += 1;
    *(u8 **)(p + 0x1D0) = (u8 *)((u32)*(u8 **)(*(u8 **)(p + 0x1DC) + 0x184) + (p[0x1B5] & 0x7F) * 28);
    p[0x24D] = 0;
    p[0x247] = (*(s16 *)(p + 0x434) > 0) ? 1 : 2;
    p[0x242] = 0x1C;
    p[0x243] = 4;
    *(s16 *)(p + 0x240) = 0;
    *(s16 *)(p + 0x140) = p[0x1E6];
    p[0x20D] = 2;
    p[0x13C] = 1;
    *(u32 *)(p + 0x48) = 0;
    *(V3 *)(p + 0x50) = *(V3 *)(p + 0x298);
    *(f32 *)(p + 0x118) = 1.0f;
    func_00178E10(p);
    func_0018F130(p, p[0x243]);
    *(u32 *)(p + 0x6C) = 0xBF9A4924;
    *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x22C);
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0x230);
    *(s16 *)(p + 0x1C) = 0;
    func_0017E2E0(p);
}
