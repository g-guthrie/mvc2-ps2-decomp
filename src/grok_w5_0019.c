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

typedef struct {
    u8 field0;
    u8 field1;
    u8 pad2[14];
    void (*callback)(u8 *);
    u8 pad20[4];
    void *arg;
    u16 extra;
    u8 pad1e[2];
    u8 field32;
    u8 field33;
    u8 pad34[4];
    u16 value;
} Entry;

extern void *func_003DA750(void *, int, int);
extern void func_00192BD0(u8 *);
extern void func_0019FF30(u8 *);
extern void func_001996B0(u8 *);
extern void func_0019CB50(u8 *);
extern void func_0019D5A0(u8 *);
extern void func_0019C870(u8 *);
extern void func_001754A0(u8 *, int, int);
extern int func_00417A40(u8 *);
extern int func_00175670(u8 *);
extern int func_00175700(u8 *);
extern void func_001975C0(u8 *, u8 *);
extern void func_0019C470(u8 *);
extern void func_0019CB70(u8 *);
extern int func_00175910(u8 *, int, int, int);
extern u8 D_00446FD0[];
extern u8 D_00446FD1[];
extern s16 D_0044A310[];
extern s16 D_0044A330[];
extern f32 D_004F1FC8;
extern f32 D_004F1FCC;
extern u8 D_0044A7E0[];
extern u16 D_0044A7F0[];

void func_00190C10(u8 *p)
{
    p[0x295] = 0;
    p[0x294] = 0;
    p[0x292] = D_00446FD0[p[1] * 2];
    p[0x293] = D_00446FD1[p[1] * 2];
}

void func_00192B00(void *arg)
{
    Entry *e = func_003DA750(0, 4, 0);
    if (e) {
        e->callback = func_00192BD0;
        e->arg = arg;
        e->value = 0;
    }
}

void func_0019FEE0(void *arg)
{
    Entry *e = func_003DA750(0, 3, 1);
    if (e) {
        e->value = 0xC01;
        e->callback = func_0019FF30;
        e->arg = arg;
    }
}

void func_00199460(void *arg)
{
    Entry *e = func_003DA750(0, 3, 0);
    if (e) {
        e->callback = func_001996B0;
        e->arg = arg;
        e->field32 = 0;
        e->value = 0x501;
    }
}

void func_0019CAF0(u8 *p)
{
    Entry *e = func_003DA750(0, 3, 0);
    if (e) {
        e->callback = func_0019CB50;
        e->arg = p;
        e->value = 0x904;
        e->extra = H(p, 360);
    }
}

void func_0019D540(u8 *p)
{
    Entry *e = func_003DA750(0, 3, 0);
    if (e) {
        e->callback = func_0019D5A0;
        e->arg = p;
        e->value = 0xA01;
        e->field1 = p[1];
    }
}

void func_0019C7E0(u8 *p)
{
    Entry *e = func_003DA750(0, 3, 0);
    if (e) {
        e->callback = func_0019C870;
        e->arg = *(void **)(p + 0x18);
        e->field32 = 2;
        e->value = 0x903;
    }
}

void func_00197760(u8 *p)
{
    S(p, 0x1e) = D_0044A310[func_00417A40(p) & 0xf];
}

void func_001977A0(u8 *p)
{
    S(p, 0x1e) = D_0044A330[func_00417A40(p) & 0xf];
}

void func_00195690(u8 *p, u8 *q)
{
    if (*(s8 *)(q + 0x151)) {
        func_00175670(p);
        func_001975C0(p, q);
    }
}

void func_0019C420(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[4]++;
        func_0019C470(p);
    }
}

int func_0019F3A0(u8 *p)
{
    if (F(p, 0x34) < D_004F1FC8)
        p[0x13c] = 0;
    else if (F(p, 0x34) > D_004F1FCC)
        p[0x13c] = 0;
    else
        p[0x13c] = 1;
    return *(s8 *)(p + 0x13c);
}

void func_0019CB70(u8 *p)
{
    u8 *q = *(u8 **)(p + 0x18);
    s8 a1 = *(s8 *)(q + 0x151);
    if ((a1 & 0xf) == 0)
        return;
    if (a1 == p[0x21])
        return;
    p[0x21] = a1;
    func_00175910(p, 0x17, 8, (p[0x21] - 1) & 0xf);
}

void func_0019A880(u8 *p)
{
    u8 *q;
    *(s8 *)(p + 0x31) = -120;
    S(p, 0x140) ^= 1;
    q = *(u8 **)(p + 0x14);
    I(p, 0x48) = D_0044A7F0[D_0044A7E0[q[0x22]]];
    func_001754A0(p, 0x1b, 7);
}

void func_0019CCE0(u8 *p)
{
    u8 *q;
    func_0019CB70(p);
    q = *(u8 **)(p + 0x18);
    if (!*(s8 *)(q + 0x151) || H(q, 360) != S(p, 28)) {
        p[4]++;
        p[0x13c] = 0;
    }
}


typedef void (*OwnerHandler)(u8 *, void *);
extern const u32 jtbl_0044A800[9];

void func_0019A940(u8 *p)
{
    void *owner = *(void **)(p + 0x18);
    p[0x24] = 8;
    ((OwnerHandler)jtbl_0044A800[p[0x20]])(p, owner);
}

void func_0019A970(u8 *p, void *owner)
{
    s8 result = (s8)func_00175670(p);
    if (result < 0) {
        p[4]++;
        p[0x13C] = 0;
    }
}
