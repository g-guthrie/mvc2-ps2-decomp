typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))

extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00175C00(u8 *, s32);
extern void func_001D8580(u8 *, u8 *, s32);
extern void func_001E3710(u8 *, s32);
extern void func_001E2490(s32, s32);
extern void func_003B5560(u8 *, u8 *);
extern void func_003B5530(u8 *, u8 *);
extern void func_003B8DC0(u8 *);
extern void func_003AADA0(u8 *, u8 *);
extern void func_003B3870(u8 *);
extern void func_003B7990(u8 *);
extern void func_003B7FB0(u8 *);
extern void func_003B9300(u8 *);
extern void func_003BA220(u8 *);
extern void func_003BD920(u8 *);
extern void func_003B7FC0(u8 *);
extern void func_001E7F60(u8 *);
extern void func_003A4440(void);
extern void func_003A9B50(void);
extern void func_003AE900(void);
extern void func_003BF700(void);
extern void func_003B6680(void);

typedef struct {
    u8 field0;
    u8 field1;
    u8 pad2[14];
    void (*callback)(void);
    u8 pad20[4];
    void *arg;
    u8 pad28[4];
    u8 field32;
    u8 field33;
    u8 pad34[4];
    u16 value;
} Entry;
extern Entry *func_003DA750(s32, s32, s32);

extern u8 *D_004C2840;

typedef void (*DispatchFn)(u8 *);
extern DispatchFn jtbl_00474190[];
extern DispatchFn jtbl_00474260[];
extern DispatchFn jtbl_00474290[];
extern DispatchFn jtbl_00474460[];
extern DispatchFn jtbl_004744E0[];
extern DispatchFn jtbl_004742A0[];

extern s16 D_004C1F50;

void func_003AE370(u8 *p)
{
    S(p, 30) = (&D_004C1F50)[I(p, 208)];
}

void func_003B5530(u8 *p, u8 *q)
{
    F(p, 52) = F(q, 52) + F(p, 144) + F(p, 152);
    F(p, 56) = F(q, 56) + F(p, 148);
    func_003B5560(p, q);
}

typedef struct { f32 x, y, z; } V3;

void func_003BF3D0(u8 *p, u8 *q)
{
    V3 *dst = (V3 *)(p + 52);
    V3 *src = (V3 *)(q + 52);
    p[36] = 7;
    *dst = *src;
    func_001757E0(p, 22, 58);
}

void func_003A3880(u8 *p, u8 *q)
{
    q[710] = (s8)(q[710] & ~(1 << (s8)p[32]));
    p[4] = 2;
    func_001757E0(p, 21, 4);
}

void func_003B8D70(u8 *p)
{
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
    F(p, 56) += F(p, 96);
    F(p, 96) += F(p, 108);
    func_003B8DC0(p);
}

void func_003AD2D0(u8 *p, u8 *q)
{
    func_001D8580(*(u8 **)(p + 24), p, 2);
    func_003AADA0(p, q);
}

void func_003B3810(u8 *p)
{
    p[4]++;
    func_003B3870(p);
    func_001E3710(p, 58);
    func_001E2490(6, 72);
}

void func_003BD7B0(u8 *p)
{
    u8 *q = *(u8 **)(p + 208);
    if (*(s32 *)(D_004C2840 + 28) & 1)
        func_00175C00(q, 1);
    else
        func_00175C00(q, 8);
}

void func_003B75E0(u8 *p)
{
    func_003B7990(p);
    jtbl_00474190[p[4]](p);
}

void func_003B7AB0(u8 *p)
{
    func_003B7FB0(p);
    jtbl_00474260[p[4]](p);
}

void func_003B81F0(u8 *p)
{
    func_003B9300(p);
    jtbl_00474290[p[4]](p);
}

void func_003B9500(u8 *p)
{
    func_003BA220(p);
    jtbl_00474460[p[4]](p);
}

void func_003BA360(u8 *p)
{
    func_003BD920(p);
    jtbl_004744E0[p[32]](p);
}

void func_003AE6F0(u8 *p)
{
    if (--S(p, 30) <= 0) {
        p[4]++;
        p[316] = 0;
    } else
        func_00175700(p);
}

void func_003B7E60(u8 *p)
{
    func_003B7FC0(p);
    if ((s8)func_00175700(p) < 0)
        p[4]++;
    func_001E7F60(p);
}

void func_003B8240(u8 *p)
{
    jtbl_004742A0[p[32]](p);
    p[4]++;
    p[5] = 0;
}

void func_003BA0A0(u8 *p)
{
    F(p, 56) += F(p, 96);
    F(p, 96) += F(p, 108);
    if ((*(u8 **)(p + 24))[4] != 1) {
        p[4]++;
        p[316] = 0;
    }
}

void func_003A43F0(u8 *p)
{
    Entry *e = func_003DA750(0, 1, 1);
    if (e) {
        e->value = 0x2D01;
        e->callback = func_003A4440;
        e->arg = p;
    }
}

void func_003A9A60(u8 *p)
{
    Entry *e = func_003DA750(0, 1, 0);
    if (e) {
        e->callback = func_003A9B50;
        e->arg = p;
        e->value = 0x2F05;
        e->field32 = 0;
    }
}

void func_003AE8B0(u8 *p)
{
    Entry *e = func_003DA750(0, 1, 0);
    if (e) {
        e->callback = func_003AE900;
        e->arg = p;
        e->value = 0x3003;
        e->field32 = 0;
    }
}

void func_003BF6A0(u8 *p)
{
    Entry *e = func_003DA750(0, 1, 0);
    if (e) {
        e->callback = func_003BF700;
        e->arg = p;
        e->field1 = p[1];
        e->value = 0x3603;
    }
}

void func_003B6630(u8 *p)
{
    Entry *e = func_003DA750((s32)p, 1, 2);
    if (e) {
        e->callback = func_003B6680;
        e->arg = *(void **)(p + 24);
        *(void **)((u8 *)e + 20) = p;
        e->value = 0x3402;
    }
}

void func_003B4FE0(u8 *p, u8 *q)
{
    s16 t = S(p, 28);
    S(p, 28) = t - 1;
    if (t == 0) {
        p[4]++;
        p[316] = 0;
    } else
        func_003B5530(p, q);
}

void func_003B52C0(u8 *p, u8 *q)
{
    s16 t = S(p, 28);
    S(p, 28) = t - 1;
    if (t == 0) {
        p[4]++;
        p[316] = 0;
    } else
        func_003B5530(p, q);
}
