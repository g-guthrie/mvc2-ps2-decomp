/* All 17 functions and both literal pools match retail across the 660-byte
 * section. The two-byte alignment pad at 0x0c056b7a joins the tail pool to
 * this unit; earlier data-only owners are released on registration. */
struct Rec_ub3_05 { unsigned char pad[28]; int l28; };

struct Obj_ub3_05 {
    unsigned char pad0[5];
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char pad1[20];
    short s28;
    unsigned char pad2[2];
    unsigned char b32;
    unsigned char pad3[19];
    float f52;
    float f56;
    unsigned char pad4[32];
    float f92;
    float f96;
    unsigned char pad5[4];
    float f104;
    float f108;
    unsigned char pad6[209];
    unsigned char b141;
    unsigned char pad7[144];
    unsigned char b1d2;
    unsigned char pad8[36];
    unsigned char b1f7;
    unsigned char pad9[10];
    unsigned char b202;
};

typedef void (*handler_ub3_05)(struct Obj_ub3_05 *);

extern char func_0c02a026(struct Obj_ub3_05 *);
extern int func_0c037d54(struct Obj_ub3_05 *);
extern void func_0c044450(struct Obj_ub3_05 *, int);
extern void func_0c02a0c4(struct Obj_ub3_05 *, int, int);
extern void func_0c0437b8(struct Obj_ub3_05 *);
extern struct Rec_ub3_05 *dat_0c2d6f84;
extern handler_ub3_05 table_0c23f68c[];
extern handler_ub3_05 table_0c23f694[];
extern handler_ub3_05 table_0c23f69c[];
extern handler_ub3_05 table_0c23f6a4[];
extern handler_ub3_05 table_0c23f6ac[];
extern int func_0c03916c(struct Obj_ub3_05 *);

void func_0c056910(struct Obj_ub3_05 *a)
{
    func_0c02a026(a);
    if (a->b141 != 0)
        return;
    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->s28 = 30;
    if (!a->b202) {
        a->f92 = (a->b1d2 != 0) ? 10.833333015441895f : -10.833333015441895f;
        a->f104 = (a->b1d2 != 0) ? -0.3125f : 0.3125f;
    } else {
        a->f92 = (a->b1d2 != 0) ? 5.83333302f : -5.83333302f;
        a->f104 = (a->b1d2 != 0) ? -0.1041666642f : 0.1041666642f;
    }
}

void func_0c0569a2(struct Obj_ub3_05 *a)
{
    int r;

    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    if ((r = func_0c037d54(a)) != 0) {
        a->b7 = 0;
        a->b6 = 0;
        a->b1f7 = 7;
        func_0c044450(a, r);
        return;
    }
    if (--a->s28 == 0) {
        a->b6++;
        func_0c02a0c4(a, 15, 5);
    }
}

void func_0c056a62(struct Obj_ub3_05 *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c056a84(struct Obj_ub3_05 *a)
{
    func_0c0437b8(a);
}

void func_0c056a8a(struct Obj_ub3_05 *a)
{
    table_0c23f68c[a->b6](a);
}

void func_0c056a9c(struct Obj_ub3_05 *a)
{
    a->b6++;
    func_0c02a0c4(a, 18, 0);
}

void func_0c056aaa(struct Obj_ub3_05 *a)
{
    if (func_0c02a026(a) < 0)
        a->b5++;
}

void func_0c056aca(struct Obj_ub3_05 *a)
{
    a->b6++;
    if (dat_0c2d6f84->l28 & 1)
        func_0c02a0c4(a, 19, 0);
    else
        func_0c02a0c4(a, 19, 1);
}

void func_0c056aea(struct Obj_ub3_05 *a)
{
    func_0c02a026(a);
}

void func_0c056af0(struct Obj_ub3_05 *a)
{
    table_0c23f694[a->b6](a);
}

void func_0c056b02(struct Obj_ub3_05 *a)
{
    a->b6++;
    func_0c02a0c4(a, 19, 2);
}

void func_0c056b10(struct Obj_ub3_05 *a)
{
    func_0c02a026(a);
}

void func_0c056b16(struct Obj_ub3_05 *a)
{
    table_0c23f69c[a->b6](a);
}

void func_0c056b28(struct Obj_ub3_05 *a)
{
    a->b6++;
    func_0c02a0c4(a, 19, 2);
}

void func_0c056b36(struct Obj_ub3_05 *a)
{
    func_0c02a026(a);
}

void func_0c056b3c(struct Obj_ub3_05 *a)
{
    table_0c23f6a4[a->b6](a);
}

void func_0c056b4e(struct Obj_ub3_05 *a)
{
    if (func_0c03916c(a) != 0) {
        func_0c0437b8(a);
        return;
    }
    table_0c23f6ac[a->b32](a);
}
