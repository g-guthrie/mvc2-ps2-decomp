/* Initialize the linked work fields and copy the current facing and target. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_001266A0(u8 *,int,int),func_00185490(u8 *),func_00183D10(u8 *);
extern int func_001757E0(u8 *,int,int);
void func_00236D90(u8 *p,u8 *work)
{
 s8 kind;
 if(p[0x269]==6){p[0x404]=255;p[0x405]=16;}
 ++p[7];p[0x1E8]=1;*(s16*)(p+0x1C)=40;
 work[0x16]=10;work[0x18]=4;work[0x17]=5;
 *(u8**)(work+0x20)=*(u8**)(p+0x220);
 work[0x19]=0;work[0x1A]=0;work[0x1B]=0;work[0x1D]=0;work[0x1C]=0;work[0x1E]=0;
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 kind=p[2]?4:3;func_001266A0(p,1,kind);
 p[0x1B5]=69;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 func_00185490(p);
 work[0x1F]=*(s8*)(p+0x140);p[0x20]=1;
 if(p[0x20D]!=2){func_00183D10(p);p[0x20]=0;p[0x210]=0;*(float*)(p+0x38)=*(float*)(p+0x430);}
 func_001757E0(p,22,p[0x20]);
}
