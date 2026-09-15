typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;

#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))

extern u8 D_004D18A0;
extern s32 func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_001820A0(u8 *);
extern s32 func_001864A0(u8 *);
extern void func_001E3240(u8 *, int);
extern void func_001865B0(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_0034FA80(u8 *, int);
extern void func_0034E160(u8 *, int);
extern void func_0020CB80(u8 *, u8 *);
extern void func_0020D250(u8 *, u8 *, int);
extern void func_00217DD0(u8 *);

s32 func_0020D350(u8 *p, u8 *q)
{
    if ((u8)(--q[8]) == 0) {
        q[7] = 0;
        return 0;
    }
    if (!(*(u16 *)(p + 866) & 0x800))
        return 0;
    q[7] = 0;
    return 1;
}

void residual_00217D80(u8 *p)
{
    if (D_004D18A0 < 2)
        p[316] = 0;
    else {
        p[6]++;
        p[316] = 1;
        func_00217DD0(p);
    }
}

void func_002157A0(u8 *p)
{
    func_00175700(p);
    func_001820A0(p);
    if (func_001864A0(p)) {
        func_001E3240(p, 31);
        func_001E3240(p, 32);
        func_001865B0(p);
    }
}

void residual_0020AC10(u8 *p)
{
    func_00175700(p);
    if (!*(s8 *)(p + 337)) {
        p[7]++;
        p[525] = 2;
        I(p, 92) = 0;
        I(p, 104) = 0;
        I(p, 96) = 0x414DB6DB;
        I(p, 108) = 0;
    }
}

void residual_0020F9F0(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 337)) {
        p[6]++;
        I(p, 92) = 0;
        I(p, 104) = 0;
        I(p, 96) = 0xC1892492;
        I(p, 108) = 0xBF4DB6DB;
    }
}

void residual_0020FD60(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 337)) {
        p[6]++;
        I(p, 92) = 0;
        I(p, 104) = 0;
        I(p, 96) = 0x42092492;
        I(p, 108) = 0xBF892492;
    }
}

void func_0020EB70(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
    else if (*(s8 *)(p + 337)) {
        p[337] = 0;
        func_0034FA80(p, 0);
    }
}

void func_0020EC90(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
    else if (*(s8 *)(p + 337)) {
        p[337] = 0;
        func_0034E160(p, 4);
    }
}

void residual_0020CB20(u8 *p, u8 *q)
{
    p[7]++;
    q[11]--;
    func_001757E0(p, 20, 7);
    func_0020CB80(p, q);
}

void func_0020CE10(u8 *p, u8 *q)
{
    if ((s8)func_00175700(p) < 0) {
        q[9] = 0;
        S(p, 28) = 240;
        func_0020D250(p, q, 0);
    }
}


