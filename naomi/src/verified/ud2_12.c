/* Verified: repeated-case switch handlers; `goto call; call:` before the tail call selects retail r2.
 * Offsets and return type are checked by config/type_contracts.json. */

struct S_ud2_12 {
    unsigned char pad0[2];
    unsigned char b2;
    unsigned char pad1[2];
    unsigned char b5, b6, b7;
    unsigned char pad2[0x34 - 8];
    float f34;
    float f56;
    unsigned char pad4[0x5c - 0x3c];
    float f92, f96;
    unsigned char pad5[0x68 - 0x64];
    float f104, f108;
    unsigned char pad6[0x141 - 0x70];
    unsigned char b141;
    unsigned char pad6b[0x19e - 0x142];
    unsigned char b19e;
    unsigned char pad6c[0x1a1 - 0x19f];
    unsigned char b1a1;
    unsigned char pad6d[0x1a3 - 0x1a2];
    unsigned char b1a3;
    unsigned char pad6e[0x1ac - 0x1a4];
    short w1ac;
    unsigned char pad6f[0x1c4 - 0x1ae];
    unsigned int u1c4;
    unsigned char pad6g[0x1d2 - 0x1c8];
    unsigned char b1d2;
    unsigned char pad7[0x1e9 - 0x1d3];
    unsigned char b1e9;
    unsigned char pad7b[0x1f9 - 0x1ea];
    unsigned char b1f9;
    unsigned char pad9[0x4c9 - 0x1fa];
    unsigned char b4c9;
};

struct Table2f83f8_ud2_12 { unsigned char pad[124]; short counts[64]; };

extern signed char func_0c02a026(struct S_ud2_12 *);
extern void func_0c0437b8(struct S_ud2_12 *);
extern void (*dat_0c2487ec[])(struct S_ud2_12 *);
extern void func_0c02a39a(struct S_ud2_12 *, int);
extern struct Table2f83f8_ud2_12 *dat_0c2f83f8;
extern void func_0c02a0c4(struct S_ud2_12 *, int, int);
extern unsigned char func_0c044e52(struct S_ud2_12 *);
extern void func_0c043324(struct S_ud2_12 *);
extern void func_0c0439c4(struct S_ud2_12 *);
extern void func_0c045248(struct S_ud2_12 *, int);

void func_0c0d6964(struct S_ud2_12 *a)
{
    if (func_0c02a026(a) >= 0)
        return;
    a->f92 = 0;
    a->f96 = 0;
    a->f104 = 0;
    a->f108 = 0;
    func_0c0437b8(a);
}

void func_0c0d6996(struct S_ud2_12 *a)
{
    dat_0c2487ec[a->b6](a);
}

void func_0c0d69a8(struct S_ud2_12 *a)
{
    func_0c02a39a(a, 0);
    a->b6 = a->b6 + 1;
    a->b1f9 = 2;
    a->f92 = 30.0f;
    if (a->b1d2 == 0)
        a->f92 = -a->f92;
    a->f104 = 0.0f;
    a->f96 = 4.285714149475098f;
    a->f108 = -0.80357140303f;
    a->b1a1 = 70;
    a->w1ac = 0;
    a->b19e = 0;
    a->u1c4 = 0;
    dat_0c2f83f8->counts[a->b2]++;
    func_0c02a0c4(a, 20, 0);
}

void func_0c0d6a22(struct S_ud2_12 *a)
{
    func_0c02a026(a);
    a->f34 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a) != 0) {
        a->b6 = a->b6 + 1;
        func_0c043324(a);
        func_0c02a0c4(a, 20, 1);
    }
}

void func_0c0d6a90(struct S_ud2_12 *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c02a39a(a, 0);
        func_0c0439c4(a);
    } else if (a->b141)
        a->b141 = 0;
}

void func_0c0d6afa(struct S_ud2_12 *a)
{
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    switch((signed char)a->b4c9){case 0:a->b1e9=8;break;case 1:a->b1e9=8;break;case 2:a->b1e9=8;break;}
    func_0c045248(a, 29);
}

void func_0c0d6b1e(struct S_ud2_12 *a)
{
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    switch((signed char)a->b4c9){case 0:a->b1e9=8;break;case 1:a->b1e9=8;break;case 2:a->b1e9=8;break;}
    func_0c045248(a, 29);
}

void func_0c0d6b42(struct S_ud2_12 *a)
{
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    switch ((signed char)a->b4c9) {
    case 0: a->b1e9 = 0; break;
    case 1: a->b1e9 = 2; break;
    default: goto finished;
    case 2: a->b1e9 = 3;
    }
    a->b1a3 = 1;
finished: goto call; call:;
    func_0c045248(a, 21);
}

void func_0c0d6b82(struct S_ud2_12 *a)
{
    a->b5 = 0;
    a->b7 = 0;
    a->b6 = 0;
    switch ((signed char)a->b4c9) {
    case 0: a->b1e9 = 0; break;
    case 1: a->b1e9 = 3; break;
    default: goto finished;
    case 2: a->b1e9 = 2;
    }
    a->b1a3 = 1;
finished: goto call; call:;
    func_0c045248(a, 21);
}
