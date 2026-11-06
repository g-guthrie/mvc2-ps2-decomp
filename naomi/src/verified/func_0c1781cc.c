struct Obj_0c1781cc {
    unsigned char pad0[1];
    unsigned char b1;
    unsigned char pad1[4 - 2];
    unsigned char b4;
    unsigned char pad2[16 - 5];
    void (*p16)(struct Obj_0c1781cc *);
    unsigned char pad3[24 - 20];
    struct Obj_0c1781cc *p24;
    unsigned char pad4[32 - 28];
    unsigned char b32;
    unsigned char b33;
    unsigned char pad5[38 - 34];
    short s38;
};

typedef void (*handler2_0c1781cc)(struct Obj_0c1781cc *, struct Obj_0c1781cc *);
typedef void (*handler_0c1781cc)(struct Obj_0c1781cc *);

extern struct Obj_0c1781cc *func_0c0374da(int a, int b, int c);
extern handler2_0c1781cc dat_0c253720[];
extern handler_0c1781cc dat_0c253724[];

void func_0c17821a(struct Obj_0c1781cc *p);
void func_0c178230(struct Obj_0c1781cc *p);

struct Obj_0c1781cc *func_0c1781cc(struct Obj_0c1781cc *p, unsigned char b, unsigned char c)
{
    struct Obj_0c1781cc *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c17821a;
        q->s38 = 0x3100;
        q->p24 = p;
        q->b1 = p->b1;
        *(&q->b32) = b;
        *(&q->b33) = c;
    }
    return q;
}

void func_0c17821a(struct Obj_0c1781cc *p)
{
    dat_0c253720[p->b32](p, p->p24);
}

void func_0c178230(struct Obj_0c1781cc *p)
{
    dat_0c253724[p->b4](p);
}
