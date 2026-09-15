typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

extern s8 func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern int func_00364EC0(u8 *, int);
extern void func_001A78D0(u8 *, int);
extern void func_001757E0(u8 *, int, int);
extern void func_0024AB80(u8 *);
extern void func_001E3210(u8 *, int);
extern void func_001E3710(u8 *, int);
extern void func_0036A930(u8 *, int, int, int);

#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))

void func_0024FF50(u8 *p, u8 *q)
{
    func_00175700(p);
    if (*(s8 *)(p + 337)) {
        p[6]++;
        q[4] = 0;
        if (!func_00364EC0(p, 1))
            func_001843A0(p);
        else {
            p[655] = 0;
            p[654] = 16;
        }
    }
}

void func_0024AB20(u8 *p)
{
    p[826] = 255;
    p[7] = 3;
    I(p, 92) = 0;
    I(p, 96) = 0;
    I(p, 104) = 0;
    I(p, 108) = 0;
    func_001A78D0(p, 0);
    func_001757E0(p, 19, 3);
    func_0024AB80(p);
}

void func_0024C3F0(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 337)) {
        p[6]++;
        S(p, 28) = 0;
        S(p, 30) = 1;
        func_001E3210(p, 47);
        func_001A78D0(p, 2);
    }
}

void func_0025F640(u8 *p)
{
    s16 t;
    if (*(s8 *)(p + 337)) {
        p[337] = 0;
        func_001E3710(p, 22);
    }
    t = S(p, 28);
    S(p, 28) = t - 1;
    if (t == 0) {
        p[6]++;
        func_001757E0(p, 21, 13);
    }
    func_00175700(p);
}

void func_00251D60(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    func_00175700(p);
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 22, 5);
    }
}

void func_0024FFD0(u8 *p, u8 *q)
{
    func_00175700(p);
    if (!q[1])
        func_001843A0(p);
    else if (q[4]) {
        p[6]++;
        S(p, 28) = 0x20;
        func_001757E0(p, 21, 1);
    }
}

void func_00257FC0(u8 *p)
{
    if (*(s8 *)(p + 434)) {
        p[7]++;
        func_0036A930(p, 5, 0, 0);
    }
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}

void func_0024BC10(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 336)) {
        p[6]++;
        if (!p[439])
            func_001A78D0(p, 4);
        else
            func_001A78D0(p, 7);
    }
}
