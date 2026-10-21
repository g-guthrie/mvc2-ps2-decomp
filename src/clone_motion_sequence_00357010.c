#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u8 prefix[0x34];f32 x,y,z;u8 gap40[8];u32 angle;s16 originX,originY;f32 scaleX,scaleY,scaleZ,vx,vy,vz,ax,ay;} Motion;
extern int func_001757E0(u8 *,int,int);
extern int func_00174170(void);
#define OWNER(p) (*(u8 **)((p)+0x18))
#define LINK(p) (*(u8 **)((p)+0x14))
#define COPY_FIELDS(p) do { (p)[0x13c]=1;(p)[2]=OWNER(p)[2];(p)[1]=OWNER(p)[1];*(f32 *)((p)+0x50)=*(f32 *)(OWNER(p)+0x50);*(f32 *)((p)+0x54)=*(f32 *)(OWNER(p)+0x54);(p)[0x1b7]=OWNER(p)[0x1b7];(p)[0x1b8]=OWNER(p)[0x1b8];((s8 *)(p))[0x30]=((s8 *)OWNER(p))[0x30];*(V3 *)((p)+0x50)=*(V3 *)(OWNER(p)+0x50);((s8 *)(p))[0x24]=((s8 *)OWNER(p))[0x24];}while(0)

extern s16 D_00462CA0[][2];
extern f32 D_00462CC0[][4];
void func_00357010(u8 *p) {
 u8 *owner=OWNER(p);Motion *m=(Motion *)p;s32 count=49;s32 *d,*s;f32 x,ax,vx,extra;
 p[4]++;d=(s32 *)(p+0xec);s=(s32 *)(OWNER(p)+0xec);
 do{*d=*s;count--;s++;d++;}while(count>0);
 COPY_FIELDS(p);
 p[0x13c]=1;if(p[0x21]&1)p[0x13c]=0;
 p[0x24]=10;p[0x1b0]=0;p[0x1b1]=0;
 m->x=*(f32 *)(LINK(p)+0x34);m->y=*(f32 *)(LINK(p)+0x38);
 func_001757E0(p,21,(u8)((u32)func_00174170()%3+2));
 *(s16 *)(p+0x1c)=30;
 x=1.6666666269302368f*D_00462CA0[p[0x21]][0];if(*(s16 *)(p+0x140))x=-x;
 m->x+=x;m->y+=2.142857074737549f*D_00462CA0[p[0x21]][1];
 vx=D_00462CC0[p[0x21]][0];ax=D_00462CC0[p[0x21]][1];
 if(*(s16 *)(p+0x140)){vx=-vx;ax=-ax;}
 m->vx=vx;m->ax=ax;m->vy=D_00462CC0[p[0x21]][2];m->ay=D_00462CC0[p[0x21]][3];
 if(p[7]==0){extra=6.666666507720947f;if(owner[0x1e6])extra=-extra;m->vx+=extra;}
}
