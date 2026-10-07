/* State-six callback table used by the exact indirect dispatch family. */
#include "dispatch_state_6.h"

extern void func_00228230(DispatchState_6 *);
extern void func_00228300(DispatchState_6 *);
extern void func_00228350(DispatchState_6 *);
extern void func_002283C0(DispatchState_6 *);

const DispatchState6Handler jtbl_004518E0[4] = {
    func_00228230,
    func_00228300,
    func_00228350,
    func_002283C0,
};
