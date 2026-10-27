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
    void (*callback)(u8 *);
    u8 pad14[4];
    void *arg;
    u8 pad1c[4];
    u8 field32;
} Event;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001843A0(u8 *);
extern void func_00184540(u8 *);
extern u8 *D_004C28D8;
extern Event *func_003DA750(s32, s32, s32);
extern void func_003DAA40(u8 *);
extern void func_0039E450(u8 *);
extern void func_0039A200(u8 *);
extern void func_0039A620(u8 *);
extern void func_0039ACF0(u8 *);
extern void func_00395890(u8 *);
extern void func_00387380(u8 *);
extern void func_00398220(u8 *);
extern void func_00398AE0(u8 *);

extern u8 *D_004C29F8;
extern u8 *D_004C29D8;
extern u16 *D_004C2A08;
extern u8 *D_004C29C4;
extern u8 *D_004C2938;
extern u8 *D_004C29A4;

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

void func_002C27A0(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        if (p[525] != 2) {
            func_001843A0(p);
            return;
        }
        *(s32 *)(p + 96) = 0;
        *(s32 *)(p + 108) = 0;
        func_00184540(p);
        return;
    }
    if ((s8)p[337] != 0) {
        p[337] = 0;
        D_004C28D8[3] = 0;
        func_003981D0(p);
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

void func_00346030(void)
{
    if (D_004C2938[2] < 12) {
        u32 value = D_004C2938[3] - 1;
        D_004C2938[3] = value;
        if ((u8)value <= 0) {
            D_004C2938[3] = 2;
            D_004C2938[2]++;
        }
    }
}
