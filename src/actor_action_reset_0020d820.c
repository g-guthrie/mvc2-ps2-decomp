/* Clear motion and select the initial action from the current mode. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_0018C4B0(u8 *,int),func_00185490(u8 *);
extern int func_001757E0(u8 *,int,int);
void func_0020D820(u8 *p,u8 *work)
{
 u8 action;
 ++p[6];func_0018C4B0(p,10);func_00185490(p);
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 p[0x20D]=2;work[5]=5;
 action=p[0x212]?79:76;
 p[0x1B5]=(s8)action+*(s8*)(p+0x1B7)*2;
 p[0x1B2]=*(u16*)(p+0x1C0)=0;
 *(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 func_001757E0(p,21,(u8)(p[0x1B7]*2+18));
}
