/* State-six callback table used by the exact indirect dispatch family. */
#include "dispatch_state_6.h"

extern void func_00227ED0(DispatchState_6 *);
extern void func_00227F90(DispatchState_6 *);
extern void func_00227FB0(DispatchState_6 *);
extern void func_00228080(DispatchState_6 *);
extern void func_00228160(DispatchState_6 *);

const DispatchState6Handler jtbl_004518A0[5] = {
    func_00227ED0,
    func_00227F90,
    func_00227FB0,
    func_00228080,
    func_00228160,
};
