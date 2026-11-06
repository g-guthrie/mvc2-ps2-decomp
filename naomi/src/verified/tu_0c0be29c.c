/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
struct Vec3_0c053b94 { float x, y, z; };
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c0442fa(struct Actor *);
extern void func_0c0432ca(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern char func_0c02a026(struct Actor *);
extern void func_0c0429a4(struct Actor *, struct Vec3_0c053b94 *, int);
extern struct Actor *func_0c15ba0c(struct Actor *, int, int);

void func_0c0be29c(struct Actor *a)
{
    struct Vec3_0c053b94 v;
    a->b3f8 = 2;
    a->b328 = 5;
    a->b3f1 = (a->b255 == 6) ? 2 : 0;
    func_0c02a026(a);
    if (a->b141) {
        a->b6++;
        a->b141 = 0;
        a->b3f0 = 0;
        a->b3f1 = 0;
        v.x = 68.33333f;
        v.y = 152.142853f;
        v.z = 0;
        func_0c0429a4(a, &v, 1);
    }
}

void func_0c0be30c(struct Actor *a, unsigned char *state)
{
    int command;
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    if (!(((char *)&a->w150)[1] & 1))
        return;
    a->b6++;
    state[1] = 0;
    func_0c15ba0c(a, 11, 0);
    if (!(a->p20 = func_0c15ba0c(a, 1, 0))) {
        command = a->b6 = 4;
    } else {
        state[2] = 8;
        command = 3;
    }
    func_0c02a0c4(a, 22, command);
}
