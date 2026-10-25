/* Initialize the launch timer and facing-dependent horizontal velocity. */
#pragma padloop on
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern void func_00185490(u8 *),func_0018C4B0(u8 *,int);
extern int func_001757E0(u8 *,int,int);
void func_00265540(u8 *p)
{
 ++p[6];*(s16*)(p+0x1C)=p[0x1B7]?40:30;
 func_00185490(p);func_0018C4B0(p,5);
 p[0x20D]=0;*(float*)(p+0x38)=*(float*)(p+0x430);
 p[0x1B5]=p[0x1B7];p[0x1B2]=*(u16*)(p+0x1C0)=0;*(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 *(float*)(p+0x5C)=0;*(float*)(p+0x60)=0;*(float*)(p+0x68)=0;*(float*)(p+0x6C)=0;
 func_001757E0(p,21,12);
 *(float*)(p+0x5C)=*(s16*)(p+0x140)?7.0833330154418945f:-7.0833330154418945f;
 p[0x206]=10;p[0x207]=10;
}
