/* Throw step 0x0c0cd364 (parameter copied to p so x/y take fr14/fr15), countdown 0x0c0cd3be and dispatchers. */
#include "objects.h"
extern void (*table_0c248058[])(struct Actor *);
/* func_0c0cd364: no twin (90 bytes) */
extern char func_0c02a026(struct Actor*);
extern void func_0c0437b8(struct Actor*);
extern void func_0c1aede8(struct Actor *);
extern void func_0c1618dc(struct Actor *, int, float, float);
extern int func_0c047bbe(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
void func_0c0cd364(struct Actor *a);
void func_0c0cd3be(struct Actor *a,struct ActorSub2a4 *state);
void func_0c0cd436(struct Actor *a,struct ActorSub2a4 *state);
void func_0c0cd458(struct Actor *a);

void func_0c0cd364(struct Actor *a)
{
    struct Actor *p = a;
    register float y;
    register float x;
    p->b3f8 = 2;
    p->b328 = 5;
    func_0c02a026(p);
    if (p->b141) {
        p->b141 = 0;
        p->b6++;
        x = 195.0f;
        y = 113.57143f;
        func_0c1aede8(p);
        func_0c1618dc(p, 0, x, y);
    }
}

/* func_0c0cd3be: no twin (120 bytes) */
void func_0c0cd3be(struct Actor *a,struct ActorSub2a4 *state)
{
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    if ((signed char)state->b3 > 0 && func_0c047bbe(a)) {
        state->b3--;
        a->s28++;
    }
    if (--a->s28 <= 0) {
        int zero = 0;
        a->b6++;
        a->b3f9 = zero;
        a->b3f8 = zero;
        a->b327 = zero;
        a->b328 = zero;
        func_0c02a0c4(a, 22, 2);
    }
}

void func_0c0cd436(struct Actor *a,struct ActorSub2a4 *state){if(func_0c02a026(a)<0)func_0c0437b8(a);}

void func_0c0cd458(struct Actor *a){table_0c248058[a->b6](a);}
