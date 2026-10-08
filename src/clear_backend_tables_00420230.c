typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_004D0DE0[];
extern u8 D_004D0E60[];
extern u8 D_004D0EE0[];
extern u8 D_004D0F60[];
extern u8 D_004D0FA0[];
extern u8 D_004D0FE0[];
extern u8 D_004D0FEA[];
extern u32 D_004C2BA0;
extern volatile u8 D_004D106A[];
extern volatile u8 D_004D106B[];
extern u8 D_004BF130[];

extern void func_0011D8F8(void *destination, s32 value, u32 size);
extern void func_0011F938(void *destination, void *source, s32 mode);

void func_00420230(void)
{
    func_0011D8F8(D_004D0DE0, 0, 128);
    func_0011D8F8(D_004D0E60, 0, 128);
    func_0011D8F8(D_004D0EE0, 0, 128);
    func_0011D8F8(D_004D0F60, 0, 64);
    func_0011D8F8(D_004D0FA0, 0, 64);
    func_0011D8F8(D_004D0FE0, 0, 10);
    func_0011D8F8(D_004D0FEA, 0, 128);
    func_0011D8F8(&D_004C2BA0, 0, 4);
    D_004D106A[0] = 0;
    D_004D106B[0] = 0;
    func_0011F938(&D_004C2BA0, D_004BF130, *(volatile s8 *)D_004D106A);
}
