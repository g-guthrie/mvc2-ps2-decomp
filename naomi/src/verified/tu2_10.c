/* Four handlers sharing the pool at 0x0c0ca240. */
struct Sub_tu2_10 { unsigned char pad[2]; char b2; };

struct Obj_tu2_10 {
    unsigned char pad0[5];
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char pad1[0xc4 - 8];
    unsigned char bc4;
    unsigned char pad2[0x1e9 - 0xc5];
    unsigned char b1e9;
    unsigned char pad3[0x1f7 - 0x1ea];
    unsigned char b1f7;
    unsigned char pad4[0x2a4 - 0x1f8];
    struct Sub_tu2_10 s2a4;
    unsigned char pad5[0x364 - 0x2a7];
    unsigned char s364[8];
    unsigned char s36c[8];
    unsigned char s374[0x3c4 - 0x374];
    unsigned char s3c4[4];
};

extern unsigned char func_0c046e7e(struct Obj_tu2_10 *, void *, void *);
extern void func_0c047aac(struct Obj_tu2_10 *, void *);
extern void func_0c045248(struct Obj_tu2_10 *, int);
extern int func_0c037d54(struct Obj_tu2_10 *);
extern void func_0c044450(struct Obj_tu2_10 *, int);
extern int dat_0c247d90;
extern int dat_0c247da0;
extern int dat_0c247db0;
extern int dat_0c247e52;

int func_0c0ca114(struct Obj_tu2_10 *o)
{
    struct Sub_tu2_10 *s = &o->s2a4;

    if (!func_0c046e7e(o, &dat_0c247d90, o->s364))
        return 0;
    else if (s->b2)
        return 0;
    func_0c047aac(o, o->s364);
    o->b5 = 0;
    o->b7 = 0;
    o->b6 = 0;
    o->b1e9 = 0;
    func_0c045248(o, 21);
    return 1;
}

int func_0c0ca172(struct Obj_tu2_10 *o)
{
    if (func_0c046e7e(o, &dat_0c247da0, o->s36c) == 0)
        return 0;
    func_0c047aac(o, o->s36c);
    o->b5 = 0;
    o->b1e9 = 1;
    func_0c045248(o, 21);
    o->b6 = o->b7 = 0;
    return 1;
}

int func_0c0ca1ba(struct Obj_tu2_10 *o)
{
    if (func_0c046e7e(o, &dat_0c247db0, o->s374) == 0)
        return 0;
    func_0c047aac(o, o->s374);
    o->b1e9 = 2;
    o->b5 = 0;
    func_0c045248(o, 21);
    o->b6 = o->b7 = 0;
    return 1;
}

int func_0c0ca202(struct Obj_tu2_10 *o)
{
    int v;

    if (func_0c046e7e(o, &dat_0c247e52, o->s3c4) == 0)
        return 0;
    else if ((v = func_0c037d54(o)) == 0)
        return 0;
    o->b1f7 = 0xc4;
    func_0c044450(o, v);
    return 1;
}
