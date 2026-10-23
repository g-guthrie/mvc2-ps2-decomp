/* Launch using the selected native motion bank and supplied work context. */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
typedef struct {s32 vx,ax,vy,ay;} MotionLanes;
typedef struct {u8 pad[0x7C];s16 counters[];} SharedCounters;
extern SharedCounters *D_004C2794 __attribute__((section(".sdata")));
extern const MotionLanes *const D_004C10F8[] __attribute__((section(".sdata")));
extern int func_00175700(u8 *),func_003A4AC0(void *),func_001757E0(u8 *,int,int);
extern void func_001E3210(u8 *,int),func_0018C4B0(u8 *,int);
void func_002E6290(u8 *p,void *context)
{
 u8 *work=context;
 const MotionLanes *motion;
 if((s8)func_00175700(p)<0) {
  func_001E3210(p,21);
  if(p[0x20D]==2)*(float*)(p+0x38)+=85.7142791748046875f;
  func_003A4AC0(p);func_0018C4B0(p,5);
  motion=D_004C10F8[*(s8*)(work+5)];
  motion+=p[0x1B7];
  *(float*)(p+0x5C)=1.66666662693023681640625f*(float)motion->vx/65536.0f;
  *(float*)(p+0x68)=1.66666662693023681640625f*(float)motion->ax/65536.0f;
  *(float*)(p+0x60)=2.142857074737548828125f*(float)motion->vy/65536.0f;
  *(float*)(p+0x6C)=2.142857074737548828125f*(float)motion->ay/65536.0f;
  if(p[0x1E6]) {*(float*)(p+0x5C)=-*(float*)(p+0x5C);*(float*)(p+0x68)=-*(float*)(p+0x68);}
  p[0x1B5]=*(s8*)(p+0x1B7)+50;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(s32*)(p+0x1D8)=0;
  D_004C2794->counters[p[2]]++;
  *(u16*)(p+0x1C0)|=16;p[7]++;p[0x20D]=2;func_001757E0(p,21,6);
 }
}
