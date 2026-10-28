#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef struct {float x,y,z;} V3;
#define F(o) (*(float*)(p+(o)))
#define OTHER (*(u8**)(p+0x1DC))
/* 3.0: ./try30.sh src/ns4_b.c "-O3,p -sdatathreshold 0" */
void func_002C4BC0(u8 *p)
{
 extern int func_00175700(u8*),func_00182E20(u8*),func_00182D30(u8*);
 extern void func_0018FDB0(u8*),func_001E3710(u8*,u8),func_00154790(V3 *,s32,u32,s32);
 extern void func_001757E0(u8*,s32,s32);
 V3 v;
 u8 *o;
 func_00175700(p);
 if(func_00182E20(p))p[0x152]=1;
 --*(s16*)(p+0x1C);
 if(p[0x15B]){
  if((*(s16*)(p+0x1E)==0&&func_00182D30(OTHER))||(*(s16*)(p+0x1C)<=0&&*(s16*)(p+0x1E)==0)){
   *(s16*)(p+0x1E)=1;++p[6];func_001757E0(p,15,7);return;
  }
 }else if(*(s8*)(p+0x151)&&(s8)*(s8*)(p+0x151)>0){
  p[0x151]=0;o=OTHER;o[0x1B5]=38;func_0018FDB0(p);
  if(o[0x1E6]==0)*(float*)(o+0x34)+=-53.33333206176758f;else *(float*)(o+0x34)+=53.33333206176758f;
  *(float*)(o+0x38)+=-171.4285583f;
  v.y=122.14285278320312f+F(0x38);
  if(*(s16*)(p+0x140))v.x=95.0f;else v.x=-95.0f;
  v.x+=F(0x34);v.z=F(0x3C);func_00154790(&v,*(s16*)(p+0x140),1,0);func_001E3710(p,0);
 }
}
