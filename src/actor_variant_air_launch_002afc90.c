#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern float D_00458B90,D_00458B94,D_00458B80[][2],D_00458B84[][2];
extern void func_00185490(u8*),func_0018C4B0(u8*,int);
extern int func_001757E0(u8*,int,int);
#define SET(action) do{p[0x1B5]=(action);p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;{u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}}while(0)
void func_002AFC90(u8 *p)
{
 float vx;
 ++p[6];p[0x20D]=0;func_00185490(p);
 if(p[0x269]==8){*(float*)(p+0x5C)=D_00458B90;*(float*)(p+0x60)=D_00458B94;SET(76);}
 else{*(float*)(p+0x5C)=D_00458B80[p[0x1B7]][0];*(float*)(p+0x60)=D_00458B84[p[0x1B7]][0];SET((s8)p[0x1B7]*2+75);}
 *(float*)(p+0x6C)=-0.8035714030265808f;
 if(p[0x1E6])vx=*(float*)(p+0x5C);else vx=-*(float*)(p+0x5C);
 *(float*)(p+0x5C)=vx;*(float*)(p+0x68)=0;
 func_0018C4B0(p,8);func_001757E0(p,21,(u8)(p[0x1B7]+12));
}
