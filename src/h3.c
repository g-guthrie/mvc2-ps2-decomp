typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004D18A0;
extern s32 D_004D18B8, D_004D18BC, D_004D18C0, D_004D18C4, D_004D18C8, D_004D18CC;
extern void func_003278C0(s32, s32, s32);
void func_00327BC0(void)
{
    if (D_004D18A0 < 5) {
        func_003278C0(D_004D18B8, D_004D18BC, D_004D18C0);
        func_003278C0(D_004D18C4, D_004D18C8, D_004D18CC);
    }
}

s32 func_0028BAB0(u8 *p)
{
    u32 t = p[0x2D3] - 1;
    u8 *q = p + 0x2B8;
    s32 v = p[0x22];
    p[0x2D3] = t;
    if ((u8)t == 0) {
        u8 *r = *(u8 **)(q + 0x14);
        q[0xC] = r[0];
        v = r[2];
        if (p[0x1E6]) {
            v = (-(s8)r[2]) & 0x1F;
        }
        q[0x1B] = r[4];
        *(u8 **)(q + 0x14) = r + 6;
    }
    return v;
}

extern void func_001266A0(u8 *, s32, s32);
extern void func_001757E0(u8 *, s32, s32);
void func_00254100(u8 *p)
{
    u8 *s;
    s = *(u8 **)(p + 0x1DC);
    p[6] = 6;
    func_001266A0(p, 0, 0);
    *(u8 **)(s + 0x1C8) = p;
    s[0x20A] = 1;
    s[0x1B5] = 0x23;
    func_001757E0(p, 0xF, 4);
}

extern s8 func_00175700(u8 *);
extern void func_0022EF50(u8 *);
void func_0022EFB0(u8 *p)
{
    u8 *q = p + 0x2B8;
    if (func_00175700(p) >= 0) {
        q[0x11] = 0;
        *(s16 *)(p + 0x1C) = 0x40;
    } else {
        u32 t = p[7];
        p[7] = t + 1;
        func_0022EF50(p);
    }
}

extern void func_0018F9E0(u8 *, s32);
extern void func_0018FCA0(u8 *, s32);
extern void func_0018C4B0(u8 *, s32);
void func_003ACA10(s32 a, s32 b, u8 *c)
{
    if (c[6] == 9) {
        func_0018F9E0(c, 1);
        func_0018FCA0(*(u8 **)(c + 0x1DC), -2);
    } else {
        func_0018C4B0(c, 1);
        func_0018C4B0(*(u8 **)(c + 0x1DC), -2);
    }
}

extern u8 *func_003DA750(u8 *, s32, s32);
extern void func_00375E80(void);
void func_00375E10(u8 *p, u8 b)
{
    u8 *v = func_003DA750(p, 1, 2);
    if (v != 0) {
        *(void **)(v + 0x10) = func_00375E80;
        *(s32 *)(v + 0x18) = *(s32 *)(p + 0x18);
        *(u8 **)(v + 0x14) = p;
        v[0x20] = b;
        *(s16 *)(v + 0x26) = 0x1500;
        v[0x23] = p[0x23];
    }
}

extern void func_003A4F80(u8 *, s32, s32);
void func_002EA180(u8 *p)
{
    s16 v;
    func_00175700(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[7];
        p[7] = t + 1;
        func_003A4F80(p, 0, 2);
        p[0x28E] = 0x10;
        p[0x28F] = 0;
    }
}

void func_001DEA90(u8 *p, u8 *q)
{
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
    if (*(u16 *)(q + 0x168) != *(u16 *)(p + 0xD0)) {
        u32 t = p[4];
        p[4] = t + 1;
    } else {
        if (func_00175700(p) < 0) {
            u32 t;
            p[0x13C] = 0;
            t = p[4];
            p[4] = t + 1;
        }
    }
}

extern s8 D_004CD183[];
extern void func_001E47E0(u8);
extern void func_00422FB0(u32);
void func_001E2420(u8 *p, u8 b)
{
    s32 s = D_004CD183[p[0x1B8] * 20];
    func_001E47E0(s);
    func_00422FB0(((s & 0x7F) << 16) | ((b & 0x7F) << 8) | 1);
}

static void func_00224BB0(u8 *p)
{
    f32 *a = (f32 *)(p + 0x5C);
    f32 *c = (f32 *)(p + 0x68);
    f32 *b = (f32 *)(p + 0x60);
    f32 *d = (f32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *a = 0;
        *b = 0;
        *c = 0;
        *d = 0;
    }
}

extern void func_00367F90(u8 *, s32, u8);
extern void func_001AD170(u8 *, s32, s32);
void func_00251DD0(u8 *p)
{
    u32 t;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        func_00367F90(p, 1, (*(s16 *)(p + 0x1E) & 3) + 0x80);
        func_001AD170(p, 6, *(s16 *)(p + 0x1E) & 3);
        *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 1;
    }
}

extern void func_00224BB0(u8 *);
extern void func_00184540();
extern void func_001843A0();
void func_00224FA0(u8 *p)
{
    s16 v;
    func_00175700(p);
    func_00224BB0(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        if (p[0x20D] == 2) {
            func_00184540();
        } else {
            func_001843A0();
        }
    }
}

extern s16 D_004D18EE[];
s32 func_00134480(u8 *p, u8 *q)
{
    s32 v;
    if (p[0x14D] != 0) {
        return 0;
    }
    *(s16 *)(p + 0x140) |= *(s16 *)(q + 0x278);
    v = D_004D18EE[p[2]];
    if (v < 2) {
        if (v == 0) {
            *(s16 *)(p + 0x13E) = *(s16 *)(p + 0x144);
        }
        p[0x14D] = 1;
        return 0;
    }
    *(s16 *)(p + 0x13E) = v;
    return 1;
}

void func_002A84C0(u8 *p)
{
    if (*(s8 *)(p + 0x151) == 0) {
        func_00175700(p);
    }
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t = p[7];
        p[7] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x210] = 0;
        p[0x224] = 0;
        *(s32 *)(p + 0x5C) = 0;
        *(s32 *)(p + 0x60) = 0;
        *(s32 *)(p + 0x68) = 0;
        *(s32 *)(p + 0x6C) = 0;
    }
}

extern void (*D_00464A40[])(u8 *, u8 *);
void func_00388310(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    if (q[4] >= 2) {
        u32 t = p[4];
        p[4] = t + 1;
        p[5] = 0;
        *(s32 *)(q + 0xD0) &= ~(1 << p[0x20]);
    } else {
        D_00464A40[p[5]](p, q);
    }
}

extern void func_001E7F60(u8 *);
extern void func_003B9440(u8 *, s32, s32);
void func_003B9F60(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    if (q[4] == 1) {
        func_00175700(p);
        func_001E7F60(p);
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            func_003B9440(p, 5, 0);
        }
    } else {
        u32 t = p[4];
        p[4] = t + 1;
        p[5] = 0;
        p[0x13C] = 0;
    }
}

extern u8 *D_0045E920[];
void func_003349E0(u8 *p)
{
    s32 v;
    ((void (*)(u8 *))D_0045E920[p[4]])(p);
    v = *(s32 *)(p + 0xDC) + 1;
    *(s32 *)(p + 0xDC) = v;
    if (v > 0x514) {
        *(s32 *)(p + 0xD4) = *(s32 *)(p + 0xD4) + 1;
        *(s32 *)(p + 0xD4) = *(s32 *)(p + 0xD4) % 12;
        *(s32 *)(p + 0xDC) = 0;
        p[4] = 0;
    }
}

extern void (*D_00464A10[])(u8 *);
void func_00387EA0(u8 *p, u8 *q)
{
    q = *(u8 **)(p + 0x18);
    if (q[4] >= 2 || p[1] != q[1]) {
        p[4] = 3;
    } else if (*(s32 *)(p + 0xD0) == 0) {
        p[4] = 2;
        q[0x2BF] = 0;
    } else {
        D_00464A10[p[5]](p);
    }
}
