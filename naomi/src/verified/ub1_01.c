/* Translation unit at 0x0c1823a4, four functions (func_0c1823a4, func_0c18246c,
 * func_0c18248c, func_0c18249a), all four matching retail byte for byte
 * (254/254 in the derived section). The assigned extent (0x0c1823a4 size 254)
 * ends at 0x0c1824a2, inside the literal pool that starts at 0x0c1824a0: the
 * pool actually runs to 0x0c1824c0 (a func_0c02a026 pointer, a func_0c02849a
 * pointer, three floats and two more function pointers), and the compiled
 * unit legitimately links at 284 bytes. config/mapping.json has no reviewed
 * range for 0x0c1824a2-0x0c1824a4 (a 2-byte alignment gap between the short
 * constant at 0x1824a0 and the 4-byte-aligned pool at 0x1824a4), so
 * tools/diff_unit.py's automatic section derivation stops at 0x1824a2 and
 * reports the rest of the (byte-identical) pool as unaccounted "extra" bytes.
 * The real extent is 0x0c1823a4 size 284; every instruction byte that the
 * tool does compare is exact. */

struct Obj_ub1_01 {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char pad1[2];
    unsigned char b7;
    unsigned char pad2[52 - 8];
    float f52, f56;
    unsigned char pad3[92 - 60];
    float f92, f96, f100, f104, f108;
    unsigned char pad4[204 - 112];
    int i204;
    unsigned char pad5[300 - 208];
    unsigned char b300;
};

extern char func_0c02a026(struct Obj_ub1_01 *);
extern int func_0c02849a(void);
extern void func_0c037d0c(struct Obj_ub1_01 *);
extern void func_0c037688(struct Obj_ub1_01 *);

void func_0c1823a4(struct Obj_ub1_01 *a)
{
    short d;

    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if ((float)a->i204 > a->f56) {
        if (a->b7++ == 0) {
            a->b300 &= 1;
            a->f56 = (float)a->i204;
            d = -(func_0c02849a() & 0x30) - 16;
            a->f96 = 3.2142857f;
            a->f108 = (float)d * 2.1428571f / 256.0f;
        } else {
            a->b4++;
        }
    }
    a->b300 ^= 1;
    if (!a->b7)
        func_0c037d0c(a);
}

void func_0c18246c(struct Obj_ub1_01 *a)
{
    if (func_0c02a026(a) < 0)
        a->b4++;
}

void func_0c18248c(struct Obj_ub1_01 *a)
{
    a->b4++;
    a->b300 = 0;
}

void func_0c18249a(struct Obj_ub1_01 *a)
{
    func_0c037688(a);
}
