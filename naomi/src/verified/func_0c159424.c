struct Obj_0c159424 {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char pad1[16 - 5];
    void (*p16)(struct Obj_0c159424 *);
    unsigned char pad2[24 - 20];
    struct Obj_0c159424 *p24;
    unsigned char pad3[32 - 28];
    unsigned char b32;
    unsigned char pad4[35 - 33];
    unsigned char b35;
};

typedef void (*handler_0c159424)(struct Obj_0c159424 *);

extern struct Obj_0c159424 *func_0c0374da(int a, int b, int c);
extern handler_0c159424 dat_0c2508f0[];

void func_0c159460(struct Obj_0c159424 *p);

struct Obj_0c159424 *func_0c159424(struct Obj_0c159424 *p, unsigned char b, unsigned char c)
{
    struct Obj_0c159424 *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c159460;
        q->p24 = p;
        q->b32 = b;
        q->b35 = c;
    }
    return q;
}

void func_0c159460(struct Obj_0c159424 *p)
{
    dat_0c2508f0[p->b4](p);
}
