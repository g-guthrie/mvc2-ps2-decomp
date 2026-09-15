typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))

typedef struct Event {
    u8 pad00[16];
    void *callback;
    u8 pad14[4];
    void *arg;
    u8 pad1c[4];
    u8 field32;
} Event;

extern s32 func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern Event *func_003DA750(s32, s32, s32);
extern void func_003DAA40(u8 *);
extern void func_00399BA0(u8 *);
extern void func_0039E450(u8 *);
extern void func_0039A200(u8 *);
extern void func_0039A620(u8 *);
extern void func_0039ACF0(u8 *);
extern void func_00395890(u8 *);
extern void func_00387380(void);
extern void func_00398220(void);
extern void func_00398AE0(void);

extern u8 *D_004C29F8;
extern u8 *D_004C29D8;
extern u16 *D_004C2A08;
extern u8 *D_004C29C4;
extern u8 *D_004C29A4;

void func_00394B60(u8 *p)
{
    u32 v = p[4];
    v += 1;
    p[4] = v;
    D_004C29D8[2] = 0;
    func_001757E0(p, 20, 1);
}

void func_0039A210(u8 *p)
{
    p[4] = 2;
    p[5] = 0;
    D_004C29F8[1] = 0;
    func_001757E0(p, 23, 4);
}

void func_0039A630(u8 *p)
{
    p[4] = 2;
    p[5] = 0;
    D_004C29F8[1] = 0;
    func_001757E0(p, 23, 4);
}

void func_0039B9E0(u8 *p)
{
    *D_004C2A08 = *(u16 *)(*(u8 **)(p + 24) + 360);
    p[36] = 0;
    func_001757E0(p, 21, 32);
}

void func_0039BA00(u8 *p)
{
    *D_004C2A08 = *(u16 *)(*(u8 **)(p + 24) + 360);
    p[36] = 0;
    func_001757E0(p, 21, 36);
}

void func_00399BA0(u8 *p)
{
    p[316] = 0;
    if (p[1] == (*(u8 **)(p + 24))[1])
        D_004C29F8[0] = 0;
    func_003DAA40(p);
}

void func_00396F90(u8 *p, s8 *q)
{
    s16 t = *(s16 *)(p + 0x1c) - 1;
    *(s16 *)(p + 0x1c) = t;
    if (t <= 0) {
        *(s16 *)(p + 0x1c) = 2;
        *q = *q - 1;
    }
}

void func_0038E700(u8 *p)
{
    s16 t = *(s16 *)(p + 0x1c) - 1;
    *(s16 *)(p + 0x1c) = t;
    if (t <= 0) {
        *(s16 *)(p + 0x1c) = 2;
        *D_004C29C4 = *D_004C29C4 - 1;
    }
}

void func_00396F00(u8 *p, u8 *q)
{
    if (q[2] < 12) {
        u32 v = q[3] - 1;
        q[3] = v;
        if ((u8)v <= 0) {
            q[3] = 2;
            q[2]++;
        }
    }
}

void func_003851D0(u8 *p)
{
    s16 t;
    *(s16 *)(p + 0x1c) = 2;
    t = *(s16 *)(p + 0x1e) - 1;
    *(s16 *)(p + 0x1e) = t;
    if (t == 0) {
        u32 v = p[5];
        v += 1;
        p[5] = v;
        *(s16 *)(p + 0x1c) = 0x40;
        *(s16 *)(p + 0x1e) = 0x40;
    }
}

void func_003816C0(u8 *p)
{
    if (D_004C29A4[1] < 16) {
        s16 t = *(s16 *)(p + 0x1e) - 1;
        *(s16 *)(p + 0x1e) = t;
        if (t <= 0) {
            *(s16 *)(p + 0x1e) = 1;
            D_004C29A4[1]++;
        }
    }
}

void func_0039CC90(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    *(f32 *)(p + 52) = *(f32 *)(q + 52);
    q = *(u8 **)(p + 24);
    *(f32 *)(p + 56) = *(f32 *)(q + 56);
    p[36] = *(s8 *)(p + 28);
    func_00175700(p);
}

void func_0038FFF0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        u32 v = p[5];
        v += 1;
        p[5] = v;
        func_001757E0(p, 23, 10);
    }
}

void func_00399B50(u8 *p)
{
    p[36] = 0;
    if ((s8)func_00175700(p) < 0) {
        u32 v = p[4];
        v += 1;
        p[4] = v;
        p[316] = 0;
        func_00399BA0(p);
    }
}

void func_0039CAB0(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    *(f32 *)(p + 52) = *(f32 *)(q + 52);
    p[36] = 0;
    if ((s8)func_00175700(p) < 0)
        func_0039E450(p);
}

void func_00386DF0(u8 *p)
{
    s16 t = *(s16 *)(p + 0x1c) - 1;
    *(s16 *)(p + 0x1c) = t;
    if (t == 0) {
        u32 v = p[4];
        v += 1;
        p[4] = v;
        p[316] = 0;
    } else
        func_00175700(p);
}

void func_00387AF0(u8 *p, u8 *q)
{
    if (q[4] >= 2) {
        u32 v = p[5];
        v += 1;
        p[5] = v;
        func_001757E0(p, 23, 7);
    }
    func_00175700(p);
}

void func_00397970(u8 *p)
{
    p[36] = 0;
    if ((s8)func_00175700(p) < 0) {
        p[316] = 0;
        p[4] = 2;
    }
}

void func_0039A1C0(u8 *p)
{
    p[36] = 0;
    if ((s8)func_00175700(p) < 0)
        func_0039A200(p);
}

void func_0039A5E0(u8 *p)
{
    p[36] = 0;
    if ((s8)func_00175700(p) < 0)
        func_0039A620(p);
}

void func_0039ACD0(u8 *p)
{
    p[4] = 3;
    p[316] = 0;
    D_004C29F8[13] = 1;
    func_0039ACF0(p);
}

void func_00394B10(u8 *p)
{
    if ((s8)func_00175700(p) < 0)
        func_00395890(p);
    else
        p[36] = 0;
}

void func_0038E610(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    F(p, 52) = F(q, 52);
    q = *(u8 **)(p + 24);
    F(p, 56) = F(q, 56);
    F(p, 52) += F(D_004C29C4, 8);
    F(p, 56) += F(D_004C29C4, 12);
}

void func_0038FFA0(u8 *p)
{
    F(p, 52) += F(p, 92);
    F(p, 92) += F(p, 104);
    if (*(s8 *)(p + 337)) {
        p[6]++;
        p[337] = 0;
    }
    func_00175700(p);
}

void func_0038E660(void)
{
    if (D_004C29C4[2] < 12) {
        u32 v = D_004C29C4[3] - 1;
        D_004C29C4[3] = v;
        if ((u8)v <= 0) {
            D_004C29C4[3] = 2;
            D_004C29C4[2]++;
        }
    }
}

void func_003981D0(void *arg)
{
    Event *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_00398220;
        e->arg = arg;
    }
}

void func_00398A90(void *arg)
{
    Event *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_00398AE0;
        e->arg = arg;
    }
}

void func_003872E0(u8 *p)
{
    Event *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_00387380;
        e->arg = p;
        e->field32 = 0;
        p[0x2be] = 0xff;
    }
}

void func_00389710(u8 *p, u8 *q)
{
    if ((s8)func_00175700(p) < 0) {
        p[6] = 0;
        q[724] &= 0xfe;
    }
}

void func_00389870(u8 *p, u8 *q)
{
    if ((s8)func_00175700(p) < 0) {
        p[6] = 0;
        q[724] &= 0xfd;
    }
}

void func_00389120(u8 *p, u8 *q)
{
    u8 *r = q + 696;
    if (q[720] >= 3 || S(r, 30) == 0) {
        p[4]++;
        p[316] = 0;
    } else
        func_00175700(p);
}
