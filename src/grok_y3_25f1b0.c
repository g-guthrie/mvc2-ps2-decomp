typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;

extern void func_0018C4B0(u8 *, int);
extern void func_0025F4A0(u8 *);
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern void func_00183D10(u8 *);
extern void func_001757E0(u8 *, int, int);

void residual_0025F1B0(u8 *p)
{
    func_0018C4B0(p, 5);
    if (p[0x1B7] == 0) {
        p[6]++;
    } else {
        p[6] = 6;
        func_0025F4A0(p);
        return;
    }
    p[0x23] = 0;
    *(u16 *)(p + 0x1C) = 0;
    *(int *)(p + 0x5C) = 0;
    *(int *)(p + 0x60) = 0;
    *(int *)(p + 0x68) = 0;
    *(int *)(p + 0x6C) = 0;
    p[0x20D] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    func_00185490(p);
    func_00175C00(p, 0);
    func_00183D10(p);
    func_001757E0(p, 21, 14);
}
