typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_00182C30(s32, s32);
extern void func_00182DB0(u8 *, s32);
extern void func_001F67E0(u8 *);
extern void func_001F6A90(u8 *);
extern void func_00186A20(u8 *);
extern void func_00184540(u8 *);
extern s32 func_001864A0(u8 *);
extern void func_001865B0(u8 *);
extern void func_001820A0(u8 *);
extern void func_00182300(u8 *);
extern void func_001FDAE0(u8 *);
extern void func_00186A60(u8 *, s32);
extern void func_001843A0(u8 *);
extern void func_001F8820(u8 *);
extern void func_001F87E0(u8 *);
extern u8 *D_004C2840;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))

void func_001F3800(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 15, 44);
    }
}

void func_001F47B0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 15, 30);
    }
}

void func_001F2280(u8 *p)
{
    p[518] = 3;
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 15, 25);
    }
}

void func_001F4010(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        p[490] = 17;
        func_00186A20(p);
        func_001757E0(p, 15, 48);
    }
}

void func_001F59C0(u8 *p)
{
    if (*(s8 *)(p + 699) == 0) {
        func_00175700(p);
    } else {
        p[6]++;
        func_001757E0(p, 21, 10);
    }
}

void func_001F0280(u8 *p)
{
    p[6]++;
    if (I(D_004C2840, 28) & 1)
        func_001757E0(p, 19, 0);
    else
        func_001757E0(p, 19, 1);
}

void func_001F0420(u8 *p)
{
    I(p, 92) = 0;
    I(p, 96) = 0;
    I(p, 104) = 0;
    I(p, 108) = 0;
    p[528] = 0;
    p[525] = 0;
    F(p, 56) = F(p, 1072);
    func_00185490(p);
    func_00183D10(p);
}

void func_001F6940(u8 *p)
{
    p[7]++;
    func_00182C30(I(p, 476), 20);
    func_00182DB0(p, 3);
    S(p, 28) = 64;
    func_001F67E0(p);
}

void func_001F6BF0(u8 *p)
{
    p[7]++;
    func_00182C30(I(p, 476), 20);
    func_00182DB0(p, 3);
    S(p, 28) = 64;
    func_001F6A90(p);
}

void func_001FE600(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        S(p, 28) = 32;
        func_001757E0(p, 18, 1);
    }
}

void func_001FD8B0(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        func_00184540(p);
    if (func_001864A0(p))
        func_001865B0(p);
}

void func_001FDBE0(u8 *p)
{
    func_001820A0(p);
    func_00182300(p);
    if (p[530] == 1)
        func_001FDAE0(p);
    else
        func_001FD8B0(p);
}

void func_001F7180(u8 *p)
{
    s8 v;
    p[5] = 0; p[7] = 0; p[6] = 0;
    v = *(s8 *)(p + 1245);
    switch (v) {
    case 0: p[509] = 0; p[439] = 1; break;
    case 1: p[509] = 4; p[439] = 0; break;
    case 2: p[509] = 6; p[439] = 1; break;
    }
    func_00186A60(p, 21);
}

void func_001F71F0(u8 *p)
{
    s8 v;
    p[5] = 0; p[7] = 0; p[6] = 0;
    v = *(s8 *)(p + 1245);
    switch (v) {
    case 0: p[509] = 0; p[439] = 1; break;
    case 1: p[509] = 4; p[439] = 1; break;
    case 2: p[509] = 6; p[439] = 1; break;
    }
    func_00186A60(p, 21);
}

void func_001FBE30(u8 *p)
{
    s8 v;
    p[5] = 0; p[7] = 0; p[6] = 0;
    v = *(s8 *)(p + 1245);
    switch (v) {
    case 0: p[509] = 3; p[439] = 1; break;
    case 1: p[509] = 4; break;
    case 2: p[509] = 4; break;
    }
    func_00186A60(p, 29);
}

void func_001FBE90(u8 *p)
{
    s8 v;
    p[5] = 0; p[7] = 0; p[6] = 0;
    v = *(s8 *)(p + 1245);
    switch (v) {
    case 0: p[509] = 3; p[439] = 1; break;
    case 1: p[509] = 4; break;
    case 2: p[509] = 4; break;
    }
    func_00186A60(p, 29);
}

void func_001FBEF0(u8 *p)
{
    s8 v;
    p[5] = 0; p[7] = 0; p[6] = 0;
    v = *(s8 *)(p + 1245);
    switch (v) {
    case 0: p[509] = 1; p[439] = 1; break;
    case 1: p[509] = 0; p[439] = 1; break;
    case 2: p[509] = 0; p[439] = 1; break;
    }
    func_00186A60(p, 21);
}

void func_001FBF60(u8 *p)
{
    s8 v;
    p[5] = 0; p[7] = 0; p[6] = 0;
    v = *(s8 *)(p + 1245);
    switch (v) {
    case 0: p[509] = 1; p[439] = 1; break;
    case 1: p[509] = 0; p[439] = 1; break;
    case 2: p[509] = 1; p[439] = 1; break;
    }
    func_00186A60(p, 21);
}

void func_001FFE90(u8 *p)
{
    u8 *q = p + 696;
    p[714] = 6;
    if ((s8)func_00175700(p) < 0) {
        q[12] = 0;
        func_001843A0(p);
    }
}

void func_001F8770(u8 *p)
{
    func_001820A0(p);
    func_00182300(p);
    if (p[530] == 1)
        func_001F8820(p);
    else
        func_001F87E0(p);
    if (func_001864A0(p))
        func_001865B0(p);
}


