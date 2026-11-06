/* Five actor callbacks and a shared pool. func_0c118b08 ends by calling the
 * adjacent func_0c118b5a; SHC emits the retail fallthrough after its epilogue. */
#include "objects.h"
typedef void (*Handler_118ad4)(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *);
extern void func_0c0442fa(struct Actor *);
extern void func_0c02a39a(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
extern Handler_118ad4 table_0c24cb84[];
extern Handler_118ad4 table_0c24cb9c[];

void func_0c118b5a(struct Actor *a, struct Actor *b);

void func_0c118ad4(struct Actor *a)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c118af6(struct Actor *a)
{
    table_0c24cb84[a->b6](a);
}

void func_0c118b08(struct Actor *a, struct Actor *b)
{
    a->b6++;
    func_0c0442fa(a);
    func_0c02a39a(a, 0);
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    func_0c02a0c4(a, 20, 3);
    func_0c118b5a(a, b);
}

void func_0c118b5a(struct Actor *a, struct Actor *b)
{
    if (func_0c02a026(a) < 0)
        func_0c0437b8(a);
}

void func_0c118b7c(struct Actor *a)
{
    table_0c24cb9c[a->b6](a);
}
