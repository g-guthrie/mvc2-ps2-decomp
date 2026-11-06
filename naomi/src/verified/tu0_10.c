/* Four functions sharing the literal pool at 0x0c1c716a. */

struct V3_0c1c7090 { float x, y, z; };

struct Obj_0c1c7090;
typedef void (*fn_0c1c7090)(struct Obj_0c1c7090 *);

struct Obj_0c1c7090 {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char pad1[16 - 5];
    fn_0c1c7090 p16;
    void *p20;
    struct Obj_0c1c7090 *p24;
    unsigned char pad2[32 - 28];
    unsigned char b32;
    unsigned char b33;
    unsigned char b34;
    unsigned char pad3[52 - 35];
    struct V3_0c1c7090 v52;
    int arr64[1];
    int d68;
    int d72;
    unsigned char pad4[0x84 - 76];
    int d84;
    unsigned char pad5[0xcc - 0x88];
    int dcc;
    unsigned char pad6[0x12c - 0xd0];
    unsigned char b12c;
};

struct Glob_0c2d9658 { int (*p0)[1]; };

extern struct Glob_0c2d9658 *dat_0c2d9658;
extern fn_0c1c7090 dat_0c25e718[];
extern struct Obj_0c1c7090 *func_0c0374da(int, int, int);
extern void func_0c02fc02(struct Obj_0c1c7090 *, int, float, float);
extern void func_0c037688(struct Obj_0c1c7090 *);

void func_0c1c713e(struct Obj_0c1c7090 *a);

void func_0c1c7090(struct Obj_0c1c7090 *a, unsigned char b)
{
    struct Obj_0c1c7090 *r;

    if ((r = func_0c0374da(0, 5, 1)) != 0) {
        r->p24 = a;
        r->p20 = a->p20;
        r->b12c = 1;
        r->p16 = func_0c1c713e;
        r->b32 = a->b32;
        r->b33 = a->b33;
        r->b34 = b;
        r->d84 = (*dat_0c2d9658->p0)[a->b32 + 110];
        r->v52 = a->v52;
        r->arr64[0] = a->arr64[0];
        r->d68 = a->d68;
        r->d72 = a->d72;
        r->dcc = 0x0809;
        if (b)
            func_0c02fc02(r, r->b32 + 110, 0.1875f, 0.0f);
    }
}

void func_0c1c713e(struct Obj_0c1c7090 *a)
{
    dat_0c25e718[a->p24->b4](a);
}

void func_0c1c7152(struct Obj_0c1c7090 *a)
{
    a->b12c = a->p24->b12c;
    a->d72 = a->p24->d72;
}

void func_0c1c7164(struct Obj_0c1c7090 *a)
{
    func_0c037688(a);
}
