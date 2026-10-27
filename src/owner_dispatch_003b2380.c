/* Provisional: callback table ABI and phase bounds need proof. */
typedef unsigned char u8;
typedef signed char s8;
typedef void (*Callback)(u8 *,u8 *);
extern Callback const jtbl_00473D80[3];
void func_003B2380(u8 *p,u8 *owner) {
 p[0x24]=*(s8 *)(owner+0x24);
 jtbl_00473D80[p[5]](p,owner);
}
