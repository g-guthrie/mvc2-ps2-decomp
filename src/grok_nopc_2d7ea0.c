typedef unsigned char u8;
typedef float f32;

extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_002D7EA0(u8 *p)
{
    p[6]++;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x2BA] = 0x32;
    p[0x2BD] = 1;
    p[0x20D] = 0;
    p[0x219] = 0x30;
    func_00185490(p);
    func_00183D10(p);
    func_001757E0(p, 0x15, 4);
}
