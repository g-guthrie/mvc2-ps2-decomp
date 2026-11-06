/* State handlers 0x0c123358..0x0c123624 and their counter helpers. */
#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c048bb0(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c1bc740(struct Actor *, int, int);
extern void func_0c183408(struct Actor *, int, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c02a684(struct Actor *, int, int, int);
extern void (*table_0c24d660[])(struct Actor *);
void func_0c1233ec(struct Actor *a, struct ActorSubCounter10 *p);
void func_0c12357e(struct Actor *a, struct ActorSubCounter10 *p);
void func_0c1235da(struct Actor *a, struct ActorSubCounter10 *p);

void func_0c123358(struct Actor *a, struct ActorSubCounter10 *p)
{
    void *zero;
    a->b6++;
    func_0c048bb0(a, 5);
    func_0c0442fa(a);
    func_0c02a39a(a, 0);
    func_0c0432ca(a);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    zero = 0;
    a->b1f9 = 1;
    a->f56 = a->f41c;
    a->b1a1 = a->b1a3 * 2 + 51;
    a->w1ac = (int)zero;
    a->b19e = (int)zero;
    *(void **)&a->p1c4 = zero;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, a->b1a3 + 6);
    a->s28 = 16;
    func_0c1233ec(a, p);
}

void func_0c1233ec(struct Actor *a, struct ActorSubCounter10 *p)
{
    func_0c02a026(a);
    if (a->b141 & 1) {
        a->b141 &= 0xfe;
        func_0c1235da(a, p);
        func_0c1bc740(a, 2, 0);
    }
    if (a->b141 & 2) {
        a->b141 &= 0xfd;
        func_0c02a39a(a, 0);
        func_0c1bc740(a, 3, 0);
    }
    if (a->b141 & 16) {
        a->b141 &= 0xef;
        func_0c183408(a, 0, 0);
        func_0c183408(a, 0, 1);
        func_0c183408(a, 0, 2);
        func_0c183408(a, 0, 3);
        func_0c183408(a, 0, 4);
        func_0c183408(a, 0, 5);
        func_0c183408(a, 0, 6);
        func_0c183408(a, 0, 7);
        func_0c183408(a, 0, 8);
        func_0c183408(a, 0, 9);
    }
    if (a->b141 & 8) {
        a->b141 &= 0xf7;
        p->b9 = 0;
        p->b10 = 0;
        func_0c1bc740(a, 6, 0);
    }
    if (a->b141 & 4) {
        func_0c12357e(a, p);
        if (--a->s28 == 0) {
            a->b6++;
            func_0c02a39a(a, 0);
            func_0c02a0c4(a, 21, a->b1a3 + 8);
        }
    }
}

void func_0c12354a(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c12356c(struct Actor *a) { table_0c24d660[a->b6](a); }

void func_0c12357e(struct Actor *a, struct ActorSubCounter10 *p)
{
    if (!p->b8) {
        if (!p->b10--) {
            p->b10 = 4;
            func_0c02a684(a, 0, a->b37 * 6 + p->b9 + 36, 1);
            if (p->b9 < 4)
                p->b9++;
        }
    }
}

void func_0c1235da(struct Actor *a, struct ActorSubCounter10 *p)
{
    if (!p->b8)
        func_0c02a684(a, 0, a->b37 * 6 + 41, 1);
}
