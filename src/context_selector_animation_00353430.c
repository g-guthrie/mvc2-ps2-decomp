typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u8 prefix[0x14];u8 *link,*owner;s16 timer,repeat;u8 kind,phase,frame,slot;s8 mode;u8 gap25[0xf];f32 x,y,z;u8 gap40[8];u32 angle;s16 originX,originY;f32 scaleX,scaleY,scaleZ,vx,vy,vz,ax,ay;u8 gap70[0xa8];f32 intensity;u8 gap11c[0x20];s8 active;u8 gap13d[3];s16 facing;u8 gap142[0xf];s8 animPhase;} Motion;
extern int func_00174170(void);
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *,int,int);
extern void func_001E7F60(u8 *);
extern void func_001E3710(u8 *,int);
extern void func_001E3210(u8 *,int);
#define OWNER(p) (*(u8 **)((p)+0x18))
#define LINK(p) (*(u8 **)((p)+0x14))
#define COPY_FIELDS(p) do {(p)[0x13c]=1;(p)[2]=OWNER(p)[2];(p)[1]=OWNER(p)[1];*(f32 *)((p)+0x50)=*(f32 *)(OWNER(p)+0x50);*(f32 *)((p)+0x54)=*(f32 *)(OWNER(p)+0x54);(p)[0x1b7]=OWNER(p)[0x1b7];(p)[0x1b8]=OWNER(p)[0x1b8];((s8 *)(p))[0x30]=((s8 *)OWNER(p))[0x30];*(V3 *)((p)+0x50)=*(V3 *)(OWNER(p)+0x50);((Motion *)(p))->mode=((Motion *)OWNER(p))->mode;}while(0)

extern u8 D_004629D0[],D_00462970[],D_00462A30[];
extern s16 D_00462930[],D_00462932[];
extern int func_00175910(u8 *,s32,s32,s32);
void func_00353430(u8 *p,u8 *context) {
 u8 *record,*table;u8 selector;f32 dx,dy;
 if(p[0x20]){
  record=*(u8 **)(context+0xc)+0x88;
  if(context[3]&&record[0]==0x40)goto special;
  selector=record[0];table=D_004629D0;
 }else{selector=context[0];table=D_00462970;}
 table+=selector;
 if(selector!=0x40)func_00175910(p,21,8,table[p[0x22]]);else func_00175910(p,21,8,table[p[0x22]*2]);
 return;
special:
   func_00175910(p,21,8,D_00462A30[p[0x22]]);
   if(record[0xb]){
    record[0x28]=p[0x22];dx=1.66666663f*D_00462930[p[0x22]*2];dy=2.14285707f*D_00462932[p[0x22]*2];
    if(*(s16 *)(p+0x140))dx=-dx;
    *(f32 *)(record+0x1c)=*(f32 *)(p+0x34)+dx;*(f32 *)(record+0x20)=*(f32 *)(p+0x38)-dy;
   }

}
