#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef float f32;
typedef struct {u8 prefix[0x34];f32 x,y,z;u8 gap40[0x10];f32 scaleX,scaleY;} ActorPosition;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern int func_00174470(u8 *);
extern void func_001E7F60(u8 *);
extern int func_00175700(u8 *);
void func_003474C0(u8 *p) {
 ActorPosition *position=(ActorPosition *)p;
 if((*(u8 **)(p+0x18))[0x1e4]!=29) {p[4]=3;return;}
 if(!func_00174470(p)) {p[4]=3;return;}
 position->x=*(f32 *)(*(u8 **)(p+0x18)+0x34);
 if(*(s16 *)(p+0x140)==0)position->x-=120.0f;
 else position->x+=120.0f;
 position->y=*(f32 *)(*(u8 **)(p+0x18)+0x38);
 position->y+=120.0f;
 position->z=*(f32 *)(*(u8 **)(p+0x18)+0x3c);
 if(position->scaleX<1.0f) {
  position->scaleX+=0.03999999910593033f;
  position->scaleY+=0.03999999910593033f;
 }else {position->scaleX=1;position->scaleY=1;}
 ++*(s16 *)(p+0x1e);
 if(*(s16 *)(p+0x1e)==6) {
  p[0x21]--;
  if(p[0x21]==0) {
   p[0x1b5]=65;p[0x1b2]=*(u16 *)(p+0x1c0)=0;*(u32 *)(p+0x1d8)=0;
   {u32 address=p[2]*2;address+=(u32)D_004C2794;address+=0x7c;++*(s16 *)address;}
   p[4]+=2;*(s16 *)(p+0x1c)=2;
  }else {
   if((p[0x21]&3)==0) {
    p[0x1b5]=59;p[0x1b2]=*(u16 *)(p+0x1c0)=0;*(u32 *)(p+0x1d8)=0;
    {u32 address=p[2]*2;address+=(u32)D_004C2794;address+=0x7c;++*(s16 *)address;}
   }else {
    p[0x1b5]=80;p[0x1b2]=*(u16 *)(p+0x1c0)=0;*(u32 *)(p+0x1d8)=0;
    {u32 address=p[2]*2;address+=(u32)D_004C2794;address+=0x7c;++*(s16 *)address;}
   }
   if(!(*(f32 *)(*(u8 **)(p+0x18)+0x34)<=position->x)) {
    if(*(f32 *)(*(u8 **)(*(u8 **)(p+0x18)+0x220)+0x34)<=position->x)*(s16 *)(p+0x1c0)=16;
   }else {
    if(!(*(f32 *)(*(u8 **)(*(u8 **)(p+0x18)+0x220)+0x34)<position->x))*(s16 *)(p+0x1c0)=16;
   }
  }
  *(s16 *)(p+0x1e)=0;
 }
 if(--*(s16 *)(p+0x1c)==0) {p[4]++;*(f32 *)(p+0x118)=1.0f;}
 else {func_001E7F60(p);func_00175700(p);}
}
