/* Three two-entry state tables indexed by the actor's sub-state byte:
 * 00396A40 dispatches the first with (actor, owner), 00397140 the
 * second with (actor, owner, work) as received from 00396E30, and
 * 00397FA0 the third with the actor alone. */
typedef unsigned char u8;
typedef void (*OwnerCallback)(u8 *, u8 *);
typedef void (*OwnerWorkCallback)(u8 *, u8 *, u8 *);
typedef void (*ActorCallback)(u8 *);
extern void func_00396A70(u8 *, u8 *);
extern void func_00396BD0(u8 *, u8 *);
extern void func_00397180(u8 *, u8 *, u8 *);
extern void func_00397250(u8 *, u8 *, u8 *);
extern void func_00397FC0(u8 *);
extern void func_003980C0(u8 *);
typedef struct {
    OwnerCallback owner_states[2];
    OwnerWorkCallback work_states[2];
    ActorCallback actor_states[2];
} ActorStateTables;
const ActorStateTables jtbl_004C1E38 = {
    {func_00396A70, func_00396BD0},
    {func_00397180, func_00397250},
    {func_00397FC0, func_003980C0},
};
