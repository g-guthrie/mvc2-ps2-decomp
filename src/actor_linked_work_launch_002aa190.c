#pragma padloop on
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {u8 pad[0x5C];float vx;} Motion;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *),func_00183D10(u8 *),func_00394780(void *,u8,u8);
extern int func_001757E0(u8 *,int,int);
void func_002AA190(u8 *p,u8 *work)
{
 Motion *motion=(Motion*)p;
 if(p[0x269]==6){p[0x404]=255;p[0x405]=16;}
 ++p[6];p[0x1B5]=57;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 func_00185490(p);
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 *(float*)(p+0x38)=*(float*)(p+0x430);p[0x20D]=0;
 work[1]=(*(u8**)(p+0x220))[1];*(s16*)(p+0x1C)=16;
 motion->vx=p[0x1E6]?20.0f:-20.0f;
 func_00183D10(p);func_00394780(p,6,0);func_001757E0(p,22,0);
}
