typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00126400(void);
extern void func_00175C00(u8 *, int);
extern void func_001821D0(u8 *);
extern void func_00182380(void);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
extern void func_001846B0(u8 *);
extern void func_001E3240(u8 *, int);
extern void func_002E8560(u8 *);
extern void func_002E9A40(u8 *);
extern void func_002E9BC0(u8 *);
extern void func_002EA5C0(u8 *);
extern void func_002EC5B0(u8 *);
extern void func_002F1DF0(u8 *);
extern void func_003A6DC0(u8 *, int, int);

extern u8 D_004D18A0;

void func_002E5BA0(u8 *p)
{
    p[316] = 0;
    if (D_004D18A0 == 2) {
        p[6]++;
        p[316] = 1;
        func_001757E0(p, 18, 0);
    }
}

void func_002E8540(u8 *p)
{
    p[6]++;
    *(s32 *)(p + 92) = 0;
    *(s32 *)(p + 96) = 0;
    *(s32 *)(p + 104) = 0;
    *(s32 *)(p + 108) = 0;
    func_002E8560(p);
}

void func_002E8560(u8 *p)
{
    u8 *other;
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[6]++;
        p[337] = 0;
        other = *(u8 **)(p + 476);
        *(u8 **)(other + 456) = p;
        other[522] = 1;
        other[486] = p[486];
        other[525] = 2;
        other[437] = 34;
        p[34] = 10;
        if (p[486] != 0)
            p[34] = 22;
        func_00126400();
    }
}

void func_002E85F0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        *(s32 *)(p + 96) = 0xC0CDB6DB;
        *(s32 *)(p + 108) = 0xBF092492;
        func_00184540(p);
    }
}

void func_002E99F0(u8 *p)
{
    func_002EC5B0(p);
    if (p[530] == 1)
        func_002E9BC0(p);
    else
        func_002E9A40(p);
}

void func_002EA570(u8 *p)
{
    if (p[533] != 0)
        func_002EA5C0(p);
    else {
        func_00182380();
        func_001821D0(p);
        func_002EA5C0(p);
    }
}

void func_002EB330(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        func_001757E0(p, 19, 2);
    } else
        func_00175700(p);
}

void func_002EF1C0(u8 *p)
{
    p[6]++;
    p[316] = 1;
    func_001757E0(p, 18, 0);
}

void func_002F5170(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        *(f32 *)(p + 56) = *(f32 *)(p + 1072);
        p[525] = 0;
        func_001843A0(p);
    }
}

void func_002FB9F0(u8 *p)
{
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[337] = 0;
        p[6]++;
        *(s32 *)(p + 108) = 0xBF4DB6DB;
    }
}

void func_002FC850(u8 *p, u8 *q)
{
    if (q[10] != 0) {
        if (p[5] != 0 || p[484] != 21 || p[509] != 0)
            q[10] = 0;
    }
}

void func_002FFF10(u8 *p)
{
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[6]++;
        *(s32 *)(p + 96) = 0;
        *(s32 *)(p + 108) = 0xBF4DB6DB;
    }
}

void func_002E8440(u8 *p)
{
    u8 *other;
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[6]++;
        p[337] = 0;
        other = *(u8 **)(p + 476);
        *(u8 **)(other + 456) = p;
        other[522] = 1;
        other[486] = p[486];
        other[525] = 2;
        other[437] = 32;
        p[34] = 5;
        if (p[486] != 0)
            p[34] = 27;
        func_00126400();
    }
}
