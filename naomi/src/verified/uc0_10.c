struct Obj_uc0_10 {
    unsigned char pad0[6];
    unsigned char b6;
    unsigned char pad1[28 - 7];
    short s28;
    unsigned char pad2[52 - 30];
    float f52, f56;
    unsigned char pad3[92 - 60];
    float f92, f96, f100, f104, f108;
    unsigned char pad4[0xc0 - 112];
    unsigned char bc0;
    unsigned char pad5[0xcc - 0xc1];
    unsigned int ucc;
    unsigned char pad6[0x1d2 - 0xd0];
    unsigned char b1d2;
    unsigned char pad7[0x1f7 - 0x1d3];
    unsigned char b1f7;
    unsigned char b1f8;
    unsigned char b1f9;
    unsigned char pad8[0x2a8 - 0x1fa];
    unsigned int u2a8;
    unsigned char pad9[0x2c8 - 0x2ac];
    unsigned int i2c8;
    unsigned char pad10[0x411 - 0x2cc];
    unsigned char b411;
};

struct Rec_uc0_10 { unsigned char pad0[1]; unsigned char b1; };

extern void func_0c02a026(struct Obj_uc0_10 *);
extern void func_0c02a0c4(struct Obj_uc0_10 *, int, int);
extern struct Rec_uc0_10 *func_0c037d54(struct Obj_uc0_10 *);
extern void func_0c08151c(struct Obj_uc0_10 *, struct Rec_uc0_10 *);
extern void func_0c044450(struct Obj_uc0_10 *, struct Rec_uc0_10 *);

void func_0c07e984(struct Obj_uc0_10 *a)
{
    struct Rec_uc0_10 *r;

    a->i2c8 = 4;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if (--a->s28 == 0) {
        float f4 = 0.5208333135f;
        if (a->b1d2 != 0)
            f4 = -f4;
        a->f104 = f4;
        a->b6++;
        if (a->b1f9 == 2) {
            a->b6 = 4;
            a->i2c8 = 0;
            a->f92 = 0.0f;
            a->f96 = 0.0f;
            a->f104 = 0.0f;
            a->f108 = 0.0f;
            a->f108 = -0.80357140303f;
            func_0c02a0c4(a, 1, 9);
        } else {
            func_0c02a0c4(a, 21, 23);
        }
    } else {
        if ((r = func_0c037d54(a)) != 0) {
            a->i2c8 = 16;
            if (a->b411 == 0) {
                a->u2a8 = r->b1;
                func_0c08151c(a, r);
            } else {
                a->ucc = 0;
            }
            a->b1f7 = 0xc0;
            func_0c044450(a, r);
        }
    }
}
