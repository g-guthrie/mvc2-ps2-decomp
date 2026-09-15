typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);

extern void func_001821D0(u8 *);
extern void func_00182380(u8 *);
extern void func_001843A0(u8 *);

extern void func_001C8B10(u8 *);
extern void func_001C9420(u8 *, int, int);
extern void func_001CCB70(u8 *, int);
extern s32 func_0028B0B0(u8 *);
extern s32 func_0028D8B0(u8 *);
extern void func_00292420(u8 *);
extern void func_002B4450(u8 *);
extern void func_002B4630(u8 *);
extern s32 func_002C0530(u8 *);
extern s32 func_002C0590(u8 *);
extern void func_002C1670(u8 *);
extern void func_002C6C60(u8 *);
extern s32 func_002D9730(u8 *);
extern s32 func_002D97A0(u8 *);
extern void func_002D9D10(u8 *);
extern void func_002E1520(u8 *, int);
extern s32 func_002E92E0(u8 *);
extern s32 func_002E9340(u8 *);
extern s32 func_002EE150(u8 *);
extern s32 func_002EE200(u8 *);
extern s32 func_003D92F0(u8 *);

void func_002882B0(u8 *p)
{
    if (func_0028D8B0(p) == 0)
        p[6]++;
}

void func_0028ABE0(u8 *p)
{
    if (--*(s16 *)(p + 0x1c) == 0)
        func_0028B0B0(p);
}

void func_00291F50(u8 *p)
{
    if (--*(s16 *)(p + 0x1c) == 0)
        func_00292420(p);
}

void func_002A8580(u8 *p)
{
    if (*(s8 *)(p + 0x151)) {
        p[6] = 0;
        *(u32 *)(p + 0x5c) = 0;
    }
}

void func_002B4A90(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151))
        p[0x151] = 0;
}

void func_002CF7F0(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        p[6]++;
    }
}

void func_002D2EA0(u8 *p)
{
    p[0x13c] = 0;
    if (--*(s16 *)(p + 0x1c) <= 0) {
        p[6]++;
        p[7] = 0;
        p[0x13c] = 1;
    }
}

void func_002D3CA0(u8 *p)
{
    p[0x151] = 0;
    if (p[0x1e6])
        *(u32 *)(p + 0x5c) = 0x41555555;
    else
        *(u32 *)(p + 0x5c) = 0xc1555555;
    *(u32 *)(p + 0x68) = 0;
}

void func_002D3CD0(u8 *p)
{
    p[0x151] = 0;
    if (p[0x1e6])
        *(u32 *)(p + 0x68) = 0xc0555555;
    else
        *(u32 *)(p + 0x68) = 0x40555555;
}

void func_002D7260(u8 *p)
{
    if (func_003D92F0(p))
        func_001843A0(p);
}

void func_002E4490(u8 *unused, u8 *q)
{
    if (*(s8 *)(q + 2) == 0)
        q[3] = 0;
}

void func_002E57B0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6] = 0;
        func_001843A0(p);
    }
}

void func_002B25F0(u8 *p)
{
    if (*(s32 *)(p + 0xd0) == 0)
        func_001757E0(p, 2, 1);
    else
        func_001757E0(p, 2, 5);
}

void func_002B4410(u8 *p)
{
    if (p[0x21])
        func_002B4630(p);
    else
        func_002B4450(p);
}

int func_002C04F0(u8 *p)
{
    if (func_002C0530(p))
        return 1;
    return func_002C0590(p) != 0;
}

void func_002C1630(u8 *p)
{
    if (!p[0x215]) {
        func_00182380(p);
        func_001821D0(p);
    }
    func_002C1670(p);
}

void func_002C6C20(u8 *p)
{
    if (!p[0x215]) {
        func_00182380(p);
        func_001821D0(p);
    }
    func_002C6C60(p);
}

int func_002D96F0(u8 *p)
{
    if (func_002D9730(p))
        return 1;
    return func_002D97A0(p) != 0;
}

void func_002D9D90(u8 *p)
{
    if (!p[0x215]) {
        func_00182380(p);
        func_001821D0(p);
    }
    func_002D9D10(p);
}

int func_002E92A0(u8 *p)
{
    if (func_002E92E0(p))
        return 1;
    return func_002E9340(p) != 0;
}

int func_002EE110(u8 *p)
{
    if (func_002EE150(p))
        return 1;
    return func_002EE200(p) != 0;
}

void func_00298390(u8 *p)
{
    if (--*(s16 *)(p + 0x1c) < 0) {
        *(s16 *)(p + 0x1c) = 2;
        func_001C8B10(p);
    }
}

void func_0029FA00(u8 *p)
{
    s8 v = *(s8 *)(p + 0x151);
    if (v) {
        p[0x151] = 0;
        func_001C9420(p, 1, v & 0x7f);
    }
}

void func_002ADE20(u8 *p)
{
    if (--*(s16 *)(p + 0x1c) < 0) {
        *(s16 *)(p + 0x1c) = 2;
        func_001CCB70(p, 8);
    }
}

void func_002E2AB0(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        func_002E1520(p, p[0x20d]);
}


