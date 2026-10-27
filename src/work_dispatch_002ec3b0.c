/* Provisional: callback table ownership and selector bounds need proof. */
typedef unsigned char u8;typedef void (*OwnerCallback)(u8 *,u8 *);
extern const OwnerCallback jtbl_004C11A0[2] __attribute__((section(".sdata")));
void func_002EC3B0(u8 *p,u8 *context) {if(p[0x20d]==2)p[6]=1;jtbl_004C11A0[p[6]](p,context);}
