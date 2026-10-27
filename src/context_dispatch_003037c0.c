/* Provisional: callback table ownership and selector bounds need proof. */
typedef unsigned char u8;typedef void (*OwnerCallback)(u8 *,void *);
extern const OwnerCallback jtbl_004C14E0[2] __attribute__((section(".sdata")));
void func_003037C0(u8 *p,void *context) {if(p[0x20d]==2)p[6]=1;jtbl_004C14E0[p[6]](p,context);}
