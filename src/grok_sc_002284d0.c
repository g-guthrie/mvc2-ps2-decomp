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

void residual_002284D0(u8 *p)
{
    p[6]++;
    func_00185490(p);
    if (p[0x20D] != 2) {
        p[0x20D] = 0;
        func_00183D10(p);
    }
    *(u32 *)(p + 0x2D0) = 0;
    func_0018C4B0(p, 1);
    {
        f32 f0, f1;
        *(u32 *)&f0 = 0xC1855555;
        *(u32 *)&f1 = 0x3EA00000;
        if (p[0x1E6]) {
            f0 = -f0;
            f1 = -f1;
        }
        *(f32 *)(p + 0x5C) = f0;
        *(f32 *)(p + 0x68) = f1;
    }
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
    func_001757E0(p, 21, 22);
}
