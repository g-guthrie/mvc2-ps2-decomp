/* Movement step, landing check, factory dispatch, spawn checks and the b1f7
 * dispatcher for one move family (absorbs the former tu_0c0e7574). */
#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
typedef struct Actor *(*ActorFactory)(struct Actor *);
extern ActorFactory table_0c249710[];
extern ActorHandler table_0c249720[];
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c0439c4(struct Actor *), func_0c043324(struct Actor *), func_0c02a0c4(struct Actor *, int, int);
extern struct Actor *func_0c037d54(struct Actor *);

void func_0c0e7410(struct Actor *a)
{
    func_0c02a026(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    if (func_0c044e52(a)) {
        a->b6++;
        func_0c043324(a);
        func_0c02a0c4(a, 20, 1);
    }
}

void func_0c0e747e(struct Actor*a){if(func_0c02a026(a)<0)func_0c0439c4(a);else if(a->b141)a->b141=0;}

struct Actor *func_0c0e74aa(struct Actor *a)
{
    return table_0c249710[a->b1f9](a);
}

struct Actor *func_0c0e74c2(struct Actor *a)
{
    struct Actor *t;
    if (!(a->b34 = (a->w1fa & 0xc00) >> 10))
        return 0;
    if (!a->b1fe && (unsigned char)a->b1a3 == 1) {
        a->b34 ^= 3;
        if (!(t = func_0c037d54(a)))
            return 0;
        a->b1f7 = 5;
        return t;
    } else if ((unsigned char)a->b1fe == 1 && (unsigned char)a->b1a3 == 1) {
        if (!(t = func_0c037d54(a)))
            return 0;
        a->b1f7 = 0;
        return t;
    }
    return 0;
}

int func_0c0e7570(void) { return 0; }

struct Actor *func_0c0e7574(struct Actor *a)
{
    struct Actor *t;
    if (!(a->b34 = (a->w1fa & 0xc00) >> 10))
        return 0;
    if (!a->b1fe && (unsigned char)a->b1a3 == 1 && a->f56 > 137.142853f) {
        a->b34 ^= 3;
        if (!(t = func_0c037d54(a)))
            return 0;
        a->b1f7 = 2;
        return t;
    } else if ((unsigned char)a->b1fe == 1 && (unsigned char)a->b1a3 == 1 && a->f56 > 137.142853f) {
        if (!(t = func_0c037d54(a)))
            return 0;
        a->b1f7 = 1;
        return t;
    }
    return 0;
}

void func_0c0e760e(struct Actor *a)
{
    table_0c249720[a->b1f7&63](a);
}
