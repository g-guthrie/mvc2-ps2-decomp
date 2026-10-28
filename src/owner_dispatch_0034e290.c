/* Phase dispatch on p[4] through jtbl_004622A0 (4 void(u8 *) entries:
 * func_0034E2D0, func_0034EAB0, func_0034FA60, func_0034FA70). */
typedef unsigned char u8;
typedef void (*Phase)(u8 *);
extern u8 *D_004C2950 __attribute__((section(".sdata")));
extern u8 *D_004C294C __attribute__((section(".sdata")));
extern Phase const jtbl_004622A0[4];
void func_0034E290(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 D_004C2950=p+0xd0; D_004C294C=owner+0x2b8;
 jtbl_004622A0[p[4]](p);
}
