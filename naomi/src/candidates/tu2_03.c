/* Two spawners sharing the pool at 0x0c1d4900. Both functions are
 * instruction-identical to retail; only the six mov.l pool displacements
 * differ, by one word: the retail translation unit starts at func_0c1d4814
 * (0x0c1d4814, 26 bytes, which bsr's these two and func_0c1d4920/498c after
 * the pool), so its code before the pool is 236 bytes and the pool needs no
 * alignment word, whereas this file starts at 0x0c1d482e (2 mod 4) and the
 * compiler pads the pool with .RES.W. The whole retail unit runs on through
 * pools at 0x0c1d4a74 and 0x0c1d4b44 and is outside this assignment. */
struct V3 { float x, y, z; };

struct Obj_tu2_03 {
    unsigned char pad0[0x10];
    void (*p10)(struct Obj_tu2_03 *);
    unsigned char pad1[28 - 0x14];
    short s28;
    short s30;
    unsigned char pad2[52 - 32];
    struct V3 v52;
    unsigned char pad3[80 - 64];
    float f80, f84, f88;
    unsigned char pad4[116 - 92];
    float f116;
    unsigned char pad5[0x84 - 120];
    int l84;
    unsigned char pad6[0xcc - 0x88];
    int lcc;
    unsigned char pad7[0x12c - 0xd0];
    unsigned char b12c;
};

struct Src_tu2_03 { unsigned char pad[0x2e8]; int l2e8; };

extern struct Obj_tu2_03 *func_0c0374da(int, int, int);
extern void func_0c1d49f8(struct Obj_tu2_03 *);
extern void func_0c1d4a2e(struct Obj_tu2_03 *);
extern struct Src_tu2_03 **dat_0c2d9650;

void func_0c1d482e(struct V3 *a)
{
    struct Obj_tu2_03 *r;

    if ((r = func_0c0374da(0, 7, 1)) != 0) {
        r->b12c = 1;
        r->p10 = func_0c1d49f8;
        r->l84 = (*dat_0c2d9650)->l2e8;
        r->v52 = *a;
        r->v52.y += 137.14286f;
        r->lcc = 49;
        r->s28 = 0;
        r->f116 = 1.0f;
        r->f80 = 1.0f;
        r->f84 = 1.0f;
        r->f88 = 1.0f;
    }
}

void func_0c1d489a(struct V3 *a)
{
    struct Obj_tu2_03 *r;

    if ((r = func_0c0374da(0, 7, 1)) != 0) {
        r->b12c = 1;
        r->p10 = func_0c1d4a2e;
        r->l84 = (*dat_0c2d9650)->l2e8;
        r->v52 = *a;
        r->v52.y += 137.14286f;
        r->lcc = 33;
        r->s28 = 0;
        r->s30 = 0;
        r->f116 = 1.0f;
    }
}
