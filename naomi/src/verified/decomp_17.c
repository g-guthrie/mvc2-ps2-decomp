#include "objects.h"

#pragma section n02156c
void func_0c02156c(struct ActorInputRecord20 *p) {
    unsigned short z;
    z = 0;
    p->w16 = z;
    if (p->w2 == p->buttons) {
        p->w18 = p->w18 + 1;
        if (p->w18 > 30) {
            if (p->w18 > 35) {
                p->w18 = 30;
                p->w16 = p->buttons;
            }
        }
    } else {
        p->w18 = z;
    }
}

#pragma section n15c860
void func_0c15c860(struct Actor *p) {
    p->s28 = 2;
    if (--p->s30 == 0) {
        p->b5 = p->b5 + 1;
        p->s28 = 64;
        p->s30 = 64;
    }
}

