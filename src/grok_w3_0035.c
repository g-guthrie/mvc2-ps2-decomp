typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;

typedef struct {
    u8 field0;
    u8 field1;
    u8 pad2[14];
    void (*callback)(void);
    void *extra;
    void *arg;
    u8 pad28[4];
    u8 field32;
    u8 field33;
    u8 pad34[4];
    u16 value;
} Entry;

extern Entry *func_003DA750(s32, s32, s32);
extern void func_00353790(void);
extern void func_003550D0(void);
extern void func_00355740(void);
extern void func_00356B50(void);
extern void func_00357C40(void);
extern void func_0035B560(void);
extern void func_0035BF00(void);
extern void func_0035C490(void);
extern void func_0035F4C0(void);
extern s8 func_00175700(u8 *);
extern void func_00350FD0(u8 *);
extern void func_00175910(u8 *, s32, s32, s32);
extern void func_001E3210(u8 *, s32);
extern void func_00356AB0(u8 *);

void func_00353730(u8 *arg, u8 mode)
{
    Entry *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_00353790;
        e->arg = arg;
        e->field32 = mode;
        e->field33 = 0;
        e->value = 0x602;
    }
}

void func_00355060(u8 *arg, u8 mode)
{
    Entry *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_003550D0;
        e->arg = arg;
        e->field32 = mode;
        e->value = 0x800;
        arg[0x2c2] = 1;
    }
}

void func_003556D0(u8 *arg, u8 mode)
{
    Entry *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_00355740;
        e->arg = arg;
        e->field32 = mode;
        *(s16 *)((u8 *)e + 0x140) = *(s16 *)(arg + 0x140);
        e->value = 0x801;
    }
}

void func_003569A0(u8 *arg, u8 mode)
{
    Entry *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_00356B50;
        e->field32 = 0;
        e->field33 = mode;
        e->arg = arg;
        e->field1 = arg[1];
        e->value = 0x902;
    }
}

void func_00357690(u8 *arg, u8 mode)
{
    Entry *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_00357C40;
        e->field32 = 0;
        e->field33 = mode;
        e->arg = arg;
        e->field1 = arg[1];
        e->value = 0x903;
    }
}

void func_0035B500(u8 *arg, u8 mode)
{
    Entry *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_0035B560;
        e->value = 0xC00;
        e->field32 = mode;
        e->arg = arg;
    }
}

void func_0035BEB0(u8 *arg)
{
    Entry *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_0035BF00;
        e->value = 0xC01;
        e->arg = arg;
    }
}

void func_0035C440(u8 *arg)
{
    Entry *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_0035C490;
        e->value = 0xC02;
        e->arg = arg;
    }
}

void func_0035F470(u8 *arg)
{
    Entry *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_0035F4C0;
        e->value = 0xE01;
        e->arg = arg;
    }
}

void func_0035F3E0(u8 *p, u8 *q, u8 *r)
{
    s16 v = *(s16 *)(p + 0x1e) - 1;
    *(s16 *)(p + 0x1e) = v;
    if (v == 0) {
        p[4] = 2;
        p[0x13c] = 0;
        r[4] = 1;
    }
}

void func_00350F90(u8 *p)
{
    func_00175700(p);
    if ((*(u8 **)(p + 0x18))[0x1e4] != 22)
        func_00350FD0(p);
}

void func_00355AE0(u8 *p)
{
    s32 v;
    v = p[0x22];
    if (*(s16 *)(p + 0x140) & 1)
        v ^= 0x10;
    func_00175910(p, 21, p[0xd0], v / 2);
}

void func_00357340(u8 *p)
{
    p[5]++;
    func_001E3210(p, 31);
    func_00356AB0(p);
    *(s16 *)(p + 0x1e) = 10;
}
