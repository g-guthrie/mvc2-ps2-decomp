/* Typed callback entries recovered from the exact dispatch callers. */
/* Consumers: src/grok_w5_disp.c (jtbl_0044E7A0, dispatched with the object
 * alone by 001D8610) and the table 0044E7B0 state table that
 * 001D8B30 dispatches with the owner loaded from object+0x18. */
#include "mvc2_state_callbacks.h"

extern void func_001D8630(u8 *);
extern void func_001D8700(u8 *);
extern void func_001D8A00(u8 *);
extern void func_001D8A20(u8 *);
extern void func_001D8DF0(u8 *, void *);
extern void func_001D8FF0(u8 *, void *);
extern void func_001D9190(u8 *, void *);

typedef struct {
    Mvc2StateCallback object_states[4];
    Mvc2OwnerStateCallback owner_states[3];
} ObjectOwnerStateTables;
const ObjectOwnerStateTables jtbl_0044E7A0 = {{
    func_001D8630,
    func_001D8700,
    func_001D8A00,
    func_001D8A20,
}, {
    func_001D8DF0,
    func_001D8FF0,
    func_001D9190,
}};
