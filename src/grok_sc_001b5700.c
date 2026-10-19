typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern u8 *D_004C2794;
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_0018C4B0(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_00183D10(u8 *);
extern int func_00175700(u8 *);
extern int func_00174170(void);
extern void func_00176160(u8 *, int, int, int);
extern void func_0011D8F8(u8 *, int, int);
extern void func_0015B200(u8 *, f32 *, int, int);
extern void func_001E3710(u8 *, int);
extern u8 D_004D18A0;
extern f32 D_004BFEF8[];
extern u8 D_004C0288[];
extern u8 D_004C0290[];

extern void func_001ECF90(u8 *);

void func_001B5700(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    p[6]++;
    func_001757E0(p, 22, 0x39);
    p[0x24] = 7;
    func_00176160(q, 2, 12, 2);
    *(u32 *)(p + 0x118) = 0x3F000000;
    *(f32 *)(p + 0x50) = 0.3f + *(f32 *)(q + 0x50);
    *(f32 *)(p + 0x54) = 0.2f + *(f32 *)(q + 0x54);
    {
        int six = 6;
        *(u16 *)(p + 0x1C) = six;
    }
    *(u32 *)(p + 0x5C) = 0x3D23D70A;
    *(u32 *)(p + 0x68) = 0xBB83126F;
    *(u32 *)(p + 0x60) = 0x3D23D70A;
    *(u32 *)(p + 0x6C) = 0xBB83126F;
    *(u32 *)(p + 0x70) = 0xC0AB6DB6;
}
