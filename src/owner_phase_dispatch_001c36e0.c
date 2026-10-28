/* Entry 17 of jtbl_0044CAA0 (word at 0x0044CAE4), dispatched by func_001C1DF0 as
 * jtbl_0044CAA0[p[4]](p, owner); it forwards both arguments to
 * jtbl_0044CB60[4 + p[7]] (retail addresses that sub-table as 0x0044CB70). */
typedef unsigned char u8;typedef void (*Callback)(u8 *,u8 *);
extern Callback const jtbl_0044CB60[];
void func_001C36E0(u8 *p,u8 *owner){u8 *work=owner+0x2b8;if(owner[5]!=0 || owner[0x1e4]!=29)work[0x0b]=0;jtbl_0044CB60[4+p[7]](p,owner);}
