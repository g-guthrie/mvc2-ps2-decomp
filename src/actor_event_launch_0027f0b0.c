/* Initialize the action, handle the pending event, and place the scaled launch effect. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {float x,y,z;} V3;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern int func_001757E0(u8 *,int,int),func_00175700(u8 *),func_0027F270(u8 *);
extern void func_00280340(u8 *),func_00185770(u8 *,u8 *),func_00381F30(u8 *,V3 *,u8,u8);
void func_0027F0B0(u8 *p)
{
 V3 point;
 p[0x1FE]=1;
 if(p[7]==0){
  ++p[7];p[0x20D]=0;p[0x1B5]=61;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
  {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
  func_001757E0(p,19,3);return;
 }
 if((s8)func_00175700(p)<0){
  if((*(u8**)(p+0x220))[5]!=2){func_00280340(p);return;}
  ++p[6];p[7]=0;
 }else{
  s8 flags=*(s8*)(p+0x1B2);
  if(!(flags&8) && flags){
   p[0x1B2]=flags|8;
   if(func_0027F270(p)){p[0x20B]=192;func_00185770(p,*(u8**)(p+0x220));}
  }
 }
 if(*(s8*)(p+0x151)){
  p[0x151]=0;point=*(V3*)(p+0x34);
  if(*(s16*)(p+0x140))point.x+=320.0f * *(float*)(p+0x50);
  else point.x-=320.0f * *(float*)(p+0x50);
  point.y=*(float*)(p+0x430)-40.0f;
  func_00381F30(p,&point,4,1);
 }
}
