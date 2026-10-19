typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;

extern void func_00175C00(u8 *, s32);
extern void func_00176160(u8 *, s32, s32, s32);
extern s32 func_00174170(void);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00288A70(u8 *);
extern void func_00288950(u8 *);

void residual_00288890(u8 *p)
{
    func_00175C00(p, 0);
    func_00176160(p, 7, 0x57 * p[0x25] + 0x39, 1);
    if (*(u16 *)(p + 0x4F0) & 0x200)
        goto other;
    if (!(func_00174170() & 0xF0))
        goto other;
    p[7] = 4;
    func_001757E0(p, 0x13, 6);
    func_00288A70(p);
    return;
other:
    p[7]++;
    func_001757E0(p, 0x13, 7);
    func_00288950(p);
}
