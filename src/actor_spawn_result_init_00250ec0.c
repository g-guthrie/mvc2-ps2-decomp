/* Initialize the action and record whether the event allocation succeeded. */
#pragma padloop on
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Event;
extern struct Event *func_00367F90(void *,u8,u8);
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_0018C4B0(u8 *,int),func_00185490(u8 *),func_00183D10(u8 *);
extern int func_001757E0(u8 *,int,int);
#define SET(action) do{p[0x1B5]=(action);p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;{u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}}while(0)
void func_00250EC0(u8 *p,u8 *work)
{
 ++p[6];
 if(p[0x269]==3){SET(83);}else{SET(54);}
 func_0018C4B0(p,5);func_00185490(p);
 *(float*)(p+0x38)=*(float*)(p+0x430);p[0x20D]=0;
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 if(func_00367F90(p,0,0))work[8]=0;else work[8]=1;
 func_00183D10(p);func_001757E0(p,21,(u8)(p[0x1B7]+15));
}
