typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

#define F(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define H(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define I(p, o) (*(s32 *)((u8 *)(p) + (o)))

typedef void (*DispatchFn)(u8 *);

typedef struct {
    u8 pad00[16];
    void *callback;
    u8 pad14[4];
    void *arg;
    u16 extra;
    u8 pad1e[2];
    u8 field32;
    u8 pad21[5];
    u16 value;
} Entry;

extern Entry *func_003DA750(s32, s32, s32);
extern void func_00345D80(u8 *);
extern s8 func_00175700(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_0034FA60(u8 *);
extern void func_0034F900(u8 *);
extern void func_00350FD0(u8 *);
extern void func_00352140(u8 *);
extern void func_00355BD0(u8 *);
extern void func_003562D0(u8 *);
extern void func_00356990(u8 *);
extern void func_00357680(u8 *);
extern void func_001E3210(u8 *, s32);
extern void func_00356AB0(u8 *);
extern void func_00357650(u8 *);
extern void func_003584D0(void);
extern void func_0035BF00(void);
extern void func_0035C490(void);
extern void func_0035F4C0(void);
extern void func_001E7F60(u8 *, u8 *);

extern u8 *D_004C2840;
extern u8 *D_004C294C;
extern DispatchFn D_00461E00[32];
extern DispatchFn D_00462BF0[32];
extern DispatchFn D_00462C50[32];
extern DispatchFn D_00462D40[32];
extern DispatchFn D_004C19F8[1];
extern DispatchFn D_004C1A48[1];
extern DispatchFn D_004C1A70[1];

void func_003458A0(u8 *p)
{
    func_00345D80(p);
    D_00461E00[p[4]](p);
}

void func_0034AB30(u8 *p, u8 *q)
{
    if (*(s8 *)(q + 0x2c6)) {
        p[5]++;
        func_001757E0(p, 0x16, 0x11);
    } else {
        func_00175700(p);
    }
}

void func_0034AFC0(u8 *p)
{
    s8 v = *(s8 *)(p + 0x1b4);
    if (v != 0)
        p[0x1b4] = v - 1;
    else
        D_004C19F8[p[0x20]](p);
}

void func_0034F830(u8 *p)
{
    p[0x13c] = 1;
    if (--S(p, 0x1c) == 0)
        p[5]++;
    F(p, 0x34) += F(p, 0x5c);
    F(p, 0x5c) += F(p, 0x68);
    func_00175700(p);
}

void func_00355B10(u8 *p)
{
    F(p, 0x34) += F(p, 0x5c);
    F(p, 0x5c) += F(p, 0x68);
    F(p, 0x38) += F(p, 0x60);
    F(p, 0x60) += F(p, 0x6c);
    func_00355BD0(p);
}

void func_00355C50(u8 *p)
{
    func_003562D0(p);
    D_00462BF0[p[4]](p);
}

void func_00356450(u8 *p)
{
    func_00356990(p);
    D_00462C50[p[4]](p);
}

void func_00356B50(u8 *p)
{
    func_00357680(p);
    D_00462D40[p[4]](p);
}

void func_00357340(u8 *p)
{
    p[5]++;
    func_001E3210(p, 0x1f);
    func_00356AB0(p);
    S(p, 0x1e) = 10;
}

void func_003574E0(u8 *p)
{
    if (--S(p, 0x1e) != 0)
        *(s8 *)(p + 0x13c) ^= 1;
    else {
        p[4]++;
        func_00357650(p);
    }
}

void func_00358480(u8 *p)
{
    Entry *e = func_003DA750(0, 1, 0);
    e->callback = func_003584D0;
    e->arg = p;
    e->value = 0x904;
    e->extra = H(p, 0x168);
}

void func_0035BEB0(void *arg)
{
    Entry *e = func_003DA750(0, 1, 0);
    if (e) {
        e->callback = func_0035BF00;
        e->value = 0xC01;
        e->arg = arg;
    }
}

void func_0035C440(void *arg)
{
    Entry *e = func_003DA750(0, 1, 0);
    if (e) {
        e->callback = func_0035C490;
        e->value = 0xC02;
        e->arg = arg;
    }
}

void func_0035F470(void *arg)
{
    Entry *e = func_003DA750(0, 1, 0);
    if (e) {
        e->callback = func_0035F4C0;
        e->value = 0xE01;
        e->arg = arg;
    }
}

void func_0035CC50(u8 *p, u8 *q)
{
    func_001E7F60(p, q);
    if (q[0x2b8])
        p[4]++;
}

void func_0035F3E0(u8 *p, u8 *q, u8 *r)
{
    if (--S(p, 0x1e) == 0) {
        p[4] = 2;
        p[0x13c] = 0;
        r[4] = 1;
    }
}

void func_00350F90(u8 *p)
{
    u8 *q;
    func_00175700(p);
    q = *(u8 **)(p + 0x18);
    if (q[0x1e4] != 0x16)
        func_00350FD0(p);
}

void func_0034ECE0(u8 *p)
{
    if (--S(p, 0x1c) < 0)
        func_0034FA60(p);
    else
        p[0x13c] = *(s8 *)(D_004C2840 + 0x1c) & 1;
}

void func_0034F260(u8 *p)
{
    if (--S(p, 0x1c) < 0)
        func_0034FA60(p);
    else
        p[0x13c] = *(s8 *)(D_004C2840 + 0x1c) & 1;
}

void func_0034F3B0(u8 *p)
{
    if ((*(u8 **)(p + 0x1c4))[3]) {
        p[5] = 5;
        S(p, 0x1c) = 0x18;
        func_001757E0(p, 0x17, 0x11);
    }
}

void func_00351E40(u8 *p)
{
    if ((*(u8 **)(p + 0x18))[5])
        func_00352140(p);
    else
        D_004C1A70[p[0x20]](p);
}

void func_0034F7E0(u8 *p)
{
    D_004C1A48[p[5]](p);
    if (D_004C294C[4])
        func_0034F900(p);
}


