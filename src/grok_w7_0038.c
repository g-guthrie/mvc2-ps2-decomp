typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
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
extern void func_0015B200(u8 *, u8 *, s32, s32);
extern void func_001E3710(u8 *, s32);
extern void func_001E7F60(u8 *);
extern Event *func_003DA750(s32, s32, s32);
extern void func_0038F430(u8 *);
extern void func_0039B7D0(u8 *);
extern void func_00386600(void);
extern void func_00387C90(void);

extern void (*jtbl_00471A80[])(u8 *);

void func_003891D0(u8 *p, u8 *q)
{
    s16 t = S(q, 320) ^ S(p, 208);
    S(p, 320) = t;
    if (t == 0)
        F(p, 52) = F(q, 52) + F(p, 92);
    else
        F(p, 52) = F(q, 52) - F(p, 92);
    F(p, 56) = F(q, 56) + F(p, 96);
}

void func_00387BE0(u8 *p)
{
    Event *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_00387C90;
        e->arg = p;
        e->field32 = 0;
        p[703] = 1;
        p[704] = 1;
        p[705] = 0;
    }
}

void func_0038EEB0(u8 *p)
{
    func_0038F430(p);
    jtbl_00471A80[p[4]](p);
}

void func_0039CE90(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    if (*(s8 *)(q + 435)) {
        u32 v = p[5];
        v += 1;
        p[5] = v;
        func_0015B200(p, p + 52, 1, 8);
        func_001E3710(p, 73);
    }
}

void func_0039B780(u8 *p)
{
    if ((s8)func_00175700(p) >= 0)
        func_001E7F60(p);
    else
        func_0039B7D0(p);
}

void func_00386510(u8 *p)
{
    u8 *r = p + 696;
    Event *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_00386600;
        e->arg = p;
        e->field32 = 0;
        r[4] = 0;
    }
}

void func_0038A560(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    u8 *r = q + 696;
    u32 v = p[4];
    v += 1;
    p[4] = v;
    p[316] = 0;
    if (r[29])
        r[29]--;
}

void func_0039B050(u8 *p)
{
    if (*(s8 *)(p + 337))
        p[337] = 0;
    p[36] = 0;
    if ((s8)func_00175700(p) < 0) {
        u32 v = p[5];
        v += 1;
        p[5] = v;
    }
    func_001E7F60(p);
}

void func_00388D30(u8 *p, u8 *q)
{
    u8 *r = q + 696;
    if (q[7] != 7 || r[24] >= 3 || S(r, 30) == 0) {
        u32 v = p[4];
        v += 1;
        p[4] = v;
        p[316] = 0;
    } else
        func_00175700(p);
}

void func_00388040(u8 *p, u8 *q)
{
    u8 *r = q + 696;
    if (*(s8 *)(q + 436)) {
        u32 v = p[6];
        v += 1;
        p[6] = v;
    } else if (*(s8 *)(r + 7) >= 0) {
        s16 t = S(p, 28) - 1;
        S(p, 28) = t;
        if (t == 0) {
            r[8] = 0;
            *(s32 *)(p + 216) = 0;
        }
    }
}
