/* func_003ADA10 (src/wave5.c): lbu p[4], sll 2, lw, jalr with p in $a0. */
#include "mvc2_state_callbacks.h"

extern void func_003ADA70(u8 *);
extern void func_003ADB80(u8 *);
extern void func_003AE880(u8 *);
extern void func_003AE8A0(u8 *);

const Mvc2StateCallback jtbl_00473B10[4] = {
    func_003ADA70,
    func_003ADB80,
    func_003AE880,
    func_003AE8A0,
};
