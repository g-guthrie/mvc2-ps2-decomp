/* Native owner-dependent landing and launch states. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
extern int func_00175700(u8 *),func_001757E0(u8 *,int,int);
extern void func_001E7F60(u8 *),func_001E3210(u8 *,int),func_0035DEF0(u8 *,u8,u8),func_0035E730(u8 *,void *);
extern float D_004F1FCC,D_004F1FC8,D_004F1FD0;
extern void func_0015E630(u8 *),func_001C5AD0(u8 *,u8 *);
void func_0035E3D0(u8 *p,void *owner_context)
{
 u8 *owner=owner_context;
 *(float*)(p+0x38)+=*(float*)(p+0x60);
 *(float*)(p+0x60)+=*(float*)(p+0x6C);
 func_00175700(p);func_001E7F60(p);
 if(!(*(float*)(owner+0x430)<*(float*)(p+0x38))) {
  *(float*)(p+0x38)=*(float*)(owner+0x430);
  if(!(p[0x21]&15))func_001E3210(p,30);
  func_0035DEF0(p,2,0);
  p[4]++;func_0035E730(p,owner);
 }
}

void func_0035E690(u8 *p,void *owner_context)
{
 u8 *owner=owner_context;
 *(float*)(p+0x34)+=*(float*)(p+0x5C);
 *(float*)(p+0x5C)+=*(float*)(p+0x68);
 *(float*)(p+0x38)+=*(float*)(p+0x60);
 *(float*)(p+0x60)+=*(float*)(p+0x6C);
 func_00175700(p);
 if(!(*(float*)(owner+0x430)<*(float*)(p+0x38))) {
  p[4]++;func_0035E730(p,owner);
 }
}

void func_001C59D0(u8 *p,u8 *owner)
{
 p[7]++;p[0x14C]=16;p[0x14D]=16;p[0x14E]=16;p[0x14F]=16;
 *(s16*)(p+0x1C)=16;
 if((*(s16*)(p+0x140)=*(s16*)(owner+0x140))==0) {
  *(float*)(p+0x34)=80.0f+D_004F1FCC;
  *(float*)(p+0x5C)=-6.666666507720947265625f;
 } else {
  *(float*)(p+0x34)=D_004F1FC8-80.0f;
  *(float*)(p+0x5C)=6.666666507720947265625f;
 }
 *(float*)(p+0x38)=D_004F1FD0-205.7142791748046875f;
 *(float*)(p+0x68)=0;*(float*)(p+0x60)=0;*(float*)(p+0x6C)=0;
 func_001757E0(p,25,19);
 p[0]=1;func_0015E630(p);
 func_001C5AD0(p,owner);
}
