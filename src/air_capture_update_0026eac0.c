/* Update airborne motion, land, and apply the captured target transition. */
typedef unsigned char u8;
typedef signed char s8;
extern int func_00175700(u8 *);
extern void func_00183D50(u8 *),func_0018FDB0(u8 *),func_001548D0(u8 *,float *,int),func_001E3B70(u8 *,unsigned int),func_001E3710(u8 *,unsigned int);
void func_0026EAC0(u8 *p)
{
 float offset[4];
 if(p[0x20D]==2) {
  *(float*)(p+0x34)+=*(float*)(p+0x5C);
  *(float*)(p+0x5C)+=*(float*)(p+0x68);
  *(float*)(p+0x38)+=*(float*)(p+0x60);
  *(float*)(p+0x60)+=*(float*)(p+0x6C);
  if(*(float*)(p+0x38)<*(float*)(p+0x430)) {func_00183D50(p);*(float*)(p+0x38)=*(float*)(p+0x430);p[0x20D]=0;}
 }
 func_00175700(p);
 if(*(s8*)(p+0x150)) {
  p[0x150]=0;p[0x151]=0;
  *(u8**)(*(u8**)(p+0x1DC)+0x1C8)=p;
  (*(u8**)(p+0x1DC))[0x1B5]=32;
  func_0018FDB0(p);
  offset[0]=-213.3333282470703125f;offset[1]=171.428558349609375f;offset[2]=0;
  func_001548D0(p,offset,0);func_001E3B70(*(u8**)(p+0x1DC),1);func_001E3710(p,11);
  return;
 }
 if(*(s8*)(p+0x151)) {
  u8 *target;
  p[6]++;p[0x151]=0;target=*(u8**)(p+0x1DC);
  *(u8**)(target+0x1C8)=p;target[0x20A]=1;target[0x1B5]=33;
 }
}
