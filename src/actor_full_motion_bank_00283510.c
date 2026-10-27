/* Select the movement bank and its mode-specific effect and animation. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata"))),*D_004C2840 __attribute__((section(".sdata")));
extern float D_00455AA0[][4],D_00455AA4[][4],D_00455AA8[][4],D_00455AAC[][4];
extern void func_0018C4B0(u8 *,int),func_00185490(u8 *),func_001E3210(u8 *,int),func_00183D10(u8 *);
extern u8 *func_00383B80(void *, u8, u8);
extern int func_001757E0(u8 *,int,int);
void func_00283510(u8 *p)
{
 float vx,ax;
 ++p[6];p[0x1B5]=p[0x1B7]?55:52;p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 func_0018C4B0(p,12);func_00185490(p);p[0x20D]=0;*(float*)(p+0x38)=*(float*)(p+0x430);
 if(*(s8*)(D_004C2840+0x45))func_001E3210(p,20);else func_001E3210(p,26);
 if(p[0x1E6])vx=D_00455AA0[p[0x1B7]][0];else vx=-D_00455AA0[p[0x1B7]][0];
 *(float*)(p+0x5C)=vx;
 if(p[0x1E6])ax=D_00455AA4[p[0x1B7]][0];else ax=-D_00455AA4[p[0x1B7]][0];
 *(float*)(p+0x68)=ax;
 *(float*)(p+0x60)=D_00455AA8[p[0x1B7]][0];*(float*)(p+0x6C)=D_00455AAC[p[0x1B7]][0];
 func_00183D10(p);func_00383B80(p,4,2);
 p[0x168]=p[0x1B7]?3:1;func_001757E0(p,21,p[0x168]);
}
