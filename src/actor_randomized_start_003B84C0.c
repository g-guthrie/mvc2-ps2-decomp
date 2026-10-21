#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct {u8 prefix[0x7c];s16 count[2];} GameState;
extern GameState *D_004C2794 __attribute__((section(".sdata")));
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern u8 data_u8_004742B0[16];
/* Native selector addresses byte zero of each four-byte record. */
extern s8 D_004742C0[16][4];
extern void func_003B9220(u8 *);
extern int func_00174170(void);
extern int func_001757E0(u8 *,int,int);
void func_003B84C0(u8 *p)
{
 u8 *owner;
 u32 random;
 f32 amount;
 func_003B9220(p);
 p[0x13c]=1;p[6]=0;p[0x24]=11;
 owner=*(u8 **)(p+0x18);
 amount=(f32)((u32)func_00174170()&31);
 amount=1.6666666269302368f*amount;
 *(f32 *)(p+0x34)=*(f32 *)(owner+0x34)+amount;
 amount=(f32)((u32)func_00174170()&15);
 amount=2.142857074737549f*amount;
 *(f32 *)(p+0x38)=*(f32 *)(owner+0x38)+amount;
 *(f32 *)(p+0x60)=8.571428298950195f;
 *(f32 *)(p+0x6c)=0.2678571343421936f;
 *(f32 *)(p+0x5c)=0.0f;*(f32 *)(p+0x68)=0.0f;
 *(s16 *)(p+0x1c)=10;
 if(*(u32 *)(D_004C2840+0x1c)&3) {
 p[0x1b5]=57;
 p[0x1b2]=*(u16 *)(p+0x1c0)=0;
 *(u32 *)(p+0x1d8)=0;
 D_004C2794->count[p[2]]++;
 } else {
 p[0x1b5]=56;
 p[0x1b2]=*(u16 *)(p+0x1c0)=0;
 *(u32 *)(p+0x1d8)=0;
 D_004C2794->count[p[2]]++;
 }
 p[0x1b0]=66;p[0x1b1]=66;
 random=(u32)func_00174170()&15;
 p[0x21]=D_004742C0[random][0];
 func_001757E0(p,18,data_u8_004742B0[random]);
}
