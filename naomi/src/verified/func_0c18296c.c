struct Obj_0c18296c {
    unsigned char pad0[1];
    unsigned char b1;
    unsigned char pad1[4 - 2];
    unsigned char b4;
    unsigned char pad2[16 - 5];
    void (*p16)(struct Obj_0c18296c *);
    unsigned char pad3[24 - 20];
    struct Obj_0c18296c *p24;
    unsigned char pad4[38 - 28];
    short s38;
    unsigned char pad5[0xcc - 40];
    int lcc;
    unsigned char pad6[0xd4 - 0xd0];
    struct Obj_0c18296c *pd4;
    unsigned char pad7[0x158 - 0xd8];
    unsigned short w158;
};

typedef void (*handler_0c18296c)(struct Obj_0c18296c *, struct Obj_0c18296c *);

extern struct Obj_0c18296c *func_0c0374da(int a, int b, int c);
extern handler_0c18296c dat_0c25573c[];

void func_0c1829aa(struct Obj_0c18296c *p);

struct Obj_0c18296c *func_0c18296c(struct Obj_0c18296c *p)
{
    struct Obj_0c18296c *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c1829aa;
        q->p24 = p;
        q->b1 = p->b1;
        q->s38 = 0x3604;
        q->pd4 = p;
        q->lcc = p->w158;
    }
    return q;
}

void func_0c1829aa(struct Obj_0c18296c *p)
{
    dat_0c25573c[p->b4](p, p->p24);
}
