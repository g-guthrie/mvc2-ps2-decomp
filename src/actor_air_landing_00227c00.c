/* Advance the launch and landing phases while preserving the native cancellation paths. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef struct {u8 pad[0x38];float y;u8 pad3C[0x3F4];float ground;} PositionView;
extern int func_003D92F0(u8 *),func_00175700(u8 *),func_00174170(void),func_001757E0(u8 *,int,int);
extern void func_0022C5D0(u8 *),func_003589A0(u8 *,u8,float,float),func_00176160(u8 *,int,int,int),func_0022C6B0(u8 *),func_001E3210(u8 *,u8);
extern u8 D_004C0090[] __attribute__((section(".sdata")));
void func_00227C00(u8 *p)
{
 u8 type,phase;
 PositionView *position=(PositionView*)p;
 if((type=p[0x20])!=0){
  if(type==2 && func_003D92F0(p)){func_0022C5D0(p);return;}
  func_00175700(p);return;
 }
 if(*(int*)(p+0x2CC)!=3){
  if(func_003D92F0(p)){func_0022C5D0(p);return;}
  else{
   if(*(s8*)(p+0x151)){p[0x151]=0;func_003589A0(p,1,-34.0f,95.0f);}
   func_00175700(p);
  }
  return;
 }
 if((phase=p[7])==0){
  float speed;
  ++p[7];
  speed=5.0f;
  if(*(short*)(p+0x140))speed=-speed;
  *(float*)(p+0x5C)=speed;*(float*)(p+0x68)=0;
  *(float*)(p+0x60)=23.571428298950195f;*(float*)(p+0x6C)=-1.0044642686843872f;
 }else if(phase==1){
  *(float*)(p+0x34)+=*(float*)(p+0x5C);
  *(float*)(p+0x5C)+=*(float*)(p+0x68);
  position->y+=*(float*)(p+0x60);
  *(float*)(p+0x60)+=*(float*)(p+0x6C);
  if(position->y>position->ground)func_00175700(p);
  else{
   ++p[7];position->y=position->ground;
   func_00176160(p,0,p[2]+20,1);
   func_001757E0(p,19,D_004C0090[func_00174170()&7]);
   func_0022C6B0(p);func_001E3210(p,16);
  }
 }else{
  if(func_003D92F0(p))func_0022C5D0(p);
  else func_00175700(p);
 }
}
