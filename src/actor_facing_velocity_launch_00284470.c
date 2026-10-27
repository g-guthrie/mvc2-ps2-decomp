/* Initialize facing-dependent launch velocity and opposing acceleration. */
#pragma padloop on
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {u8 pad[0x5C];float vx,vy,vz,ax,ay;} Motion;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *),func_00183D10(u8 *);
extern u8 *func_00383B80(void *, u8, u8);
extern int func_001757E0(u8 *,int,int);
void func_00284470(u8 *p)
{
 Motion *motion=(Motion*)p;
 if(p[0x269]==6){p[0x404]=255;p[0x405]=16;}
 ++p[6];p[0x1B5]=75;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 func_00185490(p);p[0x20D]=0;*(float*)(p+0x38)=*(float*)(p+0x430);
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 motion->vx=p[0x1E6]?10.0f:-10.0f;
 motion->ax=p[0x1E6]?-0.4166666567325592f:0.4166666567325592f;
 motion->vy=23.571428298950195f;motion->ay=-0.4017857015132904f;
 func_00183D10(p);func_00383B80(p,4,2);func_001757E0(p,22,9);
}
