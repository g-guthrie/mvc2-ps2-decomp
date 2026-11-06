/* Exact 0x0c0a8958..0x0c0a8ac8: initialize mirrored motion and update its action state. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c02850e(struct Actor *);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c02a0c4(struct Actor *, int, int);
void func_0c0a8958(struct Actor *a)
{
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    a->b141 = 2;
    a->b141 = 0;
    if (!func_0c02850e(a)) {
        a->b6++;
        a->f96 = -12.85714245f;
        a->f108 = 0.066964284f;
        func_0c0344a0(a, 30);
        if (!a->b2) {
            a->w130 = 0;
            a->f92 = -20.0f;
        } else {
            goto direction;direction:a->w130 = 1;
            a->f92 = 20.0f;
        }
        a->f104 = 0;
    }
}
void func_0c0a89fa(struct Actor *a)
{
    float *stored = (float *)&a->sub2a4;
    a->f52 += a->f92;
    a->f92 += a->f104;
    a->f56 += a->f96;
    a->f96 += a->f108;
    func_0c02a026(a);
    a->b141 = 2;
    a->b141 = 0;
    if (!a->b2) {
        if (a->f52 <= *stored) goto arrived;
    } else if (a->f52 >= *stored) goto arrived;
    return;
arrived:
    a->b6++;
    a->f52 = *stored;
    a->f56 += 68.57143f;
    func_0c02a0c4(a, 1, 1);
}
