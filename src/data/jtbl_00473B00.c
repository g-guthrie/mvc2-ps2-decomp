/* func_003AD700 (src/grok_y5_3ad700.c): lbu p[4], sll 2, lw, jalr with p in $a0. */
#include "mvc2_state_callbacks.h"

extern void func_003AD7A0(u8 *);
extern void func_003AD910(u8 *);
extern void func_003AE880(u8 *);
extern void func_003AE8A0(u8 *);

const Mvc2StateCallback jtbl_00473B00[4] = {
    func_003AD7A0,
    func_003AD910,
    func_003AE880,
    func_003AE8A0,
};
