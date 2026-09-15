typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_001820A0(u8 *);
extern void func_00182300(u8 *);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
extern s32 func_001864A0(u8 *);
extern void func_00186A20(u8 *);
extern void func_001E24E0(u8 *, int);
extern void func_001E3710(u8 *, int);
extern void func_001EB060(u8 *, u8 *);
extern void func_001EFA70(u8 *);
extern void func_001EFC80(u8 *);
extern void func_00345830(u8 *, int);
extern void func_003471C0(u8 *, int);
extern u8 D_004F1F45;
extern u8 D_004F1F46;

void func_001E3C40(u8 *p)
{
    u8 *q = *(u8 **)(p + 544);
    func_001E3710(p, 35);
    func_001E24E0(q, 42);
    func_001E24E0(q, 43);
    func_001E3710(q, 58);
    func_001E3710(q, 59);
}

void func_001EAF70(u8 *p)
{
    if ((s32)func_00175700(p) < 0)
        func_001843A0(p);
    else if (*(s8 *)(p + 337)) {
        p[337] = 0;
        func_00345830(p, 0);
    }
}

void func_001EB2D0(u8 *p, u8 *q)
{
    func_00175700(p);
    func_001EB060(p, q);
    if (!*(s8 *)(p + 337)) {
        p[6]++;
        func_00186A20(p);
    }
}

void func_001EC200(u8 *p)
{
    if ((s32)func_00175700(p) < 0) {
        if (p[525] != 2)
            func_001843A0(p);
        else
            func_00184540(p);
    }
}

void func_001EC490(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 337)) {
        p[337] = 0;
        p[6]++;
        func_00186A20(p);
    }
}

void func_001EC7E0(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        func_001757E0(p, 20, 6);
    } else if ((s32)func_00175700(p) < 0)
        func_001843A0(p);
}

void func_001EF620(u8 *p)
{
    if ((s32)func_00175700(p) < 0)
        func_001843A0(p);
    else if (p[508] == 2 && p[347]) {
        func_001E3710(p, 22);
        p[347] = 0;
    }
}

void func_001EF7A0(u8 *p)
{
    if ((s32)func_00175700(p) < 0)
        func_001843A0(p);
    if (p[508] == 2 && p[347]) {
        func_001E3710(p, 22);
        p[347] = 0;
    }
}

void func_001EF970(u8 *p)
{
    func_00175700(p);
    if (func_001864A0(p)) {
        p[7]++;
        *(s32 *)(p + 92) = 0;
        *(s32 *)(p + 96) = 0;
        *(s32 *)(p + 104) = 0;
        *(s32 *)(p + 108) = 0;
        D_004F1F45 = 1;
        D_004F1F46 = 1;
        func_001E3710(p, 44);
        p[525] = 0;
        func_001757E0(p, 11, 9);
    }
}

void func_001EFA00(u8 *p)
{
    if ((s32)func_00175700(p) < 0) {
        *(s16 *)(p + 320) ^= 1;
        func_001843A0(p);
    } else if (*(s8 *)(p + 337)) {
        p[337] = 0;
        *(s16 *)(p + 320) ^= 1;
    }
}

void func_001EFD70(u8 *p)
{
    func_001820A0(p);
    func_00182300(p);
    if (p[530] == 1)
        func_001EFC80(p);
    else
        func_001EFA70(p);
}

void func_001FA5E0(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    p[521] = 2;
    if ((s32)func_00175700(p) < 0) {
        func_001757E0(p, 22, 9);
        p[6]++;
    } else if (*(s8 *)(p + 337)) {
        func_003471C0(p, 0);
        p[337] = 0;
    }
}

void func_001FA660(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    p[521] = 2;
    if ((u8)(--p[32]) == 0) {
        p[1037] = 0;
        p[1036] = 0;
        p[827] = 0;
        p[828] = 0;
        p[6]++;
        func_001757E0(p, 22, 10);
    } else
        func_00175700(p);
}
