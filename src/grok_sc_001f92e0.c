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

void residual_001F92E0(u8 *p)
{
    p[6]++;
    if (p[0x20] == 2) {
        func_001757E0(p, 19, 4);
        return;
    }
    *(u16 *)(p + 0x1C) = func_00174170() & 3;
    switch (*(s16 *)(p + 0x1C)) {
    case 0:
        func_001757E0(p, 19, 0);
        break;
    case 1:
        func_001757E0(p, 19, 3);
        break;
    case 2:
        func_001757E0(p, 19, 3);
        break;
    case 3:
        func_001757E0(p, 19, 3);
        break;
    }
}
