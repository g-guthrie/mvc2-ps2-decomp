/* 92-byte spawner. v52 is a real struct member so the following constant
 * store uses indexed @(r0, r4) with the value in r1, matching retail. */
#include "objects.h"

struct Spawn_0c1e0b64 {
    unsigned char pad0[0x10];
    void (*p16)(struct Spawn_0c1e0b64 *);
    unsigned char pad1[52 - 0x14];
    struct LinkedActorVec3 v52;
    unsigned char pad2[0x84 - 64];
    void *p84;
    unsigned char pad3[0xcc - 0x88];
    int lcc;
    unsigned char pad4[0x12c - 0xd0];
    unsigned char b12c;
};

extern struct ActorGlobalRoot *dat_0c2d964c;
extern const struct LinkedActorVec3 dat_0c262718;
extern struct Spawn_0c1e0b64 *func_0c0374da(int, int, int);
extern void func_0c1e0b60(struct Spawn_0c1e0b64 *);

void func_0c1e0b64(void)
{
    struct Spawn_0c1e0b64 *a;

    if ((a = func_0c0374da(0, 5, 1)) == 0)
        return;
    a->b12c = 1;
    a->p16 = func_0c1e0b60;
    a->p84 = dat_0c2d964c->p0->entries[11].pointer;
    a->v52 = dat_0c262718;
    a->lcc = 0x0901;
}
