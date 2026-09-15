typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

extern s32 func_00175700(u8 *);
extern s32 func_00393390(u8 *);
extern void func_00393A20(void);
extern void func_00394080(void);
extern void func_00394700(void);
extern void func_00390CB0(u8 *, u8 *);
extern void func_00391620(u8 *, u8 *);
extern void func_00395890(u8 *);
extern s8 *D_004C29D4;
void func_00393860(u8 *p)
{
    func_00175700(p);
    if (func_00393390(p))
        func_00393A20();
    else if (D_004C29D4[9] >= 2)
        p[5]++;
}

void func_00393EC0(u8 *p)
{
    func_00175700(p);
    if (func_00393390(p))
        func_00394080();
    else if (D_004C29D4[9] >= 2)
        p[5]++;
}

void func_00394540(u8 *p)
{
    func_00175700(p);
    if (func_00393390(p))
        func_00394700();
    else if (D_004C29D4[9] >= 2)
        p[5]++;
}

void func_00390FB0(u8 *p, u8 *q)
{
    func_00175700(p);
    p[5]++;
    p[316] = 0;
    func_00390CB0(p, q);
    p[5] = 0;
    func_00391620(p, q);
}

void func_00397970(u8 *p)
{
    p[36] = 0;
    if ((s8)func_00175700(p) < 0) {
        p[316] = 0;
        p[4] = 2;
    }
}

void func_00394B10(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        func_00395890(p);
    else
        p[36] = 0;
}
