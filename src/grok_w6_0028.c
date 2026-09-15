typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern s32 func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
extern void func_0018CEA0(u8 *);
extern void func_00280330(u8 *);
extern void func_00175C00(u8 *, s32);
extern s32 func_0028D910(u8 *, s32);
extern void func_0028D8B0(u8 *);
extern void func_001757E0(u8 *, s32, s32);

void func_002802B0(u8 *p)
{
    p[0x2B8] = 1;
    *(u32 *)(p + 0x2BC) = 0x3F800000;
    if (p[6] == 0) {
        p[6]++;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x6C) = 0;
        return;
    }
    func_0018CEA0(p);
    if ((s8)func_00175700(p) < 0)
        func_00280330(p);
}

void func_00284DF0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        if (p[0x20D] == 2) {
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x6C) = 0;
            func_00184540(p);
        } else {
            *(s32 *)(p + 0x5C) = 0;
            *(s32 *)(p + 0x60) = 0;
            *(s32 *)(p + 0x68) = 0;
            *(s32 *)(p + 0x6C) = 0;
            func_001843A0(p);
        }
    }
}

void func_0028C9F0(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        p[7] = 0;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
    }
    func_0028D8B0(p);
}

void func_002889F0(u8 *p)
{
    s8 v;
    func_00175700(p);
    v = *(s8 *)(p + 0x151);
    if (v < 0) {
        p[7]++;
        func_00175C00(p, 1);
    } else if (v == 0)
        func_00175C00(p, 1);
    else
        func_0028D910(p, 2);
}

void func_00296C20(u8 *p)
{
    f32 a;
    f32 b;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x6C) = 0;
    p[6]++;
    if (p[0x1E6])
        a = -20.0f;
    else
        a = 20.0f;
    *(f32 *)(p + 0x5C) = a;
    if (p[0x1E6])
        b = 0.625f;
    else
        b = -0.625f;
    *(f32 *)(p + 0x68) = b;
    func_001757E0(p, 2, 1);
}


