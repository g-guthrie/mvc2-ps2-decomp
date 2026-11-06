/* func_0c1407b8, func_0c140888: grab/hold follow-up steps (draft by round-7 worker r7_0c13e1bc, b19f test spelled as a byte read). */
#include "objects.h"
#define V(p) (*(struct LinkedActorVec3 *)&(p)->f52)
#define PP(a) (*(struct Actor **)&(*(struct Actor **)&(a)->pad7e[0])->pad7e[0])
extern signed char func_0c02a026(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c194a10(struct Actor *, int);
extern void func_0c0426c2(struct Actor *, int);
extern int func_0c042780(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c04392e(struct Actor *);

void func_0c1407b8(struct Actor *a, struct Actor *b)
{
    char *p = (char *)&b->sub2a4;
    struct Actor *q = a->p20;
    q->b1eb = 2;
    V(a) = V(q);
    if (PP(a) != a) {
        a->b5++;
        a->s28 = 0;
    } else {
        int c = a->b35;
        if (q->b19f) {
            a->b5 = 3;
            a->s28 = 0;
            *(char *)((int)c + (int)(p + 1)) &= -3;
            *(char *)((int)c + (int)(p + 1)) |= -128;
            if (q->w420 == 0) { goto s7; s7: q->b1f6 = 7; } else q->b1f6 = 0;
            func_0c0344a0(a, 35);
            func_0c194a10(a, a->b34);
            return;
        }
        func_0c02a026(a);
        if (a->b141 == 0) return;
        a->b5++;
        q->b12c = 0;
    }
    func_0c0426c2(q, 8);
}

void func_0c140888(struct Actor *a, struct Actor *b)
{
    char *p = (char *)&b->sub2a4;
    struct Actor *q;
    int c;
    if (PP(a) != a) {
        a->b4 = 2;
        a->s28 = 0;
        goto end;
    }
    func_0c02a026(a);
    q = a->p20;
    c = a->b35;
    q->b1eb = 2;
    V(a) = V(q);
    if (((char *)q)[0x19f]) {
        if (q->b5 != 3) {
            a->b142 = 1;
            func_0c02a026(a);
        } else {
            a->s28 = 0;
            *(char *)((int)c + (int)(p + 1)) |= -128;
        }
    }
    q->b12c = 0;
    if (func_0c042780(q)) {
        a->b142 = 1;
        a->s28 -= (unsigned char)a->b1a3 * 4 + 3;
    }
    if (--a->s28 >= 0) return;
    a->b5++;
    *(char *)((int)c + (int)(p + 1)) &= -3;
    if (q->w420 == 0) { goto t7; t7: q->b1f6 = 7; goto end; }
    q->b1f6 = 0;
    if (!(*(unsigned char *)((int)(p + 1) + c) & 0x80)) {
        if (a->b1a3) q->b1ef = 8;
        if (q->b1f9 != 2) func_0c0437b8(q); else func_0c04392e(q);
    }
end:
    func_0c0344a0(a, 35);
    func_0c194a10(a, a->b34);
}
