struct Obj_0c16df90 {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char pad1[16 - 5];
    void (*p16)(struct Obj_0c16df90 *);
    struct Obj_0c16df90 *p20;
    struct Obj_0c16df90 *p24;
    unsigned char pad2[32 - 28];
    unsigned char b32;
    unsigned char b33;
    unsigned char pad3[38 - 34];
    short s38;
};

typedef void (*handler_0c16df90)(struct Obj_0c16df90 *);

extern struct Obj_0c16df90 *func_0c0374da(int a, int b, int c);
extern handler_0c16df90 dat_0c2525c0[];

void func_0c16dfd2(struct Obj_0c16df90 *p);

struct Obj_0c16df90 *func_0c16df90(struct Obj_0c16df90 *p, struct Obj_0c16df90 *a, int b, int c)
{
    struct Obj_0c16df90 *q;

    if ((q = func_0c0374da(0, 1, 1)) != 0) {
        q->s38 = 0x2b01;
        q->b32 = b;
        q->b33 = c;
        q->p16 = func_0c16dfd2;
        q->p20 = p;
        q->p24 = a;
    }
    return q;
}

void func_0c16dfd2(struct Obj_0c16df90 *p)
{
    dat_0c2525c0[p->b4](p);
}
