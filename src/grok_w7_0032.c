typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u8 *func_003DA750(s32, s32, s32);
extern void func_0032EF10(u8 *);
extern void func_0032F050(u8 *);
extern void func_0032F7E0(u8 *);
extern void func_0032F890(u8 *);
extern int func_0032C180(int);
extern int func_00334880(u8 *);
extern void func_00329100(u8 *);
extern void func_00329750(u8 *);
extern void func_003289F0(u8 *);
extern void func_00328C70(u8 *);
extern void func_00328EC0(u8 *);
extern void func_00329510(u8 *);
extern void func_00329810(u8 *);
extern int func_00174170(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern u8 *D_004C2840;
extern u8 D_00583B90[];
extern s8 D_00583BC7[];
typedef void (*DispatchFn)(u8 *);
extern DispatchFn jtbl_0045E898[];

void func_0032EEC0(u8 *p)
{
    switch (p[4]) {
    case 0:
        func_0032EF10(p);
        break;
    case 1:
        func_0032F050(p);
        break;
    }
}

void func_0032F790(u8 *p)
{
    switch (p[4]) {
    case 0:
        func_0032F7E0(p);
        break;
    case 1:
        func_0032F890(p);
        break;
    }
}

void func_00334840(u8 *p)
{
    if (func_00334880(p)) {
        p[5]++;
        p[6] = 1;
    }
}

void func_0032C520(void)
{
    if (!func_0032C180(0)) {
        *(s8 *)(D_004C2840 + 4) += 1;
        *(s16 *)(D_004C2840 + 8) = 15;
    }
}

void func_0032CE20(void)
{
    if (!func_0032C180(1)) {
        *(s8 *)(D_004C2840 + 4) += 1;
        *(s16 *)(D_004C2840 + 8) = 15;
    }
}

void func_0032C4E0(void)
{
    if (D_00583B90[D_00583BC7[0]] == 1)
        *(s8 *)(D_004C2840 + 4) += 1;
}

void func_00326690(u8 *p)
{
    unsigned v = (unsigned)func_00174170(p);
    func_001757E0(p, 0, (u8)(v % 3 + 10));
}

void func_003290B0(u8 *a0)
{
    u8 *p = func_003DA750(0, 12, 1);
    if (p) {
        *(s16 *)(p + 38) = 5;
        *(void **)(p + 16) = func_00329100;
        *(void **)(p + 24) = a0;
    }
}

void func_00329700(u8 *a0)
{
    u8 *p = func_003DA750(0, 12, 1);
    if (p) {
        *(s16 *)(p + 38) = 9;
        *(void **)(p + 16) = func_00329750;
        *(void **)(p + 24) = a0;
    }
}

void func_00328990(u8 *a0)
{
    u8 *p = func_003DA750(0, 12, 0);
    if (p) {
        *(void **)(p + 16) = func_003289F0;
        *(void **)(p + 24) = a0;
        *(s16 *)(p + 38) = 0x200;
        (*(s8 *)(a0 + 0x23D))++;
    }
}

void func_00328C10(u8 *a0)
{
    u8 *p = func_003DA750(0, 12, 0);
    if (p) {
        *(void **)(p + 16) = func_00328C70;
        *(void **)(p + 24) = a0;
        *(s16 *)(p + 38) = 0x300;
        (*(s8 *)(a0 + 0x23D))++;
    }
}

void func_00328E60(u8 *a0)
{
    u8 *p = func_003DA750(0, 12, 0);
    if (p) {
        *(void **)(p + 16) = func_00328EC0;
        *(void **)(p + 24) = a0;
        *(s16 *)(p + 38) = 0x400;
        (*(s8 *)(a0 + 0x23D))++;
    }
}

void func_003294B0(u8 *a0)
{
    u8 *p = func_003DA750(0, 12, 0);
    if (p) {
        *(void **)(p + 16) = func_00329510;
        *(void **)(p + 24) = a0;
        *(s16 *)(p + 38) = 0x700;
        (*(s8 *)(a0 + 0x23D))++;
    }
}

void func_003297B0(u8 *a0)
{
    u8 *p = func_003DA750(0, 12, 0);
    if (p) {
        *(void **)(p + 16) = func_00329810;
        *(void **)(p + 24) = a0;
        p[1] = a0[1];
        *(s16 *)(p + 38) = 10;
    }
}

void func_003320C0(u8 *p)
{
    jtbl_0045E898[p[5]](p);
    *(s32 *)(p + 0xDC) = *(s32 *)(*(u8 **)(p + 0x14) + 0xDC);
}
