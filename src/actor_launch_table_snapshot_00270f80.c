/* Snapshot the native launch table before callbacks and compute the launch velocity. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {float values[2][2];} LaunchTable;
extern LaunchTable D_004548D0 __attribute__((aligned(16)));
extern float D_004F1F4C;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_0018C4B0(u8 *,int),func_00185490(u8 *),func_00270B10(u8 *),func_00183D10(u8 *);
extern int func_001757E0(u8 *,int,int);
void func_00270F80(u8 *p)
{
 LaunchTable table __attribute__((aligned(16)))=D_004548D0;
 double target;
 float position;
 ++p[6];p[0x1B5]=*(s8*)(p+0x1B7)+54;
 p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 func_0018C4B0(p,5);func_00185490(p);func_00270B10(p);
 if(p[0x1E6])target=D_004F1F4C-320.0;else target=320.0+D_004F1F4C;
 position=target;
 *(float*)(p+0x5C)=(position-*(float*)(p+0x34))/32.0f;
 *(float*)(p+0x68)=0;
 *(float*)(p+0x60)=table.values[p[0x1B7]][0];
 *(float*)(p+0x6C)=table.values[p[0x1B7]][1];
 func_00183D10(p);func_001757E0(p,21,(u8)(p[0x1B7]+12));
}
