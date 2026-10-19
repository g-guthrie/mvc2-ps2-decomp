typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
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
extern s32 D_004BFEF8[8];
extern u8 D_004C0288[];
extern u8 D_004C0290[];

extern void func_001ECF90(u8 *);

void residual_00219A20(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        *(u16 *)(p + 0x1C) = 4;
        p[0x206] = 3;
        {
            f32 f0;
            f32 f1;
            *(u32 *)&f0 = 0x47800000;
            *(u32 *)&f1 = 0x3FD55555;
            f1 = f1 * (f32)D_004BFEF8[p[0x1B7]];
            *(f32 *)(p + 0x5C) = f1 / f0;
        }
        if (p[0x1E6])
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        func_001757E0(p, 21, 0x27);
    }
}
