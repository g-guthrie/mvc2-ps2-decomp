/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c0439c4(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern struct Actor *func_0c037d54(struct Actor *);

void func_0c1128d4(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        a->b6++;
        func_0c02a0c4(a, 20, 1);
        func_0c043324(a);
    }
}

void func_0c112942(struct Actor *p)
{
    if (func_0c02a026(p) < 0) {
        func_0c02a39a(p, 0);
        func_0c0439c4(p);
    }
}

struct Actor *func_0c11296a(struct Actor *a)
{
    register struct Actor *q;
    register struct ActorSub2a4 *sub;
    sub = &a->sub2a4;
    if ((a->b34 = (a->w1fa & 0x0c00) >> 10) != 0 &&
        a->b1fe == 0 && (unsigned char)a->b1a3 == 1) {
        if (sub->b16 == 0) {
            if ((q = func_0c037d54(a)) != 0) {
                a->b1f7 = 0;
                return q;
            }
        }
    }
    return 0;
}
