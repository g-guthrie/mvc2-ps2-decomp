/* Placeholder: phase bounds and DATA callback signatures remain unproved. */
typedef unsigned char u8;
typedef void (*OwnerPhase)(u8 *,u8 *);
extern OwnerPhase const jtbl_0044CD30[9];
void func_001C6250(u8 *p, u8 *owner)
{
    u8 *work = owner + 0x2B8;
    if (owner[5] || owner[0x1E4] != 29) { work[11] = 0; work[10] = 1; }
    jtbl_0044CD30[p[7]](p, owner);
}
