typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_001843A0(u8 *);
extern void func_00183D50(u8 *);
extern void func_001E3210(u8 *, s32);
extern void func_001BE890(u8 *, s32);
extern void func_001BA5D0(u8 *, s32);
extern void func_00379420(u8 *);
extern void func_001B8FB0(u8 *);
extern void func_001BC6C0(u8 *, s32);
extern void func_001E3270(u8 *, s32, f32);
extern s32 func_003D92F0(u8 *);
extern void func_001BC660(u8 *, s32);
extern void func_00378CD0(u8 *, s32);

typedef void (*DispatchFn)(u8 *);
extern DispatchFn jtbl_00454850[];

void func_00278F00(u8 *p)
{
    if (--*(s16 *)(p + 28) == 0) {
        p[6]++;
        p[316] = 1;
        func_001E3210(p, 4);
    }
}

void func_0027C100(u8 *p)
{
    p[521] = 1;
    if (--*(s16 *)(p + 28) == 0) {
        p[6]++;
        p[316] = 1;
        func_001757E0(p, 3, 2);
    }
}

void func_0027C820(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 337)) {
        p[6]++;
        p[337] = 0;
        func_001BE890(p, (u8)(p[439] + 4));
    }
}

void func_002748B0(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 337) == 5) {
        if (--*(s16 *)(p + 28) < 0)
            func_001843A0(p);
    }
}

void func_0027ED40(u8 *p)
{
    func_00175700(p);
    if (--*(s16 *)(p + 28) < 0) {
        p[6]++;
        func_001757E0(p, 21, 7);
    }
}

void func_00271FB0(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 337) < 0) {
        p[6]++;
        p[337] = 0;
        p[1037] = 0;
        p[1036] = 0;
        p[827] = 0;
        p[828] = 0;
    }
}

void func_00276250(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
    else if (*(s8 *)(p + 337) == 2) {
        p[337] = 0;
        func_001BA5D0(p, 1);
    }
}

void func_00271700(u8 *p)
{
    p[6] = 6;
    p[525] = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    func_00183D50(p);
    func_001757E0(p, 21, (u8)(p[439] + 18));
}

void func_00271F40(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 337)) {
        p[6]++;
        p[337] = 0;
        *(s16 *)(p + 28) = 0;
        func_00379420(p);
        func_001B8FB0(p);
    }
}

void func_00279C10(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 336)) {
        p[6]++;
        p[336] = 0;
        func_001BC6C0(p, 10);
        func_001BC6C0(p, 11);
        func_001BC6C0(p, 12);
    }
}

void func_00275630(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[5]++;
        *(u32 *)(p + 280) = 0x3F800000;
        *(u32 *)(p + 92) = 0;
        *(u32 *)(p + 96) = 0;
        *(u32 *)(p + 104) = 0;
        *(u32 *)(p + 108) = 0;
        *(f32 *)(p + 56) = *(f32 *)(p + 1072);
        p[525] = 0;
    }
}

void func_0027C990(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_001E3270(p, 21, 32.0f);
        func_001E3270(p, 27, 32.0f);
        func_001843A0(p);
    }
}

void func_00270880(u8 *p)
{
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    if (func_003D92F0(p))
        func_001843A0(p);
    else
        jtbl_00454850[p[32]](p);
}

void func_00279100(u8 *p)
{
    if (func_003D92F0(p))
        func_001843A0(p);
    else {
        func_00175700(p);
        if (*(s8 *)(p + 337)) {
            p[7]++;
            func_001BC660(p, 3);
        }
    }
}

void func_00270E60(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 337)) {
        p[6]++;
        p[337] = 0;
        func_00378CD0(p, 0);
        func_00378CD0(p, 1);
        func_00378CD0(p, 2);
        func_00378CD0(p, 3);
    }
}

void func_0027A500(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 337) == 0) {
        p[6]++;
        *(s16 *)(p + 28) = 60;
        if (p[486] == 0)
            *(u32 *)(p + 92) = 0xC1555555;
        else
            *(u32 *)(p + 92) = 0x41555555;
    }
}
