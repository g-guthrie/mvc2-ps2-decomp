struct Obj_0c09143c {
    unsigned char pad0[6];
    unsigned char b6;
    unsigned char b7;
    unsigned char pad1[32 - 8];
    unsigned char b32;
    unsigned char pad2[1];
    unsigned char b34;
    unsigned char pad3[0x1f2 - 35];
    unsigned char b1f2;
    unsigned char b1f3;
};

struct Tgt_0c09143c {
    unsigned char pad[32];
    unsigned char b32;
};

extern void func_0c19887c(struct Obj_0c09143c *, int, int);
extern void func_0c02a0c4(struct Obj_0c09143c *, int, int);
extern void func_0c0903b6(struct Obj_0c09143c *, struct Tgt_0c09143c *);

void func_0c09143c(struct Obj_0c09143c *p, struct Tgt_0c09143c *q)
{
    p->b6 = p->b6 + 1;
    p->b7 = 0;
    p->b34 = 28;
    p->b1f2 = 12;
    p->b1f3 = 12;
    q->b32 = 0;
    func_0c19887c(p, 8, 0);
    func_0c02a0c4(p, 20, 3);
    func_0c0903b6(p, q);
}
