/* Ground the captured target, apply the hit offset, and release on timeout. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
extern int func_00175700(u8 *);
extern void func_001549B0(u8 *,float *),func_001E3B70(u8 *,unsigned int),func_0018FDB0(u8 *),func_001843A0(u8 *);
extern int func_00182E20(u8 *),func_00182D30(u8 *);
void func_002FB6C0(u8 *p)
{
 u8 *target=*(u8**)(p+0x1DC);
 float offset[4];
 func_00175700(p);
 *(float*)(target+0x38)=*(float*)(target+0x430);
 if(func_00182E20(p))p[0x152]=1;
 if(func_00182D30(*(u8**)(p+0x1DC))) *(s16*)(p+0x1C)=0;
 if(*(s8*)(p+0x151)) {
  p[0x151]=0;
  offset[0]=-43.333332061767578125f;offset[1]=27.8571414947509765625f;
  func_001549B0(p,offset);func_001E3B70(target,2);
  *(u8**)(target+0x1C8)=p;target[0x1B5]=32;p[0x1B5]=32;
  target[0x1E6]=p[0x1E6];target[0x1E6]^=1;
  func_0018FDB0(p);p[0x1B4]=8;
 }
 if((*(s16*)(p+0x1C))-- == 0) {
  *(u8**)(target+0x1C8)=p;target[0x1B5]=32;p[0x1B5]=32;target[0x20A]=1;
  target[0x1E6]=p[0x1E6];target[0x1E6]^=1;
  func_001843A0(p);
 }
}
