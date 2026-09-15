typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern int func_00186CE0(u8 *, s32);
extern void func_001861B0(u8 *);
extern int func_001879C0(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_001E3710(u8 *, s32);
extern void func_00191210(u8 *);
extern int func_0018ABB0(u8 *);
extern void func_0018C970(u8 *);
extern void func_0018E810(u8 *, u8 *);
extern void func_0018EA00(u8 *);
extern void func_0018C8A0(u8 *);
extern u8 D_004D18A1;

int func_00186080(u8 *p)
{
    if (p[0x20D] == 2)
        return 0;
    if (!(*(u16 *)(p + 0x35C) & 0x1000))
        return 0;
    func_00186CE0(p, 5);
    return 1;
}

int func_001860D0(u8 *p)
{
    if (!(D_004D18A1 & 2) && (*(u16 *)(p + 0x354) & 0x1000))
        return 0;
    func_00186CE0(p, 7);
    return 1;
}

int func_0019B710(u8 *p, s32 a1)
{
    u8 *q = *(u8 **)(p + 0x18);
    if (*(s8 *)(p + 0x151))
        p[5]++;
    return q[0x169] == a1;
}

void func_00187050(u8 *p)
{
    p[0x20D] = 1;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x6C) = 0;
    func_001861B0(p);
    if (!func_001879C0(p))
        func_001757E0(p, 3, 1);
}

void func_00186FE0(u8 *p)
{
    p[0x20D] = 1;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x6C) = 0;
    func_001861B0(p);
    if (!func_001879C0(p) && !(*(u32 *)(p + 0x428) & 0x07000000))
        func_001757E0(p, 3, 0);
}

void func_00187200(u8 *p)
{
    p[0x20D] = 2;
    p[0x1E8] = 0;
    p[0x1E9] = 0;
    p[0x1E7] = 0;
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    func_001E3710(p, 0x3A);
    func_001757E0(p, 0x1A, 1);
}

void func_00187450(s8 *p)
{
    p[0x20D] = 2;
    p[0x1EA] = -1;
    p[6] = 2;
    p[0x210] = 1;
    func_001757E0((u8 *)p, 0xD, 0x1E);
    func_00191210((u8 *)p);
}

void func_0018E160(u8 *p, u8 *q)
{
    p[0x247] = 9;
    p[0x248] = 0;
    func_0018C970(p);
    func_0018E810(p, q);
    func_001757E0(p, 0xD, 0);
}

void func_0018E2E0(u8 *p, u8 *q)
{
    p[0x248] = 1;
    p[0x247] = 11;
    func_0018EA00(p);
    func_0018E810(p, q);
    func_001757E0(p, 0xD, 0x1D);
}

void func_0018E400(u8 *p, u8 *q)
{
    p[0x247] = 16;
    p[0x248] = 0;
    p[0x20D] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    func_0018C8A0(p);
    p[0x1F5] = 80;
    func_0018E810(p, q);
    func_001757E0(p, 0xD, 0x1A);
}

int func_0018AAC0(u8 *p)
{
    if (p[0x425])
        return 0;
    if (*(s8 *)(p + 0x539))
        return func_0018ABB0(p);
    return (*(u16 *)(p + 0x35C) & 0x3C00) != 0;
}

int func_0018AB10(u8 *p)
{
    if (p[0x425])
        return 0;
    if (*(s8 *)(p + 0x539))
        return func_0018ABB0(p);
    return (*(u16 *)(p + 0x35C) & 0x360) != 0;
}

int func_0018AB60(u8 *p)
{
    if (p[0x425])
        return 0;
    if (*(s8 *)(p + 0x539))
        return func_0018ABB0(p);
    return (*(u16 *)(p + 0x35C) & 0x3F60) != 0;
}

