/* 002C1670 sets the signed selector to 0 or 1 before calling 002C17C0. */
#include "mvc2_state_callbacks.h"
extern void func_002C17E0(u8 *);
extern void func_002C19D0(u8 *);
Mvc2StateCallback const jtbl_004C0DE8[2] __attribute__((section(".sdata"))) = {
    func_002C17E0, func_002C19D0
};
