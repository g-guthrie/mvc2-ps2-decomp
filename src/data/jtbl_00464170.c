/* Typed callback entries recovered from the exact dispatch callers. */
/* Consumers: src/composite_dispatch_heads.c (jtbl_00464170, table 00464180),
 * src/argument_dispatch_heads.c (table 00464190, table 004641A0,
 * table 004641B0) and src/grok_kk_37d8d0.c (table 004641C0). The first two
 * state tables are dispatched with the object alone; 0037CC50,
 * 0037CF40 and 0037D220 load the owner from object+0x18 and pass
 * it, and 0037D8D0 forwards that owner to the last table. */
#include "mvc2_state_callbacks.h"

extern void func_0037B9E0(u8 *);
extern void func_0037BBF0(u8 *);
extern void func_0037BDB0(u8 *);
extern void func_0037BDD0(u8 *);
extern void func_0037BF60(u8 *);
extern void func_0037C2A0(u8 *);
extern void func_0037CB10(u8 *);
extern void func_0037CB50(u8 *);
extern void func_0037CC80(u8 *, void *);
extern void func_0037CE30(u8 *, void *);
extern void func_0037CF10(u8 *, void *);
extern void func_0037CF30(u8 *, void *);
extern void func_0037CF70(u8 *, void *);
extern void func_0037D0D0(u8 *, void *);
extern void func_0037D250(u8 *, void *);
extern void func_0037D420(u8 *, void *);
extern void func_0037D690(u8 *, void *);
extern void func_0037D830(u8 *, void *);
extern void func_0037D8D0(u8 *, void *);
extern void func_0037D900(u8 *, void *);
extern void func_0037D920(u8 *, void *);

typedef struct {
    Mvc2StateCallback start[4];            /* 0037B9C0 */
    Mvc2StateCallback second[4];           /* 0037BF40 */
    Mvc2OwnerStateCallback third[4];       /* 0037CC50 */
    Mvc2OwnerStateCallback fourth[4];      /* 0037CF40 */
    Mvc2OwnerStateCallback finish[4];      /* 0037D220 */
    Mvc2OwnerStateCallback finish_child[3];/* 0037D8D0 */
} ActorPhaseTables;
const ActorPhaseTables jtbl_00464170 = {{
    func_0037B9E0,
    func_0037BBF0,
    func_0037BDB0,
    func_0037BDD0,
}, {
    func_0037BF60,
    func_0037C2A0,
    func_0037CB10,
    func_0037CB50,
}, {
    func_0037CC80,
    func_0037CE30,
    func_0037CF10,
    func_0037CF30,
}, {
    func_0037CF70,
    func_0037D0D0,
    func_0037CF10,
    func_0037CF30,
}, {
    func_0037D250,
    func_0037D8D0,
    func_0037D900,
    func_0037D920,
}, {
    func_0037D420,
    func_0037D690,
    func_0037D830,
}};
