/* Copy the owner's 0x24 byte, then dispatch the owner-aware state route
 * (jtbl_00476010 entries 36..39, all defined as (u8 *, owner) handlers). */
typedef unsigned char u8;
typedef signed char s8;
typedef void (*DispatchFn1)(u8 *);
typedef void (*DispatchFn2)(u8 *, void *);
extern const DispatchFn1 jtbl_00476010[50];
void func_003C7480(u8 *p, void *owner)
{
    p[0x24] = ((s8 *)owner)[0x24];
    ((DispatchFn2)jtbl_00476010[p[5] + 36])(p, owner);
}
