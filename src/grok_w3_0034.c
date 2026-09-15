typedef unsigned char u8;
typedef signed char s8;
typedef signed int s32;

typedef struct Event {
    u8 pad00[16];
    void *callback;
    u8 pad14[4];
    void *arg;
} Event;

extern Event *func_003DA750(s32, s32, s32);
extern void func_00344180(void);
extern void func_00346E70(void);
extern void func_00347AF0(void);
extern void func_00347DD0(void);
extern void func_0034CF30(void);
extern void func_0034CF60(void);
extern void func_003422F0(s32);
extern void func_00359A90(u8 *);
extern void func_00359AE0(u8 *);
extern void func_00359B80(u8 *);
extern void func_00359BD0(u8 *);
extern void func_00359C20(u8 *);

void func_003422C0(void)
{
    func_003422F0(0);
    func_003422F0(1);
}

void func_003446C0(void)
{
    Event *e = func_003DA750(0, 6, 0);
    if (e != 0)
        e->callback = func_00344180;
}

void func_00345B40(u8 *state)
{
    u8 *other;
    u8 *destination;

    state[4] = 2;
    other = *(u8 **)(state + 0x18);
    destination = other + 0x2b8;
    if (state[0x20] == 0)
        destination[2] = 0;
}

void func_00346E20(void *arg)
{
    Event *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_00346E70;
        e->arg = arg;
    }
}

void func_00347A70(u8 *p)
{
    u8 *q = *(u8 **)(p + 24);
    p[4]++;
    q[0x2b8] = 0;
    p[316] = 0;
}

void func_00347AA0(void *arg)
{
    Event *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_00347AF0;
        e->arg = arg;
    }
}

void func_00347D80(void *arg)
{
    Event *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_00347DD0;
        e->arg = arg;
    }
}

void func_0034D300(void)
{
    func_0034CF30();
    func_0034CF60();
}

void func_00359AA0(u8 *p)
{
    p[5]++;
    p[6] = 0;
    *(s8 *)(p + 0x31) = -2;
    func_00359A90(p);
}

void func_00359AF0(u8 *p)
{
    p[5]++;
    p[6] = 0;
    *(s8 *)(p + 0x31) = -2;
    func_00359AE0(p);
}

void func_00359B90(u8 *p)
{
    p[5]++;
    p[6] = 0;
    *(s8 *)(p + 0x31) = -2;
    func_00359B80(p);
}

void func_00359BE0(u8 *p)
{
    p[5]++;
    p[6] = 0;
    *(s8 *)(p + 0x31) = -2;
    func_00359BD0(p);
}

void func_00359C30(u8 *p)
{
    p[5]++;
    p[6] = 0;
    *(s8 *)(p + 0x31) = -2;
    func_00359C20(p);
}
