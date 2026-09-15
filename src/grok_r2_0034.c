typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern void func_003422F0(s32);
extern void func_0034DC20(u8 *);
extern void func_0034FA60(void);
extern void func_00359A90(u8 *);
extern void func_00359AE0(u8 *);
extern void func_00359B80(u8 *);
extern void func_00359BD0(u8 *);
extern void func_00359C20(u8 *);
extern void func_0036A8B0(void);
extern void func_0037F920(u8 *);
extern void func_003DAA40(u8 *);
extern void func_001E3240(u8 *, s32);
extern void func_001E3710(u8 *, s32);
extern void func_001E2490(s32, s32);
extern void func_001757E0(u8 *, s32, s32);
extern s32 func_00175700(u8 *);
extern s32 func_00174470(u8 *);
extern void func_00175C00(u8 *, u8 *);

extern u8 *D_004C293C;
extern u8 *D_004C294C;
extern u8 *D_004C2988;

void func_00347A70(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    u32 v = p[4];
    v += 1;
    p[4] = v;
    q[696] = 0;
    p[316] = 0;
}

void func_0034BAC0(u8 *p)
{
    if (--*(s16 *)(p + 30) == 0) {
        u32 v = p[4];
        v += 1;
        p[4] = v;
    }
}

void func_00371450(u8 *p)
{
    s16 t = *(s16 *)(p + 28);
    *(s16 *)(p + 28) = t - 1;
    if (t == 0) {
        u32 v = p[4];
        v += 1;
        p[4] = v;
    }
}

void func_00359AA0(u8 *p)
{
    u32 v = p[5];
    v += 1;
    p[5] = v;
    p[6] = 0;
    *(s8 *)(p + 49) = -2;
    func_00359A90(p);
}

void func_00359AF0(u8 *p)
{
    u32 v = p[5];
    v += 1;
    p[5] = v;
    p[6] = 0;
    *(s8 *)(p + 49) = -2;
    func_00359AE0(p);
}

void func_00359B90(u8 *p)
{
    u32 v = p[5];
    v += 1;
    p[5] = v;
    p[6] = 0;
    *(s8 *)(p + 49) = -2;
    func_00359B80(p);
}

void func_00359BE0(u8 *p)
{
    u32 v = p[5];
    v += 1;
    p[5] = v;
    p[6] = 0;
    *(s8 *)(p + 49) = -2;
    func_00359BD0(p);
}

void func_00359C30(u8 *p)
{
    u32 v = p[5];
    v += 1;
    p[5] = v;
    p[6] = 0;
    *(s8 *)(p + 49) = -2;
    func_00359C20(p);
}

void func_0034F7D0(void)
{
    D_004C294C[1] = 0;
    func_0034FA60();
}

void func_0036A8A0(void)
{
    D_004C2988[9] = 0;
    func_0036A8B0();
}

void func_0034DC00(u8 *p)
{
    if (p[32] == 0)
        D_004C293C[0] = 0;
    p[316] = 0;
    func_0034DC20(p);
}

void func_0037B400(u8 *p, s32 *q)
{
    if (q)
        q[179] = 0;
    func_003DAA40(p);
}

void func_00374600(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    q[510] = 1;
    if (*(s8 *)(q + 337)) {
        p[5] = 4;
        p[6] = 0;
    }
}

void func_0035AE70(u8 *p)
{
    u8 *q = *(u8 **)(p + 24) + 696;
    if (p[32] == 0)
        p[33] = 0;
    q[14] = p[32];
    q[15] = p[33];
    p[5] = 0;
}

void func_0036A600(u8 *p)
{
    p[5] = 13;
    *(s8 *)(D_004C2988 + 11) = -1;
    func_001757E0(p, 23, 30);
}

void func_003422C0(void)
{
    func_003422F0(0);
    func_003422F0(1);
}

void func_00358450(u8 *p)
{
    func_003DAA40(p);
    func_001E3240(p, 30);
}

void func_00372260(u8 *p)
{
    func_001E3710(p, 58);
    func_003DAA40(p);
}

void func_0037F8F0(u8 *p)
{
    p[316] = 0;
    func_0037F920(p);
    func_001E2490(6, 72);
}

void func_0034B040(u8 *p, u8 *q)
{
    u8 *r = *(u8 **)(q + 696);
    *(f32 *)(p + 52) = (*(f32 *)(r + 52) - *(f32 *)(q + 52)) + *(f32 *)(r + 52);
    *(f32 *)(p + 56) = *(f32 *)(q + 56);
}

int func_00354330(f32 a, f32 b, f32 c)
{
    if (a < b && a > c)
        return 1;
    return 0;
}

void func_0034A550(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        u32 v = p[4];
        v += 1;
        p[4] = v;
        p[316] = 0;
    }
}

void func_00354D90(u8 *p, u8 *q)
{
    func_00175C00(q, 0);
    func_003DAA40(p);
}

void func_0035B160(u8 *p)
{
    if (func_00174470(p) == 0)
        p[316] = 0;
    else
        p[316] = 1;
}
