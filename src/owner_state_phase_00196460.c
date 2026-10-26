typedef unsigned char u8;
extern void (*const jtbl_0044A2B0[3])(u8*,u8*);
void func_00196460(u8 *p,u8 *q) {
 u8 *local=p+0x88,*work=q+0x2B8;
 if(q[0x1E4]!=22){work[12]=0;local[0]=0;}
 jtbl_0044A2B0[p[5]](p,q);
}
