/* func_00133860: looks up the actor's owner in the per-side owner rows
 * D_004D18B8 (u8 *v[3] per side, as in src/grok_fc_00326C80.c), caches it at
 * 0x148 and dispatches on state byte 4 through jtbl_0043E8F0, a slice of
 * jtbl_0043E8EC (src/data/jtbl_0043E8EC.c): func_001338B0, func_001338F0,
 * func_001341A0, func_001341A0. The first two are defined as
 * void f(u8 *p, u8 *owner); func_001341A0 (src/tail_leaves.c) is a thunk
 * taking the same live $a0 first. */
typedef unsigned char u8;
typedef struct {u8 a[2];u8 side;u8 b;u8 state;u8 c[0x143];u8 *owner;} Actor;
typedef void (*OwnerStateCallback)(u8 *p, u8 *owner);
extern u8 *D_004D18B8[][3];
extern OwnerStateCallback const jtbl_0043E8F0[4];
void func_00133860(u8 *p){
    Actor *a = (Actor *)p;
    a->owner = D_004D18B8[a->side][0];
    jtbl_0043E8F0[a->state](p, a->owner);
}
