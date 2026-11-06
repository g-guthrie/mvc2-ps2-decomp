#include "objects.h"
extern void func_0c043352(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern struct Actor *func_0c037d54(struct Actor *);
extern void func_0c1d4610(struct Actor *, struct LinkedActorVec3 *);
extern void func_0c025900(struct Actor *, char, char);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c044548(struct Actor *, struct Actor *);
extern void func_0c0437b8(struct Actor *);
void func_0c0580ac(struct Actor *a)
{
    struct LinkedActorVec3 position;
    struct Actor *target;
    a->w3e4 = 2;
    func_0c043352(a);
    a->f52 += a->f92;
    a->f92 += a->f104;
    func_0c02a026(a);
    if ((target = func_0c037d54(a))) {
        a->b6 = 5;
        a->b7 = 0;
        position.x = -146.66666f;
        position.y = 171.42856f;
        func_0c1d4610(a, &position);
        func_0c025900(a, 5, 5);
        a->b1f7 = 198;
        func_0c02a0c4(a, 15, 29);
        func_0c044548(a, target);
        return;
    }
    a->s30 = 0;
    if (a->b1d2) {
        if ((char)a->b1fd & 1) goto blocked;
    } else if ((char)a->b1fd & 2) goto blocked;
    goto countdown;
blocked:
    a->s30 = 1;
countdown:
    if (a->s30 || --a->s28 == 0) {
        a->b6++;
        func_0c02a0c4(a, 15, 23);
    }
}
void func_0c05818c(struct Actor *a) { if (func_0c02a026(a) < 0) func_0c0437b8(a); }
