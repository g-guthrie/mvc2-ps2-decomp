#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
typedef struct {u8 prefix[0x7c];s16 count[2];} GameState;
typedef struct {u8 prefix[0x34];f32 x,y;} ActorPosition;
typedef struct {u8 prefix[2];s16 x,threshold;} FallState;
extern GameState *D_004C2794 __attribute__((section(".sdata")));
extern s16 data_s16_00472E70[16];
extern int func_001745B0(u8 *);
extern int func_00175700(u8 *);
extern int func_00174170(void);
extern int func_001757E0(u8 *,int,int);
extern void func_001E7F60(u8 *);
void func_003A7110(u8 *p,void *context)
{
 FallState *state=(FallState *)(p+0xd0);
 ActorPosition *position=(ActorPosition *)p;
 if(!func_001745B0(p))p[0x13c]=0;
 else p[0x13c]=1;
 position->y+=*(f32 *)(p+0x60);
 *(f32 *)(p+0x60)+=*(f32 *)(p+0x6c);
 func_00175700(p);
 if(!(position->y<=(f32)state->threshold)) {
 p[5]++;
 p[0x1b5]=64;
 p[0x1b2]=*(u16 *)(p+0x1c0)=0;
 *(u32 *)(p+0x1d8)=0;
 D_004C2794->count[p[2]]++;
 position->x=(f32)state->x;
 {int index=func_00174170()&15;
 position->x+=(f32)data_s16_00472E70[index];}
 *(f32 *)(p+0x60)=-34.28571319580078f;
 *(f32 *)(p+0x6c)=-0.2678571343421936f;
 func_001757E0(p,23,(u8)(p[0x21]+34));
 } else if(((s8 *)p)[0x1b3])p[4]++;
 else func_001E7F60(p);
}
