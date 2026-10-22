typedef unsigned char u8;
typedef signed short s16;
/* Strict/unordered comparisons retain native NaN behavior. */
void func_0028B200(u8 *p)
{
 u8 *other=*(u8**)(p+0x220);
 u8 *aux=p+0x2B8;
 float dx=*(float*)(other+0x34)-*(float*)(p+0x34);
 if(dx< -160.0f || !(dx<=160.0f)) {
  p[7]=7;aux[0x18]=0;
 } else if(!(*(float*)(other+0x38)<68.5714263916015625f+*(float*)(p+0x38))) {
  p[7]=4;aux[0x18]=0;
 } else if(p[7]!=1) {
  p[7]=1;aux[0x18]=0;
 }
}

void func_00292570(u8 *p)
{
 u8 *other=*(u8**)(p+0x220);
 u8 *aux=p+0x2B8;
 float dx=*(float*)(other+0x34)-*(float*)(p+0x34);
 if(dx< -160.0f || !(dx<=160.0f)) {
  p[7]=7;aux[0x18]=0;
 } else if(!(*(float*)(other+0x38)<68.5714263916015625f+*(float*)(p+0x38))) {
  p[7]=4;aux[0x18]=0;
 } else if(p[7]!=1) {
  p[7]=1;aux[0x18]=0;
 }
}
