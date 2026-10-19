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

extern void func_0018E6C0(u8 *);
void func_0018E350(u8 *p, u8 *q)
{
    func_0011D8F8(p + 0x370, 0, 8);
    p[0x24A] = 0x78;
    p[0x247] = 0xF;
    p[0x248] = 0;
    p[0x1B7] = q[0x1B7];
    p[0x23E] = 5;
    {
        int five = 5;
        if (p[0x23F] != five)
            p[0x23D] = 0;
        p[0x23C] = five;
    }
    if (p[0x20D] != 2) {
        func_0018E6C0(p);
        return;
    }
    *(u16 *)(p + 0x1C) = 10;
    func_001757E0(p, 13, 16);
}
