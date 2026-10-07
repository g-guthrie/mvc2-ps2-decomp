/* Advance planar velocity and resolve contact with the owner floor. */
typedef unsigned char u8;
extern int func_00175700(u8 *);
extern void func_00183d50(u8 *);
extern void func_001757E0(u8 *,int,int);
void func_001FF500(u8 *p) {
 *(float *)(p+0x34)+=*(float *)(p+0x5c);
 *(float *)(p+0x5c)+=*(float *)(p+0x68);
 *(float *)(p+0x38)+=*(float *)(p+0x60);
 *(float *)(p+0x60)+=*(float *)(p+0x6c);
 func_00175700(p);
 if (*(float *)(p+0x38)<=*(float *)(p+0x430)) {
  ++p[0x7]; *(float *)(p+0x38)=*(float *)(p+0x430); p[0x20d]=0;
  func_00183d50(p); func_001757E0(p,0x15,0xA);
 }
}
void func_001FF850(u8 *p) {
 *(float *)(p+0x34)+=*(float *)(p+0x5c);
 *(float *)(p+0x5c)+=*(float *)(p+0x68);
 *(float *)(p+0x38)+=*(float *)(p+0x60);
 *(float *)(p+0x60)+=*(float *)(p+0x6c);
 func_00175700(p);
 if (*(float *)(p+0x38)<=*(float *)(p+0x430)) {
  ++p[0x7]; *(float *)(p+0x38)=*(float *)(p+0x430); p[0x20d]=0;
  func_00183d50(p); func_001757E0(p,0x15,0xA);
 }
}
void func_0020B3A0(u8 *p) {
 *(float *)(p+0x34)+=*(float *)(p+0x5c);
 *(float *)(p+0x5c)+=*(float *)(p+0x68);
 *(float *)(p+0x38)+=*(float *)(p+0x60);
 *(float *)(p+0x60)+=*(float *)(p+0x6c);
 func_00175700(p);
 if (*(float *)(p+0x38)<=*(float *)(p+0x430)) {
  ++p[0x6]; *(float *)(p+0x38)=*(float *)(p+0x430); p[0x20d]=0;
  func_00183d50(p); func_001757E0(p,0x1,0x3);
 }
}
