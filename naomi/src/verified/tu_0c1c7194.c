/* Spark spawners sharing the pools at 0x0c1c72ce and 0x0c1c745a (0x0c1c7194-0x0c1c7494). */

struct V3_0c1c7194 { float x, y, z; };

struct Obj_0c1c7194;
typedef void (*fn_0c1c7194)(struct Obj_0c1c7194 *);

struct Obj_0c1c7194 {
    unsigned char pad0[1];
    unsigned char b1;
    unsigned char pad0b[2];
    unsigned char b4;
    unsigned char pad1[16 - 5];
    fn_0c1c7194 p16;
    unsigned char *p20;
    struct Obj_0c1c7194 *p24;
    unsigned char pad2[32 - 28];
    unsigned char b32;
    unsigned char b33;
    unsigned char pad3[52 - 34];
    struct V3_0c1c7194 v52;
    int arr64[1];
    int d68;
    int d72;
    unsigned char pad3b[80 - 76];
    float f80;
    float f84;
    float f88;
    unsigned char pad4[0x84 - 92];
    int d84;
    unsigned char x88[0xc8 - 0x88];
    void *pc8;
    int dcc;
    unsigned char pad6[0x12c - 0xd0];
    unsigned char b12c;
};

struct W_0c1c7194 { unsigned char pad[0x52c]; unsigned char b52c; };
struct Glob_0c2d9658 { int (*p0)[1]; };

extern struct Glob_0c2d9658 *dat_0c2d9658;
struct G_0c1c7194 { unsigned char pad[41]; unsigned char b41; };
extern struct G_0c1c7194 *dat_0c2d6f84;
extern struct V3_0c1c7194 dat_0c25e730[][3];
extern struct V3_0c1c7194 dat_0c25e778[][2];
extern fn_0c1c7194 dat_0c25e8c4[];
extern struct Obj_0c1c7194 *func_0c0374da(int, int, int);
extern void func_0c025fc2(struct Obj_0c1c7194 *, fn_0c1c7194);
extern void func_0c1c766a(struct Obj_0c1c7194 *);
extern void func_0c1c756e(struct Obj_0c1c7194 *);
extern void func_0c1c76bc(struct Obj_0c1c7194 *);

void func_0c1c743c(struct Obj_0c1c7194 *a);
void func_0c1c7278(struct Obj_0c1c7194 *a);

void func_0c1c7194(struct Obj_0c1c7194 *a)
{
    struct Obj_0c1c7194 *r;
    short i;
    struct W_0c1c7194 *w = (struct W_0c1c7194 *)a->p20;

    for (i = 0; i < 3; i++) {
        if ((r = func_0c0374da(0, 5, 1)) == 0)
            return;
        r->p24 = a;
        r->pc8 = a->x88;
        r->p20 = a->p20;
        r->b12c = 1;
        r->p16 = func_0c1c743c;
        r->b32 = a->b32;
        r->b33 = i;
        r->b1 = w->b52c;
        r->d84 = (*dat_0c2d9658->p0)[i + 99];
        r->v52 = *(&dat_0c25e730[r->b32][0] + i);
        r->arr64[0] = 0x2000;
        r->d68 = 0;
        r->d72 = 0;
        r->dcc = 0x0813;
        r->f80 = 1.0f;
        r->f84 = 0.01f;
        r->f88 = 1.0f;
        func_0c1c7278(r);
    }
}

void func_0c1c7278(struct Obj_0c1c7194 *a)
{
    struct Obj_0c1c7194 *r;

    if ((r = func_0c0374da(0, 5, 1)) != 0) {
        r->p24 = a;
        r->pc8 = a->pc8;
        r->p20 = a->p20;
        r->b12c = 1;
        r->p16 = func_0c1c766a;
        r->b32 = a->b32;
        r->b33 = a->b33;
        r->b1 = a->b1;
        if (dat_0c2d6f84->b41)
            r->d84 = (*dat_0c2d9658->p0)[108];
        else
            r->d84 = (*dat_0c2d9658->p0)[102];
        r->v52 = *(&dat_0c25e730[r->b32][0] + r->b33);
        r->arr64[0] = 0x2000;
        r->dcc = 0x0813;
        r->f80 = 1.0f;
        r->f84 = 0.01f;
        r->f88 = 1.0f;
        func_0c025fc2(r, func_0c1c76bc);
    }
}

void func_0c1c7368(struct Obj_0c1c7194 *a)
{
    struct Obj_0c1c7194 *r;
    short i;

    for (i = 0; i < 2; i++) {
        if ((r = func_0c0374da(0, 5, 1)) == 0)
            return;
        r->p24 = a;
        r->pc8 = a->x88;
        r->p20 = a->p20;
        r->b12c = 1;
        r->p16 = func_0c1c756e;
        r->b32 = a->b32;
        r->b33 = i;
        r->d84 = (*dat_0c2d9658->p0)[107 - i];
        r->v52 = *(&dat_0c25e778[r->b32][0] + i);
        r->arr64[0] = 0x2000;
        r->d68 = 0;
        r->d72 = 0;
        r->dcc = 0x0813;
        r->f80 = 1.0f;
        r->f84 = 0.01f;
        r->f88 = 1.0f;
    }
}

void func_0c1c743c(struct Obj_0c1c7194 *a)
{
    dat_0c25e8c4[a->p24->b4](a);
}

void func_0c1c7450(struct Obj_0c1c7194 *a)
{
    a->b12c = a->p24->b12c;
}
