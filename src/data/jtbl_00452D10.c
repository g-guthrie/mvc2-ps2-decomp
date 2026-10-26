/* Typed callback entries recovered from the exact dispatch callers. */
/* Consumer: src/composite_dispatch_heads.c (jtbl_00452D10). */
#include "mvc2_state_callbacks.h"

extern void func_00246510(u8 *,void *);
extern void func_002465F0(u8 *,void *);
extern void func_00246650(u8 *,u8 *);
extern void func_002466E0(u8 *);
extern void func_00246750(u8 *);

typedef struct {
    Mvc2OwnerStateCallback work_start[2];
    void (*timer)(u8 *,u8 *);
    Mvc2StateCallback later[2];
} WorkChainPhaseTables;
const WorkChainPhaseTables jtbl_00452D10 = {{
    func_00246510,
    func_002465F0,
}, func_00246650, {
    func_002466E0,
    func_00246750,
}};
