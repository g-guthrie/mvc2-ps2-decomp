typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern void func_00178F20(u8 *, u8 *);
extern void func_00179150(u8 *, u8 *);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
extern void func_00186A20(u8 *);
extern void func_00183D10(u8 *);
extern void func_001266A0(u8 *, int, int);
extern void func_001CCB70(u8 *, int);
extern void func_001CE4A0(u8 *, int);
extern void func_00391650(u8 *, int);
extern void func_00394780(u8 *, int, int);
extern void func_00397580(u8 *, int);
extern void func_002AD6F0(u8 *);
extern u8 D_004D18A0;

void func_002B7000(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        *(u32 *)(p + 0x6c) = 0xbf4db6db;
        func_00184540(p);
    }
}

void func_002A0980(u8 *p)
{
    if (*(s16 *)(p + 0x1c)) {
        func_00175700(p);
        if (*(s8 *)(p + 0x153) & 0x80)
            *(s16 *)(p + 0x1c) = 0;
    }
}

void func_002AFDF0(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        p[6]++;
        func_00186A20(p);
        func_00183D10(p);
    }
}

void func_002A5B20(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x1dc);
    if ((s32)q[6] > 0)
        func_00178F20(q, p);
    else
        func_00179150(q, p);
}

void func_002AD6B0(u8 *p)
{
    if (D_004D18A0 < 2)
        p[0x13c] = 0;
    else {
        p[7]++;
        func_002AD6F0(p);
    }
}

void func_002B4580(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        *(s16 *)(p + 0x1c) = 0x3c;
        func_001757E0(p, 0x12, 1);
    }
}

void func_002B4850(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        *(s16 *)(p + 0x1c) = 0x78;
        func_001757E0(p, 0xd, 0x1f);
    }
}

void func_002B5A00(u8 *p)
{
    p[1036] = 2;
    p[828] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        p[6]++;
        func_00397580(p, 1);
    }
}

void func_002A9300(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x161) & 1) {
        p[6]++;
        func_00186A20(p);
        func_00394780(p, 7, 0);
    }
}

void func_002B6740(u8 *p)
{
    func_00175700(p);
    *(s16 *)(p + 0x1c) = *(s16 *)(p + 0x1c) - 1;
    if (*(s16 *)(p + 0x1c) <= 0) {
        *(u32 *)(p + 0x5c) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6c) = 0;
        func_001843A0(p);
    }
}

void func_002AE850(u8 *p)
{
    func_00175700(p);
    if (--*(s16 *)(p + 0x1c) <= 0) {
        u8 *q = *(u8 **)(p + 0x220);
        q[0x201] = 0x30;
        func_001843A0(p);
    }
}

void func_002AEA00(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        p[6]++;
        if (*(s32 *)(p + 0xd0) == 0) {
            func_001CCB70(p, 6);
            p[0x2c7] = 1;
        }
    }
}

void func_002A4130(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        func_00391650(p, 1);
    }
}

void func_002A65B0(u8 *p)
{
    u8 *q;
    func_00175700(p);
    p[6]++;
    q = *(u8 **)(p + 0x1dc);
    *(u8 **)(q + 0x1c8) = p;
    q[0x20a] = 1;
    q[0x1b5] = 0x23;
    func_001266A0(p, 0, 0);
}

void func_002B9BA0(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        p[5]++;
    else if (*(s8 *)(p + 0x151) < 0) {
        p[0x151] = 0;
        func_001CE4A0(p, 0);
    }
}

void func_002B4520(u8 *p)
{
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5c);
    *(f32 *)(p + 0x5c) += *(f32 *)(p + 0x68);
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[6]++;
        p[0x151] = 0;
    }
}

void func_002AF4B0(u8 *p)
{
    *(f32 *)(p + 0x5c) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5c);
    if ((s8)func_00175700(p) < 0)
        func_001843A0(p);
}
