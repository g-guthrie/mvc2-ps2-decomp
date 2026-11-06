struct Game_tu2_12 { unsigned char pad[124]; short w7c[1]; };

struct Obj_tu2_12 {
    unsigned char pad0[2];
    unsigned char b2;
    unsigned char pad1[3];
    unsigned char b6;
    unsigned char b7;
    unsigned char pad2[0x19e - 8];
    unsigned char b19e;
    unsigned char pad3[0x1a1 - 0x19f];
    unsigned char b1a1;
    unsigned char pad4[0x1a7 - 0x1a2];
    unsigned char b1a7;
    unsigned char pad5[0x1ac - 0x1a8];
    short w1ac;
    unsigned char pad6[0x1c4 - 0x1ae];
    int l1c4;
    unsigned char pad7[0x1d6 - 0x1c8];
    char b1d6;
    unsigned char pad8[0x1e8 - 0x1d7];
    unsigned char b1e8;
    unsigned char pad9[0x1fc - 0x1e9];
    unsigned char b1fc;
    unsigned char pad10[1];
    unsigned char b1fe;
    unsigned char b1ff;
    unsigned char pad11[0x3f4 - 0x200];
    int l3f4;
};

extern void func_0c02a0c4(struct Obj_tu2_12 *, int, int);
extern struct Game_tu2_12 *dat_0c2f83f8;
extern unsigned char dat_0c24e065[];
extern unsigned char dat_0c24e05f[];
extern char dat_0c24e068[];
extern char dat_0c24e06e[];
extern int dat_0c24df1c[];
extern void (*dat_0c24e074[])(struct Obj_tu2_12 *);

void func_0c12ea2c(struct Obj_tu2_12 *o)
{
    unsigned char idx;

    o->b7 = 0;
    o->b6 = 0;
    idx = o->b1e8;
    if (o->b1fe != 0)
        idx += 3;
    o->b1a7 = dat_0c24e065[o->b1e8];
    o->b1a1 = dat_0c24e05f[idx];
    o->w1ac = 0;
    o->b19e = 0;
    o->l1c4 = 0;
    (*dat_0c2f83f8).w7c[o->b2]++;
    func_0c02a0c4(o, dat_0c24e06e[idx], dat_0c24e068[idx]);
    if (o->b1fc != 0)
        idx += 6;
    o->l3f4 = dat_0c24df1c[idx];
    if (o->b1fe == 0) {
        if (o->b1d6 & 15)
            o->b1d6 = o->b1d6 - 1;
    } else {
        if (o->b1d6 & 0xf0)
            o->b1d6 = o->b1d6 - 16;
    }
}

void func_0c12eade(struct Obj_tu2_12 *o)
{
    if (o->b1fe == 0) {
        if (o->b1d6 & 15)
            goto call;
    } else {
        if ((o->b1d6 & 0xf0) == 0)
            return;
call:
        func_0c12ea2c(o);
    }
}

void func_0c12eb02(struct Obj_tu2_12 *o)
{
    dat_0c24e074[o->b1ff](o);
}
