#pragma padloop on
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern float D_004588D0[][3],D_004588D4[][3],D_004588D8[][3];
extern void func_0018C4B0(u8 *,int),func_00185490(u8 *),func_00183D10(u8 *),func_00394780(void *,u8,u8);
extern int func_001757E0(u8 *,int,int);
#define SET(action) do{p[0x1B5]=(action);p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;{u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}}while(0)
void func_002A9150(u8 *p)
{
 float vx;
 ++p[6];
 if(p[0x269]==3){SET(81);}
 else{SET(p[0x1B7]?53:51);func_0018C4B0(p,10);}
 func_00185490(p);*(float*)(p+0x38)=*(float*)(p+0x430);p[0x20D]=0;
 if(p[0x1E6])vx=D_004588D0[p[0x1B7]][0];else vx=-D_004588D0[p[0x1B7]][0];
 *(float*)(p+0x5C)=vx;
 *(float*)(p+0x60)=D_004588D4[p[0x1B7]][0];*(float*)(p+0x6C)=D_004588D8[p[0x1B7]][0];*(float*)(p+0x68)=0;
 func_00394780(p,2,0);func_00183D10(p);
 p[0x168]=p[0x1B7]?4:2;func_001757E0(p,21,p[0x168]);
}
