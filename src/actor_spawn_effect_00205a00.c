/* Initialize the animation state and place a spawned effect using the native signed facing. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {u8 pad[0x5C];float vx,vy,vz,ax,ay;} Motion;
typedef struct {u8 pad[0x34];float x;} Position;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern u16 D_004B7118[];
extern void func_00185490(u8 *),func_0018C4B0(u8 *,int),func_00183D10(u8 *),func_001843A0(u8 *),func_00184540(u8 *);
extern int func_001757E0(u8 *,int,int),func_00175700(u8 *);
extern void *func_0034B070(void *,u8);
#define SET(action) do {p[0x1B5]=(action);p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;{u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}}while(0)
void func_00205A00(u8 *p)
{
 if(p[6]==0){
  ++p[6];func_00185490(p);func_0018C4B0(p,5);
  if(p[0x20D]!=2){p[0x20D]=0;func_00183D10(p);SET(48);func_001757E0(p,21,0);return;}
  else{
   Motion *motion=(Motion*)p;
   p[0x20D]=2;motion->vx=0;motion->vy=0;motion->ax=0;motion->ay=0;
   *(float*)(p+0x6C)=-0.8035714030265808f;
   SET(49);func_001757E0(p,21,1);
  }
 }else{
 if(*(s8*)(p+0x151)){
  Position *q;
  if((q=func_0034B070(p,0))!=0){
   u32 offset;
   p[0x151]=0;
   offset=D_004B7118[p[0x1B7]];
   q->x=1.6666666269302368f*offset;
   if(!*(s16*)(p+0x140))q->x=-q->x;
   q->x+=*(float*)(p+0x34);
  }
 }
 if(p[0x20D]!=2){if((s8)func_00175700(p)<0)func_001843A0(p);}
 else{if((s8)func_00175700(p)<0)func_00184540(p);}
 }
}
