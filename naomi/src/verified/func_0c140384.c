struct Obj_0c140384 {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char pad1[16 - 5];
    void (*p16)(struct Obj_0c140384 *);
    unsigned char pad2[24 - 20];
    struct Obj_0c140384 *p24;
    unsigned char pad3[32 - 28];
    unsigned char b32;
    unsigned char pad4[38 - 33];
    short s38;
};

typedef void (*handler_0c140384)(struct Obj_0c140384 *, struct Obj_0c140384 *);

extern struct Obj_0c140384 *func_0c0374da(int a, int b, int c);
extern handler_0c140384 dat_0c24f674[];

void func_0c1403b8(struct Obj_0c140384 *p);

struct Obj_0c140384 *func_0c140384(struct Obj_0c140384 *p, int b)
{
    struct Obj_0c140384 *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c1403b8;
        q->s38 = 0x0c00;
        q->b32 = b;
        q->p24 = p;
    }
    return q;
}

void func_0c1403b8(struct Obj_0c140384 *p)
{
    dat_0c24f674[p->b4](p, p->p24);
}
