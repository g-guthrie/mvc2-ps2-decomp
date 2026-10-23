/* Flight, capture, and landing branches share the actor-local context. */
typedef unsigned char u8;
typedef signed char s8;
extern int func_00175700(u8 *),func_001757E0(u8 *,int,int),func_00185980(u8 *);
extern int func_00175910(u8 *,int,int,int);
extern void func_00185490(u8 *),func_001266A0(u8 *,int,int);
void func_002DF5E0(u8 *p,u8 *state)
{
 float *vx=(float*)(p+0x5C);
 float *vy=(float*)(p+0x60);
 float *ax=(float*)(p+0x68);
 float *ay=(float*)(p+0x6C);
 p[0x40C]=2;p[0x33C]=5;p[0x209]=2;
 *(float*)(p+0x34)+=*(float*)(p+0x5C);
 *(float*)(p+0x5C)+=*(float*)(p+0x68);
 *(float*)(p+0x38)+=*(float*)(p+0x60);
 *(float*)(p+0x60)+=*(float*)(p+0x6C);
 func_00175700(p);
 if(*(s8*)(p+0x151)) {
  p[0x151]=0;p[0x20D]=2;
  *(float*)(p+0x5C)=-10.0f;
  if(p[0x1E6])*(float*)(p+0x5C)=-*(float*)(p+0x5C);
  *(float*)(p+0x68)=0;
  *(float*)(p+0x60)=21.428569793701171875f;
  *(float*)(p+0x6C)=-1.3392856121063232421875f;
 }
 if(*(s8*)(p+0x1B2)) {
  if(!func_00185980(p)) {
   p[0x40D]=0;p[0x40C]=0;p[0x33B]=0;p[0x33C]=0;
   p[6]++;p[7]=1;
   *(float*)(p+0x5C)=3.3333332538604736328125f;
   if(p[0x1E6])*(float*)(p+0x5C)=-*(float*)(p+0x5C);
   *(float*)(p+0x68)=0;
   *(float*)(p+0x60)=6.428571224212646484375f;
   *(float*)(p+0x6C)=-0.803571403026580810546875f;
   p[0x20D]=2;
   func_00175910(p,1,2,13);return;
  } else {
   u8 *target;
   float offset;
   s8 side;
   p[7]++;*vx=0;*vy=0;*ax=0;*ay=0;
   func_00185490(p);
   target=*(u8**)(p+0x1C4);
   offset=-80.0f;
   target[0x20D]=0;p[0x20D]=0;
   *(float*)(p+0x38)=*(float*)(target+0x38)=*(float*)(p+0x430);
   *(float*)(target+0x34)=*(float*)(p+0x34);
   *(float*)(p+0x5C)=-0.20833332836627960205078125f;
   if(p[0x1E6]) {offset=-offset;*(float*)(p+0x5C)=-*(float*)(p+0x5C);}
   *(float*)(target+0x34)+=offset;
   *(u8**)(state+8)=target;
   side=p[2]?3:4;
   func_001266A0(p,side,side);
   func_001757E0(p,22,13);
  }
 } else if(34.28571319580078125f+*(float*)(p+0x38)<*(float*)(p+0x430)) {
  p[0x40D]=0;p[0x40C]=0;p[0x33B]=0;p[0x33C]=0;
  p[6]++;p[7]=2;p[0x20D]=0;
  *(float*)(p+0x38)=*(float*)(p+0x430);
  *vx=0;*vy=0;*ax=0;*ay=0;
  func_001757E0(p,22,15);
 }
}
