typedef unsigned char u8;
typedef short s16;
typedef void (*State)(u8 *, void *);
extern State const jtbl_00475B40[6];
/* Per-state handlers, indexed by the state byte at p[5]. */
void func_003BE8A0(u8 *p, void *owner_arg) {
    u8 *owner = owner_arg;
    if (p[5] != 0 && p[5] != 5) {
        if (owner[0x1e4] != 0x1d || owner[5] != 0) {
            p[5] = 5;
            *(s16 *)(p + 0x1c) = 1;
        }
    }
    jtbl_00475B40[p[5]](p, owner);
}
