/* Dispatch the child state and release it after its owner leaves the stance. */
typedef unsigned char u8;
typedef void (*StateCallback)(u8 *);
extern StateCallback D_004BF868[1];
void func_001B2840(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 D_004BF868[p[5]](p);
 if (owner[0x1e4]!=29 || owner[0x1fd]!=9) {
  ++p[4]; p[0x13c]=0;
 }
}
extern StateCallback D_004C1CB0[2];
void func_0036F920(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 D_004C1CB0[p[5]](p);
 if (owner[0x1e4]!=21 || owner[0x1fd]!=6) {
  ++p[4]; p[0x13c]=0;
 }
}
extern StateCallback D_004C1CB8[2];
void func_00370790(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 D_004C1CB8[p[5]](p);
 if (owner[0x1e4]!=29 || owner[0x1fd]!=9) {
  ++p[4]; p[0x13c]=0;
 }
}
extern StateCallback D_004C1CD4[2];
void func_00371830(u8 *p) {
 u8 *owner=*(u8 **)(p+0x18);
 D_004C1CD4[p[5]](p);
 if (owner[0x1e4]!=29 || owner[0x1fd]!=3) {
  ++p[4]; p[0x13c]=0;
 }
}
