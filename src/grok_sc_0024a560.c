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

extern void func_0024A620(u8 *);
void residual_0024A560(u8 *p)
{
    p[6]++;
    p[0x13C] = 1;
    *(f32 *)(p + 0x64) = *(f32 *)(p + 0x34);
    if (!(p[0x1B8] & 1)) {
        *(f32 *)(p + 0x34) -= 426.66666f;
        *(u32 *)(p + 0x5C) = 0x41200000;
    } else {
        *(f32 *)(p + 0x34) += 426.66666f;
        *(u32 *)(p + 0x5C) = 0xC1200000;
    }
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    *(u32 *)(p + 0x68) = 0;
    *(u16 *)(p + 0x1C) = 0x1E;
    func_001757E0(p, 18, 0);
    func_0024A620(p);
}
