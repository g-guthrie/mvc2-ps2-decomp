typedef unsigned char u8;
typedef signed int s32;

extern void func_001049F8(s32);
extern void func_00402498(void);
extern void func_003FD928(void);
extern void func_00411A30(void);
extern void func_00411A48(void);
extern void func_00411AB8(void);
extern void func_00411AD0(void);
extern void func_00411AE8(void);
extern s32 *func_003F1540(void *, s32);
extern s32 *func_003F15A0(void);
extern s32 *func_003F1F90(void *, s32);

void func_003F04D0(void)
{
    func_001049F8(2);
    func_001049F8(1);
}

s32 func_003F0B20(s32 *p)
{
    s32 t;
    if (p[3] != 0)
        t = (p[5] + p[1]) - p[4] - p[8];
    else
        t = p[4] - (p[5] - p[1]) - p[8];
    return t;
}

s32 func_003F13E0(void *p)
{
    s32 *r = func_003F1540(p, 0);
    if (r != 0)
        return r[1];
    return 0;
}

s32 func_003F1620(void)
{
    u8 *r = (u8 *)func_003F15A0();
    if (r != 0)
        return (s32)(r + 12);
    return 0;
}

s32 func_003F1FF0(void *p)
{
    s32 *r = func_003F1F90(p, 0x100);
    if (r == 0)
        return -1;
    return r[1];
}

s32 func_003F2030(void *p)
{
    s32 *r = func_003F1F90(p, 0x800);
    if (r != 0)
        return r[1];
    return -1;
}

s32 func_003FDA60(void)
{
    func_00402498();
    return 0;
}

s32 func_003FDA80(void)
{
    func_003FD928();
    return 0;
}

s32 func_003FE570(void)
{
    func_00411A30();
    func_00411A48();
    func_00411AB8();
    func_00411AD0();
    func_00411AE8();
    return 0;
}
