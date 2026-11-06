/* Four functions sharing the literal pool at 0x0c102890. Candidate:
 * func_0c102780 and func_0c102826 have the retail instruction stream;
 * func_0c1027dc differs only by a `nop` retail places after each `mov r4,r0`
 * in the s == 7 || s == 9 || s == 11 chain (no source shape found);
 * func_0c10283a continues past the pool in retail (SHC flushed the pool after
 * the two `bra` tail calls to the same-file functions at 0x0c1028d4 and
 * 0x0c10296c, which live after the pool and are not in this file, so they
 * become `jmp` through the pool here). The unit's mov.l pool starts at
 * 0x0c1028a4 behind an unmapped pad word at 0x0c1028a2, so the diff tool's
 * section stops at 0x0c1028a2. */
struct Link_tu7_02 { unsigned char pad0[9]; char b9; };

struct Obj_tu7_02 {
    unsigned char pad0[37];
    unsigned char b37;
    char b141;
    unsigned char pad1[0x141 - 38];
    unsigned char pad2[0x158 - 0x142];
    unsigned char b158, b159;
    unsigned char pad3[0x1a3 - 0x15a];
    char b1a3;
    unsigned char pad4[0x1e8 - 0x1a4];
    unsigned char b1e8;
    unsigned char pad5[0x1f9 - 0x1e9];
    char b1f9;
    unsigned char pad6[0x1fe - 0x1fa];
    char b1fe;
    unsigned char pad7[0x2a4 - 0x200];
    unsigned char b1ff;
    struct Link_tu7_02 s2a4;
};

struct Ctl_tu7_02 { unsigned char pad0[16]; char b16; };

typedef void (*fn_tu7_02)(struct Obj_tu7_02 *);

extern fn_tu7_02 dat_0c24b21c[];
extern void func_0c02a39a(struct Obj_tu7_02 *, int);
extern void func_0c02a684(struct Obj_tu7_02 *, int, int, int);
extern void func_0c044cbc(struct Obj_tu7_02 *);
extern void func_0c1048d6(struct Obj_tu7_02 *);
extern void func_0c1028d4(struct Obj_tu7_02 *);
extern void func_0c10296c(struct Obj_tu7_02 *);
extern void func_0c102a26(struct Obj_tu7_02 *);
extern void func_0c102abe(struct Obj_tu7_02 *);

void func_0c102780(struct Obj_tu7_02 *a, struct Ctl_tu7_02 *b)
{
    if (b->b16) {
        b->b16 = 0;
        if (a->b159 == 12 && a->b158 == 5) {
            b->b16 = 1;
            func_0c02a684(a, 0, a->b37 * 48 + a->b141 + 5, 1);
        } else {
            func_0c02a39a(a, 0);
        }
    }
}

void func_0c1027dc(struct Obj_tu7_02 *a)
{
    int s = a->b159;
    if (s == 7 || s == 9 || s == 11) {
        if (a->b1a3)
            func_0c02a684(a, 0, a->b37 * 48 + 34, 1);
    }
}

void func_0c102826(struct Obj_tu7_02 *a)
{
    dat_0c24b21c[a->b1ff](a);
}

void func_0c10283a(struct Obj_tu7_02 *a)
{
    struct Link_tu7_02 *s = &a->s2a4;
    func_0c044cbc(a);
    if (s->b9 != 0 && a->b1e8 == 2) {
        func_0c1048d6(a);
        return;
    }
    if (a->b1fe == 0) {
        if (a->b1f9 == 0)
            func_0c1028d4(a);
        else
            func_0c10296c(a);
        return;
    }
    if (a->b1f9 == 0)
        func_0c102a26(a);
    else
        func_0c102abe(a);
}
