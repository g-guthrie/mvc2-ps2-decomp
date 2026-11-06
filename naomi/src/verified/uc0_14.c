struct Vec3_uc0_14 { float x, y, z; };

struct Obj_uc0_14 {
    unsigned char pad0[4];
    unsigned char b4, b5;
    unsigned char pad1[28 - 6];
    short s28;
    unsigned char pad2[33 - 30];
    unsigned char b33;
    unsigned char pad3[36 - 34];
    unsigned char b36;
    unsigned char pad4[52 - 37];
    struct Vec3_uc0_14 v52;
    unsigned char pad5[92 - 64];
    float f92, f96;
    unsigned char pad6[104 - 100];
    float f104;
    unsigned char pad7[0x12c - 108];
    unsigned char b12c;
    unsigned char pad8[0x1d0 - 0x12d];
    unsigned char b1d0;
    unsigned char pad9[0x1e9 - 0x1d1];
    unsigned char b1e9;
    unsigned char pad10[0x2a4 - 0x1ea];
    unsigned char b2a4;
};

struct Dat0c2f8338_uc0_14 {
    unsigned char pad0[59];
    unsigned char b59;
    unsigned short w60;
};

typedef void (*handler_uc0_14)(struct Obj_uc0_14 *);

extern struct Dat0c2f8338_uc0_14 dat_0c2f8338;
extern handler_uc0_14 dat_0c2580e4[];
extern void func_0c14264c(struct Obj_uc0_14 *);

void func_0c19762c(struct Obj_uc0_14 *a, struct Obj_uc0_14 *b)
{
    if (b->b5 == 0)
        if (b->b1d0 == 21)
            if (b->b1e9 == 1)
                goto success;
    a->b4 = 2;
    a->b12c = 0;
    return;
success:
    a->b36 = 12;
    if ((dat_0c2f8338.w60 & (1 << dat_0c2f8338.b59)) == 0)
        dat_0c2580e4[a->b5](a);
}

void func_0c197688(struct Obj_uc0_14 *a, struct Obj_uc0_14 *b)
{
    a->v52 = b->v52;
    a->v52.x += a->f92;
    a->f92 += a->f104;
    if (--a->s28 == 0) {
        a->b5++;
        func_0c14264c(a);
    }
    a->f96 = a->f92 / (float)a->b33;
}

void func_0c1976ea(struct Obj_uc0_14 *a, struct Obj_uc0_14 *b)
{
    unsigned char *p = &b->b2a4;

    a->v52 = b->v52;
    a->v52.x += a->f92;
    if (*p != 0) {
        a->b5++;
        a->f104 = -a->f104;
        a->s28 = 8;
    }
    a->f96 = a->f92 / (float)a->b33;
}
