struct Obj_0c154028 {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char pad1[16 - 5];
    void (*p16)(struct Obj_0c154028 *);
    unsigned char pad2[24 - 20];
    struct Obj_0c154028 *p24;
    unsigned char pad3[33 - 28];
    unsigned char b33;
    unsigned char pad4[38 - 34];
    short s38;
    unsigned char pad5[0xcc - 40];
    int lcc;
};

typedef void (*handler_0c154028)(struct Obj_0c154028 *);

extern struct Obj_0c154028 *func_0c0374da(int a, int b, int c);
extern int *dat_0c2fb354;
extern handler_0c154028 dat_0c250650[];

void func_0c154074(struct Obj_0c154028 *p);

struct Obj_0c154028 *func_0c154028(struct Obj_0c154028 *p)
{
    int n;
    struct Obj_0c154028 *q;

    n = 0;
    do {
        if ((q = func_0c0374da(0, 1, 0)) != 0) {
            q->p16 = func_0c154074;
            q->p24 = p;
            q->s38 = 0x1601;
            q->b33 = n;
            n = n + 1;
        } else
            break;
    } while (n < 16);
    return q;
}

void func_0c154074(struct Obj_0c154028 *p)
{
    dat_0c2fb354 = &p->lcc;
    dat_0c250650[p->b4](p);
}
