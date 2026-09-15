typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define H(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U(p, o) (*(u32 *)((u8 *)(p) + (o)))

typedef void (*DispatchFn)(u8 *);
typedef struct { f32 x, y, z; } Vec3;

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_001843A0(u8 *);
extern void func_001266A0(u8 *, s32, s32);
extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, s32);
extern void func_00183D10(u8 *);
extern void func_00276D00(u8 *);
extern void func_001E3210(u8 *, s32);
extern void func_001E3710(u8 *, s32);
extern void func_00191210(u8 *);
extern void func_001BE890(u8 *, s32);
extern int func_003D92F0(u8 *);
extern void func_001B3E30(u8 *, s32, s32);
extern DispatchFn jtbl_00454C60[];
extern DispatchFn jtbl_00454CB0[];
extern DispatchFn jtbl_004553D0[];
extern DispatchFn jtbl_00454210[];
extern void (*jtbl_00454340[])(u8 *, u8 *);

void func_00260020(u8 *p)
{
    S(p, 0x366) = 0;
    I(p, 0x48) = 0;
    if (func_00175700(p) < 0)
        func_001843A0(p);
}

void func_00264710(u8 *p)
{
    func_00175700(p);
    p[6]++;
    F(p, 0x5c) = 0.0f;
    F(p, 0x68) = 0.0f;
    U(p, 0x60) = 0x412B6DB6;
    U(p, 0x6c) = 0xBF1A4924;
}

void func_00268FE0(u8 *p)
{
    func_00175700(p);
    if (--S(p, 0x1c) <= 0)
        func_001843A0(p);
}

void func_00269960(u8 *p)
{
    if (func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 0x16, 0x29);
    }
}

void func_002699B0(u8 *p)
{
    if (func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 0x16, 0x2B);
    }
}

void func_00269A00(u8 *p)
{
    if (func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 0x16, 0x27);
    }
}

void func_00269A50(u8 *p)
{
    if (func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 0x16, 0x2C);
    }
}

void func_00269AA0(u8 *p)
{
    if (func_00175700(p) < 0) {
        p[7]++;
        func_001757E0(p, 0x16, 0x26);
    }
}

void func_00269AF0(u8 *p)
{
    if (func_00175700(p) < 0) {
        p[7] = 1;
        func_001757E0(p, 0x16, 0x29);
    }
}

void func_0026A960(u8 *p)
{
    if (func_00175700(p) < 0) {
        func_001266A0(p, 0xD, 0);
        func_001843A0(p);
    }
}

void func_0026B6C0(u8 *p)
{
    if (p[0x1E5] == 0x1D && p[0x1FD] == 3)
        *(Vec3 *)(p + 0x50) = *(Vec3 *)(p + 0x298);
}

void func_00275A80(u8 *p)
{
    p[0x20D] = 0;
    F(p, 0x5c) = 0.0f;
    F(p, 0x60) = 0.0f;
    F(p, 0x68) = 0.0f;
    F(p, 0x6c) = 0.0f;
    func_00185490(p);
    func_00175C00(p, 1);
    func_00183D10(p);
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

void func_00277650(u8 *p)
{
    if (func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 0x14, 3);
    }
}

void func_00278F00(u8 *p)
{
    if (--S(p, 0x1c) == 0) {
        p[6]++;
        p[0x13C] = 1;
        func_001E3210(p, 4);
    }
}

void func_00279E30(u8 *p)
{
    if (func_00175700(p) < 0) {
        func_001E3710(p, 0x3A);
        func_001843A0(p);
    }
}

void func_0027BF30(u8 *p)
{
    if (func_00175700(p) < 0)
        p[6]++;
    if (*(s8 *)(p + 0x151))
        p[0x209] = 1;
}

void func_0027C7D0(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x150)) {
        p[6]++;
        if (p[0x1B7] > 0)
            func_001BE890(p, 3);
    }
}

void func_0027FE70(u8 *p)
{
    func_00191210(p);
    p[0x23C] = 0;
    jtbl_004553D0[p[0x1E4]](p);
}

void func_00260800(u8 *p)
{
    p[0x40D] = 0;
    p[0x40C] = 0;
    p[0x33B] = 0;
    p[0x33C] = 0;
    if (*(s8 *)(p + 0x153) < 0) {
        func_001266A0(p, 0, 0xD);
        func_001843A0(p);
    } else {
        func_00175700(p);
    }
}

void func_00261060(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (*(s8 *)(p + 0x153) < 0) {
        p[6]++;
        S(p, 0x1c) = 10;
        func_001757E0(p, 0x16, 0xD);
    } else {
        func_00175700(p);
    }
}

void func_00264860(u8 *p)
{
    if (func_003D92F0(p)) {
        func_00175C00(p, 0);
        func_001843A0(p);
    } else {
        jtbl_00454210[p[0x20]](p);
    }
}

void func_00266EB0(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    jtbl_00454340[p[7]](p, p + 0x2B8);
    p[0x216] |= 0x80;
    p[0x1FF] = 2;
    func_00191210(p);
}

void func_00267690(u8 *p)
{
    if (func_00175700(p) < 0 && !(H(p, 0x354) & 0x2000)) {
        p[7] = 2;
        func_001757E0(p, 0x16, 0x27);
    }
}

void func_002676F0(u8 *p)
{
    if (func_00175700(p) < 0 && !(H(p, 0x354) & 0x1000)) {
        p[7] = 3;
        func_001757E0(p, 0x16, 0x2B);
    }
}

void func_00268CE0(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        func_001757E0(p, 0x13, 9);
    } else if (func_00175700(p) < 0) {
        func_001843A0(p);
    }
}

void func_00269100(u8 *p)
{
    if (func_00175700(p) <= 0) {
        p[6]++;
        func_001757E0(p, 0x15, 0x18);
        func_001B3E30(p, 4, 0);
        func_001B3E30(p, 5, 0);
    }
}


