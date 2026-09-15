typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00178F20(u8 *, u8 *);
extern void func_001843A0(u8 *);
extern void func_0011D8F8(u8 *, int, int);
extern void func_001821D0(u8 *);
extern void func_00182380(void);
extern void func_001A78D0(u8 *, int);
extern void func_001B0F40(u8 *, int);
extern void func_00244450(u8 *);
extern void func_002445A0(u8 *);
extern void func_00244B90(u8 *);
extern void func_002477E0(u8 *);
extern void func_00248EC0(void);
extern void func_00249010(void);
extern void func_00253FC0(u8 *);
extern void func_0036BFF0(u8 *, int, int, int);

void func_00243600(u8 *p, u8 *q)
{
    if (p[6] == 0)
        p[520] = 2;
    else
        func_00178F20(q, p);
}

void func_00244400(u8 *p)
{
    func_002477E0(p);
    if (p[530] == 1)
        func_002445A0(p);
    else
        func_00244450(p);
}

void func_00244B40(u8 *p)
{
    if (p[533] != 0)
        func_00244B90(p);
    else {
        func_00182380();
        func_001821D0(p);
        func_00244B90(p);
    }
}

void func_00247070(u8 *p)
{
    s16 t;
    func_00175700(p);
    t = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = t - 1;
    if (t == 0) {
        func_001757E0(p, 22, 4);
        p[6]++;
    }
}

void func_00248E70(u8 *p)
{
    if (p[530] == 1)
        func_00249010();
    else
        func_00248EC0();
    *(u32 *)(p + 108) = 0xBF4DB6DB;
}

void func_0024AC50(u8 *p)
{
    p[826] = 0xFF;
    if (--*(s16 *)(p + 28) <= 0) {
        p[7]++;
        func_001757E0(p, 19, 4);
    }
}

void func_0024CCB0(u8 *p)
{
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[6]++;
        func_001A78D0(p, 16);
    }
}

void func_0024D620(u8 *p)
{
    u8 *q = p + 696;
    u32 saved = *(u32 *)q;
    u8 savedb = q[4];
    func_0011D8F8(p + 696, 0, 128);
    *(u32 *)q = saved;
    q[4] = savedb;
}

void func_00250340(u8 *p)
{
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[6]++;
        *(s16 *)(p + 450) = 128;
    }
}

void func_00252130(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[525] = 0;
        *(u32 *)(p + 92) = 0;
        *(u32 *)(p + 96) = 0;
        *(u32 *)(p + 104) = 0;
        *(u32 *)(p + 108) = 0;
        func_001843A0(p);
    }
}

void func_00252A70(u8 *p)
{
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[6]++;
        *(s16 *)(p + 28) = 120;
    }
}

void func_00253DD0(u8 *p)
{
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[337] = 0;
        func_00253FC0(p);
        p[6] = 3;
        *(s16 *)(p + 30) = 12;
    }
}

void func_0025E2F0(u8 *p)
{
    if ((s8)p[337] == 1) {
        p[337] = 0;
        func_001B0F40(p, 14);
        func_001B0F40(p, 10);
    }
    func_00175700(p);
}

void func_0025EC50(u8 *p)
{
    *(s16 *)(p + 870) = 0;
    p[525] = 0;
    *(u32 *)(p + 72) = 0;
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}

void func_0025EF10(u8 *p)
{
    if ((s8)p[337] <= 0) {
        p[6]++;
        p[337] = 0;
        func_0036BFF0(p, 0, 19, 0);
    }
    func_00175700(p);
}

void func_0025F100(u8 *p)
{
    s16 t = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = t - 1;
    if (t == 0) {
        p[6]++;
        func_001757E0(p, 21, 11);
    }
    func_00175700(p);
}

void func_0025F390(u8 *p)
{
    if ((s8)p[339] < 0) {
        p[6]++;
        func_001757E0(p, 21, 27);
    }
    func_00175700(p);
}

void func_0025F6B0(u8 *p)
{
    if ((s8)p[337] != 0) {
        p[6]++;
        func_0036BFF0(p, 4, 19, 4);
        p[337] = 0;
    }
    func_00175700(p);
}

void func_0025F810(u8 *p)
{
    if ((s8)p[337] != 0) {
        p[6]++;
        func_0036BFF0(p, 5, 19, 5);
        p[337] = 0;
    }
    func_00175700(p);
}
