#pragma padloop on
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct {u8 prefix[0x7c];s16 count[2];} GameState;
extern GameState *D_004C2794 __attribute__((section(".sdata")));
extern f32 D_004C2A0C,D_004C2A10 __attribute__((section(".sdata")));
extern s32 D_004C2A14 __attribute__((section(".sdata")));
extern f32 D_004F1FD0 __attribute__((section(".bss")));
extern f32 data_f32_004741A0[16];
typedef struct {f32 value[4];} F32Vector4;
extern F32Vector4 data_f32v4_004741E0[8];
extern void func_003B78B0(u8 *);
extern int func_00174170(void);
extern int func_001757E0(u8 *,int,int);
void func_003B7630(u8 *p)
{
 u8 *owner;
 p[4]++;
 owner=*(u8 **)(p+0x18);
 func_003B78B0(p);
 owner[0x21]=1;
 D_004C2A14=func_00174170()&15;
 D_004C2A0C=data_f32_004741A0[D_004C2A14];
 if(owner[0x1e6]==0)D_004C2A0C=-D_004C2A0C;
 *(f32 *)(p+0x34)+=D_004C2A0C;
 *(f32 *)(p+0x38)=68.57142639160156f+D_004F1FD0;
 D_004C2A14&=7;
 D_004C2A10=data_f32v4_004741E0[D_004C2A14].value[0];
 D_004C2A0C=data_f32v4_004741E0[D_004C2A14].value[1];
 *(f32 *)(p+0x60)=data_f32v4_004741E0[D_004C2A14].value[2];
 *(f32 *)(p+0x6c)=data_f32v4_004741E0[D_004C2A14].value[3];
 if(owner[0x1e6]==0) {
 D_004C2A10=-D_004C2A10;
 D_004C2A0C=-D_004C2A0C;
 }
 *(f32 *)(p+0x5c)=D_004C2A10;
 *(f32 *)(p+0x68)=D_004C2A0C;
 p[0x1b0]=66;p[0x1b1]=66;
 p[0x1b5]=51;
 p[0x1b2]=*(u16 *)(p+0x1c0)=0;
 *(u32 *)(p+0x1d8)=0;
 D_004C2794->count[p[2]]++;
 func_001757E0(p,22,3);
}
