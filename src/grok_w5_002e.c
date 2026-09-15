typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00175C00(u8 *, int);
extern void func_001266A0(u8 *, int, int);
extern void func_001843A0(u8 *);
extern void func_00185490(u8 *);
extern void func_00186A60(u8 *, int);
extern void func_00183D10(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_0018C6E0(u8 *);
extern int func_00189310(u8 *, void *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_001D2A10(u8 *, int);
extern void func_003A2470(u8 *);
extern void func_002E09B0(u8 *);
extern u32 D_0045ADC0[];
extern u8 D_0045AEC0[];
extern u8 D_0045AED0[];

void residual_002E0060(u8 *p)
{
    p[6]++;
    p[525] = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    *(s16 *)(p + 28) = 60;
    *(s32 *)(p + 92) = 0;
    *(s32 *)(p + 96) = 0;
    *(s32 *)(p + 104) = 0;
    *(s32 *)(p + 108) = 0;
    func_00185490(p);
    func_001757E0(p, 20, 2);
}

void func_002E00D0(u8 *p)
{
    func_00175700(p);
    if (--*(s16 *)(p + 28) == 0) {
        p[6]++;
        func_001757E0(p, 20, 3);
    }
}

void func_002E04D0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        if (--*(s16 *)(p + 28) == 0)
            func_001843A0(p);
    }
}

void func_002E0600(u8 *p)
{
    func_001266A0(p, 5, 5);
    func_0018C6E0(p);
    ((void (*)(u8 *))D_0045ADC0[p[523] & 0x3f])(p);
}

void func_002E07E0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001D2A10(p, 0);
        func_001757E0(p, 15, 1);
    }
}

void residual_002E0960(u8 *p)
{
    p[6]++;
    *(s32 *)(p + 92) = 0;
    *(s32 *)(p + 96) = 0;
    *(s32 *)(p + 104) = 0;
    *(s32 *)(p + 108) = 0;
    func_001D2A10(p, 1);
    func_002E09B0(p);
}

void residual_002E09D0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        *(s32 *)(p + 92) = 0;
        *(s32 *)(p + 96) = 0xC11A4924;
        *(s32 *)(p + 104) = 0;
        *(s32 *)(p + 108) = 0xBF892492;
        func_001757E0(p, 15, 3);
    }
}

int func_002E11E0(u8 *p)
{
    if (!func_00189310(p, D_0045AEC0, p + 920))
        return 0;
    func_0018A990(p, p + 920);
    p[5] = 0;
    func_00186A60(p, 21);
    p[7] = 0;
    p[6] = 0;
    p[509] = 4;
    p[531] = 0;
    return 1;
}

int func_002E1250(u8 *p)
{
    if (!func_00189310(p, D_0045AED0, p + 936))
        return 0;
    func_0018A990(p, p + 936);
    p[5] = 0;
    func_00186A60(p, 21);
    p[7] = 0;
    p[6] = 0;
    p[509] = 8;
    p[531] = 0;
    return 1;
}

void func_002E2CC0(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    func_00175700(p);
    if (--*(s16 *)(p + 28) < 0) {
        p[6]++;
        func_001757E0(p, 22, 2);
    }
}

void func_002E3160(u8 *p)
{
    p[6]++;
    func_00175C00(p, 0);
    func_00185490(p);
    func_00183D10(p);
    p[525] = 0;
    func_0018C4B0(p, 5);
    func_001757E0(p, 21, 19);
}

void func_002E31D0(u8 *p)
{
    func_00175700(p);
    if ((s8)p[337] != 0) {
        p[337] = 0;
        p[6]++;
        *(s16 *)(p + 450) = 128;
        *(s16 *)(p + 28) = 16;
        if (p[439] == 0)
            *(s16 *)(p + 28) += 4;
    }
}

void func_002E3360(u8 *p)
{
    p[513] = 2;
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_003A2470(p);
        func_001757E0(p, 22, 14);
    }
}

