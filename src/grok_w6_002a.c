typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))

extern s8 func_00175700(u8 *);
extern void func_00186A60(u8 *, int);
extern int func_00189310(u8 *, u8 *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_001266A0(u8 *, int, int);
extern void func_00184540(u8 *);
extern void func_001843A0(u8 *);

extern u8 D_00458E70[];
extern u8 D_00459250[];

void func_002A5500(u8 *p, u8 *q)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((s16)(--S(p, 0x1C)) == 0) {
        p[7]++;
        q[9] = 3;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
    }
}

void func_002B8080(u8 *p)
{
    s8 v;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    v = (s8)p[0x4DD];
    switch (v) {
    case 0:
        p[0x1FD] = 0;
        break;
    case 1:
        p[0x1FD] = 1;
        break;
    case 2:
        p[0x1FD] = 14;
        break;
    }
    p[0x1B7] = 1;
    func_00186A60(p, 21);
}

void func_002B80E0(u8 *p)
{
    s8 v;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    v = (s8)p[0x4DD];
    switch (v) {
    case 0:
        p[0x1FD] = 0;
        break;
    case 1:
        p[0x1FD] = 1;
        break;
    case 2:
        p[0x1FD] = 2;
        break;
    }
    p[0x1B7] = 1;
    func_00186A60(p, 21);
}

void func_002A6E10(u8 *p)
{
    s8 v;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    v = (s8)p[0x4DD];
    switch (v) {
    case 0:
        p[0x1FD] = 0;
        p[0x1B7] = 1;
        break;
    case 1:
        p[0x1FD] = 3;
        p[0x1B7] = 1;
        break;
    case 2:
        p[0x1FD] = 2;
        p[0x1B7] = 1;
        break;
    }
    func_00186A60(p, 21);
}

void func_002AB880(u8 *p)
{
    s8 v;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    v = (s8)p[0x4DD];
    switch (v) {
    case 0:
        p[0x1FD] = 0;
        p[0x1B7] = 1;
        break;
    case 1:
        p[0x1FD] = 1;
        p[0x1B7] = 1;
        break;
    case 2:
        p[0x1FD] = 1;
        p[0x1B7] = 1;
        break;
    }
    func_00186A60(p, 21);
}

void func_002B2430(u8 *p)
{
    s8 v;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    v = (s8)p[0x4DD];
    switch (v) {
    case 0:
        p[0x1FD] = 0;
        p[0x1B7] = 1;
        break;
    case 1:
        p[0x1FD] = 5;
        p[0x1B7] = 1;
        break;
    case 2:
        p[0x1FD] = 1;
        p[0x1B7] = 1;
        break;
    }
    func_00186A60(p, 21);
}

void func_002B24A0(u8 *p)
{
    s8 v;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    v = (s8)p[0x4DD];
    switch (v) {
    case 0:
        p[0x1FD] = 0;
        p[0x1B7] = 1;
        break;
    case 1:
        p[0x1FD] = 5;
        p[0x1B7] = 1;
        break;
    case 2:
        p[0x1FD] = 1;
        p[0x1B7] = 1;
        break;
    }
    func_00186A60(p, 21);
}

void func_002A0AD0(u8 *p)
{
    s8 v;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    v = (s8)p[0x4DD];
    switch (v) {
    case 0:
        p[0x1FD] = 6;
        p[0x1B7] = 1;
        break;
    case 1:
        p[0x1FD] = 5;
        p[0x1B7] = 1;
        break;
    case 2:
        p[0x1FD] = 4;
        p[0x1B7] = 1;
        break;
    }
    func_00186A60(p, 21);
}

void func_002A0B40(u8 *p)
{
    s8 v;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    v = (s8)p[0x4DD];
    switch (v) {
    case 0:
        p[0x1FD] = 6;
        p[0x1B7] = 1;
        break;
    case 1:
        p[0x1FD] = 5;
        p[0x1B7] = 1;
        break;
    case 2:
        p[0x1FD] = 4;
        p[0x1B7] = 1;
        break;
    }
    func_00186A60(p, 21);
}

void func_002A6DA0(u8 *p)
{
    s8 v;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    v = (s8)p[0x4DD];
    switch (v) {
    case 0:
        p[0x1FD] = 0;
        p[0x1B7] = 1;
        break;
    case 1:
        p[0x1FD] = 2;
        p[0x1B7] = 1;
        break;
    case 2:
        p[0x1FD] = 3;
        p[0x1B7] = 1;
        break;
    }
    func_00186A60(p, 21);
}

void func_002A6A40(u8 *p)
{
    u8 *q;
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[6]++;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x1B5] = 37;
        func_001266A0(p, 0, 0);
    }
}

int func_002B2AE0(u8 *p)
{
    if (!func_00189310(p, D_00458E70, p + 888))
        return 0;
    func_0018A990(p, p + 888);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[509] = 0;
    func_00186A60(p, 21);
    return 1;
}

int func_002B8320(u8 *p)
{
    if (!func_00189310(p, D_00459250, p + 896))
        return 0;
    func_0018A990(p, p + 896);
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    p[509] = 0;
    func_00186A60(p, 21);
    return 1;
}

void func_002B66D0(u8 *p)
{
    F(p, 0x34) += F(p, 0x5C);
    F(p, 0x5C) += F(p, 0x68);
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[6]++;
        p[0x151] = 0;
        S(p, 0x1C) = 60;
    }
}

void func_002B6A00(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    F(p, 0x34) += F(p, 0x5C);
    F(p, 0x5C) += F(p, 0x68);
    if ((s8)func_00175700(p) < 0)
        p[6]++;
}

void func_002BDA90(u8 *p)
{
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    if ((s8)func_00175700(p) < 0) {
        if (p[0x20D] == 2)
            func_00184540(p);
        else
            func_001843A0(p);
    }
}
