/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0438de(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c240960[])(struct Actor *);
extern int func_0c02a39a(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c043014(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c0344a0(struct Actor *, int);
extern void (*table_0c240968[])(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c043324(struct Actor *);
extern void func_0c025900(struct Actor *, char, char);

void func_0c084dc8(struct Actor *a)
{
    (void)func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a) != 0) {
        a->b7++;
        func_0c043324(a);
        func_0c02a0c4(a, 22, 8);
    }
}

/* func_0c084e36: no verified twin. Ghidra draft:
*/
void func_0c084e36(struct Actor *a)
{
    struct Actor *other;
    if (a->s28-- == 0) {
        a->b7++;
        a->b141 = 0;
        func_0c025900(a, 0, 0);
        other = a->p1c8;
        other->p1b4 = a;
        other->b1a1 = 36;
        other->b1f9 = 2;
        other->b1f6 = 1;
        other->b1d2 = a->b1d2;
        a->b1d2 = a->b1d2 ^ 1;
        a->f92 = a->w130 ? -13.33333302f : 13.33333302f;
        a->f104 = 0.0f;
        a->f96 = 17.142857f;
        a->f108 = -1.07142854f;
        func_0c02a0c4(a, 22, 7);
    }
}
