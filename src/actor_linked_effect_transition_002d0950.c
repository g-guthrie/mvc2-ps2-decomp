#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef struct {float x,y,z;} V3;
extern int func_00175700(u8*),func_00182E20(u8*),func_00182D30(u8*);
extern void func_002D0890(u8*),func_0018FDB0(u8*),func_001E3710(u8*,u8),func_00154790(s32,s32,u32,s32);
#define F(o) (*(float*)(p+(o)))
#define OTHER (*(u8**)(p+0x1DC))
void func_002D0950(u8 *p)
{
 V3 first,second;
 func_00175700(p);
 if(--*(s16*)(p+0x1C)<=0){
  func_002D0890(p);++p[6];first.y=122.14285278320312f+F(0x38);
  if(*(s16*)(p+0x140))first.x=95.0f;else first.x=-95.0f;
  first.x+=F(0x34);first.z=F(0x3C);func_00154790((s32)&first,*(s16*)(p+0x140),1,0);func_001E3710(p,0);return;
 }
 if(func_00182E20(p))p[0x152]=1;
 if(func_00182D30(OTHER)){func_002D0890(p);++p[6];}
 else if(*(s8*)(p+0x151)){
  p[0x151]=0;*(u8**)(OTHER+0x1C8)=p;OTHER[0x1B5]=33;func_0018FDB0(p);
  second.y=122.14285278320312f+F(0x38);
  if(*(s16*)(p+0x140))second.x=95.0f;else second.x=-95.0f;
  second.x+=F(0x34);second.z=F(0x3C);func_00154790((s32)&second,*(s16*)(p+0x140),1,0);func_001E3710(p,0);
 }
}
