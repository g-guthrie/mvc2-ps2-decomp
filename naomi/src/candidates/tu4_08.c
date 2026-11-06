/* Three functions sharing the literal pool at 0x0c197600. 320/344 bytes match:
 * func_0c1974d4 and func_0c197538 are exact. func_0c19754c differs at
 * 0x0c19759c..0x0c1975b2: retail loads b->b36 into r2 and discards it before
 * storing a->b36 = 12 (no tst, then `mov r3,r0; nop` feeding the 12-byte copy
 * size), and at 0x0c1975d0..0x0c1975de it indexes the float table with r3 and
 * tests w130 in r2 where we get r1 and r3. Struct copies go through the
 * runtime: __slow_mvn = 0x0c1fb838 (0xc0 bytes), __quick_mvn = 0x0c1fb7a0
 * (12 bytes), passed with --import. */
struct Blk_tu4_08_12 { float a, b, c; };
struct Blk_tu4_08_c0 { unsigned char bytes[0xc0]; };

struct Obj_tu4_08 {
    unsigned char pad0[1];
    unsigned char b1;
    unsigned char b2;
    unsigned char pad1[1];
    unsigned char b4;
    unsigned char b5;
    unsigned char pad2[10];
    void (*p16)(struct Obj_tu4_08 *);
    unsigned char pad3[4];
    struct Obj_tu4_08 *p24;
    short s28;
    unsigned char pad4[2];
    unsigned char b32;
    unsigned char b33;
    unsigned char pad5[2];
    unsigned char b36;
    unsigned char pad6[1];
    unsigned short w38;
    unsigned char pad7[8];
    unsigned char b48;
    unsigned char pad8[3];
    struct Blk_tu4_08_12 s52;
    unsigned char pad9[16];
    float f80, f84;
    unsigned char pad10[4];
    float f92, f96;
    unsigned char pad11[4];
    float f104, f108;
    unsigned char pad12[0xdc - 112];
    unsigned char b12c_pad[0x12c - 0xdc];
    unsigned char b12c;
    unsigned char pad14[3];
    short w130;
    unsigned char pad15[0x1a3 - 0x132];
    unsigned char b1a3;
    unsigned char b1a4;
};

extern short dat_0c2f6830;
extern struct Obj_tu4_08 *func_0c0374da(int a, int b, int c);
extern void (*const dat_0c2580d8[])(struct Obj_tu4_08 *, struct Obj_tu4_08 *);
extern const float dat_0c2580d0[];
extern void func_0c02a0c4(struct Obj_tu4_08 *p, int a, int b);

void func_0c197538(struct Obj_tu4_08 *a);

int func_0c1974d4(struct Obj_tu4_08 *a)
{
    int n = a->b1a3 * 4 + 1;
    int i;
    struct Obj_tu4_08 *o;
    if (dat_0c2f6830 <= n)
        return 0;
    for (i = 0; i < n; i++) {
        if (o = func_0c0374da(0, 3, 1)) {
            o->w38 = 0x0e01;
            o->b32 = i;
            o->b33 = n;
            o->p16 = func_0c197538;
            o->p24 = a;
        }
    }
    return 1;
}

void func_0c197538(struct Obj_tu4_08 *a)
{
    dat_0c2580d8[a->b4](a, a->p24);
}

void func_0c19754c(struct Obj_tu4_08 *a, struct Obj_tu4_08 *b)
{
    float v;
    a->b4++;
    *(struct Blk_tu4_08_c0 *)a->b12c_pad = *(struct Blk_tu4_08_c0 *)b->b12c_pad;
    a->b12c = 1;
    a->b2 = b->b2;
    a->b1 = b->b1;
    a->f80 = b->f80;
    a->f84 = b->f84;
    a->b1a3 = b->b1a3;
    a->b1a4 = b->b1a4;
    a->b48 = b->b48;
    *(struct Blk_tu4_08_12 *)&a->f80 = *(struct Blk_tu4_08_12 *)&b->f80;
    if (b->b36)
        a->b36 = 12;
    else
        a->b36 = 12;
    a->s52 = b->s52;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f108 = 0.0f;
    a->f104 = 0.0f;
    if (a->b32 == 0) {
        v = dat_0c2580d0[b->b1a3];
        if (a->w130)
            v = -v;
        a->f92 = v;
        a->s28 = 8;
        a->f104 = v;
    } else {
        a->b5 = 3;
    }
    func_0c02a0c4(a, 23, 19);
}
