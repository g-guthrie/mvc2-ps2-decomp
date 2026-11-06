/* The first initializer differs in register allocation. The other five
 * complete functions and the whole literal pool match retail exactly. */
#include "objects.h"
extern unsigned char dat_0c2f837e;
extern unsigned int func_0c02849a(void);
extern int func_0c043628(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern struct Actor *func_0c1a5250(struct Actor *);
extern void (*table_0c244ac0[])(struct Actor *);
void func_0c0b11e8(struct Actor *a)
{
    int animation;
    int one = 1;
    int two = 2;
    a->b6++;
    if (a->b32 == 2) goto second;
    if (!dat_0c2f837e) a->s28 = one;
    else a->s28 = func_0c02849a() & 1;
    if (func_0c043628(a) >= two) a->s28 = one;
    switch (a->s28) {
    case 0:
        a->b6 = one;
        animation = 0;
        break;
    case 1:
second:
        a->b6 = two;
        animation = 1;
        break;
    case 2:
    default:
        return;
    }
    func_0c02a0c4(a, 19, animation);
}
void func_0c0b126c(struct Actor *a)
{
    a->b326 = 255;
    func_0c02a026(a);
    if (!a->b141) return;
    a->b141 = 0;
    func_0c1a5250(a);
}
void func_0c0b129a(struct Actor *a) { func_0c02a026(a); }
void func_0c0b12a0(struct Actor *a)
{
    if (!a->b6) { a->b6++; func_0c02a0c4(a, 19, 2); }
    else func_0c02a026(a);
}
void func_0c0b12ba(struct Actor *a)
{
    if (!a->b6) { a->b6++; func_0c02a0c4(a, 19, 2); }
    else func_0c02a026(a);
}
void func_0c0b12d4(struct Actor *a) { table_0c244ac0[a->b1e9](a); }
