typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s8 *D_004C2840;
extern s32 func_0013D350(void *p);
extern s32 func_003DAA40(void *p);

s32 func_0013D8A0(void *p)
{
    func_0013D350(p);
    if (D_004C2840[3] != 2) {
        return func_003DAA40(p);
    }
}

void func_003712F0(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x14);
    if (q[4] == 2) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else {
        *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
        *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x14) + 0x34);
        *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x14) + 0x38);
        *(f32 *)(p + 0x3C) = *(f32 *)(*(u8 **)(p + 0x14) + 0x3C);
    }
}

extern void func_003182F0(void *p);
extern s8 func_00175700(void *p);
extern void func_001757E0(void *p, s32 b, s32 c);
extern void func_00175C00(void *p, s32 b);

void func_00318280(u8 *p)
{
    func_003182F0(p);
    if (func_00175700(p) < 0) {
        u32 t = p[5];
        p[5] = t + 1;
        func_001757E0(p, 0, 0);
        func_00175C00(p, 0);
    }
}

extern void func_001820A0(void *p);
extern void func_00184540(void *p);
extern s32 func_001864a0(void *p);
extern s32 func_001865B0(void *p);

void func_002D5CA0(u8 *p)
{
    func_001820A0(p);
    if (func_00175700(p) < 0) {
        p[0x1E7] = 1;
        func_00184540(p);
    } else if (func_001864a0(p)) {
        func_001865B0(p);
    }
}

extern u8 *D_004C29C4;

void func_0038E500(u8 *p)
{
    f32 k = 1.6666666f;
    f32 v;
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    v = k * (f32)(D_004C29C4[6] << 5);
    if (*(s16 *)(p + 0x140) == 0) v = -v;
    *(f32 *)(p + 0x34) += v;
    *(u32 *)(p + 0x50) = 0x3F866666;
}

void func_002FFC70(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x5C) = -5.0f;
        *(f32 *)(p + 0x60) = 34.2857132f;
        *(f32 *)(p + 0x6C) = -1.875f;
        if (*(s16 *)(p + 0x140) != 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
    }
}

extern void func_0018D930(void *p);

void func_0034F330(u8 *p)
{
    f32 v;
    func_0018D930(p);
    p[5] = 6;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    if (*(s16 *)(p + 0x140) != 0) {
        v = -15.0f;
    } else {
        v = 15.0f;
    }
    *(f32 *)(p + 0x5C) = v;
    *(f32 *)(p + 0x60) = 4.28571415f;
    func_001757E0(p, 0x17, 0x15);
}

typedef struct { f32 x, y, z; } V3;
extern u32 func_00174170(void *p);


extern void func_001548D0(void *p, V3 *v, s32 b, s32 c);
extern void func_001E3710(void *p, s32 b);

void func_00273030(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        V3 v;
        u32 t = p[6];
        t += 1;
        p[6] = t;
        p[0x151] = 0;
        v.x = -116.666664f;
        v.y = 203.571426f;
        v.z = 0.0f;
        func_001548D0(p, &v, 1, t);
        func_001E3710(p, 1);
    }
}

extern void func_0015D010(void *p, V3 *v);
extern void func_0018C6E0(void *);
extern void func_001266A0(void *p, s32 b, s32 c);
extern void func_001E3210(void *p, s32 b);

void func_0026A070(u8 *p)
{
    V3 v;
    v.x = -53.3333321f;
    v.y = 171.428558f;
    func_0015D010(p, &v);
    p[0x1B4] = 10;
    func_0018C6E0(p);
    func_001266A0(p, 0xD, 6);
    p[0x20D] = 2;
    func_001757E0(p, 0xF, 3);
    func_001E3210(p, 3);
}

void func_0019E580(u8 *p,u8 *work_unused)
{
    u8 *q = *(u8 **)(p + 0x18);
    p[5] = 0;
    p[0x13C] = 0;
    if (p[0x21] == 0) {
        p[0x168] = 0x29;
    } else {
        p[0x168] = 0x2A;
    }
    func_001757E0(p, 0x17, p[0x168]);
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
}

static void func_0019EA00(u8 *a0, void *q) {
    u8 *owner = *(u8 **)(a0 + 20);
    *(s16 *)(a0 + 320) = *(s16 *)(owner + 320);
    *(s8 *)(a0 + 49) = -2;
    *(f32 *)(a0 + 52) = *(f32 *)(owner + 52);
    *(f32 *)(a0 + 56) = *(f32 *)(owner + 56);
}
extern void func_0019F3A0(void *p, void *q);

void func_0019EA30(u8 *p, void *q)
{
    s16 v;
    u32 t;
    p[0x13C] = 0;
    if ((*(s16 *)(p + 0x1C))-- == 0) {
        t = p[5];
        p[5] = t + 1;
        *(s16 *)(p + 0x1C) = 0xB4;
        func_0019EA00(p, q);
        func_001757E0(p, 0x17, 0x1B);
        func_0019F3A0(p, q);
    }
}

extern void func_0018F4C0();
extern void func_0018E810();
extern void func_0018E6C0();
extern void func_0018E790(u8 *);

void func_0018DFE0(u8 *p)
{
    p[0x247] = 5;
    p[0x248] = 0;
    if (*(s16 *)(p + 0x434) == 0) {
        func_0018F4C0();
        return;
    }
    func_0018E810();
    if (p[0x20D] != 2) {
        func_0018E6C0(p);
    } else {
        func_0018E790(p);
        p[0x20D] = 2;
        *(s16 *)(p + 0x1C) = 10;
    }
}

extern void func_001266A0(void *p, s32 b, s32 c);
extern void func_0015D010(void *p, V3 *v);
extern void func_0018C6E0(void *);

void func_002C46D0(u8 *p)
{
    V3 v;
    if ((p[0x22] & 2) == 0) {
        u32 t = p[0x1E6];
        p[0x1E6] = t ^ 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    func_001266A0(p, 5, 5);
    v.x = -90.0f;
    v.y = 162.857132f;
    func_0015D010(p, &v);
    p[0x1B4] = 10;
    func_0018C6E0(p);
    func_001757E0(p, 0xF, 6);
}

void func_0024A6D0(u8 *p)
{
    f32 *a = (f32 *)(p + 0x5C);
    f32 *b = (f32 *)(p + 0x68);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) > 0.0f) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x34) = *(f32 *)(p + 0x64);
        *a = 0.0f;
        *b = 0.0f;
        func_001757E0(p, 0x12, 2);
    }
    func_00175700(p);
}

extern u8 D_004C1380[4];
extern void func_001E3710(void *p, s32 b);


extern void *func_003DA750(void *, s32, s32);
extern void func_00342910(u8 *);
extern u8 *D_004C283C;

void func_00342CA0(V3 *p, s32 q)
{
    u8 *o = func_003DA750(0, 6, 1);
    if (o != 0) {
        o[0x13C] = 1;
        *(void (**)(u8 *))(o + 0x10) = func_00342910;
        *(s16 *)(o + 0xCC) = q + 0x2A;
        *(u8 **)(o + 0x84) = D_004C283C;
        *(u32 *)(o + 0xD0) = 0x80B;
        o[0x20] = q;
        *(f32 *)(o + 0x78) = 1.0f;
        *(f32 *)(o + 0x7C) = 1.0f;
        *(f32 *)(o + 0x80) = 1.0f;
        *(V3 *)(o + 0x34) = *p;
    }
}

extern u8 D_00455C00[];
extern s32 func_0018A160(u8 *p, u8 *a, u8 *b);
extern void func_00186A60(u8 *p, s32 b);


extern void func_001843A0(void *p);
extern void func_00185870(u8 *p, u8 *q);
extern void func_00190D50(u8 *q, u8 *p);

void func_00231AA0(u8 *p, u8 *q)
{
    u8 *r = *(u8 **)(q + 4);
    if (*(s16 *)(r + 0x434) == 0) {
        *(u32 *)(r + 0x60) = 0xBF4DB6DB;
        func_001843A0(p);
        return;
    }
    {
        u32 t = p[7];
        p[7] = t + 1;
    }
    func_001757E0(p, 0xF, 3);
    p[0x20B] = 0xC3;
    func_00185870(p, r);
    func_00190D50(r, p);
    func_001266A0(p, 5, 5);
    r[0x24A] = 0;
}

extern void func_001E7F60(void *p);

void func_00346990(u8 *p, u8 *q)
{
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    *(s8 *)(p + 0x31) = -2;
    if (*(s16 *)(p + 0x1E) != *(u16 *)(q + 0x168)) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else {
        if (*(s8 *)(q + 0x1B4) == 0) {
            if (func_00175700(p) < 0) {
                u32 t = p[4];
                p[4] = t + 1;
                p[0x13C] = 0;
                return;
            }
        }
        func_001E7F60(p);
    }
}

extern void func_0015B660(V3 *v, s32 b);
extern void func_0015B200(void *p, V3 *v, s32 c, s32 d);

void func_001F53D0(u8 *p)
{
    if (*(s8 *)(p + 0x151) != 0) {
        V3 v;
        p[0x151] = 0;
        v.x = *(f32 *)(*(u8 **)(p + 0x1DC) + 0x34);
        v.y = *(f32 *)(p + 0x430);
        func_0015B660(&v, 1);
        func_0015B200(p, &v, 4, 0x7E);
        func_001E3710(p, 0x4A);
    }
    if (func_00175700(p) < 0) {
        u32 t = p[7];
        p[7] = t + 1;
        func_001757E0(p, 0xF, 0xE);
    }
}

void func_001F1E10(u8 *p)
{
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00175700(p) < 0) {
        p[0x219] = 0;
        func_00184540(p);
        return;
    }
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    }
}

void func_0028FC90(u8 *p)
{
    s16 v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[7];
        u32 w;
        p[7] = t + 1;
        w = p[0x1E6];
        p[0x1E6] = w ^ 1;
        func_001757E0(p, 0x12, 6);
        return;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
}
