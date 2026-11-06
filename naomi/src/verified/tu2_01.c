struct V3 { float x, y, z; };

struct Obj_tu2_01 {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char b5;
    unsigned char pad1[0x10 - 6];
    void (*p10)(struct Obj_tu2_01 *);
    unsigned char pad2[28 - 0x14];
    short s28;
    unsigned char pad3[52 - 30];
    struct V3 v52;
    int arr64[1];
    int l68;
    unsigned char pad4[80 - 72];
    struct V3 v80;
    struct V3 v92;
    unsigned char pad5[120 - 104];
    float f120;
    float f124;
    float f128;
    int l84;
    unsigned char pad6[0xcc - 0x88];
    int lcc;
    unsigned char pad7[0x12c - 0xd0];
    unsigned char b12c;
};

struct Src_tu2_01 { unsigned char pad[52]; int l52; int l56; };

extern void func_0c1d2742(struct Obj_tu2_01 *);
extern struct Obj_tu2_01 *func_0c0374da(int, int, int);
extern void func_0c037688(struct Obj_tu2_01 *);
extern float func_0c1ce8c4(void *, unsigned char *, int);
extern struct Src_tu2_01 **dat_0c2d9650;
extern struct V3 dat_0c261100;
extern int dat_0c26110c[];
extern struct V3 dat_0c261114[];
extern int dat_0c2611a4;
extern int dat_0c2611b4;

void func_0c1d2870(struct Obj_tu2_01 *o);

void func_0c1d27f8(struct V3 *a, int b)
{
    struct Obj_tu2_01 *r;

    if ((r = func_0c0374da(0, 7, 1)) != 0) {
        r->b12c = 1;
        r->p10 = func_0c1d2742;
        r->l84 = (*dat_0c2d9650)->l52;
        r->v52 = *a;
        r->l68 = dat_0c26110c[b];
        r->v80 = dat_0c261100;
        r->v92 = dat_0c261114[b];
        r->lcc = 0x515;
    }
}

void func_0c1d2870(struct Obj_tu2_01 *o)
{
    if (o->s28 >= 13) {
        func_0c037688(o);
        return;
    }
    o->arr64[0] = (int)(func_0c1ce8c4(&dat_0c2611a4, &o->b4, o->s28) * 65536.0f / 360.0f + 0.5f) & 0xffff;
    o->f120 = func_0c1ce8c4(&dat_0c2611b4, &o->b5, o->s28);
    o->f124 = o->f120;
    o->f128 = o->f120;
    o->s28 = o->s28 + 1;
}

void func_0c1d28ea(struct V3 *a, int b)
{
    struct Obj_tu2_01 *r;

    if ((r = func_0c0374da(0, 7, 1)) != 0) {
        r->b12c = 1;
        r->p10 = func_0c1d2870;
        r->l84 = (*dat_0c2d9650)->l56;
        r->v52 = *a;
        r->l68 = dat_0c26110c[b];
        r->lcc = 0x507;
    }
}
