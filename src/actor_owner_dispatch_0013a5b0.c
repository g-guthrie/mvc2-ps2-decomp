/* The owner and child are appended in that order to kind 6.
 * When the owner advances to state 5, this callback removes the child
 * before the owner can advance to state 6 on the next update. */
typedef unsigned char u8;
typedef void (*ActorCallback)(u8 *);
extern const unsigned char *const jtbl_00440070[6];

void func_0013A5B0(u8 *p) {
    u8 *owner = *(u8 **)(p + 0x18);
    ((ActorCallback)jtbl_00440070[owner[4]])(p);
}
