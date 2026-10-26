typedef unsigned char u8;
typedef void (*StateFn)(u8 *);
extern StateFn const jtbl_00463D68[3];
void func_0036D7D0(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 jtbl_00463D68[p[5]](p);
 { u8 *work=owner+0x2B8; if(work[1]) {++p[4];p[0x13C]=0;work[0]=0;} }
}
