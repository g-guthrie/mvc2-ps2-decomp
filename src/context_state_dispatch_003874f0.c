/* Provisional: forwarded context provenance, owner lifetime and selector bounds require proof. */
typedef unsigned char u8;
extern void (*jtbl_00464990[])(u8 *,u8 *);
void func_003874F0(u8 *p,u8 *q) {
 if (q[4]>=2 || p[1]!=q[1]) {p[4]++;p[0x13c]=0;}
 else if(q[5]>=2) {p[4]++;p[0x13c]=0;q[0x2be]=0;}
 else jtbl_00464990[p[5]](p,q);
}
