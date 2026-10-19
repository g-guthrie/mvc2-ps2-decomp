typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

extern void func_00175700(u8 *);
extern int func_001864A0(u8 *);
extern void func_0018F730(u8 *);
extern void func_001E3A10(u8 *);
extern void func_00158C70(u8 *, int);
extern void func_00186CE0(u8 *, int);
extern u8 D_004F1F46;
extern u8 D_004F1F45;

void func_00180090(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_001864A0(p) == 0)
        return;
    {
        typedef struct { u8 b[28]; } Row;
        typedef struct { u8 pad[0x184]; Row *rows; } Own;
        Own *o = *(Own **)(p + 0x1DC);
        *(Row **)(p + 0x1D0) = o->rows + (p[0x1B5] & 0x7F);
    }
    func_0018F730(p);
    *(u16 *)(p + 0x140) = p[0x1E6];
    func_001E3A10(p);
    func_00158C70(p + 0x34, p[2]);
    D_004F1F46 = 1;
    D_004F1F45 = 3;
    p[0x20D] = 3;
    {
        int forty = 0x40;
        p[0x209] = (u8)forty;
        *(u16 *)(p + 0x1FA) = (u16)forty;
    }
    p[0x1F7] = 0x64;
    func_00186CE0(p, 0x17);
}
