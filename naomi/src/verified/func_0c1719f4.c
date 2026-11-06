struct Obj_0c1719f4 {
    unsigned char pad0[1];
    unsigned char b1;
    unsigned char pad1[4 - 2];
    unsigned char b4;
    unsigned char pad2[16 - 5];
    void (*p16)(struct Obj_0c1719f4 *);
    unsigned char pad3[24 - 20];
    struct Obj_0c1719f4 *p24;
    unsigned char pad4[32 - 28];
    unsigned char b32;
    unsigned char b33;
    unsigned char pad5[38 - 34];
    short s38;
};

typedef void (*handler2_0c1719f4)(struct Obj_0c1719f4 *, struct Obj_0c1719f4 *);
typedef void (*handler_0c1719f4)(struct Obj_0c1719f4 *);

extern struct Obj_0c1719f4 *func_0c0374da(int a, int b, int c);
extern handler2_0c1719f4 dat_0c2528dc[];
extern handler_0c1719f4 dat_0c2528e4[];

void func_0c171a42(struct Obj_0c1719f4 *p);
void func_0c171a58(struct Obj_0c1719f4 *p);

struct Obj_0c1719f4 *func_0c1719f4(struct Obj_0c1719f4 *p, unsigned char b, unsigned char c)
{
    struct Obj_0c1719f4 *q;

    if ((q = func_0c0374da(0, 2, 0)) != 0) {
        q->p16 = func_0c171a42;
        q->s38 = 0x2e03;
        q->p24 = p;
        q->b1 = p->b1;
        *(&q->b32) = b;
        *(&q->b33) = c;
    }
    return q;
}

void func_0c171a42(struct Obj_0c1719f4 *p)
{
    dat_0c2528dc[p->b32](p, p->p24);
}

void func_0c171a58(struct Obj_0c1719f4 *p)
{
    dat_0c2528e4[p->b4](p);
}
