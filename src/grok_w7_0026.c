typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00380270(u8 *, int, int);
extern void func_0037E080(u8 *, int, int);
extern void func_00280330(u8 *);
extern void func_001BFCA0(u8 *, int);
extern u8 D_004C0839;

void func_0027C040(u8 *p)
{
    p[521] = 1;
    if ((s16)(--*(s16 *)(p + 28)) == 0) {
        p[6]++;
        *(s16 *)(p + 28) = 20;
        func_00380270(p, 0, 1);
    }
}

void func_0027BFE0(u8 *p)
{
    p[521] = 1;
    if ((s16)(--*(s16 *)(p + 28)) == 0) {
        p[6]++;
        *(s16 *)(p + 28) = 20;
        func_00380270(p, 0, 0);
    }
}

void func_0027C0A0(u8 *p)
{
    p[521] = 1;
    if ((s16)(--*(s16 *)(p + 28)) == 0) {
        p[6]++;
        *(s16 *)(p + 28) = 20;
        func_00380270(p, 0, 2);
    }
}

void func_00260F10(u8 *p)
{
    s16 t;
    p[1036] = 2;
    p[828] = 5;
    t = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = t - 1;
    if (t == 0) {
        p[6]++;
        *(s16 *)(p + 28) = 20;
    } else if (p[33] == 0)
        func_00175700(p);
}

void func_0026AB20(u8 *p)
{
    func_00175700(p);
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    if ((s16)(--*(s16 *)(p + 28)) <= 0) {
        p[6]++;
        *(s32 *)(p + 104) = 0;
    }
}

void func_00279650(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
    else if (*(s8 *)(p + 337)) {
        p[828] = 5;
        if (*(s8 *)(p + 338) & 1)
            func_0037E080(p, 0, 0);
    }
}

void func_0027CB60(u8 *p)
{
    func_00175700(p);
    if ((s16)(--*(s16 *)(p + 28)) == 0) {
        p[6]++;
        func_001757E0(p, 21, (&D_004C0839)[p[439] * 2]);
    }
}

void func_0027F810(u8 *p)
{
    p[316] = 0;
    if ((s16)(--*(s16 *)(p + 28)) < 0)
        func_00280330(p);
    else if ((s16)(--*(s16 *)(p + 30)) < 0) {
        *(s16 *)(p + 30) = 12;
        func_001BFCA0(p, 3);
    }
}

