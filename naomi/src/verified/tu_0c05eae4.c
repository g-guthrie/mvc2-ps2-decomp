/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
typedef void (*ActorHandler)(struct Actor *);
extern ActorHandler table_0c23fd50[];
extern int func_0c037d54(struct Actor *);
extern void func_0c025900(struct Actor *, int, int);
extern void func_0c1d4610(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c048ce6(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);

/* func_0c05eae4: no verified twin. Ghidra draft:
*/
int func_0c05eae4(struct Actor *a)
{
    int result;
    if ((a->b34 = (a->w1fa & 0x1c00) >> 10) == 0)
        return 0;
    if (a->b1fe == 0 && (unsigned char)a->b1a3 == 1 && a->f56 > 137.142853f) {
        if ((result = func_0c037d54(a)) != 0) {
            a->b1f7 = 2;
            return result;
        }
    } else if ((unsigned char)a->b1fe == 1 && (unsigned char)a->b1a3 == 1 && a->f56 > 137.142853f) {
        if ((result = func_0c037d54(a)) != 0) {
            a->b1f7 = 3;
            return result;
        }
    }
    return 0;
}
void func_0c05eb74(struct Actor *a)
{
    table_0c23fd50[a->b1f7 & 63](a);
}

void func_0c05eb8c(struct Actor *a)
{
    struct LinkedActorVec3 v;
    if (!(a->b34 & 1)) {
        a->b1d2 ^= 1;
        a->w130 = (unsigned char)a->b1d2;
    }
    func_0c025900(a, 5, 5);
    v.x = -113.33333f;
    v.y = 195.0f;
    v.z = 0.0f;
    func_0c1d4610(a, &v);
    a->b1a0 = 10;
    func_0c048ce6(a);
    func_0c02a0c4(a, 15, 0);
}
