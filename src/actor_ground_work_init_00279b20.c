/* Initialize grounded work, clear movement, and select the next action. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *),func_00175C00(u8 *,int),func_0018C4B0(u8 *,int),func_00183D10(u8 *),func_00279C10(u8 *,u8 *);
extern int func_001757E0(u8 *,int,int);
void func_00279B20(u8 *p,u8 *work)
{
 ++p[6];func_00185490(p);func_00175C00(p,0);
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 *(float*)(p+0x38)=*(float*)(p+0x430);p[0x210]=0;p[0x20D]=0;
 work[0]=*(s8*)(p+0x539)?12:24;*(s16*)(p+0x1C)=64;func_0018C4B0(p,5);
 p[0x1B5]=53;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 func_001757E0(p,21,3);func_00183D10(p);func_00279C10(p,work);
}
