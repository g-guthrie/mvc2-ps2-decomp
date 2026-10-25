/* Clear movement and initialize the NPC-dependent work counter. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *),func_00183D10(u8 *);
extern int func_001757E0(u8 *,int,int);
void func_002995F0(u8 *p,u8 *work)
{
 if(p[0x269]==6){p[0x404]=255;p[0x405]=16;}
 ++p[6];*(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 func_00185490(p);func_00183D10(p);*(float*)(p+0x38)=*(float*)(p+0x430);p[0x20D]=0;
 work[3]=*(s8*)(p+0x539)?16:24;*(s16*)(p+0x1C)=40;
 p[0x1B5]=85;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 func_001757E0(p,22,1);
}
