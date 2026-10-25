#pragma padloop on
typedef unsigned char u8;typedef signed char s8;typedef short s16;typedef unsigned short u16;
typedef struct {float x,y,z;} V3;
typedef struct {float x,y,vx,vy;u16 tag,pad12;int count;u8 pad18[4];u8 phase;} Work;
typedef struct {u8 pad[0x34];float x,y,z;u8 pad40[0x1C];float vx,vy,vz,ax,ay;} Motion;
extern int D_004493C0[];
extern s16 D_00449320[],D_00449322[],D_00449360[],D_00449362[],D_00449364[];
extern int func_001754A0(u8*,int,int);
extern void func_00176160(u8*,int,int,int);
void func_00193500(u8*p,u8*owner) {
 Work *work=(Work*)(p+0x88);Motion *motion=(Motion*)p,*parent=(Motion*)owner;int count;int *dst,*src;
 p[4]++;
 src=(int*)(owner+0xEC);dst=(int*)(p+0xEC);
 for(count=49;count>0;--count)*dst++=*src++;
 p[0x13C]=1;p[2]=owner[2];p[1]=owner[1];
 *(float*)(p+0x50)=*(float*)(owner+0x50);*(float*)(p+0x54)=*(float*)(owner+0x54);
 p[0x1B7]=owner[0x1B7];p[0x1B8]=owner[0x1B8];p[0x30]=*(s8*)(owner+0x30);
 *(V3*)(p+0x50)=*(V3*)(owner+0x50);p[0x24]=*(s8*)(owner+0x24);
 work->tag=*(u16*)(owner+0x168);work->phase=3;
 *(s16*)(p+0x1C)=4;*(s16*)(p+0x1E)=8;*(s8*)(p+0x31)=-2;p[0x168]=9;
 func_001754A0(p,27,p[0x168]);
 if(p[0x21]==0)func_00176160(owner,2,D_004493C0[owner[0x25]],1);
 motion->x=parent->x;work->x=0.0f;
 motion->y=parent->y;work->y=0.0f;
 motion->ax=0.0f;motion->ay=0.0f;
 work->vx=1.6666666269302368f*D_00449320[p[0x21]*2]/256.0f;
 work->vy=2.1428570747375488f*D_00449322[p[0x21]*2]/256.0f;
 motion->vx=1.6666666269302368f*D_00449360[p[0x21]*3]/256.0f;
 motion->vy=2.1428570747375488f*D_00449362[p[0x21]*3]/256.0f;
 work->count=D_00449364[p[0x21]*3];
 if(*(s16*)(p+0x140)==0){work->vx=-work->vx;motion->vx=-motion->vx;}
 work->x+=motion->vx;work->y+=motion->vy;
 motion->x=work->x+parent->x;motion->y=work->y+parent->y;
}
