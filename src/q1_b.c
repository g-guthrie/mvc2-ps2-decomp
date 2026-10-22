typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s16 D_004B5770[][2];
extern s16 D_004B5772[][2];
extern s32 func_001266A0(u8 *, s32, s32);
extern s32 func_001757E0(u8 *, s32, s32);
extern void func_0015D010(u8 *, u32 *);
extern void func_0018C6E0(u8 *);
extern void func_00388780(u8 *);
extern s32 func_00175700(u8 *);
extern void func_001E7F60(u8 *);
extern s32 func_00189310(u8 *, void *, u8 *);
extern void func_00186A60(u8 *, s32);
extern u8 D_0045DDA0[];
extern u8 D_004511E0[];
extern void func_001A70B0(u8 *, s32, s32);
extern void func_001E3210(u8 *, s32);
extern void func_001B0FA0(u8 *, s32);
extern s32 func_00175670(u8 *);
extern s32 func_003DAA40(u8 *, u8 *);
extern f32 D_004641E0[];
extern f32 D_00464200[];
extern u8 D_004636F0[];
extern void func_001754A0(u8 *, s32, s32);


void func_0023EAD0(u8 *p)
{
    u32 v[3];
    func_001266A0(p, 5, 5);
    func_001757E0(p, 0xF, (u8)(p[0x1B7] + 2));
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    v[0] = 0xC36E5555;
    v[1] = 0x43294924;
    v[2] = 0;
    func_0015D010(p, v);
    func_0018C6E0(p);
}

extern u8 *D_004C2794;

s32 func_003127B0(u8 *p)
{
    p[6]++;
    p[0x20D] = 2;
    *(u32 *)(p + 0x5C) = 0xC1F00000;
    if (p[0x1E6] != 0) *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0x3E892492;
    *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    p[0x1B5] = 0x3A;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(u32 *)(p + 0x1D8) = 0;
    (*(s16 *)((p[2] << 1) + (u32)D_004C2794 + 0x7C))++;
    return func_001757E0(p, 0x14, 0);
}

void func_00388440(u8 *p, u8 *q)
{
    if (*(s8 *)(p + 0x1B2) != 0 || *(s8 *)(p + 0x1B3) != 0) {
        p[4]++;
        p[5] = 0;
        *(u32 *)(q + 0xD0) &= ~(1 << p[0x20]);
    } else {
        if (*(s32 *)(q + 0xD4) < 0) {
            p[5]++;
            func_00388780(p);
        }
        func_00175700(p);
        func_001E7F60(p);
    }
}



void func_00247ED0(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u8 *q;
        *(s8 *)(p + 0x151) = 0;
        p[6]++;
        *(s16 *)(p + 0x1C) = 0x1E;
        q = *(u8 **)(p + 0x1DC);
        q[0x20A] = 1;
        q[0x20D] = 2;
        q[0x1B5] = 0x22;
        p[0x1B5] = 0x22;
        q[0x1E6] = p[0x1E6];
        q[0x1E6] ^= 1;
        func_001A70B0(p, 1, 1);
        func_001E3210(p, 0x22);
    }
}

void func_001B2DC0(u8 *p)
{
    if ((*(u8 **)(p + 0x18))[0x1E4] != 0x16) {
        p[4]++;
    } else {
        if (*(s8 *)(p + 0x151) == 1) {
            *(s8 *)(p + 0x151) = 0;
            func_001B0FA0(p, 9);
            func_001B0FA0(p, 8);
        }
        if (*(s8 *)(p + 0x151) == 2) {
            *(s8 *)(p + 0x151) = 0;
            func_001B0FA0(p, 0xB);
        }
        if (*(s8 *)(p + 0x153) >= 0) func_00175670(p);
    }
}

s32 func_0037D9F0(u8 *a, u8 *b)
{
    f32 d;
    s32 i = a[0x23];
    if (i >= 6) return func_003DAA40(a, b);
    d = D_004641E0[(u8)i];
    if (*(s16 *)(a + 0x140) == 0) d = -d;
    *(f32 *)(a + 0x34) = *(f32 *)(b + 0x34) + d;
    *(f32 *)(a + 0x38) = *(f32 *)(b + 0x38) + D_00464200[a[0x23]];
    if (a[0x23] == 1) *(u32 *)(a + 0x48) = 0xE4FB;
}

typedef struct { f32 x, y, z; } V3;

void func_00364470(u8 *a)
{
    u8 *t = *(u8 **)(a + 0x14);
    u8 *e;
    a[5]++;
    *(s16 *)(a + 0x1C) = 10;
    *(s16 *)(a + 0x1E) = 0xC80;
    *(V3 *)(a + 0x34) = *(V3 *)(t + 0x34);
    *(u32 *)(a + 0x50) = 0x3FC00000;
    *(u32 *)(a + 0x54) = 0x3FC00000;
    e = D_004636F0 + a[0x23] * 4;
    a[0x24] = 8;
    a[0x31] = *(s8 *)e;
    a[0x22] = e[1];
    if (*(s16 *)(a + 0x140) != 0) a[0x22] = (32 - *(s8 *)(a + 0x22)) & 0x1F;
    func_001754A0(a, 0x1B, e[3]);
}

extern void (*D_004C1BFC[2])();
extern int func_00174470(const void *);

void func_00360F40(u8 *p, u8 *q)
{
    if (*(u16 *)(q + 0x168) != *(u16 *)(p + 0xD0)) {
        p[4]++;
    } else if (func_00174470(p) == 0 || !(*(f32 *)(q + 0x430) <= *(f32 *)(p + 0x38))) {
        p[4]++;
    } else {
        D_004C1BFC[p[5]](p, q);
    }
}

extern u8 D_0045AEF0[];
extern s32 func_0018A990(u8 *, u8 *);


extern u8 *func_003DA750(s32, s32, s32);
extern void func_001DC1A0(u8 *);

void func_001DC0F0(u8 *p, u16 x, f32 a, f32 b)
{
    u8 *o;
    if ((o = func_003DA750(0, 3, 0)) != 0) {
        *(void **)(o + 0x10) = (void *)func_001DC1A0;
        *(u32 *)(o + 0x18) = *(u32 *)(p + 0x18);
        o[1] = p[1];
        *(u8 **)(o + 0xD0) = p;
        o[0x20] = x >> 8;
        o[0x21] = x;
        *(s16 *)(o + 0x26) = 0x3600;
        *(f32 *)(o + 0x34) = a;
        *(f32 *)(o + 0x38) = b;
        o[0x22] = p[0x22];
        p[0x22] ^= 1;
    }
}

extern void func_001843A0(u8 *);
extern void func_001E3A40(u8 *);

void func_002BF6B0(u8 *p)
{
    u32 v[3];
    u8 *q;
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (p[0x15B] != 0) {
        p[0x15B] = 0;
        v[0] = 0x42555555;
        v[1] = 0x42F00000;
        v[2] = 0;
        func_0015D010(p, v);
        p[0x1B4] = 10;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 2;
        q[0x1B5] = 0x25;
        func_001E3A40(p);
    }
}

void func_00317F50(u8 *p)
{
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        *(u32 *)(p + 0x68) = 0xBFBAAAAA;
        if (*(s16 *)(p + 0x140) != 0) *(f32 *)(p + 0x68) = -*(f32 *)(p + 0x68);
        func_001757E0(p, 2, 3);
    }
}

void func_002E52E0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    switch (p[0x1FC]) {
    case 0:
    case 1:
        break;
    case 2:
        if (*(s8 *)(p + 0x151) != 0) {
            *(s8 *)(p + 0x151) = 0;
            p[0x1B5] = 5;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            (*(s16 *)((p[2] << 1) + (u32)D_004C2794 + 0x7C))++;
        }
        break;
    }
}

extern void func_00179150(u8 *, u8 *);
extern void func_001E0760(u8 *, s32);

void func_00325EE0(u8 *p)
{
    u32 v[3];
    u8 *q;
    f32 x, y;
    v[0] = 0xC1555555;
    v[1] = 0x42092492;
    func_0015D010(p, v);
    func_001266A0(p, 5, 5);
    func_001757E0(p, 0xF, p[0x20B] & 0x3F);
    q = *(u8 **)(p + 0x1DC);
    x = *(f32 *)(p + 0x34);
    y = *(f32 *)(p + 0x38);
    func_00179150(p, q);
    *(f32 *)(p + 0x34) = x;
    *(f32 *)(p + 0x38) = y;
    func_0018C6E0(p);
    if (p[0x20D] != 2) func_001E0760(p, 1);
}

extern void func_00184540(u8 *);

void func_0020EDD0(u8 *p, u8 *q)
{
    if ((s8)func_00175700(p) < 0) {
        if (p[0x20D] == 2) {
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
            *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
            func_00184540(p);
        } else {
            p[0x20D] = 0;
            func_001843A0(p);
        }
    } else {
        if (*(s8 *)(p + 0x151) == 0) {
            *(s8 *)(p + 0x151) = 0;
            q[2] = 1;
            p[0x28F] = 0;
            p[0x28E] = 0x10;
        }
    }
}
