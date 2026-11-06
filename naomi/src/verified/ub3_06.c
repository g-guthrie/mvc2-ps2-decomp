/* All four callbacks and their shared pool match at the reviewed 364-byte
 * extent. The three 5/3-derived constants need SHC's exact decimal spellings. */
struct Obj_ub3_06 {
    unsigned char pad0[6];
    unsigned char b6;
    unsigned char pad1[21];
    short s28;
    unsigned char pad2[22];
    float f52;
    float f56;
    unsigned char pad3[32];
    float f92;
    unsigned char pad4[4];
    float f100;
    float f104;
    unsigned char pad5[192];
    unsigned char b12c;
    unsigned char pad6[20];
    unsigned char b141;
    unsigned char pad7[98];
    unsigned char b1a4;
    unsigned char pad8[631];
    float f41c;
};

typedef void (*handler_ub3_06)(struct Obj_ub3_06 *);

extern void func_0c043352(struct Obj_ub3_06 *);
extern char func_0c02a026(struct Obj_ub3_06 *);
extern void func_0c0437b8(struct Obj_ub3_06 *);
extern handler_ub3_06 table_0c2430e4[];
extern void func_0c02a0c4(struct Obj_ub3_06 *, int, int);
extern void func_0c0344a0(struct Obj_ub3_06 *, int);

void func_0c096ae6(struct Obj_ub3_06 *a);

void func_0c096a18(struct Obj_ub3_06 *a)
{
    func_0c043352(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
    if (a->b141) {
        a->b141 = 0;
        a->f92 = 0.0f;
        a->f104 = 0.0f;
    }
}

void func_0c096a6c(struct Obj_ub3_06 *a)
{
    table_0c2430e4[a->b6](a);
}

void func_0c096a7e(struct Obj_ub3_06 *a)
{
    a->b6++;
    a->b12c = 1;
    a->f100 = a->f52;
    if ((a->b1a4 & 1) == 0) {
        a->f52 -= 426.66666f;
        a->f92 = 10.0f;
    } else {
        a->f52 += 426.66666f;
        a->f92 = -10.0f;
    }
    a->f56 = a->f41c;
    a->f104 = 0.0f;
    a->s28 = 30;
    func_0c02a0c4(a, 18, 0);
    func_0c096ae6(a);
}

void func_0c096ae6(struct Obj_ub3_06 *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    if (--a->s28 <= 0) {
        a->b6++;
        a->f104 = (a->b1a4 & 1) == 0 ? -0.41666666f : 0.41666666f;
        func_0c02a0c4(a, 18, 1);
        func_0c0344a0(a, 10);
    }
    func_0c02a026(a);
}
