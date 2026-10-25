#include "inherited_effect_phase_tables.h"
typedef signed char s8;

extern void func_00361880(u8 *,u8 *);
extern void func_003610F0(u8 *, int, int);

void func_00361310(u8 *p, u8 *q)
{
    p[0x24] = *(s8 *)(q + 0x24);
    jtbl_004634F0.phase[p[5]](p, q);
}

void func_00361340(u8 *p,u8 *owner)
{
    func_00361880(p,owner);
    func_003610F0(p, 2, 0);
    p[5]++;
}
