typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;

void residual_0017E580(u8 *p) {
    extern void func_00191430(u8 *);
    extern void func_0018F730(u8 *);
    extern void func_00328C10(u8 *);
    extern void func_00328E60(u8 *);
    extern void func_00178E10(u8 *);
    extern void func_0018EF20(u8 *);
    extern void func_0017E6E0(u8 *);
    u8 c;
    u32 t = p[6];
    p[6] = t + 1;
    p[0x24E] = p[0x24E] + 1;
    p[0x24C] = 0;
    func_00191430(p);
    *(u8 **)(p + 0x1D0) = (u8 *)(((p[0x1B5] & 0x7F) * 28) + (u32)*(u8 **)(*(u8 **)(p + 0x1DC) + 0x184));
    func_0018F730(p);
    if (((*(u8 **)(p + 0x1D0))[1] & 0x20) != 0) p[0x249] = 1;
    c = (p[0x20A] == 9) ? 2 : 3;
    if (p[0x23F] != (p[0x23E] = c)) p[0x23D] = 0;
    if (*(s8 *)(p + 0x23D) < 4) {
        if (c == 2) func_00328C10(p);
        else func_00328E60(p);
    }
    p[0x24D] = *(s8 *)(p + 0x246);
    *(s16 *)(p + 0x140) = p[0x1E6];
    p[0x20D] = 2;
    p[0x13C] = 1;
    *(u32 *)(p + 0x48) = 0;
    *(V3 *)(p + 0x50) = *(V3 *)(p + 0x298);
    *(u32 *)(p + 0x118) = 0x3F800000;
    func_00178E10(p);
    func_0018EF20(p);
    *(u32 *)(p + 0x6C) = 0xBF9A4924;
    *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x22C);
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0x230);
    *(s16 *)(p + 0x1C) = 0;
    func_0017E6E0(p);
}
