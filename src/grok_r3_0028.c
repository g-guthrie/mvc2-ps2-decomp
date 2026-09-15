typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00175C00(u8 *, s32);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
extern void func_001846B0(u8 *);
extern void func_00186A20(u8 *);
extern void func_001C09A0(u8 *, s32);
extern void func_001CBDA0(u8 *, s32, s32);
extern void func_001D5670(u8 *, s32, s32);
extern void func_001E3240(u8 *, s32);
extern void func_001E3710(u8 *, s32);
extern s32 func_0028D8B0(u8 *);
extern void func_00289570(u8 *);
extern void func_00290E30(u8 *);
extern void func_00294BC0(u8 *);
extern void func_0029F470(u8 *);
extern void func_002D4240(u8 *);
extern void func_002EBB00(u8 *);
extern void func_002F1DF0(u8 *);
extern void func_002F8D80(u8 *);
extern void func_00383B80(u8 *, s32, s32);
extern s32 func_00174A40(u8 *, s32);
extern s32 func_001864A0(u8 *);

void func_00285730(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[6]++;
        p[0x151] = 0;
        *(s16 *)(p + 0x1c) = 22;
        func_00383B80(p, 6, 0);
    }
}

void func_00289510(u8 *p)
{
    func_00289570(p);
    func_0028D8B0(p);
    if ((s8)func_00175700(p) < 0) {
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6c) = 0;
        func_00184540(p);
    }
}

void func_00289C90(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[7]++;
        func_001C09A0(p, 8);
        func_001E3710(p, 75);
    }
}

void func_0028FEA0(u8 *p)
{
    if (--*(s16 *)(p + 0x1c) == 0) {
        p[7]++;
        func_001757E0(p, 8, 2);
    } else {
        func_00175700(p);
    }
}

void func_002904A0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        *(s16 *)(p + 0x1c) = 1;
        func_001757E0(p, 0, 0);
    }
}

void func_00290DD0(u8 *p)
{
    func_00290E30(p);
    func_00294BC0(p);
    if ((s8)func_00175700(p) < 0) {
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x6c) = 0;
        func_00184540(p);
    }
}

void func_00293990(u8 *p)
{
    p[0x40c] = 2;
    p[0x33c] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[6]++;
        func_001C09A0(p, 26);
    }
}

void func_0029E070(u8 *p)
{
    func_00175700(p);
    if (--*(s16 *)(p + 0x1c) < 0)
        func_001843A0(p);
}

void func_0029F590(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_0029F470(p);
    }
}

void func_002A2C10(u8 *p)
{
    p[0x33a] = 0xff;
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        func_001CBDA0(p, 4, 0);
    }
}

void func_002A5340(u8 *p, u8 *q)
{
    func_00175700(p);
    if (*(s8 *)(q + 8) < 0) {
        *(u32 *)(p + 0x5c) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6c) = 0;
        func_001843A0(p);
    }
}

void func_002AD4C0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        *(s16 *)(p + 0x1c) = 18;
        func_001757E0(p, 18, 0);
    }
}

void func_002AD660(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[5]++;
        p[6] = 0;
        p[7] = 0;
    }
}

void func_002B0290(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[0x1e6] ^= 1;
        func_001843A0(p);
    }
}

void func_002B4910(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[5]++;
        p[6] = 0;
        *(u32 *)(p + 0x5c) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6c) = 0;
    }
}

void func_002B6250(u8 *p)
{
    p[0x40c] = 2;
    p[0x33c] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        p[6]++;
        func_00186A20(p);
    }
}

void func_002BB620(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[6]++;
        *(s16 *)(p + 450) = 128;
        *(s16 *)(p + 0x1c) = 1;
        *(s16 *)(p + 0x1e) = 8;
    }
}

void func_002D4190(u8 *p)
{
    func_00175700(p);
    func_00174A40(p, 2000);
    if (func_001864A0(p)) {
        p[6]++;
        func_002D4240(p);
    }
}

void func_002D7210(u8 *p)
{
    func_00175700(p);
    if (*(s16 *)(p + 0x1c) == 0)
        p[5]++;
    else
        --*(s16 *)(p + 0x1c);
}

void func_002D7F10(u8 *p)
{
    func_00175700(p);
    if (--*(s8 *)(p + 698) == 0)
        func_001843A0(p);
}

void func_002E33C0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6] = 3;
        *(s16 *)(p + 0x1c) = 20;
        func_001757E0(p, 22, 15);
    }
}

void func_002E7B60(u8 *p)
{
    p[828] = 5;
    if ((s8)func_00175700(p) < 0) {
        p[827] = 0;
        p[828] = 0;
        func_001843A0(p);
    }
}

void func_002EA120(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[7]++;
        *(s16 *)(p + 0x1c) = 10;
        func_001D5670(p, 2, 2);
    }
}

void func_002EB710(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[7]++;
        *(s16 *)(p + 0x1c) = 0;
        p[654] = 16;
        p[655] = 0;
    }
}

void func_002EB970(u8 *p)
{
    func_002EBB00(p);
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[7]++;
        *(s16 *)(p + 0x1c) = 0;
        p[654] = 16;
        p[655] = 0;
    }
}

void func_002EBC90(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[6]++;
        *(s16 *)(p + 0x1c) = 0;
        p[654] = 16;
        p[655] = 0;
    }
}

void func_002EBEF0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 21, 14);
    }
}

void func_002EF860(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_001E3240(p, 0x1f);
        func_002F1DF0(p);
    }
}

void func_002F0F20(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[0x33b] = 0;
        p[0x33c] = 0;
        func_002F1DF0(p);
    }
}

void func_002F8C60(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        func_001757E0(p, 19, 2);
        func_002F8D80(p);
    } else {
        func_00175700(p);
    }
}

void func_002F8CC0(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        func_001757E0(p, 19, 1);
        func_002F8D80(p);
    } else {
        func_00175700(p);
    }
}

void func_002F8D20(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        func_001757E0(p, 19, 2);
        func_002F8D80(p);
    } else {
        func_00175700(p);
    }
}

void func_002F92E0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[7]++;
        p[316] = 0;
        *(s16 *)(p + 0x1c) = 16;
        *(s16 *)(p + 0x1e) = 0;
    }
}

void func_002FDAC0(u8 *p)
{
    func_00175700(p);
    if (--*(s16 *)(p + 0x1c) == 0)
        p[5]++;
}

void func_002FDEF0(u8 *p)
{
    func_00175700(p);
    if (--*(s16 *)(p + 0x1c) == 0) {
        func_00175C00(p, 0);
        func_001846B0(p);
    }
}
