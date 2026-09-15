typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

extern void func_00178F20(void);
extern void func_0018FDB0(u8 *);
extern void func_001548D0(u8 *, u32 *, s32);
extern void func_001E3710(u8 *, s32);

void func_0021BF20(u8 *a0, u8 *a1)
{
    u32 tmp[4];

    a0[0x151] = 0;
    a0[0x2c4] = 1;
    func_00178F20();
    *(u8 **)(a1 + 0x1c8) = a0;
    a1[0x1b5] = 0x21;
    func_0018FDB0(a0);
    tmp[0] = 0x42A00000;
    tmp[1] = 0x42092492;
    func_001548D0(a0, tmp, 2);
    func_001E3710(a0, 5);
}

void func_003217D0(u8 *a0, u8 *a1)
{
    u32 tmp[4];

    a0[0x151] = 0;
    a0[0x2c4] = 1;
    func_00178F20();
    *(u8 **)(a1 + 0x1c8) = a0;
    a1[0x1b5] = 0x21;
    func_0018FDB0(a0);
    tmp[0] = 0x42A00000;
    tmp[1] = 0x42092492;
    func_001548D0(a0, tmp, 2);
    func_001E3710(a0, 5);
}

void func_0021C7C0(u8 *a0, u8 *a1)
{
    u32 tmp[4];

    a0[0x151] = 0;
    a0[0x2c4] = 1;
    func_00178F20();
    *(u8 **)(a1 + 0x1c8) = a0;
    a1[0x1b5] = 0x26;
    func_0018FDB0(a0);
    func_001E3710(a0, 5);
    tmp[0] = 0xC2A00000;
    tmp[1] = 0x41892492;
    func_001548D0(a0, tmp, 2);
}

void func_00322070(u8 *a0, u8 *a1)
{
    u32 tmp[4];

    a0[0x151] = 0;
    a0[0x2c4] = 1;
    func_00178F20();
    *(u8 **)(a1 + 0x1c8) = a0;
    a1[0x1b5] = 0x26;
    func_0018FDB0(a0);
    func_001E3710(a0, 5);
    tmp[0] = 0xC2A00000;
    tmp[1] = 0x41892492;
    func_001548D0(a0, tmp, 2);
}
