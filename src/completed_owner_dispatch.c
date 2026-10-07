/* Release completed entries or dispatch the owner-specific active state. */
typedef unsigned char u8;
typedef void (*OwnerHandler)(u8 *,u8 *);
extern void func_003DAA40(u8 *);
extern OwnerHandler D_0044DD70[];
void func_001CCD40(u8 *p) {
    u8 *owner = *(u8 **)(p+0x18);
    if (p[4] >= 2) func_003DAA40(p);
    else D_0044DD70[p[0x20]](p,owner);
}
extern OwnerHandler D_0044DF20[];
void func_001D0580(u8 *p) {
    u8 *owner = *(u8 **)(p+0x18);
    if (p[4] >= 2) func_003DAA40(p);
    else D_0044DF20[p[0x20]](p,owner);
}
extern OwnerHandler D_0044E2D0[];
void func_001D37D0(u8 *p) {
    u8 *owner = *(u8 **)(p+0x18);
    if (p[4] >= 2) func_003DAA40(p);
    else D_0044E2D0[p[0x20]](p,owner);
}
