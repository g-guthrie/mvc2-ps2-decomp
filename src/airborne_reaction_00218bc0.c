typedef unsigned char u8;
typedef signed char s8;
extern void func_00185490(u8 *),func_001820A0(u8 *);
extern int func_001757E0(u8 *,int,int),func_00175700(u8 *);
void func_00218BC0(u8 *p)
{
 u8 *state=p+0x2B8;
 *(float*)(p+0x34)+=*(float*)(p+0x5C);
 *(float*)(p+0x5C)+=*(float*)(p+0x68);
 *(float*)(p+0x38)+=*(float*)(p+0x60);
 *(float*)(p+0x60)+=*(float*)(p+0x6C);
 if(*(s8*)(p+0x1B2)) {
  p[6]++;p[7]=0;
  *(float*)(p+0x60)=18.2142848968505859375f;
  *(float*)(p+0x6C)=-0.803571403026580810546875f;
  *(float*)(p+0x5C)/=8.0f;
  if(*(s8*)(p+0x1B2)&1)*(float*)(p+0x5C)/=8.0f;
  *(float*)(p+0x5C)=-*(float*)(p+0x5C);
  p[0x20D]=2;func_00185490(p);
  if(p[0x286]!=state[2]) {p[6]++;func_001757E0(p,1,9);}
  else func_001757E0(p,21,19);
  return;
 }
 {
  int input=*(s8*)(p+0x211);
  if(input&&!(input&(1<<p[0x1E6]))) {
   u8 animation=p[0x22];
   if(animation&&animation!=4) {p[7]=2;func_001757E0(p,21,20);return;}
  }
 }
 if(*(float*)(p+0x38)<*(float*)(p+0x430)) {
  p[7]=1;*(float*)(p+0x38)=*(float*)(p+0x430);func_00185490(p);
  p[0x20D]=1;func_001757E0(p,21,21);
 } else {
  int finished=(s8)func_00175700(p)<0;
  if(finished) {
   p[6]++;p[7]=0;
   *(float*)(p+0x6C)=-0.803571403026580810546875f;
   p[0x20D]=2;state[0]=1;func_001820A0(p);
   func_001757E0(p,21,(u8)(p[0x168]+1));
  }
 }
}
