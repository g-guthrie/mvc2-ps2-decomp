#include "objects.h"
extern void func_0c0344e4(struct Actor *);
void func_0c02a0c4(struct Actor *a, int bank, int animation)
{
    unsigned char *base;
    unsigned int *banks;
    unsigned int *sequence;
    a->b159 = bank;
    a->b158 = animation;
    base = a->p168;
    banks = (unsigned int *)(base + a->w132);
    sequence = (unsigned int *)(base + banks[(unsigned char)bank]);
    a->p154 = (struct AnimationFrame20 *)(base + sequence[(unsigned char)animation]);
    *(struct AnimationFrame20 *)&a->b140 = *a->p154;
    if (!a->b142) {
        do {
        a->p154++;
        if (a->b143 & 0x80) a->p154 = (struct AnimationFrame20 *)(a->p168 + *(unsigned int *)a->p154);
        *(struct AnimationFrame20 *)&a->b140 = *a->p154;
        } while (!a->b142);
    }
    a->p1c0 = (struct HitboxSelection_15dc08 *)(a->p16c + a->p154->index * 16);
    if (a->b14c) func_0c0344e4(a);
}
