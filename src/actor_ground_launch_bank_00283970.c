/* Initialize ground movement and the facing-dependent horizontal velocity. */
#pragma padloop on
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {u8 pad[0x5C];float vx,vy,vz,ax,ay;} Motion;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern float D_00455AF0[][2],D_00455AF4[][2];
extern void func_0018C4B0(u8 *,int),func_00185490(u8 *),func_00183D10(u8 *);
extern u8 *func_00383B80(void *, u8, u8);
extern int func_001757E0(u8 *,int,int);
void func_00283970(u8 *p)
{
 Motion *motion=(Motion*)p;
 float vx;
 ++p[6];p[0x1B5]=p[0x1B7]?59:57;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 func_0018C4B0(p,12);func_00185490(p);p[0x20D]=0;*(float*)(p+0x38)=*(float*)(p+0x430);
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 *(s16*)(p+0x1E)=0;
 if(p[0x1E6])vx=D_00455AF0[p[0x1B7]][0];else vx=-D_00455AF0[p[0x1B7]][0];
 motion->vx=vx;motion->vy=D_00455AF4[p[0x1B7]][0];motion->ay=-2.142857074737549f;
 func_00183D10(p);func_00383B80(p,4,1);
 p[0x168]=p[0x1B7]?6:4;func_001757E0(p,21,p[0x168]);
}
