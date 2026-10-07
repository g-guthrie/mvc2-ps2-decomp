/* Dispatch an owner's current state while the object's inhibit byte is clear. */
typedef unsigned char u8;
typedef void (*OwnerHandler)(u8 *, void *);
extern OwnerHandler D_0044AF60[], D_0044AFD0[], D_0044B010[], D_0044B3E0[];

#define OWNER_STATE_DISPATCH(name, handlers) \
void name(u8 *p) { \
    void *owner = *(void **)(p + 0x18); \
    if (!p[0x23]) (handlers)[p[4]](p, owner); \
}

OWNER_STATE_DISPATCH(func_001A01C0, D_0044AF60)
OWNER_STATE_DISPATCH(func_001A1400, D_0044AFD0)
OWNER_STATE_DISPATCH(func_001A26E0, D_0044B010)
OWNER_STATE_DISPATCH(func_001A5E50, D_0044B3E0)
