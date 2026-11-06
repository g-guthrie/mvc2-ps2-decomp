/* The nonzero branch preserves retail's register allocation for the store.
 * The 0.6f multiplier is spelled 1.0f - 0.4f so SHC loads 0x3f19999a;
 * a bare 0.6f compiles one ULP low. */
struct V3 { float x, y, z; };

struct Parent_tu2_11 {
    unsigned char pad0[28];
    short s28;
    unsigned char pad1[0xd4 - 30];
    int ld4;
};

struct Obj_tu2_11 {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char pad1[0x10 - 5];
    void (*p10)(struct Obj_tu2_11 *);
    unsigned char pad2[24 - 0x14];
    struct Parent_tu2_11 *p24;
    unsigned char pad3[52 - 28];
    struct V3 v52;
    int arr64[3];
    unsigned char pad4[80 - 76];
    float f80, f84, f88, f92;
    unsigned char pad5[120 - 96];
    float f120, f124, f128;
    int l84;
    unsigned char pad6[0xcc - 0x88];
    int lcc;
    unsigned char pad7[0x12c - 0xd0];
    unsigned char b12c;
};

struct Src_tu2_11 { unsigned char pad[36]; int l36; };
struct Game_tu2_11 { unsigned char pad[2]; char b2; };

extern struct Obj_tu2_11 *func_0c0374da(int, int, int);
extern void func_0c037688(struct Obj_tu2_11 *);
extern struct Src_tu2_11 **dat_0c2d9680;
extern struct Game_tu2_11 *dat_0c2d6f84;
extern struct V3 dat_0c232090;
extern struct V3 dat_0c23209c;
extern void (*dat_0c260aac[])(struct Obj_tu2_11 *);

void func_0c1cdff0(struct Obj_tu2_11 *o);

void func_0c1cdf30(struct Parent_tu2_11 *a)
{
    struct Obj_tu2_11 *r;

    if ((r = func_0c0374da(0, 11, 1)) != 0) {
        r->p24 = a;
        r->b12c = 1;
        r->p10 = func_0c1cdff0;
        r->l84 = (*dat_0c2d9680)->l36;
        r->v52 = dat_0c232090;
        r->arr64[0] = (int)(dat_0c23209c.x * 65536.0f / 360.0f + 0.5f) & 0xffff;
        r->arr64[1] = (int)(dat_0c23209c.y * 65536.0f / 360.0f + 0.5f) & 0xffff;
        r->arr64[2] = (int)(dat_0c23209c.z * 65536.0f / 360.0f + 0.5f) & 0xffff;
        r->lcc = 0x0c1f;
        r->f80 = 1.0f - 0.4f;
        r->f84 = 1.0f - 0.4f;
        r->f88 = 1.0f - 0.4f;
        r->f92 = dat_0c23209c.x;
        r->p24->ld4 = 1;
        r->f120 = 1.0f;
        r->f124 = 1.0f;
        r->f128 = 1.0f;
    }
}

void func_0c1cdff0(struct Obj_tu2_11 *o)
{
    if (dat_0c2d6f84->b2 != 3)
        goto tail;
    if (o->p24->s28 != 0)
        o->p24->ld4 = 0;
    else
        goto dispatch;
tail:
    func_0c037688(o);
    return;
dispatch:
    dat_0c260aac[o->b4](o);
}
