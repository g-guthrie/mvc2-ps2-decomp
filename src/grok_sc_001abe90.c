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

extern f32 func_001AC390(u8 *, int);
extern void func_001ABF50(u8 *, u8 *);
void func_001ABE90(u8 *p, u8 *q)
{
    f32 r;
    p[7]++;
    r = func_001AC390(q, 0x38);
    if (*(f32 *)(p + 0x34) - r < 0.0f) {
        *(u16 *)(p + 0x140) = 1;
        *(u32 *)(p + 0x5C) = 0x40FD5555;
    } else {
        *(u16 *)(p + 0x140) = 0;
        *(u32 *)(p + 0x5C) = 0xC0FD5555;
    }
    *(u32 *)(p + 0x68) = 0;
    if (p[6] != *(u32 *)(p + 0xD0))
        func_001757E0(p, 23, 13);
    func_001ABF50(p, q);
}
