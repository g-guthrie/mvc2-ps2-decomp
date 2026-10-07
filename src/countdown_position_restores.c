/* Restore the shared position when the planar-motion countdown expires. */
typedef unsigned char u8;
extern void func_00175700(u8 *),func_001757E0(u8 *,int,int);
extern float *D_004C29D0;
void func_00393740(u8 *p) {
 func_00175700(p);
 *(float *)(p+0x34)+=*(float *)(p+0x5c); *(float *)(p+0x5c)+=*(float *)(p+0x68);
 *(float *)(p+0x38)+=*(float *)(p+0x60); *(float *)(p+0x60)+=*(float *)(p+0x6c);
 if (!--*(short *)(p+0x1c)) {
  ++p[5]; *(float *)(p+0x34)=D_004C29D0[1]; *(float *)(p+0x38)=D_004C29D0[2];
  func_001757E0(p,23,10);
 }
}
void func_00393DA0(u8 *p) {
 func_00175700(p);
 *(float *)(p+0x34)+=*(float *)(p+0x5c); *(float *)(p+0x5c)+=*(float *)(p+0x68);
 *(float *)(p+0x38)+=*(float *)(p+0x60); *(float *)(p+0x60)+=*(float *)(p+0x6c);
 if (!--*(short *)(p+0x1c)) {
  ++p[5]; *(float *)(p+0x34)=D_004C29D0[1]; *(float *)(p+0x38)=D_004C29D0[2];
  func_001757E0(p,23,11);
 }
}
void func_00394420(u8 *p) {
 func_00175700(p);
 *(float *)(p+0x34)+=*(float *)(p+0x5c); *(float *)(p+0x5c)+=*(float *)(p+0x68);
 *(float *)(p+0x38)+=*(float *)(p+0x60); *(float *)(p+0x60)+=*(float *)(p+0x6c);
 if (!--*(short *)(p+0x1c)) {
  ++p[5]; *(float *)(p+0x34)=D_004C29D0[1]; *(float *)(p+0x38)=D_004C29D0[2];
  func_001757E0(p,23,12);
 }
}
