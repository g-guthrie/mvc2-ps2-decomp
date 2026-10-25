/* Initialize the mode-dependent launch and local event counters. */
/* Initialize the owner launch and mode-dependent event counters. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void func_00185490(u8 *),func_0018C4B0(u8 *,int);
extern int func_001757E0(u8 *,int,int);
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern u8 D_004C0AE0[][2] __attribute__((section(".sdata")));
extern u8 D_004C0AE1[][2] __attribute__((section(".sdata")));
void func_002972B0(u8 *p,u8 *counts)
{
 float speed;
 func_00185490(p);
 *(float*)(p+0x38)=*(float*)(p+0x430);
 ++p[6];
 
 p[0x210]=0;p[0x20D]=0;
 func_0018C4B0(p,10);
 if(p[0x1B7]==0){speed=13.333333015441895f;*(float*)(p+0x60)=17.142856597900391f;}
 else {speed=20.0f;*(float*)(p+0x60)=34.285713195800781f;}
 if(p[0x1E6])*(float*)(p+0x5C)=speed;
 else *(float*)(p+0x5C)=-speed;
 *(float*)(p+0x68)=p[0x1E6]?-0.8333333134651184f:0.8333333134651184f;
 *(float*)(p+0x6C)=-1.0714285373687744f;
 p[0x1B5]=*(s8*)(p+0x1B7)+51;
 p[0x1B2]=*(u16*)(p+0x1C0)=0;
 *(u32*)(p+0x1D8)=0;
 {u32 a=p[2]*2;a+=(u32)D_004C2794;a+=0x7C;++*(s16*)a;}
 counts[0]=D_004C0AE0[p[0x1B7]][0];
 counts[1]=D_004C0AE1[p[0x1B7]][0];
 func_001757E0(p,21,(u8)(p[0x1B7]+2));
}
