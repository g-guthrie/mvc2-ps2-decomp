typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed char s8;
typedef float f32;
typedef union { f32 value; u32 bits; } FloatBits;
typedef void (*ActorCallback)(u8 *);
typedef struct { u8 prefix[0x5c]; FloatBits f5c; FloatBits f60; u32 padding; FloatBits f68; FloatBits f6c; } ActorView;
extern void func_002F4710(u8 *);
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00126400(void);
extern void func_00184540(u8 *);
extern void func_001843A0(u8 *);
extern void func_00183920(u8 *, f32 *);
extern const u32 jtbl_0045BCE0[12];
void func_002F48D0(u8 *p)
{
    s8 result;
    ActorView *actor = (ActorView *)p;
    func_002F4710(p);
    result = (s8)func_00175700(p);
    if (result >= 0)
        return;
    func_00126400();
    actor->f5c.bits = 0;
    actor->f60.bits = 0;
    actor->f68.bits = 0;
    actor->f6c.bits = 0;
    actor->f6c.bits = 0xBF4DB6DB;
    func_00184540(p);
}

void func_002F5330(u8 *p, void *q)
{
    s8 result = (s8)func_00175700(p);
    ActorView *actor = (ActorView *)p;
    if (result < 0) {
        func_00126400();
        actor->f5c.bits = 0;
        actor->f60.bits = 0;
        actor->f68.bits = 0;
        actor->f6c.bits = 0;
        actor->f6c.bits = 0xBF4DB6DB;
        func_00184540(p);
    }
}

void func_002F52C0(u8 *p, void *q)
{
    p[0x40d] = 0;
    p[0x40c] = 0;
    p[0x33b] = 0;
    p[0x33c] = 0;
    p[6]++;
    ((s8 *)p)[0x1b1] = -128;
    p[0x201] = 0;
    func_001757E0(p, 21, 25);
    func_002F5330(p, q);
}

void func_002F5A30(u8 *p)
{
    s8 result;
    struct { union { f32 values[2]; u32 bits[2]; } pair; u32 padding[2]; } position;

    result = (s8)func_00175700(p);
    if (result < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        position.pair.bits[0] = 0x42BE0000;
        position.pair.bits[1] = 0x42700000;
        func_00183920(p, position.pair.values);
    }
}

void func_002F54C0(u8 *p, void *q)
{
    s8 result;
    ActorView *actor = (ActorView *)p;

    p[0x40d] = 0;
    p[0x40c] = 0;
    p[0x33b] = 0;
    p[0x33c] = 0;
    p[0x1b0] = 0;
    p[0x200] = 3;
    result = (s8)func_00175700(p);
    if (result < 0) {
        func_00126400();
        actor->f5c.bits = 0;
        actor->f60.bits = 0;
        actor->f68.bits = 0;
        actor->f6c.bits = 0;
        func_00184540(p);
    }
}

void func_002F5EE0(u8 *p)
{
    if ((*(u16 *)(p + 0x362) & 0x400) != 0) {
        ActorView *actor = (ActorView *)p;
        actor->f5c.bits = 0;
        actor->f68.bits = 0;
        actor->f6c.bits = 0xBF4DB6DB;
        func_00184540(p);
    } else {
        ((ActorCallback)jtbl_0045BCE0[p[6]])(p);
    }
}
