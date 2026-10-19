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
extern int func_001757E0(u8 *, int, int);
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

void func_0020B9D0(u8 *p)
{
    p[6]++;
    p[0x1B5] = p[0x1B7] ? 0x3B : 0x39;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    ((s16 *)(D_004C2794 + 124))[p[2]]++;
    func_0018C4B0(p, 8);
    func_00185490(p);
    p[0x20D] = 2;
    *(f32 *)(p + 0x5C) /= 4.0f;
    *(f32 *)(p + 0x68) /= 4.0f;
    *(f32 *)(p + 0x60) /= 4.0f;
    *(f32 *)(p + 0x6C) /= 4.0f;
    *(u16 *)(p + 0x1C) = 14;
    func_001757E0(p, 21, 13);
}
