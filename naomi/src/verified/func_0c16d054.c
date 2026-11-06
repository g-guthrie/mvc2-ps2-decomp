struct Obj_0c16d054 {
    unsigned char pad0[1];
    unsigned char b1;
    unsigned char pad1[4 - 2];
    unsigned char b4;
    unsigned char pad2[16 - 5];
    void (*p16)(struct Obj_0c16d054 *);
    unsigned char pad3[24 - 20];
    struct Obj_0c16d054 *p24;
    unsigned char pad4[32 - 28];
    unsigned char b32;
    unsigned char b33;
    unsigned char pad5[38 - 34];
    short s38;
    unsigned char pad6[52 - 40];
    float f52, f56;
    unsigned char pad7[0xd4 - 60];
    struct Obj_0c16d054 *pd4;
};

typedef void (*handler_0c16d054)(struct Obj_0c16d054 *, struct Obj_0c16d054 *);

extern struct Obj_0c16d054 *func_0c0374da(int a, int b, int c);
extern handler_0c16d054 dat_0c25239c[];

void func_0c16d10a(struct Obj_0c16d054 *p);

struct Obj_0c16d054 *func_0c16d054(struct Obj_0c16d054 *p)
{
    struct Obj_0c16d054 *q;
    short n;
    short s;

    n = 1;
    s = 0x2a01;
    do {
        if ((q = func_0c0374da(0, 1, 0)) != 0) {
            q->p16 = func_0c16d10a;
            q->p24 = p;
            q->pd4 = p;
            q->b1 = p->b1;
            q->b33 = 0;
            q->b32 = n;
            q->s38 = s;
        }
        n = n - 1;
    } while (n >= 0);
    return q;
}

struct Obj_0c16d054 *func_0c16d0ac(struct Obj_0c16d054 *p, unsigned short b)
{
    struct Obj_0c16d054 *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c16d10a;
        q->p24 = p;
        q->pd4 = p->p24;
        q->b1 = p->b1;
        q->b33 = 1;
        q->f52 = p->f52;
        q->f56 = p->f56 + 2.1428571f * (float)b;
        q->s38 = 0x2a01;
    }
    return q;
}

void func_0c16d10a(struct Obj_0c16d054 *p)
{
    dat_0c25239c[p->b4](p, p->pd4);
}
