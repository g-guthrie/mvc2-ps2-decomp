typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;
typedef void (*Fn)(u8 *);

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define H(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define P(p, o) (*(u8 **)((u8 *)(p) + (o)))

typedef struct {
    u8 field0;
    u8 field1;
    u8 pad2[14];
    void (*callback)(void);
    u8 pad20[4];
    void *arg;
    u16 extra;
    u8 pad1e[2];
    u8 field32;
    u8 field33;
    u8 pad34[4];
    u16 value;
} Entry;

extern s32 func_00175700(u8 *);
extern void func_003B5560(u8 *, u8 *);
extern void func_003B8DC0(u8 *);
extern void func_003B7990(u8 *);
extern void func_003B7FB0(u8 *);
extern void func_003B9300(u8 *);
extern void func_003BA220(u8 *);
extern void func_003BD920(u8 *);
extern void func_003B3870(u8 *);
extern void func_001E3710(u8 *, s32);
extern void func_001E2490(s32, s32);
extern void func_001D8580(void *, u8 *, s32);
extern void func_003AADA0(u8 *, u8 *);
extern Entry *func_003DA750(int, int, int);
extern void func_003A4440(void);
extern Fn jtbl_00474190[];
extern Fn jtbl_00474260[];
extern Fn jtbl_00474290[];
extern Fn jtbl_00474460[];
extern Fn jtbl_004744E0[];

void func_003B5530(u8 *p, u8 *q);

void func_003B5530(u8 *p, u8 *q)
{
    F(p, 0x34) = F(p, 0x98) + (F(q, 0x34) + F(p, 0x90));
    F(p, 0x38) = F(q, 0x38) + F(p, 0x94);
    func_003B5560(p, q);
}

void func_003B4FE0(u8 *p, u8 *q)
{
    s16 t = S(p, 0x1c);
    S(p, 0x1c) = t - 1;
    if (t == 0) {
        p[4]++;
        p[0x13c] = 0;
    } else {
        func_003B5530(p, q);
    }
}

void func_003B52C0(u8 *p, u8 *q)
{
    s16 t = S(p, 0x1c);
    S(p, 0x1c) = t - 1;
    if (t == 0) {
        p[4]++;
        p[0x13c] = 0;
    } else {
        func_003B5530(p, q);
    }
}

void func_003B8D70(u8 *p)
{
    F(p, 0x34) += F(p, 0x5c);
    F(p, 0x5c) += F(p, 0x68);
    F(p, 0x38) += F(p, 0x60);
    F(p, 0x60) += F(p, 0x6c);
    func_003B8DC0(p);
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
    jtbl_004744E0[p[0x20]](p);
}

void func_003B3810(u8 *p)
{
    p[4]++;
    func_003B3870(p);
    func_001E3710(p, 0x3a);
    func_001E2490(6, 0x48);
}

void func_003AE6F0(u8 *p)
{
    s16 t = S(p, 0x1e) - 1;
    S(p, 0x1e) = t;
    if (t <= 0) {
        p[4]++;
        p[0x13c] = 0;
    } else {
        func_00175700(p);
    }
}

void func_003AD2D0(u8 *p, u8 *q)
{
    func_001D8580(P(p, 0x18), p, 2);
    func_003AADA0(p, q);
}

void func_003A43F0(void *arg)
{
    Entry *e = func_003DA750(0, 1, 1);
    if (e) {
        e->value = 0x2d01;
        e->callback = func_003A4440;
        e->arg = arg;
    }
}
