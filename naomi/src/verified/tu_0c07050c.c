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
extern ActorHandler table_0c240e8c[];
extern int (*table_0c240e7c[])(struct Actor *);
extern void func_0c1910d0(struct Actor *, int);
extern int func_0c037d54(struct Actor *);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c1d4610(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c048ce6(struct Actor *);

void func_0c07050c(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        a->b6++;
        func_0c02a0c4(a, 20, 8);
        func_0c043324(a);
    }
}

/* func_0c07057a: no verified twin. Ghidra draft:
*/
void func_0c07057a(struct Actor *a)
{
    if (func_0c02a026(a) < 0) {
        func_0c02a39a(a, 0);
        func_0c0439c4(a);
        return;
    }
    else {
      if (a->b141) {
        a->b141 = 0;
        func_0c1910d0(a, 7);
      }
    }
}

/* func_0c0705ba: no verified twin. Ghidra draft:
*/
int func_0c0705ba(struct Actor *a)
{
    return table_0c240e7c[a->b1f9](a);
}

/* func_0c0705d2: no verified twin. Ghidra draft:
*/
int func_0c0705d2(struct Actor *a)
{
    int result;
    if ((a->b34 = (a->w1fa & 0xc00) >> 10) == 0)
        return 0;
    if (a->b1fe == 0 && (unsigned char)a->b1a3 == 1) {
        if ((result = func_0c037d54(a)) != 0) {
            a->b1f7 = 2;
            return result;
        }
    } else if ((unsigned char)a->b1fe == 1 && (unsigned char)a->b1a3 == 1) {
        if ((result = func_0c037d54(a)) != 0) {
            a->b1f7 = 5;
            return result;
        }
    }
    return 0;
}

int func_0c07067c(struct Actor *a)
{
    int result;
    if ((a->b34 = (a->w1fa & 0xc00) >> 10) == 0)
        return 0;
    if ((unsigned char)a->b1fe == 1 && (unsigned char)a->b1a3 == 1) {
        if ((result = func_0c037d54(a)) != 0) {
            a->b1f7 = 1;
            return result;
        }
    }
    return 0;
}
int func_0c0706d2(struct Actor *a)
{
    int result;
    if ((a->b34 = (a->w1fa & 0xc00) >> 10) == 0)
        return 0;
    if (a->b1fe == 0 && (unsigned char)a->b1a3 == 1 && a->f56 > a->f41c + 137.142853f) {
        if ((result = func_0c037d54(a)) != 0) {
            a->b1f7 = 132;
            return result;
        }
    }
    return 0;
}

void func_0c070738(struct Actor *a)
{
    table_0c240e8c[a->b1f7 & 63](a);
}
