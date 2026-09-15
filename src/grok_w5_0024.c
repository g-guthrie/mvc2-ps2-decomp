typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_001843A0(u8 *);
extern void func_00248310(u8 *);
extern void func_001E3210(u8 *, int);
extern int func_003D92F0(void);
extern int func_001864A0(u8 *);
extern void func_001865B0(u8 *);
extern void func_001820A0(u8 *);
extern void func_00182300(u8 *);
extern void func_00240140(u8 *);
extern void func_002401F0(u8 *);
extern void func_001A3A10(u8 *, int, int);
extern void func_0018C4B0(u8 *, int);
extern int func_001A3F40(u8 *);
extern void func_0035EF90(u8 *, int, u8 *);
extern void func_001A7930(u8 *, int);
extern void func_00367F90(u8 *, int, int);
extern void func_001AD170(u8 *, int, int);
extern void func_001266A0(u8 *, int, int);

void func_002482C0(u8 *p)
{
    if (!p[533]) {
        F(p, 56) += F(p, 96);
        F(p, 96) += F(p, 108);
    }
    {
        f32 lim = F(p, 1072);
        if (!(lim <= F(p, 56)))
            *(f32 *)(p + 56) = lim;
    }
}

void func_002465F0(u8 *p)
{
    func_00175700(p);
    if (!*(s8 *)(p + 337)) {
        p[337] = 0;
        p[6]++;
        S(p, 28) = 36;
        S(p, 30) = 0;
        func_001E3210(p, 32);
    }
}

void func_00247D70(u8 *p)
{
    s16 t;
    func_00175700(p);
    func_00248310(p);
    t = S(p, 28);
    S(p, 28) = t - 1;
    if (t == 0) {
        p[6]++;
        func_001757E0(p, 15, 1);
    }
}

void func_00247F70(u8 *p)
{
    s16 t;
    func_00175700(p);
    func_00248310(p);
    t = S(p, 28);
    S(p, 28) = t - 1;
    if (t == 0) {
        p[6]++;
        func_001757E0(p, 15, 5);
    }
}

void func_0024ACA0(u8 *p)
{
    p[826] = 255;
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 13, 31);
    }
}

void func_0024C390(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 336)) {
        p[6]++;
        func_001A7930(p, 10);
    }
}

void func_00251050(u8 *p, u8 *q)
{
    func_00175700(p);
    if (q[8]) {
        p[6]++;
        func_001757E0(p, 21, (p[439] + 17) & 0xff);
    }
}

void func_00250FF0(u8 *p, u8 *q)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_00251050(p, q);
    }
}

void func_002407B0(u8 *p)
{
    if (p[484] == 22 && func_003D92F0())
        func_001843A0(p);
    else
        func_00175700(p);
}

void func_002400D0(u8 *p)
{
    func_001820A0(p);
    func_00182300(p);
    if (!p[530])
        func_00240140(p);
    else
        func_002401F0(p);
    if (func_001864A0(p))
        func_001865B0(p);
}

void func_002405A0(u8 *p)
{
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
    func_00175700(p);
    if (--S(p, 28) == 0) {
        p[6]++;
        func_001757E0(p, 2, 3);
    }
}

void func_00240670(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        p[316] = 1;
        func_001757E0(p, 18, 0);
    }
    if ((s8)func_00175700(p) < 0) {
        p[5]++;
        func_001757E0(p, 0, 0);
    }
}

void func_00240B80(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
    else if (*(s8 *)(p + 337)) {
        p[337] = 0;
        func_001A3A10(p, 1, 0);
    }
}

void func_00240CC0(u8 *p, s8 *q)
{
    func_00175700(p);
    if (*(s8 *)(p + 337)) {
        p[6]++;
        p[337] = 0;
        func_0018C4B0(p, 5);
        if (!func_001A3F40(p))
            *q = -1;
    }
}

void func_00240D30(u8 *p, s8 *q)
{
    func_00175700(p);
    if (*q == -1) {
        p[6]++;
        func_001757E0(p, 21, (p[439] + 14) & 0xff);
    }
}

void func_00242230(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 337)) {
        p[6]++;
        p[7] = 0;
        p[337] = 0;
        S(p, 28) = 360;
        func_0035EF90(p, 0, p);
    }
}

void func_002524C0(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    func_00175700(p);
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
    p[6]++;
}

void func_00252840(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 337)) {
        p[6]++;
        p[337] = 0;
        func_00367F90(p, 2, 0);
        func_001AD170(p, 6, 0);
    }
}

void func_00252960(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[525] = 0;
        func_001266A0(p, 0, 0);
        I(p, 92) = 0;
        I(p, 96) = 0;
        I(p, 104) = 0;
        I(p, 108) = 0;
        func_001843A0(p);
    }
}


