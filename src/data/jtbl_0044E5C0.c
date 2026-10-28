/* Typed callback entries recovered from the exact dispatch callers. */
/* Consumers: src/composite_dispatch_heads.c (jtbl_0044E5C0, table 0044E5D0,
 * table 0044E5F0), src/indirect_dispatch.c (table 0044E5E0),
 * src/grok_w5_001d.c (table 0044E600), src/argument_dispatch_heads.c
 * (table 0044E610, table 0044E620). Each four-entry state table is typed by
 * its own dispatcher: all forward the owner context except table 0044E5F0,
 * whose head 001D6BC0 passes only the object. */
#include "mvc2_state_callbacks.h"

extern void func_001D6500(u8 *, void *);
extern void func_001D6680(u8 *, void *);
extern void func_001D6760(u8 *, void *);
extern void func_001D6890(u8 *, void *);
extern void func_001D6970(u8 *, void *);
extern void func_001D6A70(u8 *, void *);
extern void func_001D6B20(u8 *, void *);
extern void func_001D6B40(u8 *, void *);
extern void func_001D6BE0(u8 *);
extern void func_001D6D10(u8 *);
extern void func_001D6D40(u8 *, void *);
extern void func_001D6D80(u8 *, void *);
extern void func_001D6DC0(u8 *);
extern void func_001D6E00(u8 *);
extern void func_001D6E90(u8 *, void *);
extern void func_001D6FD0(u8 *, void *);
extern void func_001D7050(u8 *, void *);
extern void func_001D7060(u8 *, void *);
extern void func_001D7150(u8 *, void *);
extern void func_001D7340(u8 *, void *);
extern void func_001D7500(u8 *, void *);
extern void func_001D7510(u8 *, void *);

typedef struct {
    Mvc2OwnerStateCallback entry_start[4];   /* 001D6740 */
    Mvc2OwnerStateCallback entry_second[4];  /* 001D6950 */
    Mvc2OwnerStateCallback entry_third[4];   /* 001D6B00 */
    Mvc2StateCallback object_only[4];        /* 001D6BC0 */
    Mvc2OwnerStateCallback child_phase[4];   /* 001D6D10 */
    Mvc2OwnerStateCallback owner_phase[4];   /* 001D6E60 */
    Mvc2OwnerStateCallback child[4];         /* 001D7120 */
} OwnerChildModeTables;
const OwnerChildModeTables jtbl_0044E5C0 = {{
    func_001D6500,
    func_001D6680,
    func_001D6B20,
    func_001D6B40,
}, {
    func_001D6760,
    func_001D6890,
    func_001D6B20,
    func_001D6B40,
}, {
    func_001D6970,
    func_001D6A70,
    func_001D6B20,
    func_001D6B40,
}, {
    func_001D6BE0,
    func_001D6D10,
    func_001D6DC0,
    func_001D6E00,
}, {
    func_001D6D40,
    func_001D6D80,
    func_001D6D40,
    func_001D6D40,
}, {
    func_001D6E90,
    func_001D6FD0,
    func_001D7050,
    func_001D7060,
}, {
    func_001D7150,
    func_001D7340,
    func_001D7500,
    func_001D7510,
}};
