typedef unsigned char u8;
typedef short s16;
extern int func_001E1B70(u8*,u8*),func_00175670(u8*),func_001754A0(u8*,int,int);
void func_001E1930(u8 *p,u8 *q) {
 if(--*(s16*)(p+0x1E)>0) {p[0x13C]=0;return;}
 p[0x13C]=1;
 if(func_001E1B70(p,q))return;
 func_00175670(p);p[0x159]=0;
 {float *vx=(float*)(p+0x5C),*ax=(float*)(p+0x68);
 *(float*)(p+0x34)+=*(float*)(p+0x5C);*(float*)(p+0x5C)+=*(float*)(p+0x68);
 if(*(s16*)(p+0x1C)>0) {
  float offset=*(float*)(p+0x64);
  if(*(s16*)(q+0x140))offset=-offset;
  offset+=*(float*)(q+0x34);offset-=*(float*)(p+0x34);
  if(offset * *(float*)(p+0x5C)<0) {
   *(s16*)(p+0x1C)=0;goto finish;
  }
 }
 if(--*(s16*)(p+0x1C)!=0)return;
finish:
 ++p[5];*(s16*)(p+0x13E)-=6;*vx=0;*ax=0;func_001754A0(p,27,16);
 }
}
