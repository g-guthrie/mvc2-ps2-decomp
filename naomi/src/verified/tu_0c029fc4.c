#include "objects.h"
extern void func_0c0344e4(struct Actor *);
char func_0c029fc4(struct Actor *a)
{
    char result = 0;
    if (--a->b142 == 0) {
        do {
            a->p154 = (struct AnimationFrame20 *)((char *)a->p154 + 8);
            if ((result = a->b143 & 0x80)) a->p154 = (struct AnimationFrame20 *)(a->p168 + *(unsigned int *)a->p154);
            *(struct AnimationFrame8 *)&a->b140 = *(struct AnimationFrame8 *)a->p154;
            *(int *)&a->pad6ca[0] = 0;
            *(int *)&a->b14c = 0;
            *(int *)&a->w150 = 0;
        } while (!a->b142);
    }
    return result;
}
char func_0c02a026(struct Actor *a)
{
    char result = 0;
    if (--a->b142 == 0) {
        do {
            a->p154++;
            if ((result = a->b143 & 0x80)) a->p154 = (struct AnimationFrame20 *)(a->p168 + *(unsigned int *)a->p154);
            *(struct AnimationFrame20 *)&a->b140 = *a->p154;
        } while (!a->b142);
        a->p1c0 = (struct HitboxSelection_15dc08 *)(a->p16c + a->p154->index * 16);
        if (a->b14c) func_0c0344e4(a);
    }
    return result;
}
