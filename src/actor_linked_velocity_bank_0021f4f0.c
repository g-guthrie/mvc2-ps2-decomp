/* Initialize the linked action and mode-dependent horizontal and vertical motion. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {u8 pad[0x5C];float vx,vy,vz,ax,ay;} Motion;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern u8 D_004B7130[][2];
extern float D_004B7140[][4],D_004B7144[][4],D_004B7148[][4],D_004B714C[][4];
extern void func_00185490(u8 *),func_00183D10(u8 *),func_0018C4B0(u8 *,int),func_00186A20(u8 *),func_0021F6F0(u8 *);
extern int func_001757E0(u8 *,int,int);
#define SET(action) do{p[0x1B5]=(action);p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;{u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}}while(0)
void func_0021F4F0(u8 *p)
{
 u8 *work=p+0x2B8;
 Motion *motion=(Motion*)p;
 ++p[6];*(s16*)(p+0x366)=0;
 if(p[0x20D]!=2){func_00185490(p);func_00183D10(p);}
 if(p[0x269]==3){SET(86);}
 else{SET(D_004B7130[p[0x1B7]][0]);}
 func_0018C4B0(p,5);
 work[12]=0;work[11]=10;p[0x168]=*(s8*)(p+0x1B7)+11;
 func_001757E0(p,21,p[0x168]);
 work[9]=*(s8*)(p+0x151);func_00186A20(p);
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 if(p[0x1E6]){motion->vx=D_004B7140[p[0x1B7]][0];motion->ax=D_004B7144[p[0x1B7]][0];}
 else{motion->vx=-D_004B7140[p[0x1B7]][0];motion->ax=-D_004B7144[p[0x1B7]][0];}
 motion->vy=D_004B7148[p[0x1B7]][0];motion->ay=D_004B714C[p[0x1B7]][0];
 func_0021F6F0(p);
}
