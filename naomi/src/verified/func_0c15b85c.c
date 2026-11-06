struct Obj_0c15b85c {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char pad1[16 - 5];
    void (*p16)(struct Obj_0c15b85c *);
    unsigned char pad2[24 - 20];
    struct Obj_0c15b85c *p24;
    unsigned char pad3[38 - 28];
    short s38;
};

typedef void (*handler_0c15b85c)(struct Obj_0c15b85c *);

extern struct Obj_0c15b85c *func_0c0374da(int a, int b, int c);
extern handler_0c15b85c dat_0c250bb8[];

void func_0c15b888(struct Obj_0c15b85c *p);

struct Obj_0c15b85c *func_0c15b85c(struct Obj_0c15b85c *p)
{
    struct Obj_0c15b85c *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c15b888;
        q->p24 = p;
        q->s38 = 0x1a01;
    }
    return q;
}

void func_0c15b888(struct Obj_0c15b85c *p)
{
    dat_0c250bb8[p->b4](p);
}
