/* Initialize mode-dependent floating work values and the actor action. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *),func_00183D10(u8 *);
extern int func_001757E0(u8 *,int,int);
void func_00240E10(u8 *p,u8 *work)
{
 ++p[6];p[7]=0;p[0x20D]=0;*(float*)(p+0x38)=*(float*)(p+0x430);*(s16*)(p+0x1C)=0;
 p[0x22]=p[0x1B7]?28:24;work[6]=0;
 *(float*)(work+0x18)=(u32)p[0x22];
 *(float*)(work+0x14)=(u32)p[0x22];
 *(float*)(work+0x1C)=0;
 p[0x1B5]=*(s8*)(p+0x1B7)+50;
 p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 func_00185490(p);func_00183D10(p);func_001757E0(p,21,(u8)(p[0x1B7]+5));
}
