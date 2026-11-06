/* 36/42 bytes. b5 is a plain char in Obj_tu5_03; retail compares it
 * unsigned, hence the cast. Remaining: retail loads mov #120 before the
 * first fmov and hoists the 6 into r2 (ours r3). */
#include "objects.h"

#pragma section N1d89a8
void func_0c1d89a8(struct Obj_tu5_03 *a, const float *value)
{
    a->f120 = *value;
    a->f124 = *value;
    a->f128 = *value;
    if ((unsigned char)++a->b5 > 6)
        a->b4++;
}
