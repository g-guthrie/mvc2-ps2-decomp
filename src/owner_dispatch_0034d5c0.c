/* Provisional: callback table ABI, phase bounds and owner lifetime need proof. */
typedef unsigned char u8;
typedef void (*Phase)(u8 *);
extern u8 *D_004C2940 __attribute__((section(".sdata")));
extern u8 *D_004C293C __attribute__((section(".sdata")));
extern Phase const jtbl_004621F0[];
void func_0034D5C0(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 D_004C2940=p+0xd0; D_004C293C=owner+0x2b8;
 jtbl_004621F0[p[4]](p);
}
