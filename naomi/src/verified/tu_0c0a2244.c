/* Hop/fall/land state handlers, a landing check, spawn checks and dispatchers for one move family. */
#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
typedef struct Actor *(*ActorFactory)(struct Actor *);
extern ActorFactory table_0c243ab8[];
extern ActorHandler table_0c243ac8[];
extern char func_0c02a026(struct Actor *);
extern void func_0c14a9d0(struct Actor *, int), func_0c043324(struct Actor *), func_0c0437b8(struct Actor *);
extern struct Actor *func_0c037d54(struct Actor *);
void func_0c0a2244(struct Actor *a)
{
    if (a->b141) {
        a->b6++;
        a->s28 = 1;
        a->f92 = 0;
        a->f104 = 0;
    } else {
        a->b1f9 = 2;
        a->f52 += a->f92;
        a->f92 += a->f104;
    }
    func_0c02a026(a);
}

void func_0c0a228a(struct Actor *a)
{
    if (a->f96 < 0.0f) {
        a->b6++;
    } else {
        if (--a->s28 == 0) {
            func_0c14a9d0(a, 1);
            func_0c14a9d0(a, 2);
            a->s28 = 6;
        }
        a->f56 += a->f96;
        a->f96 += a->f108;
        if (a->b141)
            return;
    }
    func_0c02a026(a);
}

void func_0c0a22f6(struct Actor *a)
{
    if (a->f56 < a->f41c) {
        a->b6++;
        a->b1f9 = 0;
        a->f92 = 0;
        a->f96 = 0;
        a->f104 = 0;
        a->f108 = 0;
        a->f56 = a->f41c;
        func_0c043324(a);
    } else {
        a->f56 += a->f96;
        a->f96 += a->f108;
        if (a->b141)
            return;
    }
    func_0c02a026(a);
}

void func_0c0a236a(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

struct Actor *func_0c0a23a4(struct Actor *a)
{
    return table_0c243ab8[a->b1f9](a);
}

struct Actor *func_0c0a23bc(struct Actor *a)
{
 struct Actor *result;
 if ((a->b34 = (a->w1fa & 0x0c00) >> 10) && !a->b1fe && (unsigned char)a->b1a3 == 1) {
  if ((result = func_0c037d54(a)) != 0) { a->b1f7=0; return result; }
 }
 return 0;
}

int func_0c0a2410(void) { return 0; }

struct Actor *func_0c0a2414(struct Actor *a)
{
    struct Actor *result;
    if ((a->b34 = (a->w1fa & 0xc00) >> 10) == 0)
        return 0;
    if ((unsigned char)a->b1fe == 1 && (unsigned char)a->b1a3 == 1) {
        if ((result = func_0c037d54(a)) != 0) {
            a->b1f7 = 2;
            return result;
        }
    }
    return 0;
}

void func_0c0a246a(struct Actor *a)
{
    table_0c243ac8[a->b1f7&63](a);
}
