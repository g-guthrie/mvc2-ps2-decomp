/* Typed callback entries recovered from the exact dispatch callers. */
/* Consumers: src/composite_dispatch_heads.c (jtbl_0044E7D0, table 0044E7E0,
 * table 0044E7F0). 001D8DF0, 001D8FF0 and 001D9190 forward the
 * owner context that 001D8B30 loads from object+0x18. */
#include "mvc2_state_callbacks.h"

extern void func_001D8B60(u8 *, void *);
extern void func_001D8DB0(u8 *, void *);
extern void func_001D8E10(u8 *, void *);
extern void func_001D8F60(u8 *, void *);
extern void func_001D9110(u8 *, void *);
extern void func_001D91B0(u8 *, void *);
extern void func_001D91D0(u8 *, void *);
extern void residual_001D9010(u8 *, void *);

typedef struct {
    Mvc2OwnerStateCallback first[4];
    Mvc2OwnerStateCallback second[4];
    Mvc2OwnerStateCallback third[4];
} OwnerStateTables;
const OwnerStateTables jtbl_0044E7D0 = {{
    func_001D8B60,
    func_001D8DB0,
    func_001D91B0,
    func_001D91D0,
}, {
    func_001D8E10,
    func_001D8F60,
    func_001D91B0,
    func_001D91D0,
}, {
    residual_001D9010,
    func_001D9110,
    func_001D91B0,
    func_001D91D0,
}};
