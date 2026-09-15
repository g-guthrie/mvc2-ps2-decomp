typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

typedef void (*DispatchFn)(u8 *);

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00183D50(u8 *);
extern void func_001843A0(u8 *);
extern s32 func_003D92F0(u8 *);
extern void func_00398A90(u8 *);
extern void func_0039BC20(u8 *, s32);
extern void func_003A0890(u8 *, s32);
extern void func_002D6820(u8 *);
extern void func_002DC1B0(u8 *);
extern void func_001E3710(u8 *, s32);
extern void func_00184540(u8 *);
extern u8 *func_0039C5B0(u8 *, s32);

extern DispatchFn jtbl_00459A90[];
extern DispatchFn jtbl_00459DE0[];
extern DispatchFn jtbl_0045A470[];
extern DispatchFn jtbl_0045AA60[];

void func_002C2220(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        p[5]++;
    else if (*(s8 *)(p + 337)) {
        p[337] = 0;
        func_00398A90(p);
    }
}

void func_002D3000(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[5]++;
        p[7] = 0;
        p[6] = 0;
        func_001757E0(p, 0, 0);
    }
}

void func_002CD9A0(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
    else if (*(s8 *)(p + 337)) {
        p[337] = 0;
        func_0039BC20(p, 0);
    }
}

void func_002DE2B0(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
    else if (*(s8 *)(p + 337)) {
        p[337] = 0;
        func_003A0890(p, 0);
    }
}

void func_002D45B0(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        p[1037] = 0;
        p[1036] = 0;
        p[827] = 0;
        p[828] = 0;
    }
}

void func_002D6950(u8 *p)
{
    if (!p[530]) {
        if (*(s8 *)(p + 490) & 0xf)
            func_002D6820(p);
    } else if (*(s8 *)(p + 490) & 0xf0)
        func_002D6820(p);
}

void func_002D4240(u8 *p)
{
    *(s32 *)(p + 92) = 0;
    *(s32 *)(p + 96) = 0;
    *(s32 *)(p + 104) = 0;
    *(s32 *)(p + 108) = 0;
    func_001757E0(p, 1, 4);
    func_00183D50(p);
    *(f32 *)(p + 56) = *(f32 *)(p + 0x430);
    func_001E3710(p, 52);
}

void func_002C75C0(u8 *p)
{
    if (func_003D92F0(p))
        func_001843A0(p);
    else
        jtbl_00459DE0[p[32]](p);
}

void func_002D3130(u8 *p)
{
    if (func_003D92F0(p))
        func_001843A0(p);
    else
        jtbl_0045A470[p[32]](p);
}

void func_002DA5A0(u8 *p)
{
    if (func_003D92F0(p))
        func_002DC1B0(p);
    else
        jtbl_0045AA60[p[32]](p);
}

void func_002C2280(u8 *p)
{
    *(f32 *)(p + 56) = *(f32 *)(p + 0x430);
    if (func_003D92F0(p))
        func_001843A0(p);
    else
        jtbl_00459A90[p[32]](p);
}

void func_002D5110(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[1037] = 0;
        p[1036] = 0;
        p[827] = 0;
        p[828] = 0;
        *(s32 *)(p + 92) = 0;
        *(s32 *)(p + 96) = 0;
        *(s32 *)(p + 104) = 0;
        *(s32 *)(p + 108) = 0;
        func_001843A0(p);
    }
}

void func_002DF540(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        p[7] = 0;
        func_001757E0(p, 22, 12);
    }
}

void func_002DB590(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    *(s32 *)(p + 760) = 96;
    if ((s8)func_00175700(p) < 0) {
        p[1037] = 0;
        p[1036] = 0;
        p[827] = 0;
        p[828] = 0;
        *(s32 *)(p + 760) = 32;
        func_00184540(p);
    }
}

void func_002D7890(u8 *p)
{
    func_00175700(p);
    if (--*(s16 *)(p + 28) == 0) {
        p[6]++;
        func_001757E0(p, 21, 3);
    }
}

void func_002D37F0(u8 *p)
{
    u8 *q;
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
    else if (*(s8 *)(p + 337)) {
        p[337] = 0;
        q = func_0039C5B0(p, 4);
        if (q)
            *(s16 *)(q + 152) = 2;
    }
}

