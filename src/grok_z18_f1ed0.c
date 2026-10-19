typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

extern void func_001F0420(u8 *);
extern void func_0018C4B0(u8 *, s32);
extern int func_001757E0(u8 *, s32, s32);
extern void func_001906C0(u8 *, s16, u8, u8);

void func_001F1ED0(u8 *p)
{
    p[6]++;
    func_001F0420(p);
    func_0018C4B0(p, 0xA);
    if (p[0x269] == 8)
        func_001757E0(p, 0xF, 0x3D);
    else
        func_001757E0(p, 0xF, 0x16);
    func_001906C0(p, 0xA, 0x1E, 0x3C);
}
