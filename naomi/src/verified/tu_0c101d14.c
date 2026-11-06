/* Exact 356-byte initializer, position callback and guarded input test. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0437b8(struct Actor *);
extern int func_0c02a39a(struct Actor *, int);
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c043014(struct Actor *, struct LinkedActorVec3 *);
extern int func_0c037d54(struct Actor *);

void func_0c101d14(struct Actor *a)
{
    a->b6++;
    a->f92 = 0.0f;
    a->f96 = 0.0f;
    a->f104 = 0.0f;
    a->f108 = 0.0f;
    a->b1f9 = 0;
    a->f56 = a->f41c;
    (void)func_0c02a39a(a, 0);
    func_0c0442fa(a);
    func_0c0432ca(a);
    a->b1a1 = 63;
    a->w1ac = 0;
    a->b19e = 0;
    *(unsigned int *)&a->p1c4 = 0;
    dat_0c2f83f8->arr[a->b2]++;
    func_0c02a0c4(a, 21, 22);
}

void func_0c101d8a(struct Actor *a)
{
    struct LinkedActorVec3 position;
    if (func_0c02a026(a) < 0) {
        func_0c0437b8(a);
        return;
    }
    if (a->b141) {
        a->b141 = 0;
        position.x = 0.0f;
        position.y = 171.42856f;
        func_0c043014(a, &position);
    }
}

int func_0c101dd2(struct Actor *a)
{
    int result;
    if (!*(unsigned char *)&a->sub2a4.s14 && a->b1f9 != 1 &&
        (a->w1fa & 0x0c00) && a->b1a3) {
        if ((result = func_0c037d54(a)) != 0) {
            if (!a->b1fe)
                a->b1f7 = 0;
            else
                a->b1f7 = 1;
            *(unsigned short *)&a->sub2a4 = a->w1fa;
        }
        return result;
    }
    return 0;
}
