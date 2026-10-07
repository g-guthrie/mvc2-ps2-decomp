/* Exit when the global mode advances; otherwise drift the object upward. */
typedef unsigned char u8;
extern u8 *D_004C2840;
void func_0013B140(u8 *p) {
 if (*(signed char *)(D_004C2840+3)>1 || *(signed char *)(D_004C2840+4)>=2) {
  ++p[4];p[0x13c]=0;
 } else {
  *(int *)(p+0x44)-=256;
  *(float *)(p+0x38)+=1.0f;
 }
}
