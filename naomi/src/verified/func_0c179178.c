struct Obj_0c179178 {
    unsigned char pad0[1];
    unsigned char b1;
    unsigned char pad1[4 - 2];
    unsigned char b4;
    unsigned char pad2[16 - 5];
    void (*p16)(struct Obj_0c179178 *);
    struct Obj_0c179178 *p20;
    struct Obj_0c179178 *p24;
    unsigned char pad3[32 - 28];
    unsigned char b32;
    unsigned char b33;
    unsigned char pad4[1];
    unsigned char b35;
    unsigned char pad5[38 - 36];
    short s38;
};

typedef void (*handler2_0c179178)(struct Obj_0c179178 *, struct Obj_0c179178 *);
typedef void (*handler_0c179178)(struct Obj_0c179178 *);

extern struct Obj_0c179178 *func_0c0374da(int a, int b, int c);
extern handler2_0c179178 dat_0c2537b0[];
extern handler_0c179178 dat_0c2537bc[];

void func_0c179222(struct Obj_0c179178 *p);
void func_0c179238(struct Obj_0c179178 *p);

struct Obj_0c179178 *func_0c179178(struct Obj_0c179178 *p, unsigned char b, unsigned char c)
{
    struct Obj_0c179178 *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c179222;
        q->s38 = 0x3300;
        q->p24 = p;
        q->b1 = p->b1;
        *(&q->b32) = b;
        *(&q->b33) = c;
    }
    return q;
}

struct Obj_0c179178 *func_0c1791c6(struct Obj_0c179178 *p, unsigned char b, unsigned char c, unsigned char d)
{
    struct Obj_0c179178 *q;

    if ((q = func_0c0374da(0, 1, 1)) != 0) {
        q->p16 = func_0c179222;
        q->s38 = 0x3300;
        q->p24 = p->p24;
        q->p20 = p;
        q->b1 = p->b1;
        *(&q->b32) = b;
        *(&q->b33) = c;
        q->b35 = d;
    }
    return q;
}

void func_0c179222(struct Obj_0c179178 *p)
{
    dat_0c2537b0[p->b32](p, p->p24);
}

void func_0c179238(struct Obj_0c179178 *p)
{
    dat_0c2537bc[p->b4](p);
}
