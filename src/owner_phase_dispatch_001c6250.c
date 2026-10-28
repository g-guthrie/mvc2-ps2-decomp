/* Reset the owner's work flags unless it is idle in mode 29, then dispatch
 * phase p[7] through jtbl_0044CD30 (nine (u8 *, owner) phase handlers). */
typedef unsigned char u8;
typedef void (*Mvc2Callback)(void);
typedef void (*OwnerPhase)(u8 *, u8 *);
extern const Mvc2Callback jtbl_0044CD30[9];
void func_001C6250(u8 *p, u8 *owner)
{
    u8 *work = owner + 0x2B8;
    if (owner[5] || owner[0x1E4] != 29) { work[11] = 0; work[10] = 1; }
    ((OwnerPhase)jtbl_0044CD30[p[7]])(p, owner);
}
