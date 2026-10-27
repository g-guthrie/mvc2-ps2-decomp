/* Provisional: callback-table ABI and phase bounds require proof. */
typedef unsigned char u8; typedef signed char s8;
typedef void (*Callback)(u8 *,void *);
extern Callback const jtbl_0044E4A0[3];
void func_001D4BC0(u8 *p,void *context) {
 u8 *owner=context;
 u8 *work=owner+0x2b8;
 if (owner[0x169] != 21 || *(s8 *)(work+7) < 0) { p[4]=2; p[0x13c]=0; }
 jtbl_0044E4A0[p[4]](p,context);
}
