typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00175C00(u8 *, s32);
extern void func_001843A0(u8 *);
extern void func_00186A20(u8 *);
extern s32 func_00280EC0(u8 *);
extern void func_00280F80(u8 *);
extern void func_0028D810(u8 *, u8 *);
extern u8 D_00456520[];
extern void func_00383B80(u8 *, s32, s32);
extern void func_00397580(u8 *, s32);
extern void func_00296CE0(u8 *);
extern void func_001CB610(u8 *, s32);

void func_00280E70(u8 *p)
{
    if (!p[0x496] && !p[0x1e4]) {
        if (func_00280EC0(p) == 0)
            func_00280F80(p);
    }
}

void func_002824F0(u8 *p)
{
    func_00175700(p);
    if (--*(s16 *)(p + 0x1c) < 0)
        p[7]++;
}

void func_00285670(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[6]++;
        p[0x151] = 0;
        func_00383B80(p, 5, 0);
    }
}

void func_00288630(u8 *p)
{
    if (*(s16 *)(p + 0x1c) == 0) {
        p[7] = 4;
        func_001757E0(p, 0x13, 1);
    }
    func_00175700(p);
}

void func_00288680(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[7]++;
        p[0x33a] = 0xff;
    }
}

void func_00288950(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[7]++;
        func_0028D810(p, D_00456520);
    }
}

void func_00288CC0(u8 *p)
{
    if (*(s16 *)(p + 0x1c) == 0) {
        p[7]++;
        func_001757E0(p, 0x13, 0xc);
    }
    func_00175700(p);
}

void func_00290180(u8 *p)
{
    if (*(s16 *)(p + 0x1c) == 0) {
        p[7]++;
        func_001757E0(p, 0x13, 0);
    }
    func_00175700(p);
}

void func_00290500(u8 *p)
{
    if (*(s16 *)(p + 0x1c) == 0) {
        p[7]++;
        func_001757E0(p, 0x13, 1);
    }
    func_00175700(p);
}

void func_00290660(u8 *p)
{
    if (*(s16 *)(p + 0x1c) == 0) {
        p[7]++;
        func_001757E0(p, 0x13, 8);
    }
    func_00175700(p);
}

void func_002907A0(u8 *p)
{
    if (*(s16 *)(p + 0x1c) == 0) {
        p[7]++;
        func_001757E0(p, 0xe, 0);
    }
    func_00175700(p);
}

void func_00296C90(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        p[6]++;
        func_00296CE0(p);
    }
}

void func_002A0710(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[6]++;
        p[0x151] = 0;
        func_001CB610(p, 2);
    }
}

void func_002A2E30(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        p[7]++;
        func_00186A20(p);
    }
}

void func_002B48B0(u8 *p)
{
    func_00175700(p);
    *(s16 *)(p + 0x1c) = *(s16 *)(p + 0x1c) - 1;
    if (*(s16 *)(p + 0x1c) <= 0) {
        p[6]++;
        func_001757E0(p, 0x11, 0);
    }
}

void func_002B45E0(u8 *p)
{
    func_00175700(p);
    *(s16 *)(p + 0x1c) = *(s16 *)(p + 0x1c) - 1;
    if (*(s16 *)(p + 0x1c) <= 0) {
        p[5]++;
        p[6] = 0;
    }
}

void func_002B4DE0(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[6]++;
        p[0x151] = 0;
        func_00397580(p, 0);
    }
}

void func_002B50B0(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        p[6]++;
        func_00175C00(p, 0);
        func_00186A20(p);
    }
}

void func_002B64E0(u8 *p)
{
    func_00175700(p);
    *(s16 *)(p + 0x1c) = *(s16 *)(p + 0x1c) - 1;
    if (*(s16 *)(p + 0x1c) <= 0)
        func_001843A0(p);
}

void func_002B6B70(u8 *p)
{
    p[6]++;
    p[0x40c] = 2;
    p[0x33c] = 5;
    func_001757E0(p, 0x15, 0x22);
    *(s16 *)(p + 0x1c) = 60;
}

void func_002BD640(u8 *p)
{
    p[0x1fe] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    if (--*(s16 *)(p + 0x1e) < 0) {
        p[6]++;
        *(s16 *)(p + 0x1e) = 8;
    }
}


