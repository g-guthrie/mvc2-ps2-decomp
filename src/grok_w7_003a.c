typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef float f32;

typedef struct Event {
    u8 pad00[16];
    void *callback;
    void *extra;
    void *arg;
    u8 pad1c[4];
    u8 field32;
    u8 field33;
    u8 field34;
    u8 field35;
    u8 pad24[2];
    s16 field38;
} Event;

extern Event *func_003DA750(s32, s32, s32);
extern void func_003A8B70(void);
extern void func_003AA4D0(void);
extern void func_003B6AA0(void);
extern void func_003BFD90(void);
extern void func_003B4240(void);
extern void func_003B75E0(void);
extern void func_003BDA40(void);
extern void func_003B6230(u8 *);

void func_003A7E30(u8 *p)
{
    if (--*(s16 *)(p + 28) == 0) {
        p[5]++;
        p[0x21] = 0;
        *(s16 *)(p + 28) = 0;
    }
}

void func_003B6340(u8 *p, u8 *q)
{
    u8 *r = p + 0x88;
    *(s16 *)(p + 28) = 60;
    if (*(u16 *)(q + 0x35e) & 0x20)
        r[0x24] = 0;
    else
        r[0x24] = 1;
    p[5]++;
    func_003B6230(p);
}

void func_003A8B10(u8 *p)
{
    Event *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_003A8B70;
        e->arg = p;
        e->field38 = 0x2f01;
        *(s32 *)((u8 *)e + 0xd0) = *(u16 *)(p + 0x168);
    }
}

void func_003AA280(u8 *p)
{
    Event *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_003AA4D0;
        e->arg = p;
        e->extra = p;
        e->field32 = 0;
        e->field38 = 0x3001;
        ((u8 *)e)[0xbe] = p[0x1fd];
    }
}

void func_003B69D0(u8 *p, u8 q)
{
    Event *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_003B6AA0;
        e->arg = p;
        e->field32 = q;
        e->field33 = 0;
        e->field38 = 0x3403;
    }
}

void func_003BFD30(u8 *p)
{
    Event *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_003BFD90;
        e->arg = p;
        ((u8 *)e)[1] = p[1];
        e->field38 = 0x3604;
        *(void **)((u8 *)e + 0xd8) = p;
        *(s32 *)((u8 *)e + 0xd0) = *(u16 *)(p + 0x168);
    }
}

void func_003B4040(u8 *p, u8 q)
{
    Event *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_003B4240;
        e->arg = p;
        e->field32 = 0;
        e->field35 = q;
        e->field34 = 0;
        e->field38 = 0x3400;
    }
}

void func_003B7570(u8 *p)
{
    Event *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        e->callback = func_003B75E0;
        *(f32 *)((u8 *)e + 0x34) = *(f32 *)(p + 0x34);
        *(f32 *)((u8 *)e + 0x38) = *(f32 *)(p + 0x38);
        e->arg = p;
        ((u8 *)e)[1] = p[1];
        e->field38 = 0x3500;
    }
}

void func_003BD930(u8 *p)
{
    Event *e = func_003DA750(0, 1, 0);
    if (e != 0) {
        ((u8 *)e)[0] = 1;
        e->callback = func_003BDA40;
        e->arg = p;
        ((u8 *)e)[1] = p[1];
        e->field38 = 0x3600;
        e->field32 = 0;
        *(s32 *)((u8 *)e + 0xdc) = 0;
    }
}
