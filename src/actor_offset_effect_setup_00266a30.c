/* Initialize local work and create an effect from the current position snapshot. */
#pragma padloop on
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {float x,y,z;} V3;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_001266A0(u8 *,int,int),func_00185490(u8 *),func_00183D10(u8 *),func_001E3210(u8 *,u8);
extern void func_001830D0(u8 *,const float *,int);
extern int func_001757E0(u8 *,int,int);
void func_00266A30(u8 *p,u8 *work)
{
 union {V3 vector;float values[3];} point;
 if(p[0x269]==6){p[0x404]=255;p[0x405]=16;}
 func_001266A0(p,13,6);++p[7];*(s16*)(work+10)=240;func_00185490(p);
 *(float*)(p+0x38)=*(float*)(p+0x430);
 p[0x1B5]=66;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 func_001757E0(p,22,54);*(s16*)(work+8)=15;
 func_00183D10(p);func_001E3210(p,20);
 p[0x404]=0;p[0x405]=0;
 point.vector=*(V3*)(p+0x34);point.values[0]=0;point.values[1]+=137.14285278320312f;
 func_001830D0(p,point.values,1);
}
