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

extern void func_0024AE10(u8 *);
void residual_0024AD30(u8 *p)
{
    f32 sp[2];
    p[7]++;
    func_00175C00(p, 0);
    func_00176160(p, 5, 1, 1);
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x210] = 0;
    p[0x20D] = 0;
    if (!*(s16 *)(p + 0x140))
        sp[0] = *(f32 *)(p + 0x34);
    else
        sp[0] = *(f32 *)(p + 0x34);
    {
        f32 t;
        *(u32 *)&t = 0x42AB6DB6;
        sp[1] = t + *(f32 *)(p + 0x38);
    }
    func_0015B200(p, sp, 1, 8);
    func_001E3710(p, 0x4A);
    func_001757E0(p, 19, 2);
    func_0024AE10(p);
}
