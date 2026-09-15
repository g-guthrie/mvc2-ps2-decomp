typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

#define F(p, o) (*(float *)((u8 *)(p) + (o)))

extern void func_00174910(u8 *, int);
extern s32 func_00175700(u8 *);
extern void func_001E7F60(u8 *);
extern s32 func_00174470(u8 *);
extern void func_00375210(u8 *);
extern void func_00375750(u8 *);
extern void func_00375C90(u8 *);

extern void (*jtbl_00463590[])(u8 *, u8 *);
extern void (*jtbl_00463750[])(u8 *);
extern void (*jtbl_00463F30[])(u8 *);
extern void (*jtbl_00463F40[])(u8 *);
extern void (*jtbl_00463F50[])(u8 *);

void func_003608F0(u8 *p)
{
    func_00174910(p, 700);
    func_00175700(p);
    func_001E7F60(p);
    if (*(s8 *)(p + 434) || *(s8 *)(p + 435))
        p[4]++;
}

void func_00362CA0(u8 *p)
{
    func_00175700(p);
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
    if (!func_00174470(p)) {
        p[4]++;
        p[316] = 0;
    }
}

void func_00363150(u8 *p)
{
    func_00175700(p);
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
    if (!func_00174470(p)) {
        p[4]++;
        p[316] = 0;
    }
}

void func_00364D80(u8 *p)
{
    func_00175700(p);
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
    if (!func_00174470(p)) {
        p[4]++;
        p[316] = 0;
        p[0] = 0;
    }
}

void func_00365CF0(u8 *p)
{
    func_00175700(p);
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
    F(p, 56) += F(p, 96);
    F(p, 96) += F(p, 108);
    func_001E7F60(p);
}

void func_003622F0(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    if (q[4] >= 2) {
        p[4]++;
        p[316] = 0;
        return;
    }
    jtbl_00463590[p[32]](p, q);
}

void func_00364410(u8 *p)
{
    if ((*(u8 **)(p + 8))[4] >= 2) {
        p[4]++;
        p[316] = 0;
        return;
    }
    jtbl_00463750[p[5]](p);
}

void func_00375040(u8 *p)
{
    if (p[4] < 2)
        func_00375210(p);
    jtbl_00463F30[p[4]](p);
}

void func_003754E0(u8 *p)
{
    if (p[4] < 2)
        func_00375750(p);
    jtbl_00463F40[p[4]](p);
}

void func_00375AB0(u8 *p)
{
    if (p[4] < 2)
        func_00375C90(p);
    jtbl_00463F50[p[4]](p);
}

