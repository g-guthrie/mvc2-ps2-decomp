typedef unsigned char u8;typedef signed short s16;typedef float f32;
extern u8 D_004D18A0;
extern int func_001757E0(u8 *,int,int);
void func_00227940(u8 *p) {f32 velocity,offset;p[0x13c]=0;p[0x159]=255;if(D_004D18A0>=2){p[6]++;p[0x13c]=1;p[0x20d]=2;*(s16 *)(p+0x1c)=32;offset=-640.0f;velocity=20.0f;*(f32 *)(p+0x64)=*(f32 *)(p+0x34);if(*(s16 *)(p+0x140)!=0){offset=-offset;velocity=-velocity;}*(f32 *)(p+0x34)+=offset;*(f32 *)(p+0x5c)=velocity;*(f32 *)(p+0x68)=0;*(f32 *)(p+0x38)=*(f32 *)(p+0x430)+548.5714111328125f;*(f32 *)(p+0x60)=-17.14285659790039f;*(f32 *)(p+0x6c)=0;func_001757E0(p,18,0);}}
