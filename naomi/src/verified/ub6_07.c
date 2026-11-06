/* Translation unit around 0x0c0b4630: five small callbacks/leaves sharing
 * one actor-like object. The assignment gave size 252 (span ending at
 * 0x0c0b472c, mid pool); the real extent runs through one more pool block
 * to 0x0c0b4758, where the next function's prologue begins. Extended to
 * size 296.
 *
 * All five functions and the shared pool match. func_0c0b468e tails into
 * func_0c1a62b0(a, 4); b141 is signed so the cmp/eq immediates skip extu.b. */

struct Obj_ub6_07 {
    unsigned char pad0[5];
    unsigned char b5;
    unsigned char pad1[32 - 6];
    unsigned char b32;
    unsigned char pad2[56 - 33];
    float f56;
    unsigned char pad3[92 - 60];
    float f92, f96, f100, f104, f108;
    unsigned char pad4[0x108 - 112];
    float f264;
    unsigned char pad5[0x12c - 0x10c];
    unsigned char b12c;
    unsigned char pad6[0x141 - 0x12d];
    char b141;
    unsigned char pad7[0x1f9 - 0x142];
    unsigned char b1f9;
};

typedef void (*handler_ub6_07)(struct Obj_ub6_07 *);

extern handler_ub6_07 dat_0c244e18[];
extern signed char func_0c02a026(struct Obj_ub6_07 *);
extern void func_0c02a0c4(struct Obj_ub6_07 *, int, int);
extern void func_0c0344a0(struct Obj_ub6_07 *, int);
extern void func_0c1a62b0(struct Obj_ub6_07 *, int);

void func_0c0b4630(struct Obj_ub6_07 *a)
{
    a->b32++;
    a->b12c = 1;
    func_0c02a0c4(a, 18, 0);
    func_0c0344a0(a, 10);
}

void func_0c0b465a(struct Obj_ub6_07 *a)
{
    if (func_0c02a026(a) < 0)
        a->b5++;
}

void func_0c0b467a(struct Obj_ub6_07 *a)
{
    dat_0c244e18[a->b32](a);
}

void func_0c0b468e(struct Obj_ub6_07 *a)
{
    a->b32++;
    a->b12c = 1;
    func_0c02a0c4(a, 18, 1);
    a->f264 = 0.200000003f;
    a->f56 += 100.0f;
    a->b1f9 = 2;
    func_0c1a62b0(a, 4);
}

void func_0c0b46d4(struct Obj_ub6_07 *a)
{
    func_0c02a026(a);
    if (a->b141 == 2) {
        a->b32++;
        a->f264 = 1.0f;
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        a->f108 = -0.80357140303f;
    }
    if (a->b141 == 3) {
        a->f264 += 0.016000001f;
    }
}
