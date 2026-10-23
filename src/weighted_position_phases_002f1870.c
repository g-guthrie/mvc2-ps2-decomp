/* Jump, weighted position adjustment, capture, and landing phases. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef struct {float x,y,z;} Vec3;
extern u8 D_004F1F45,D_004F1F46;
extern const u16 D_004C11C0[] __attribute__((section(".sdata")));
extern int func_00175700(u8 *),func_001757E0(u8 *,int,int);
extern void func_00179160(void *,void *),func_00178F20(u8 *,u8 *),func_00158C70(u8 *,int),func_001E3A40(u8 *),func_00183D50(u8 *),func_00126400(void),func_002F1DF0(s32 *);
void func_002F1870(u8 *p)
{
 u8 *target;
 float oldY,oldX;
 Vec3 position;
 if(p[6]<=1) {
  if(p[6]!=1) {

  func_00175700(p);
  if(*(s8*)(p+0x150)) {
   p[6]++;p[0x150]=0;
   { float vx=6.666666507720947265625f;
   if(*(s16*)(p+0x140))vx=-vx;
   *(float*)(p+0x5C)=vx;*(float*)(p+0x68)=0;
   *(float*)(p+0x60)=34.28571319580078125f;
   *(float*)(p+0x6C)=-1.60714280605316162109375f;
   }
  }
  if(*(s8*)(p+0x151)<0) {
   oldX=*(float*)(p+0x34);oldY=*(float*)(p+0x38);
   func_00179160(p,*(u8**)(p+0x1DC));
   { float weightedX=3.0f*oldX;
     float numeratorX=*(float*)(p+0x34)+weightedX;
     float weightedY=3.0f*oldY;
     *(float*)(p+0x34)=numeratorX/4.0f;
     *(float*)(p+0x38)=(*(float*)(p+0x38)+weightedY)/4.0f;
   }
  }
  return;
  } else {

  if(*(s8*)(p+0x150)>=0)func_00175700(p);
  {
   float *vx,*vy,*ax,*ay;
   vx=(float*)(p+0x5C);ax=(float*)(p+0x68);vy=(float*)(p+0x60);ay=(float*)(p+0x6C);
   *(float*)(p+0x34)+=*(float*)(p+0x5C);
   *(float*)(p+0x5C)+=*(float*)(p+0x68);
   *(float*)(p+0x38)+=*(float*)(p+0x60);
   *(float*)(p+0x60)+=*(float*)(p+0x6C);
   target=*(u8**)(p+0x1DC);
   if(*(float*)(p+0x38)<*(float*)(p+0x430)) {
    *(float*)(p+0x38)=*(float*)(p+0x430);
    *vx=0;*vy=0;*ax=0;*ay=0;p[0x150]=0;p[0x152]=1;
    func_00175700(p);func_00178F20(p,target);
    position=*(Vec3*)(target+0x34);position.y=*(float*)(target+0x430);
    func_00158C70((u8*)&position,target[2]);func_001E3A40(p);
    D_004F1F45=3;D_004F1F46=1;func_00183D50(p);
   }
  }
  if(*(s8*)(p+0x151)<0) {
   p[6]++;p[0x151]=0;
   *(u16*)(p+0x1C0)=D_004C11C0[*(s32*)(p+0x2D4)];
   *(u8**)(target+0x1C8)=p;target[0x20A]=1;
   *(s8*)(target+0x1E6)=*(s8*)(p+0x1E6)^1;target[0x1B5]=33;
   func_00126400();
   *(s16*)(p+0x140)^=1;
   { float vx=2.5f;
   if(*(s16*)(p+0x140))vx=-vx;
   *(float*)(p+0x5C)=vx;*(float*)(p+0x68)=0;
   *(float*)(p+0x60)=17.142856597900390625f;
   *(float*)(p+0x6C)=-0.803571403026580810546875f;
   func_001757E0(p,1,11);
   }
  }
  }
 } else {

  func_00175700(p);
  *(float*)(p+0x34)+=*(float*)(p+0x5C);
  *(float*)(p+0x5C)+=*(float*)(p+0x68);
  *(float*)(p+0x38)+=*(float*)(p+0x60);
  *(float*)(p+0x60)+=*(float*)(p+0x6C);
  if(*(float*)(p+0x38)<*(float*)(p+0x430)) {
   *(float*)(p+0x38)=*(float*)(p+0x430);func_00183D50(p);func_002F1DF0((s32*)p);
  }
 }
}
