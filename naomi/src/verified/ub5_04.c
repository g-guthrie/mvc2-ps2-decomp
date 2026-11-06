/* All three functions and their shared 56-byte pool match retail across the
 * reviewed 336-byte extent. Float literals use SHC's exact decimal spellings. */
struct Block12_ub5_04 { float f[3]; };
struct Block192_ub5_04 {
    unsigned char pad0[80];
    unsigned char b80;   /* absolute offset 300 */
    unsigned char pad1[84 - 81];
    short w84;           /* absolute offset 304 */
    unsigned char pad2[101 - 86];
    signed char b101;    /* absolute offset 321 */
    unsigned char pad3[192 - 102];
};

struct Obj_ub5_04 {
    unsigned char pad0[1];
    unsigned char b1;
    unsigned char b2;
    unsigned char pad1[1];
    unsigned char b4;
    unsigned char b5;
    unsigned char pad2[33 - 6];
    unsigned char b33;
    unsigned char pad2b[36 - 34];
    unsigned char b36;
    unsigned char pad3[48 - 37];
    unsigned char b48;
    unsigned char pad4[52 - 49];
    union {
        struct { float f52, f56; unsigned char pad[4]; } fv;
        struct Block12_ub5_04 blk;
    } u52;
    unsigned char pad5[80 - 64];
    union {
        struct { float f80, f84; unsigned char pad[4]; } fv;
        struct Block12_ub5_04 blk;
    } u80;
    float f92;
    float f96;
    unsigned char pad8[104 - 100];
    float f104;
    float f108;
    unsigned char pad10[220 - 112];
    struct Block192_ub5_04 s220;
    unsigned char pad13[419 - 412];
    unsigned char b419;
    unsigned char b420;
    unsigned char pad14[464 - 421];
    unsigned char b464;
};

typedef void (*handler_ub5_04)(struct Obj_ub5_04 *);

extern handler_ub5_04 dat_0c257f20[];
extern void func_0c02a0c4(struct Obj_ub5_04 *, int, int);

void func_0c195724(struct Obj_ub5_04 *a, struct Obj_ub5_04 *b)
{
    if (b->b5 != 0)
        goto shared;
    if (b->b464 != 21)
        goto shared;
    a->u52.blk = b->u52.blk;
    if (a->b33)
        a->u52.fv.f52 += 266.66666f;
    if (!(b->s220.b101 & 2))
        return;
shared:
    a->b4 = 2;
    a->s220.b80 = 0;
}

void func_0c195776(struct Obj_ub5_04 *a)
{
    dat_0c257f20[a->b4](a);
}

void func_0c195788(struct Obj_ub5_04 *a, struct Obj_ub5_04 *b)
{
    float f4;

    a->s220 = b->s220;
    a->s220.b80 = 1;
    a->b2 = b->b2;
    a->b1 = b->b1;
    a->u80.fv.f80 = b->u80.fv.f80;
    a->u80.fv.f84 = b->u80.fv.f84;
    a->b419 = b->b419;
    a->b420 = b->b420;
    a->b48 = b->b48;
    a->u80.blk = b->u80.blk;
    a->b36 = b->b36;
    a->b4++;
    a->b36 = 0;
    a->f92 = 20.0f;
    a->f104 = 0.0f;
    a->f96 = 0.0f;
    a->f108 = -0.80357140303f;
    f4 = 106.666664124f;
    if (a->s220.w84 != 0) {
        a->f92 = -a->f92;
        a->f104 = -a->f104;
        f4 = -106.666664124f;
    }
    a->u52.fv.f52 = b->u52.fv.f52 + f4;
    a->u52.fv.f56 = 107.142853f + b->u52.fv.f56;
    func_0c02a0c4(a, 23, 21);
}
