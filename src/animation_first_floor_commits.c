/* Update animation and planar motion, then commit the floor-contact phase. */
typedef unsigned char u8;
extern void func_00175700(u8 *),func_00183d50(u8 *),func_001757E0(u8 *,int,int);
void func_0020F880(u8 *p) {
 func_00175700(p);
 *(float *)(p+0x34)+=*(float *)(p+0x5c); *(float *)(p+0x5c)+=*(float *)(p+0x68);
 *(float *)(p+0x38)+=*(float *)(p+0x60); *(float *)(p+0x60)+=*(float *)(p+0x6c);
 if (*(float *)(p+0x38)<=*(float *)(p+0x430)) {
  ++p[6]; *(float *)(p+0x38)=*(float *)(p+0x430); p[0x20d]=0;
  func_00183d50(p);func_001757E0(p,15,2);
 }
}
void func_002A4F50(u8 *p) {
 func_00175700(p);
 *(float *)(p+0x34)+=*(float *)(p+0x5c); *(float *)(p+0x5c)+=*(float *)(p+0x68);
 *(float *)(p+0x38)+=*(float *)(p+0x60); *(float *)(p+0x60)+=*(float *)(p+0x6c);
 if (*(float *)(p+0x38)<=*(float *)(p+0x430)) {
  ++p[6]; *(float *)(p+0x38)=*(float *)(p+0x430); p[0x20d]=0;
  func_00183d50(p);func_001757E0(p,22,3);
 }
}
void func_002BB310(u8 *p) {
 func_00175700(p);
 *(float *)(p+0x34)+=*(float *)(p+0x5c); *(float *)(p+0x5c)+=*(float *)(p+0x68);
 *(float *)(p+0x38)+=*(float *)(p+0x60); *(float *)(p+0x60)+=*(float *)(p+0x6c);
 if (*(float *)(p+0x38)<=*(float *)(p+0x430)) {
  ++p[6]; *(float *)(p+0x38)=*(float *)(p+0x430); p[0x20d]=0;
  func_00183d50(p);func_001757E0(p,1,5);
 }
}
void func_002E7FB0(u8 *p) {
 func_00175700(p);
 *(float *)(p+0x34)+=*(float *)(p+0x5c); *(float *)(p+0x5c)+=*(float *)(p+0x68);
 *(float *)(p+0x38)+=*(float *)(p+0x60); *(float *)(p+0x60)+=*(float *)(p+0x6c);
 if (*(float *)(p+0x38)<=*(float *)(p+0x430)) {
  ++p[6]; *(float *)(p+0x38)=*(float *)(p+0x430); p[0x20d]=0;
  func_00183d50(p);func_001757E0(p,21,19);
 }
}
