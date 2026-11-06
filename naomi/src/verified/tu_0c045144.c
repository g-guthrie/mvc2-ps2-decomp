#include "objects.h"
extern short dat_0c23ca00[][3];

void func_0c045144(struct Actor *a)
{
    float v;
    if (!((char)a->b1fd & (1 << (short)a->w130))) {
        v = dat_0c23ca00[a->b1][a->b4c9] * 1.66666663f;
        if (a->w130) v = -v;
        a->f52 += v;
    }
    v = 640.0f;
    if (a->w130) v = -640.0f;
    a->f52 += v;
    a->f92 = -(v / 21.0f);
    a->f104 = 0.0f;
    a->f56 = a->f41c + 137.142853f;
    a->f108 = -1.60714281f;
    a->f96 = (a->f41c - a->f56) / 20.0f - a->f108 * 20.0f / 2.0f;
}

void func_0c0451f2(struct Actor *a)
{
    if (a->b1f9 != 2) {
        a->b1f9 = 2;
        a->b1fc = 0;
        a->b1d4 = 0;
        a->pad7f2 = 0;
        a->b1d6 = 17;
        a->pad1d7[2] = 0;
    }
}
