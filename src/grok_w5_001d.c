typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define H(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define P(p, o) (*(u8 **)((u8 *)(p) + (o)))

typedef struct {
    u8 pad[16];
    void (*callback)(void);
    u8 pad20[4];
    void *arg;
    u8 pad28[4];
    u8 mode;
    u8 mode1;
    u8 f34;
    u8 f35;
    u8 pad36[2];
    u16 value;
} Entry;

extern Entry *func_003DA750(s32, s32, s32);
extern s8 func_00175700(u8 *);
extern s8 func_00175670(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_001D7120(void);
extern void func_001D12B0(void);
extern void func_001D7940(void);
extern void func_001D1F10(void);
extern void func_001D2A70(void);
extern void func_001D2C70(void);
extern void func_001D3520(void);
extern void func_001D3E60(void);
extern void func_001DA860(void);
extern void func_001DF5C0(void);
extern void func_001E0090(void);
extern void func_001D1950(void);
extern void func_001DBD60(u8 *);
extern void func_001DBCD0(u8 *);
extern void func_001DBDF0(u8 *);
extern s8 D_0044ED00[];

void func_001DEF30(u8 *p)
{
    s8 a1 = D_0044ED00[S(p, 28) & 0x1f];
    if (S(p, 320) != 0)
        a1 = (s8)-a1;
    F(p, 52) += (f32)a1;
}

void func_001DA3F0(u8 *p, u8 *q)
{
    func_00175700(p);
    if (q[697])
        p[4]++;
}

void func_001D9910(u8 *p, u8 *q)
{
    if (((s8 *)q)[436])
        p[316] = 0;
    else
        p[316] = 1;
    F(p, 52) = F(q, 52);
    F(p, 56) = F(q, 56);
    F(p, 52) += F(p, 92);
    F(p, 56) += F(p, 96);
}

void func_001D7070(u8 *p)
{
    Entry *e = func_003DA750(0, 4, 0);
    if (e) {
        e->callback = func_001D7120;
        e->arg = p;
        e->value = 0x2F02;
        e->mode = 0;
    }
}

void func_001DB5D0(u8 *p)
{
    s16 v;
    func_00175700(p);
    v = (s16)(S(p, 28) - 1);
    S(p, 28) = v;
    if (v == 0) {
        p[4]++;
        p[316] = 0;
    }
}

void func_001D1250(u8 *p)
{
    Entry *e = func_003DA750(0, 3, 0);
    if (e) {
        e->callback = func_001D12B0;
        e->arg = p;
        e->pad[1] = p[1];
        e->value = 0x2A02;
    }
}

void func_001D77A0(u8 *p)
{
    Entry *e = func_003DA750(0, 3, 0);
    if (e) {
        e->callback = func_001D7940;
        e->arg = p;
        e->value = 0x2F04;
        e->mode = 0;
        *(u8 **)((u8 *)e + 136) = p;
    }
}

void func_001DB8A0(u8 *p)
{
    u8 *q = P(p, 24);
    F(p, 52) = F(q, 52);
    F(p, 56) = F(q, 1072);
    p[36] = 0;
    func_001DBD60(p);
    S(p, 28) = 0;
    p[337] = 0;
    S(p, 30) = 1;
    func_001DBCD0(p);
}

void func_001DB7E0(u8 *p)
{
    u8 *q = P(p, 24);
    F(p, 52) = F(q, 52);
    F(p, 56) = F(q, 1072);
    p[36] = 10;
    func_001DBD60(p);
    S(p, 28) = 0;
    p[337] = 0;
    S(p, 30) = 1;
    func_001DBCD0(p);
}

void func_001DE610(u8 *p, u8 *q)
{
    if (H(q, 360) != H(p, 208))
        p[4]++;
    else {
        p[36] = ((s8 *)q)[36];
        F(p, 52) = F(q, 52);
        F(p, 56) = F(q, 56);
        F(p, 60) = F(q, 60);
        func_00175700(p);
    }
}

void func_001D1EB0(u8 *p)
{
    Entry *e = func_003DA750(0, 3, 1);
    if (e) {
        e->value = 0x2B01;
        e->f34 = p[484];
        e->f35 = p[509];
        e->callback = func_001D1F10;
        e->arg = p;
    }
}

void func_001D2A10(u8 *p, u8 mode)
{
    Entry *e = func_003DA750(0, 3, 1);
    if (e) {
        e->value = 0x2B05;
        e->mode = mode;
        e->callback = func_001D2A70;
        e->arg = p;
    }
}

void func_001D70C0(u8 *p)
{
    Entry *e = func_003DA750((s32)p, 4, 2);
    if (e) {
        e->callback = func_001D7120;
        e->arg = p;
        e->value = 0x2F02;
        e->mode = 1;
        e->mode1 = 0;
        I((u8 *)e, 212) = I(p, 212);
    }
}

void func_001D8100(u8 *p)
{
    if (func_00175670(p) < 0 || func_00175670(p) < 0) {
        p[4]++;
        p[316] = 0;
    }
}

void func_001D8D00(u8 *p)
{
    s16 a0;
    func_00175700(p);
    a0 = S(p, 28);
    S(p, 28) = (s16)(a0 - 1);
    if (a0 == 0) {
        p[5]++;
        if (p[33])
            p[316] = 0;
        func_001757E0(p, 23, 10);
    }
}

void func_001DF4E0(u8 *p)
{
    Entry *e = func_003DA750(0, 3, 0);
    if (e) {
        e->callback = func_001DF5C0;
        e->mode1 = 0;
        e->mode = 0;
        e->arg = p;
        e->pad[1] = p[1];
        e->value = 0x3800;
    }
}

void func_001DFFC0(u8 *p)
{
    Entry *e = func_003DA750(0, 3, 0);
    if (e) {
        e->callback = func_001E0090;
        e->mode1 = 0;
        e->mode = 0;
        e->arg = p;
        e->pad[1] = p[1];
        e->value = 0x3801;
    }
}

void func_001D34C0(u8 *p, u8 mode)
{
    Entry *e = func_003DA750(0, 3, 0);
    if (e) {
        e->callback = func_001D3520;
        e->arg = p;
        e->mode = mode;
        ((s8 *)e)[49] = (s8)p[49] + 1;
    }
}

void func_001D3E00(u8 *p)
{
    Entry *e = func_003DA750(0, 3, 0);
    if (e) {
        e->callback = func_001D3E60;
        e->mode = 0;
        e->mode1 = 0;
        e->arg = *(void **)(p + 476);
        e->pad[1] = p[1];
        e->value = 0x2C02;
    }
}

void func_001DA790(u8 *p, u8 mode)
{
    Entry *e = func_003DA750(0, 3, 0);
    if (e) {
        e->callback = func_001DA860;
        e->arg = p;
        e->mode = mode;
        e->f34 = 0;
        e->value = 0x3400;
    }
}

void func_001DB840(u8 *p)
{
    u8 *q = P(p, 24);
    F(p, 52) = F(q, 52);
    F(p, 56) = F(q, 1072);
    p[36] = 12;
    func_001DBD60(p);
    func_001DBDF0(p);
    S(p, 28) = 0;
    p[337] = 0;
    S(p, 30) = 1;
    func_001DBCD0(p);
}

void func_001D18E0(u8 *p)
{
    Entry *e = func_003DA750(0, 3, 0);
    if (e) {
        e->callback = func_001D1950;
        e->arg = p;
        e->value = 0x2A04;
        e->f34 = p[34];
        I((u8 *)e, 208) = p[361];
        I((u8 *)e, 212) = p[360];
    }
}

void func_001D2C00(u8 *p, u8 mode)
{
    Entry *e = func_003DA750(0, 3, 1);
    if (e) {
        ((u8 *)e)[0] = 1;
        e->value = 0x2B06;
        e->mode = mode;
        e->callback = func_001D2C70;
        e->arg = p;
    }
}
