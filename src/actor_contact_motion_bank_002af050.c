#pragma padloop on
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {u8 prefix[15];u8 contact;} Work;
typedef struct {u8 prefix[0x5C];float vx;} Motion;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern u8 D_004C0C8C[][2] __attribute__((section(".sdata")));
extern u16 D_004C0C48[] __attribute__((section(".sdata")));
extern float D_004C0C50[] __attribute__((section(".sdata")));
extern void func_00175C00(u8*,int),func_0018C4B0(u8*,int),func_00185490(u8*),func_001E3210(u8*,int);
extern u8 *func_001CCB70(u8*,int);
extern int func_001757E0(u8*,int,int);
void func_002AF050(u8 *p)
{
 Motion *motion=(Motion*)p;Work *work;u8 *contact;
 ++p[6];work=(Work*)(p+0x2B8);contact=&work->contact;p[0x2C6]=0;p[0x2C7]=0;func_00175C00(p,0);
 p[0x1B5]=D_004C0C8C[p[0x1B7]][0];p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 func_0018C4B0(p,4);func_00185490(p);
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 *(u16*)(p+0x1C)=D_004C0C48[p[0x1B7]];
 *(float*)(p+0x5C)=D_004C0C50[p[0x1B7]];
 if(!p[0x1E6])motion->vx=-motion->vx;
 func_001E3210(p,20);func_001757E0(p,21,(u8)(p[0x1B7]+29));
 if(*(u32*)(p+0xD0)){*contact=0;func_001CCB70(p,6);}
}
