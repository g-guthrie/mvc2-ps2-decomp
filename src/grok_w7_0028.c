typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;

extern s32 func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_001C8CE0(u8 *, int);
extern s32 func_003D92F0(u8 *);
extern void func_001843A0(u8 *);
extern void func_0028D810(u8 *, u8 *);
extern void func_001E3210(u8 *, int);
extern void func_001C09A0(u8 *, int);
extern u8 D_004563A0[];

typedef void (*DispatchFn)(u8 *);
extern DispatchFn jtbl_00455A30[];
extern DispatchFn jtbl_00456740[];

void func_00285790(u8 *p)
{
    func_00175700(p);
    if ((s16)(--*(s16 *)(p + 28)) == 0) {
        p[6]++;
        func_001757E0(p, 21, 28);
    }
}

void func_00288250(u8 *p)
{
    func_00175700(p);
    if ((s16)(--*(s16 *)(p + 28)) == 0) {
        p[6]++;
        func_001757E0(p, 18, 1);
    }
}

void func_00296E00(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        p[5]++;
    if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        func_001C8CE0(p, 0);
    }
}

void func_002831B0(u8 *p)
{
    if (func_003D92F0(p))
        func_001843A0(p);
    else
        jtbl_00455A30[p[32]](p);
}

void func_002883A0(u8 *p)
{
    if (func_003D92F0(p))
        func_001843A0(p);
    else
        jtbl_00456740[p[32]](p);
}

void func_0029A0C0(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 21, 5);
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
        *(s32 *)(p + 0x6C) = 0xBF4DB6DB;
    }
}

void func_002981C0(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        *(s16 *)(p + 0x1C) = 6;
        *(s16 *)(p + 0x1E) = 0x50;
        func_001757E0(p, 22, 4);
    }
}

void func_0029E550(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        *(s16 *)(p + 0x1C) = 0x18;
        *(s32 *)(p + 0x68) = 0x3E555555;
        if (*(s16 *)(p + 0x140))
            *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        func_001757E0(p, 22, 17);
    }
}

void func_0028C690(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (!*(s8 *)(p + 0x151)) {
        p[6]++;
        func_0028D810(p, D_004563A0);
    }
}

void func_0028C620(u8 *p)
{
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[6]++;
        func_001E3210(p, 0x2D);
        func_001C09A0(p, 0x1A);
    }
}
