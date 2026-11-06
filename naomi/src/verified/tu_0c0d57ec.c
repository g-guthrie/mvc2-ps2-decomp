#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *, int, int);
extern void func_0c0344a0(struct Actor *, int);
extern void func_0c0437b8(struct Actor *);
extern void func_0c1b1050(struct Actor *, int, int);
void func_0c0d57ec(struct Actor *a, struct ActorSubByteState *state);
void func_0c0d585e(struct Actor *a, char *state);
void func_0c0d589c(struct Actor *a, char *state);

void func_0c0d57ec(struct Actor *a, struct ActorSubByteState *state)
{
    a->b3f8 = 2;
    a->b328 = 5;
    func_0c02a026(a);
    switch (state[1].b0) {
    case 0:
        break;
    case 1:
        a->b7 += 2;
        a->s28 = 23;
        func_0c02a0c4(a, 22, 5);
        break;
    case 2:
        func_0c0344a0(a, 23);
    default:
        a->b7++;
        a->b3f9 = 0;
        a->b3f8 = 0;
        a->b327 = 0;
        a->b328 = 0;
        break;
    }
}

void func_0c0d585e(struct Actor *a, char *state)
{
    func_0c02a026(a);
    if (state[8] < 0) {
        a->f92 = 0.0f;
        a->f96 = 0.0f;
        a->f104 = 0.0f;
        a->f108 = 0.0f;
        func_0c0437b8(a);
    }
}

void func_0c0d589c(struct Actor *a, char *state)
{
    a->b3f8 = 2;
    a->b328 = 5;
    if (--a->s28 == 0) {
        a->b7++;
        a->s28 = 60;
        state[9] = 1;
        a->s30 = 0;
        a->b34 = 5;
        func_0c1b1050(a, 2, 0);
    }
}
