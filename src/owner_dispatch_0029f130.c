/* Provisional: callback table ownership and selector bounds need proof. */
typedef unsigned char u8;typedef void (*Callback)(u8 *,u8 *);
extern Callback const jtbl_00458230[];
void func_0029F130(u8 *p){p[0x40c]=2;p[0x33c]=5;p[0x1fe]=1;p[0x201]=2;jtbl_00458230[p[7]](p,*(u8 **)(p+0x1dc));}
