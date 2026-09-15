typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
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

void func_002E33C0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6] = 3;
        *(s16 *)(p + 28) = 20;
        func_001757E0(p, 22, 15);
    }
}

void func_002E5BA0(u8 *p)
{
    p[316] = 0;
    if (D_004D18A0 == 2) {
        p[6]++;
        p[316] = 1;
        func_001757E0(p, 18, 0);
    }
}

void func_002E7B60(u8 *p)
{
    p[828] = 5;
    if ((s8)func_00175700(p) < 0) {
        p[827] = 0;
        p[828] = 0;
        func_001843A0(p);
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

void func_002EB710(u8 *p)
{
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[7]++;
        *(s16 *)(p + 28) = 0;
        p[654] = 16;
        p[655] = 0;
    }
}

void func_002EBC90(u8 *p)
{
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[6]++;
        *(s16 *)(p + 28) = 0;
        p[654] = 16;
        p[655] = 0;
    }
}

void func_002EBEF0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 21, 14);
    }
}

void func_002ECD60(u8 *p)
{
    s16 t = *(s16 *)(p + 28);
    if ((t & 3) == 0) {
        u8 v = (u8)(t >> 2);
        func_003A6DC0(p, 0, v & 1);
    }
}

void func_002EF1C0(u8 *p)
{
    p[6]++;
    p[316] = 1;
    func_001757E0(p, 18, 0);
}

void func_002EF860(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_001E3240(p, 31);
        func_002F1DF0(p);
    }
}

void func_002F0F20(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[827] = 0;
        p[828] = 0;
        func_002F1DF0(p);
    }
}

void func_002F5170(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        *(f32 *)(p + 56) = *(f32 *)(p + 1072);
        p[525] = 0;
        func_001843A0(p);
    }
}

void func_002F92E0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        p[316] = 0;
        *(s16 *)(p + 28) = 16;
        *(s16 *)(p + 30) = 0;
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

void func_002FDAC0(u8 *p)
{
    func_00175700(p);
    if (--*(s16 *)(p + 28) == 0)
        p[5]++;
}

void func_002FDEF0(u8 *p)
{
    func_00175700(p);
    if (--*(s16 *)(p + 28) == 0) {
        func_00175C00(p, 0);
        func_001846B0(p);
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
