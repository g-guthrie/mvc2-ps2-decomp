typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00178F20(u8 *);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
extern void func_00186CE0(u8 *, int);
extern void func_0011D8F8(u8 *, int, int);
extern int func_00248890(u8 *);
extern int func_002488F0(u8 *);
extern void func_00279270(u8 *);
extern void func_0027BD50(u8 *);
extern void func_00280330(u8 *);

void func_00277790(u8 *p)
{
    if (*(u16 *)(p + 860) & 2)
        *(u32 *)(p + 704) += 1;
}

void func_002610C0(u8 *p)
{
    s16 t;
    p[1036] = 2;
    p[828] = 5;
    t = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = t - 1;
    if (t == 0)
        p[6]++;
}

void func_00260A00(u8 *p)
{
    s16 t;
    p[1036] = 2;
    p[828] = 5;
    t = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = t - 1;
    if (t == 0) {
        p[6]++;
        *(s16 *)(p + 28) = 120;
    }
}

void func_002555E0(u8 *p)
{
    if (*(s16 *)(p + 696) > 0) {
        p[1037] = 0;
        p[1036] = 0;
        p[828] = 5;
    } else {
        p[1036] = 2;
        p[828] = 5;
    }
}

void func_00255620(u8 *p)
{
    if (*(s16 *)(p + 696) > 0) {
        p[1037] = 0;
        p[1036] = 0;
        p[828] = 5;
    } else {
        p[1037] = 0;
        p[1036] = 0;
        p[827] = 0;
        p[828] = 0;
    }
}

void func_0027B9B0(u8 *p)
{
    if (--*(s16 *)(p + 28) <= 0) {
        p[7]++;
        *(s16 *)(p + 30) = 30;
    }
}

void func_00247470(u8 *p)
{
    s16 t;
    func_00175700(p);
    t = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = t - 1;
    if (t == 0)
        func_001843A0(p);
}

void func_00249BB0(u8 *p)
{
    if (func_00175700(p) < 0) {
        func_00184540(p);
        return;
    }
}

void func_002760B0(u8 *p)
{
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
}

void func_00269B40(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6] = 8;
        p[7] = 0;
    }
}

void func_002616D0(u8 *p)
{
    *(u32 *)(p + 72) = 0;
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}

void func_00268F10(u8 *p)
{
    func_00175700(p);
    p[6]++;
    func_001757E0(p, 21, 19);
}

void func_0027FA20(u8 *p)
{
    p[316] = 0;
    if (--*(s16 *)(p + 28) < 0)
        func_00280330(p);
}

void func_00273DE0(u8 *p)
{
    *(u32 *)(p + 708) &= *(u16 *)(p + 852);
    if (*(s32 *)(p + 728) != 0) {
        if (*(s32 *)(p + 728) < 0)
            *(s32 *)(p + 728) = 0;
        else
            *(s32 *)(p + 728) -= 1;
    }
}

int func_00248850(u8 *p)
{
    if (func_00248890(p))
        return 1;
    return func_002488F0(p) != 0;
}

void func_00254390(u8 *p)
{
    u8 *q = p + 696;
    u8 saved = q[2];
    func_0011D8F8(p + 696, 0, 128);
    q[2] = saved;
}

void func_0026AFE0(u8 *p)
{
    s16 *q = (s16 *)(p + 696);
    s16 saved = q[15];
    func_0011D8F8(p + 696, 0, 128);
    q[15] = saved;
}

void func_00279230(u8 *p)
{
    func_00186CE0(p, 21);
    p[509] = 4;
    func_00279270(p);
}

void func_0027BC10(u8 *p)
{
    func_00186CE0(p, 21);
    p[509] = 4;
    func_0027BD50(p);
}

int func_00275A40(u8 *p)
{
    if (*(f32 *)(p + 56) < *(f32 *)(p + 1072)) {
        *(s32 *)(p + 92) = 0;
        *(s32 *)(p + 96) = 0;
        *(s32 *)(p + 104) = 0;
        *(s32 *)(p + 108) = 0;
        *(f32 *)(p + 56) = *(f32 *)(p + 1072);
        return 1;
    }
    return 0;
}

void func_00260F70(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    if (*(s8 *)(p + 339) < 0)
        p[6]++;
    func_00175700(p);
}
