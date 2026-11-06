/* Translation unit at 0x0c0a0da0, four functions. The assigned extent
 * (0x0c0a0da0 size 630) ends at 0x0c0a1016, inside the trailing literal pool;
 * the real extent runs to the next function's prologue at 0x0c0a102c (size
 * 652), so this file is registered with that extent instead.
 * All four functions and both interior pools match. b419 is signed (the tail
 * call adds 2 with no extu.b) and the table index casts it back to unsigned.
 * The row pointer is assigned from the base, then += index, so SHC keeps the
 * base in r4. */
struct Vec4_ub1_02 { float x, y, z, w; };
struct Table_ub1_02 { unsigned char pad[0x7c]; short w7c[64]; };

struct Obj_ub1_02 {
    unsigned char pad0[2];
    unsigned char b2;
    unsigned char pad1[3];
    unsigned char b6;
    unsigned char pad2[28 - 7];
    short s28;
    unsigned char pad3[35 - 30];
    unsigned char b35;
    unsigned char pad4[52 - 36];
    float f52, f56;
    unsigned char pad5[92 - 60];
    float f92, f96, f100, f104, f108;
    unsigned char pad6[0x141 - 112];
    unsigned char b321;
    unsigned char pad7[0x19e - 0x142];
    unsigned char b414;
    unsigned char pad8[0x1a1 - 0x19f];
    unsigned char b417;
    unsigned char pad9[0x1a3 - 0x1a2];
    char b419;
    unsigned char pad10[0x1ac - 0x1a4];
    short s428;
    unsigned char pad11[0x1c4 - 0x1ae];
    int i452;
    unsigned char pad12[0x1d2 - 0x1c8];
    char b466;
    unsigned char pad13[0x1f9 - 0x1d3];
    unsigned char b505;
    unsigned char pad14[0x41c - 0x1fa];
    float f1052;
};

extern struct Table_ub1_02 *dat_0c2f83f8;
extern struct Vec4_ub1_02 dat_0c2437c4[];
extern void func_0c048bb0(struct Obj_ub1_02 *, int);
extern void func_0c0442fa(struct Obj_ub1_02 *);
extern void func_0c0432ca(struct Obj_ub1_02 *);
extern void func_0c02a0c4(struct Obj_ub1_02 *, int, int);
extern void func_0c0451f2(struct Obj_ub1_02 *);
extern void func_0c02a026(struct Obj_ub1_02 *);
extern void func_0c14a9d0(struct Obj_ub1_02 *, int);
extern void func_0c043324(struct Obj_ub1_02 *);

void func_0c0a0da0(struct Obj_ub1_02 *a)
{
    a->b6++;
    a->b417 = a->b419 + 52;
    a->s428 = 0;
    a->b414 = 0;
    a->i452 = 0;
    dat_0c2f83f8->w7c[a->b2]++;
    func_0c048bb0(a, 5);
    func_0c0442fa(a);
    {
        struct Vec4_ub1_02 *t = dat_0c2437c4;

        t += (unsigned char)a->b419;
        a->f92 = a->b466 ? -t->x : t->x;
        a->f104 = a->b466 ? -t->y : t->y;
        a->f96 = t->z;
        a->f108 = t->w;
    }
    if (a->b505 != 2) {
        a->b505 = 0;
        func_0c0432ca(a);
    }
    a->b35 = 0;
    func_0c02a0c4(a, 21, a->b419 + 2);
}

void func_0c0a0e5c(struct Obj_ub1_02 *a)
{
    if (a->b321) {
        a->b6++;
        a->s28 = 1;
        func_0c0451f2(a);
        a->f92 = 0;
        a->f104 = 0;
    } else {
        a->f52 += a->f92;
        a->f92 += a->f104;
    }
    func_0c02a026(a);
}

void func_0c0a0eac(struct Obj_ub1_02 *a)
{
    if (a->f96 < 0) {
        a->b6++;
    } else {
        if (--a->s28 == 0) {
            if (a->b414)
                a->b35++;
            if (a->b35 < 3) {
                if (a->b35 == 2)
                    a->b417 = a->b419 + 82;
                else
                    a->b417 = a->b419 + 52;
                a->s428 = 0;
                a->b414 = 0;
                a->i452 = 0;
                dat_0c2f83f8->w7c[a->b2]++;
            }
            func_0c14a9d0(a, 1);
            func_0c14a9d0(a, 2);
            a->s28 = 6;
        }
        a->f56 += a->f96;
        a->f96 += a->f108;
        if (a->b321)
            return;
    }
    func_0c02a026(a);
}

void func_0c0a0f9a(struct Obj_ub1_02 *a)
{
    if (a->f56 < a->f1052) {
        a->b6++;
        a->b505 = 0;
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        a->f56 = a->f1052;
        func_0c043324(a);
    } else {
        a->f56 += a->f96;
        a->f96 += a->f108;
        if (a->b321)
            return;
    }
    func_0c02a026(a);
}
