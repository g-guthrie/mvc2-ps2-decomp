typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
typedef struct { u8 b[28]; } Row;
typedef struct { u8 pad[0x184]; Row *rows; } Own;

extern void func_00191430(u8 *);
extern void func_0018F730(u8 *);
extern void func_00178E10(u8 *, int);
extern void func_0018EF20(u8 *);

void residual_0017F1F0(u8 *p)
{
    u8 *tbl;
    u32 idx;
    u32 bits;

    p[6]++;
    *(s8 *)(p + 0x24E) += 1;
    p[0x24C] = 0;
    func_00191430(p);
    {
        Own *o = *(Own **)(p + 0x1DC);
        *(Row **)(p + 0x1D0) = o->rows + (p[0x1B5] & 0x7F);
    }
    func_0018F730(p);
    if ((*(u8 **)(p + 0x1D0))[1] & 0x20)
        p[0x249] = 1;
    p[0x24D] = *(s8 *)(p + 0x246);
    *(u16 *)(p + 0x140) = p[0x1E6];
    p[0x20D] = 2;
    p[0x13C] = 1;
    *(u32 *)(p + 0x48) = 0;
    *(V3 *)(p + 0x50) = *(V3 *)(p + 0x298);
    *(u32 *)(p + 0x118) = 0x3F800000;
    func_00178E10(p, 2);
    func_0018EF20(p);
    bits = 0xBF9A4924;
    *(f32 *)(p + 0x5C) = *(f32 *)(p + 0x22C);
    *(f32 *)(p + 0x60) = *(f32 *)(p + 0x230);
    *(u32 *)(p + 0x6C) = bits;
    *(u16 *)(p + 0x1C) = 0;
    *(u16 *)(p + 0x1E) = 0x140;
}
