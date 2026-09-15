typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef void (*DispatchFn)(u8 *);

typedef struct {
    f32 x, y, z;
} V3;

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00175C00(u8 *, s32);
extern void func_001843A0(u8 *);
extern void func_00185490(u8 *);
extern void func_00183D10(u8 *);
extern void func_0011D8F8(u8 *, s32, s32);
extern void func_001266A0(u8 *, s32, s32);
extern void func_001B96F0(u8 *);
extern void func_001BE890(u8 *, s32);
extern void func_001E3210(u8 *, s32);
extern void func_001E3710(u8 *, s32);
extern void func_00191210(u8 *);
extern void func_00183D50(u8 *);
extern int func_0026B530(u8 *);
extern int func_0026B590(u8 *);
extern int func_0026F4A0(u8 *);
extern int func_0026F520(u8 *);
extern int func_00273CB0(u8 *);
extern int func_00273D10(u8 *);
extern void func_00276D00(u8 *);
extern int func_00267B00(u8 *);
extern int func_00267C90(u8 *, s32);
extern int func_00267E40(u8 *);
extern int func_003D92F0(u8 *);
extern void func_0026FF10(u8 *);
extern void func_003813B0(u8 *, s32);
extern void func_00381E40(u8 *, s32, s32);
extern DispatchFn jtbl_00454C60[];
extern DispatchFn jtbl_00454CB0[];
extern DispatchFn jtbl_004553D0[];
extern DispatchFn jtbl_00454620[];

int func_0026B4F0(u8 *p)
{
    if (func_0026B590(p))
        return 1;
    return func_0026B530(p) != 0;
}

void func_0026B6C0(u8 *p)
{
    if (p[0x1e5] == 0x1d && p[0x1fd] == 3)
        *(V3 *)(p + 0x50) = *(V3 *)(p + 0x298);
}

void func_0026EDC0(u8 *p)
{
    u8 *q = p + 0x2b8;
    s8 saved = *(s8 *)q;
    func_0011D8F8(p + 0x2b8, 0, 0x80);
    *q = saved;
}

int func_0026F460(u8 *p)
{
    if (func_0026F4A0(p))
        return 1;
    return func_0026F520(p) != 0;
}

void func_00270A00(u8 *p)
{
    p[0x33a] = 0xff;
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        func_001B96F0(p);
    }
}

int func_00273C70(u8 *p)
{
    if (func_00273CB0(p))
        return 1;
    return func_00273D10(p) != 0;
}

void func_00260020(u8 *p)
{
    *(s16 *)(p + 0x366) = 0;
    *(s32 *)(p + 0x48) = 0;
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}

void func_00275AD0(u8 *p)
{
    func_00276D00(p);
    jtbl_00454C60[p[6]](p);
}

void func_00276880(u8 *p)
{
    func_00276D00(p);
    jtbl_00454CB0[p[6]](p);
}

void func_00279E30(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_001E3710(p, 0x3a);
        func_001843A0(p);
    }
}

void func_0026A960(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_001266A0(p, 0xd, 0);
        func_001843A0(p);
    }
}

void func_0027FE70(u8 *p)
{
    func_00191210(p);
    p[0x23c] = 0;
    jtbl_004553D0[p[0x1e4]](p);
}

void func_00269AF0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[7] = 1;
        func_001757E0(p, 0x16, 0x29);
    }
}

void func_00270B10(u8 *p)
{
    p[0x210] = 0;
    p[0x20d] = 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    *(s32 *)(p + 0x5c) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6c) = 0;
    func_00185490(p);
    func_00183D10(p);
}

void func_00275A80(u8 *p)
{
    p[0x20d] = 0;
    *(s32 *)(p + 0x5c) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6c) = 0;
    func_00185490(p);
    func_00175C00(p, 1);
    func_00183D10(p);
}

void func_00264710(u8 *p)
{
    func_00175700(p);
    p[6]++;
    *(s32 *)(p + 0x5c) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x60) = 0x412b6db6;
    *(s32 *)(p + 0x6c) = 0xbf1a4924;
}

void func_00269960(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 0x16, 0x29);
    }
}

void func_002699B0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 0x16, 0x2b);
    }
}

void func_00269A00(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 0x16, 0x27);
    }
}

void func_00269A50(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 0x16, 0x2c);
    }
}

void func_00269AA0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 0x16, 0x26);
    }
}

void func_00277650(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 0x14, 3);
    }
}

void func_0027BF30(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        p[6]++;
    if (*(s8 *)(p + 0x151))
        p[0x209] = 1;
}

void func_0027C7D0(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x150)) {
        p[6]++;
        if (p[0x1b7] > 0)
            func_001BE890(p, 3);
    }
}

void func_00265700(u8 *p)
{
    p[0x209] = 2;
    if ((s8)func_00175700(p) < 0) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00183D50(p);
        func_001843A0(p);
    }
}

void func_00266F20(u8 *p)
{
    if (!func_00267B00(p) && !func_00267C90(p, 0) && !func_00267E40(p))
        func_00175700(p);
}

void func_0027C160(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
    else if (*(s8 *)(p + 0x151))
        p[0x209] = 1;
}

void func_0027F680(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        p[7] = 0;
        func_001757E0(p, 0x13, 6);
    }
}

void func_0027E2B0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_00185490(p);
        func_001757E0(p, 3, 2);
    }
}

void func_00260470(u8 *p)
{
    p[0x40c] = 2;
    p[0x33c] = 5;
    if ((s8)func_00175700(p) < 0) {
        p[0x40d] = 0;
        p[0x40c] = 0;
        p[0x33b] = 0;
        p[0x33c] = 0;
        func_001843A0(p);
    }
}

void func_0026CAB0(u8 *p)
{
    if (func_003D92F0(p))
        func_001843A0(p);
    else
        jtbl_00454620[p[32]](p);
}

void func_0026FEB0(u8 *p)
{
    if (p[0x1fc] == 2)
        func_0026FF10(p);
    else if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}

void func_00275790(u8 *p)
{
    if (func_003D92F0(p))
        func_001843A0(p);
    else {
        func_00175700(p);
        if (*(s8 *)(p + 0x151)) {
            p[0x151] = 0;
            func_001E3210(p, 0x10);
        }
    }
}

void func_0027C880(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        p[6]++;
        func_003813B0(p, 0);
        func_001BE890(p, 6);
    }
}

void func_0027ECE0(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[6]++;
        p[0x151] = 0;
        func_00381E40(p, 8, 0);
        *(s16 *)(p + 0x1c) = 120;
    }
}


