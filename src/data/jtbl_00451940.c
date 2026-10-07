/* State-six callback table used by the exact indirect dispatch family. */
#include "dispatch_state_6.h"

extern void func_00228A60(DispatchState_6 *);
extern void func_00228AF0(DispatchState_6 *);
extern void func_00228B30(DispatchState_6 *);
extern void func_00228C50(DispatchState_6 *);
extern void func_00228CB0(DispatchState_6 *);

const DispatchState6Handler jtbl_00451940[5] = {
    func_00228A60,
    func_00228AF0,
    func_00228B30,
    func_00228C50,
    func_00228CB0,
};
