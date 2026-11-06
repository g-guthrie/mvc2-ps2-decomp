#include "objects.h"

/* Assembled by tools/clone.py from verified twins. */

struct PairF {
    float f0, f4;
};

extern struct MotionGlobal_0c2d9260 dat_0c2d9260;

void func_0c025a9c(float *a, float *b)
{
    if (*a + 320.0f > dat_0c2d9260.f9c) {
        *a = dat_0c2d9260.f9c + -320.0f;
        *b = dat_0c2d9260.f9c + -320.0f;
    }
    if (*a + -320.0f < dat_0c2d9260.f98) {
        *a = dat_0c2d9260.f98 + 320.0f;
        *b = dat_0c2d9260.f98 + 320.0f;
    }
}

void func_0c025ad6(struct PairF *a)
{
    if (95.0f > a->f4)
        a->f4 = 95.0f;
    if (!(900.0f > a->f4))
        a->f4 = 900.0f;
}

void func_0c025af6(void)
{
    dat_0c2d9260.f8c = dat_0c2d9260.f12 + 320.0f;
    dat_0c2d9260.f88 = dat_0c2d9260.f12 + -320.0f;
    dat_0c2d9260.fa8 = dat_0c2d9260.f16 + 98.400002f;
    dat_0c2d9260.f90 = dat_0c2d9260.fa8 + 240.0f;
    dat_0c2d9260.f94 = dat_0c2d9260.fa8 + -240.0f;
}
