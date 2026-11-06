struct V3_0c0762f8 { float x, y, z; };

struct Obj_0c0762f8 {
    unsigned char pad0[28];
    short s28;
    unsigned char pad1[0x141 - 30];
    unsigned char b141;
    unsigned char pad2[0x1a0 - 0x142];
    unsigned char b1a0;
    unsigned char pad3[0x1f7 - 0x1a1];
    unsigned char b1f7;
};

extern void func_0c1d4610(struct Obj_0c0762f8 *, struct V3_0c0762f8 *);
extern void func_0c03f004(struct Obj_0c0762f8 *, void *);
extern void func_0c02a026(struct Obj_0c0762f8 *);

void func_0c0762f8(struct Obj_0c0762f8 *p, void *q)
{
    struct V3_0c0762f8 v;

    p->b141 = 2;
    v.x = -26.666666031f;
    v.y = 68.57143f;
    func_0c1d4610(p, &v);
    p->b1a0 = 10;
    func_0c03f004(p, q);
}

void func_0c076338(struct Obj_0c0762f8 *p)
{
    if (p->b1f7 == 1) {
        if (p->s28)
            func_0c02a026(p);
    }
}
