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

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
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
extern u8 *func_001B3E30(u8 *, int, int);
extern DispatchFn jtbl_00454C60[];
extern DispatchFn jtbl_00454CB0[];
extern DispatchFn jtbl_004553D0[];
extern DispatchFn jtbl_00454210[];
extern DispatchFn jtbl_00452CD0[];
extern void (*jtbl_00454340[])(u8 *, u8 *);

void func_00268FE0(u8 *p)
{
    func_00175700(p);
    if (--S(p, 0x1c) <= 0)
        func_001843A0(p);
}

void func_00278F00(u8 *p)
{
    if (--S(p, 0x1c) == 0) {
        p[6]++;
        p[0x13C] = 1;
        func_001E3210(p, 4);
    }
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

void func_00245B70(u8 *p)
{
    if (func_003D92F0(p)) {
        func_00175C00(p, 0);
        func_001843A0(p);
    } else {
        jtbl_00452CD0[p[0x20]](p);
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

void func_00267690(u8 *p, u8 *state_unused)
{
    if ((s8)func_00175700(p) < 0 && !(H(p, 0x354) & 0x2000)) {
        p[7] = 2;
        func_001757E0(p, 0x16, 0x27);
    }
}

void func_002676F0(u8 *p, u8 *state_unused)
{
    if ((s8)func_00175700(p) < 0 && !(H(p, 0x354) & 0x1000)) {
        p[7] = 3;
        func_001757E0(p, 0x16, 0x2B);
    }
}

void func_00268CE0(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        func_001757E0(p, 0x13, 9);
    } else if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
    }
}

void func_00269100(u8 *p)
{
    if ((s8)func_00175700(p) <= 0) {
        p[6]++;
        func_001757E0(p, 0x15, 0x18);
        func_001B3E30(p, 4, 0);
        func_001B3E30(p, 5, 0);
    }
}

