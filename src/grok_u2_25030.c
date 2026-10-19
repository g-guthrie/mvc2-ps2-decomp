typedef unsigned char u8;
typedef float f32;

extern void func_00185490(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_002250A0(u8 *);

void residual_00225030(u8 *p)
{
    p[6]++;
    func_00185490(p);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x20D] = 0;
    func_0018C4B0(p, 5);
    func_00183D10(p);
    func_001757E0(p, 21, 5);
    func_002250A0(p);
}
