/* func_003ADC70 (src/composite_dispatch_heads.c): lbu p[4], sll 2, lw, jr (tail call with p in $a0).
 * Entry 0 targets the code that directly follows func_003ADC70's dispatch (0x003ADC90). */
#include "mvc2_state_callbacks.h"

extern void func_003ADC90(u8 *);
extern void func_003ADE90(u8 *);
extern void func_003AE880(u8 *);
extern void func_003AE8A0(u8 *);

const Mvc2StateCallback jtbl_00473B20[4] = {
    func_003ADC90,
    func_003ADE90,
    func_003AE880,
    func_003AE8A0,
};
