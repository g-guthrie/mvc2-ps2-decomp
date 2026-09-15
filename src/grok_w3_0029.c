typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_00175C00(u8 *, s32);
extern void func_00183D10(u8 *);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
extern void func_00185490(u8 *);
extern void func_00186A20(u8 *);
extern void func_001C9420(u8 *, s32, s32);
extern void func_001E3210(u8 *, s32);
extern s32 func_003D92F0(u8 *);
extern void func_0038DB00(u8 *, s32);
extern void func_002971B0(u8 *, u8 *);
extern void func_00294B20(u8 *, void *);
extern void func_00294BC0(u8 *);

extern u8 D_00457310;

typedef void (*DispatchFn)(u8 *);
extern DispatchFn jtbl_00457710[];
extern DispatchFn jtbl_00458180[];

void func_00290020(u8 *p)
{
    if (func_003D92F0(p))
        func_001843A0(p);
    else
        jtbl_00457710[p[32]](p);
}

void func_0029D310(u8 *p)
{
    if (func_003D92F0(p))
        func_001843A0(p);
    else
        jtbl_00458180[p[32]](p);
}

void func_0029E920(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    p[510] = 1;
    p[513] = 2;
    func_00175700(p);
    if (*(s8 *)(p + 337) == 0) {
        p[6]++;
        p[7] = 0;
    }
}

void func_0029FCC0(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 337) == 0) {
        p[6]++;
        func_00186A20(p);
        *(u32 *)(p + 92) = 0;
        *(u32 *)(p + 104) = 0;
        *(u32 *)(p + 96) = 0x414DB6DB;
        *(u32 *)(p + 108) = 0xBF092492;
    }
}

void func_002970C0(u8 *p)
{
    if ((s32)func_00175700(p) < 0)
        func_001843A0(p);
    else if (*(s8 *)(p + 337)) {
        p[337] = 0;
        func_0038DB00(p, 0);
    }
}

void func_00298F60(u8 *p)
{
    p[521] = 2;
    func_00175700(p);
    if (--*(s16 *)(p + 28) <= 0) {
        (*(u8 **)(p + 544))[513] = 48;
        func_001843A0(p);
    }
}

void func_00297420(u8 *p, u8 *q)
{
    func_00175700(p);
    func_002971B0(p, q);
    if (*(s8 *)(p + 337) == 0) {
        p[6]++;
        func_00186A20(p);
        func_00183D10(p);
    }
}

void func_002939F0(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 337) == 0) {
        func_001E3210(p, 45);
        p[6]++;
        func_00294B20(p, &D_00457310);
    }
}

void func_0029E230(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    --*(s16 *)(p + 28);
    if (*(s8 *)(p + 337)) {
        p[6]++;
        p[337] = 0;
        func_001C9420(p, 6, 0);
    }
    func_00175700(p);
}

void func_0029D5E0(u8 *p)
{
    func_001E3210(p, 43);
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 108) = 0;
    p[528] = 0;
    p[525] = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    func_00185490(p);
    func_00175C00(p, 0);
    func_00183D10(p);
}

void func_00293D40(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        p[7] = 0;
        p[1037] = 0;
        p[1036] = 0;
        p[827] = 0;
        p[828] = 0;
    }
    func_00294BC0(p);
}

