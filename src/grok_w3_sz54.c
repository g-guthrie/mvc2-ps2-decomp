typedef unsigned char u8;
typedef signed char s8;

extern void func_0016B0C0(u8 *, u8 *, int);
extern void func_00166C80(u8 *, u8 *, int);
extern int func_003D92F0(u8 *);
extern void func_001843A0(u8 *);
extern s8 func_00175700(u8 *);
extern void func_0020D2F0(u8 *, u8 *);
extern void func_0020D250(u8 *, u8 *, int);
extern void func_00186A60(u8 *, int);

void func_001683F0(u8 *p, u8 *q)
{
    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 2);
    func_00166C80(p, q, 0);
}

void func_00168450(u8 *p, u8 *q)
{
    func_0016B0C0(p, q, 0);
    func_0016B0C0(p, q, 2);
    func_00166C80(p, q, 0);
}

void func_001FEB90(u8 *p)
{
    u8 *r = p + 0x2b8;
    if (func_003D92F0(p)) {
        r[12] = 0;
        func_001843A0(p);
    } else {
        func_00175700(p);
    }
}

void residual_001FEC80(u8 *p)
{
    u8 *r = p + 0x2b8;
    if (func_003D92F0(p)) {
        r[12] = 0;
        func_001843A0(p);
    } else {
        func_00175700(p);
    }
}

void func_0020C7B0(u8 *p, u8 *q)
{
    func_0020D2F0(p, q);
    if ((s8)func_00175700(p) < 0)
        func_0020D250(p, q, 0);
}

void func_0020D010(u8 *p, u8 *q)
{
    func_0020D2F0(p, q);
    if ((s8)func_00175700(p) < 0)
        func_0020D250(p, q, 0);
}

#define INIT_002AB750 \
    { \
        s8 v; \
        p[5] = 0; p[7] = 0; p[6] = 0; \
        v = *(s8 *)(p + 1245); \
        switch (v) { \
        case 0: p[509] = 2; break; \
        case 1: p[509] = 3; break; \
        case 2: p[509] = 2; break; \
        } \
        func_00186A60(p, 29); \
    }

void func_002AB750(u8 *p) { INIT_002AB750 }
void func_002AB7B0(u8 *p) { INIT_002AB750 }
