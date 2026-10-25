/* Initialize the airborne event from local work and integrate the actor motion. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {u8 prefix[0x1B5];u8 action;} ActionView;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_001861B0(u8 *),func_0018C4B0(u8 *,int),func_00183D90(u8 *),func_001863F0(u8 *),func_001E3710(u8 *,u8),func_001843A0(u8 *);
extern int func_001757E0(u8 *,int,int),func_00175700(u8 *);
void func_0022DE70(u8 *p)
{
 u8 *work=p+0x2B8;
 if(p[6]==0){
  func_001861B0(p);++p[6];func_0018C4B0(p,5);
  if(p[0x212]==0){
   p[0x20D]=1;
   if(work[14]){p[0x1B5]=87;func_001757E0(p,20,7);}
   else {p[0x1B5]=88;func_001757E0(p,20,8);}
   func_001E3710(p,22);
   ((ActionView*)p)->action=p[0x1B5];
   p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
   {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
  }
 }
 if(p[0x213]==3)func_00183D90(p);
 *(float*)(p+0x34)+=*(float*)(p+0x5C);
 *(float*)(p+0x5C)+=*(float*)(p+0x68);
 *(float*)(p+0x38)+=*(float*)(p+0x60);
 *(float*)(p+0x60)+=*(float*)(p+0x6C);
 func_001863F0(p);
 if((s8)func_00175700(p)<0)func_001843A0(p);
}
