/* Assignment gave 0x0c0e56e4 size 336 (end 0x0c0e5834), but both functions'
 * literal pool reaches float constants at 0x0c0e5844-0x0c0e584f and the
 * runtime address at 0x0c0e5850-0x0c0e5857, all read by func_0c0e574c; the
 * pool only flushes at the next code range, 0x0c0e5858. Extended the unit to
 * end there: size 372 (0x0c0e5858 - 0x0c0e56e4).
 *
 * Both func_0c0e56e4 (104/104) and func_0c0e574c (222/222) match retail
 * exactly, and every reviewed pool byte matches (16/16). diff_unit still
 * reports DIFFERS because config/mapping.json has an unreviewed 2-byte gap at
 * 0x0c0e583a-0x0c0e583c ("unreferenced adjacent bytes omitted" per its own
 * evidence note, almost certainly alignment padding before the pointer pool
 * at 0x0c0e583c) which stops describe()'s section walk at 342 bytes even
 * though this unit's real, correctly-matching extent is 372 bytes ending at
 * 0x0c0e5858, the next code range. Registering as a candidate since I cannot
 * map that gap myself (hard rule: only diff_unit.py touches config/*.json). */

struct Obj_ub8_02 {
    unsigned char pad0[2];
    unsigned char b2;
    unsigned char pad1[3];
    unsigned char b6;
    unsigned char pad2[0x34 - 7];
    float f52, f56, f60;
    unsigned char pad3[0x5c - 0x40];
    float f92, f96, f100, f104, f108, f112, f116;
    unsigned char pad4[0x141 - 0x78];
    unsigned char b141;
    unsigned char pad5[0x14b - 0x142];
    unsigned char b14b;
    unsigned char pad6[0x19e - 0x14c];
    unsigned char b19e;
    unsigned char pad7[0x1a1 - 0x19f];
    unsigned char b1a1;
    unsigned char pad8[0x1ac - 0x1a2];
    unsigned short w1ac;
    unsigned char pad9[0x1c4 - 0x1ae];
    int i1c4;
    unsigned char pad10[0x1d2 - 0x1c8];
    unsigned char b1d2;
    unsigned char pad11[0x1f9 - 0x1d3];
    unsigned char b1f9;
    unsigned char pad12[0x328 - 0x1fa];
    unsigned char b328;
    unsigned char pad13[0x3f8 - 0x329];
    unsigned char b3f8;
    unsigned char pad14[0x41c - 0x3f9];
    float f41c;
};

struct Table_ub8_02 { unsigned char pad[124]; short arr[1]; };

extern struct Table_ub8_02 *dat_0c2f83f8;
extern char func_0c02a026(struct Obj_ub8_02 *);
extern void func_0c02a0c4(struct Obj_ub8_02 *, int, int);

void func_0c0e56e4(struct Obj_ub8_02 *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    if (a->b141) {
        a->b6 = a->b6 + 1;
        a->b1f9 = 2;
        a->f56 += 34.2857132f;
        a->f92 = a->b1d2 ? 20.0f : -20.0f;
        a->f104 = 0.0f;
        a->f96 = 0.0f;
        a->f108 = -0.13392857f;
    }
}

void func_0c0e574c(struct Obj_ub8_02 *a)
{
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    if (a->b14b) {
        a->b14b = 0;
        a->b1a1 = 64;
        a->w1ac = 0;
        a->b19e = 0;
        a->i1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
    }
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (a->f56 <= a->f41c) {
        a->b6 = a->b6 + 1;
        a->f56 = a->f41c;
        a->b1f9 = 0;
        a->f96 = 0.0f;
        a->f108 = 0.0f;
        a->b1a1 = 65;
        a->w1ac = 0;
        a->b19e = 0;
        a->i1c4 = 0;
        dat_0c2f83f8->arr[a->b2]++;
        func_0c02a0c4(a, 21, 16);
    }
}
