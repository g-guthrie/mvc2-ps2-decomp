/* Placeholder: entry path, bounds, and DATA callback contracts remain unproved. */
typedef unsigned char u8;typedef void (*Callback)(u8 *,u8 *);
extern Callback const jtbl_0044CB60[];
void func_001C36E0(u8 *p,u8 *owner){u8 *work=owner+0x2b8;if(owner[5]!=0 || owner[0x1e4]!=29)work[0x0b]=0;jtbl_0044CB60[4+p[7]](p,owner);}
