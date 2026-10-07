/* State-six callback table used by the exact indirect dispatch family. */
#include "dispatch_state_6.h"

extern void func_00228E20(DispatchState_6 *);
extern void func_00228EA0(DispatchState_6 *);
extern void func_00228F50(DispatchState_6 *);
extern void func_00229040(DispatchState_6 *);
extern void func_002290A0(DispatchState_6 *);

const DispatchState6Handler jtbl_00451960[5] = {
    func_00228E20,
    func_00228EA0,
    func_00228F50,
    func_00229040,
    func_002290A0,
};
