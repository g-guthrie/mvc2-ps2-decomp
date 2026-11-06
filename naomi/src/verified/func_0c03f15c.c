struct Obj_0c03f15c {
    unsigned char pad0[6];
    unsigned char b6;
    unsigned char pad1[52 - 7];
    float f52, f56, f60;
    unsigned char pad2[92 - 64];
    float f92, f96, f100, f104, f108;
    unsigned char pad3[0x1dc - 112];
    char b1dc;
    unsigned char pad4[0x1ed - 0x1dd];
    unsigned char b1ed;
    unsigned char pad5[0x233 - 0x1ee];
    unsigned char b233;
    unsigned char pad6[0x238 - 0x234];
    char b238;
};

typedef void (*handler_0c03f15c)(struct Obj_0c03f15c *);

extern handler_0c03f15c dat_0c23bb84[];
extern handler_0c03f15c dat_0c23bbe8[];
extern unsigned char dat_0c2f8338;
extern void func_0c0491a4(struct Obj_0c03f15c *);
extern char func_0c02a026(struct Obj_0c03f15c *);
extern void func_0c0437b8(struct Obj_0c03f15c *);
extern void func_0c042960(struct Obj_0c03f15c *);

void func_0c03f15c(struct Obj_0c03f15c *p)
{
    dat_0c23bb84[p->b233](p);
}

void func_0c03f170(struct Obj_0c03f15c *p)
{
    if (!p->b6) {
        p->b6 = p->b6 + 1;
        p->f96 = 0.0f;
        p->f108 = 0.0f;
    } else {
        func_0c0491a4(p);
        if (func_0c02a026(p) < 0)
            func_0c0437b8(p);
    }
}

void func_0c03f1b0(struct Obj_0c03f15c *p)
{
    func_0c042960(p);
    if (dat_0c2f8338 < 5) {
        if (p->b1dc) {
            if (p->b238)
                p->b1ed = 2;
        }
    }
    dat_0c23bbe8[p->b6](p);
}
