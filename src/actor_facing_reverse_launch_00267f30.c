/* Reverse facing, initialize the action, and launch with the updated facing. */
#pragma padloop on
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {u8 pad[0x5C];float vx,vy,vz,ax,ay;} Motion;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *),func_0018C4B0(u8 *,int),func_001266A0(u8 *,int,int);
extern int func_001757E0(u8 *,int,int);
void func_00267F30(u8 *p)
{
 Motion *motion=(Motion*)p;
 ++p[6];func_00185490(p);*(s16*)(p+0x140)^=1;func_0018C4B0(p,5);
 p[0x20D]=0;*(float*)(p+0x38)=*(float*)(p+0x430);
 p[0x1B5]=73;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 func_001757E0(p,0,2);
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 motion->vx=*(s16*)(p+0x140)?12.5f:-12.5f;motion->vy=13.928570747375488f;
 func_001266A0(p,1,7);
}
