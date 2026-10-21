#pragma padloop on
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
extern u8 *D_004C2794 __attribute__((section(".sdata")));
extern f32 D_004622D0[];
extern s16 D_004622F0[];
extern int func_001757E0(u8 *,int,int);
extern void func_0034E760(u8 *);
extern void func_0015E630(u8 *);
extern int func_00417A40(void);
void func_0034E4F0(u8 *p) {
 f32 speed;

 p[0x13c]=0;p[0x24]=0;
 p[0x1b0]=68;p[0x1b1]=68;
 p[0x1b5]=69;p[0x1b2]=*(u16 *)(p+0x1c0)=0;*(u32 *)(p+0x1d8)=0;
 {u32 address=p[2]*2;address+=(u32)D_004C2794;address+=0x7c;++*(s16 *)address;}
 func_0034E760(p);
 if(*(s16 *)(p+0x140))speed=6.666666507720947f;
 else speed=-6.666666507720947f;
 *(f32 *)(p+0x5c)=speed;
 *(f32 *)(p+0x68)=0;
 *(f32 *)(p+0x60)=6.4285712242126465f;
 *(f32 *)(p+0x6c)=-0.6696428060531616f;
 func_0015E630(p);
 p[0]=1;
 *(f32 *)(p+0x6c)-=0.000032697404094506055f*(func_00417A40()&0x3000);
 *(f32 *)(p+0x38)+=D_004622D0[p[0x21]];
 *(s16 *)(p+0x1c)=D_004622F0[p[0x21]];
 func_001757E0(p,23,17);
}
