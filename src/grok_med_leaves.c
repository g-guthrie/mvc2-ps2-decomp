typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))

extern void func_00232B80(u8 *);
extern void func_00232C70(u8 *);
extern void func_00232D50(u8 *);
extern void func_00184540(u8 *);
extern void func_0018DDD0(u8 *);
extern void func_0018E0B0(u8 *);
extern void func_00175700(u8 *);
extern void func_00175670(u8 *);

void func_00232C30(u8 *p)
{
    p[6]++;
    I(p, 92) = 0;
    I(p, 96) = 0;
    I(p, 104) = 0;
    I(p, 108) = 0;
    func_00232B80(p);
}

void func_00232D10(u8 *p)
{
    p[6]++;
    I(p, 92) = 0;
    I(p, 96) = 0;
    I(p, 104) = 0;
    I(p, 108) = 0;
    func_00232C70(p);
}

void func_00232E20(u8 *p)
{
    p[6]++;
    I(p, 92) = 0;
    I(p, 96) = 0;
    I(p, 104) = 0;
    I(p, 108) = 0;
    func_00232D50(p);
}

void func_0032D110(u8 *p)
{
    f32 r = F(p, 8) / (f32)I(p, 4);
    F(p, 24) = r;
    F(p, 20) = r;
}

void func_0032D130(u8 *p)
{
    f32 r = F(p, 12) / (f32)I(p, 4);
    F(p, 32) = r;
    F(p, 28) = r;
}

void func_0032D150(u8 *p)
{
    f32 r = F(p, 16) / (f32)I(p, 4);
    F(p, 40) = r;
    F(p, 36) = r;
}

void func_002C40D0(u8 *p)
{
    p[533] = 0;
    I(p, 92) = 0;
    I(p, 104) = 0;
    I(p, 96) = 0;
    I(p, 108) = 0xBF4DB6DB;
    func_00184540(p);
}

void func_002CAFA0(u8 *p)
{
    p[533] = 0;
    I(p, 96) = 0;
    I(p, 104) = 0;
    I(p, 92) = 0;
    I(p, 108) = 0xBF4DB6DB;
    func_00184540(p);
}

void func_001C8C80(u8 *p)
{
    if (--S(p, 28) <= 0)
        p[4]++;
}

void func_00213970(u8 *p)
{
    if (--S(p, 28) <= 0)
        p[6]++;
}

void func_0018DD90(u8 *p)
{
    if (p[5] != 3 && p[584] == 0)
        p[584] = 0;
    func_0018DDD0(p);
}

void func_0018E070(u8 *p)
{
    if (p[5] != 3 && p[584] == 0)
        p[584] = 0;
    func_0018E0B0(p);
}

void func_00180060(u8 *p)
{
    if (--S(p, 28) < 0)
        p[6]++;
}

void func_0034BAC0(u8 *p)
{
    if (--S(p, 30) == 0)
        p[4]++;
}

void func_00337B40(u8 *p)
{
    if (--S(p, 28) == 0)
        p[4] = 0;
}

void func_0019E9B0(u8 *p)
{
    if (--S(p, 28) == 0)
        p[4]++;
    func_00175700(p);
}

void func_001B52F0(u8 *p)
{
    if (--S(p, 28) <= 0)
        p[4] = 2;
    func_00175670(p);
}

s32 func_00185150(u8 *p)
{
    if (S(p, 652) != 0)
        p[7]++;
    return 0;
}

void func_00190660(u8 *p, s16 a1, u8 a2)
{
    S(p, 1018) = a1;
    if (a1) {
        p[1026] = a2;
        S(p, 1020) = 0;
        p[1027] = 0;
        S(p, 1024) = 0;
        p[532] = 0;
    } else {
        p[1026] = 0;
    }
}

void func_00190690(u8 *p, s16 a1, u8 a2)
{
    S(p, 1020) = a1;
    if (a1) {
        p[1027] = a2;
        S(p, 1018) = 0;
        p[1026] = 0;
        S(p, 1024) = 0;
        p[532] = 0;
    } else {
        p[1027] = 0;
    }
}
