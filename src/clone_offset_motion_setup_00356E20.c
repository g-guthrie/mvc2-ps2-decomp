typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u8 prefix[0x1c];s16 timer,repeat;u8 kind,phase,frame,slot;s8 mode;u8 gap25[0xf];f32 x,y,z;u8 gap40[8];u32 angle;s16 originX,originY;f32 scaleX,scaleY,scaleZ,vx,vy,vz,ax,ay;u8 gap70[0xd0];s16 facing;} Motion;
extern int func_00174170(void);
extern int func_001757E0(u8 *,int,int);
#define OWNER(p) (*(u8 **)((p)+0x18))
#define LINK(p) (*(u8 **)((p)+0x14))
#define COPY_FIELDS(p) do {(p)[0x13c]=1;(p)[2]=OWNER(p)[2];(p)[1]=OWNER(p)[1];*(f32 *)((p)+0x50)=*(f32 *)(OWNER(p)+0x50);*(f32 *)((p)+0x54)=*(f32 *)(OWNER(p)+0x54);(p)[0x1b7]=OWNER(p)[0x1b7];(p)[0x1b8]=OWNER(p)[0x1b8];((s8 *)(p))[0x30]=((s8 *)OWNER(p))[0x30];*(V3 *)((p)+0x50)=*(V3 *)(OWNER(p)+0x50);((Motion *)(p))->mode=((Motion *)OWNER(p))->mode;}while(0)

extern s16 D_00462C60[][2];
void func_00356E20(u8 *p) {
 Motion *m=(Motion *)p;s32 count=49;s32 *destination,*source;f32 offset,newPosition,oldPosition,velocity;
 p[4]++;destination=(s32 *)(p+0xec);source=(s32 *)(OWNER(p)+0xec);
 do{*destination=*source;count--;source++;destination++;}while(count>0);
 COPY_FIELDS(p);
 p[0x13c]=1;m->mode=10;p[0x1b0]=0;p[0x1b1]=0;
 m->x=*(f32 *)(LINK(p)+0x34);m->y=*(f32 *)(LINK(p)+0x38);
 func_001757E0(p,21,(u8)((u32)func_00174170()%3+2));
 offset=1.6666666269302368f*D_00462C60[p[0x21]][0];if(m->facing)offset=-offset;
 oldPosition=m->x;newPosition=oldPosition+offset;velocity=(oldPosition-newPosition)/32.0f;
 m->x=newPosition;m->vx=velocity;m->ax=0;
 oldPosition=m->y;newPosition=oldPosition+2.142857074737549f*D_00462C60[p[0x21]][1];velocity=(oldPosition-newPosition)/32.0f;
 m->y=newPosition;m->vy=velocity;m->ay=0;m->timer=16;
}
