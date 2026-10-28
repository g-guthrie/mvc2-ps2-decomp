typedef unsigned char u8;
extern void (* const jtbl_0044E7C0[3])(u8 *);
void func_001D8DB0(u8 *p,u8 *owner) {
 if(p[0x21]==0)p[0x24]=9;else p[0x24]=12;
 jtbl_0044E7C0[p[5]](p);
}
