/* func_0c0b687c matches (its remaining diffs are only pool addresses shifted
 * by func_0c0b68d8's size). func_0c0b68d8 matches through 0x0c0b68f4 (the
 * a->b12d/w12e init and the a->b281==0 dispatch), then diverges: from
 * 0x0c0b68f6 retail keeps a->b1a0 in r3 through the OR-chain and the
 * decrement block, but this source gets r1 there. The condition and
 * statement shapes were checked against the disassembly instruction for
 * instruction; only the scratch-register choice differs, which MATCHING.md
 * attributes to rotation carried from the statement before it. */

struct GlobalRec_ud2_02 { unsigned char b0; unsigned char pad0[0x3e - 1]; signed char b62; };

struct S_ud2_02 {
    unsigned char pad0[2];
    unsigned char b2;
    unsigned char pad1[2];
    unsigned char b5;
    unsigned char pad2[0x34 - 6];
    float f34;
    unsigned char pad3[0x12d - 0x38];
    signed char b12d;
    short w12e;
    short w130;
    unsigned char pad6[0x19f - 0x132];
    unsigned char b19f;
    unsigned char b1a0;
    unsigned char pad7[0x1a4 - 0x1a1];
    unsigned char b1a4;
    unsigned char pad8[0x1d0 - 0x1a5];
    unsigned char b1d0;
    unsigned char pad9[0x1e9 - 0x1d1];
    unsigned char b1e9;
    unsigned char pad10[0x1f5 - 0x1ea];
    unsigned char b1f5;
    unsigned char pad11[0x280 - 0x1f6];
    unsigned char b280;
    unsigned char b281;
    unsigned char pad12[0x283 - 0x282];
    signed char b283;
    unsigned char pad13[0x420 - 0x284];
    short w420;
};

extern struct GlobalRec_ud2_02 *dat_0c2f83f8;
extern signed char dat_0c22a81c[];
extern void func_0c0453c4(struct S_ud2_02 *, int);
extern void func_0c0b68d8(struct S_ud2_02 *);

void func_0c0b687c(struct S_ud2_02 *a)
{
    func_0c0b68d8(a);
    if (dat_0c2f83f8->b0 >= 5 && (dat_0c2f83f8->b62 < 0 || dat_0c2f83f8->b62 != a->b2) && a->b5 == 0 && a->b1d0 == 0) {
        func_0c0453c4(a, 21);
        a->b1e9 = 4;
    }
    if (a->w420 == 0)
        a->b1f5 = 1;
}

void func_0c0b68d8(struct S_ud2_02 *a)
{
    a->b12d = -1;
    a->w12e = dat_0c22a81c[a->b1a4];
    if (a->b281 == 0) {
        if (a->b1a0 == 0 || a->b5 != 0 || a->b19f == 0) {
            if (a->b283 == 0)
                return;
            if (a->b1a0 != 0)
                return;
            if (--a->b283 != 0)
                return;
            a->b280 = 0;
            return;
        }
        a->b281 = a->b281 + 1;
    }
    if (a->b1a0 != 0) {
        short s = (a->b1a0 & 1) * -8 + 4;
        if (a->w130 != 0)
            s = -s;
        a->f34 += 1.666667f * (float)s;
        if ((a->b1a0 & 1) == 0) {
            a->b12d = 1;
            a->w12e = dat_0c22a81c[a->b1a4] + 4;
        }
        return;
    }
    a->b281 = 0;
}
