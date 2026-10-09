/* Initialize the observed object vector fields from fixed float templates. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef float f32;
extern void *func_003DA780(void *,int,int);
extern void func_003CE880(u8 *);
typedef struct { f32 x,y,z; } Vec3;
typedef struct { f32 w,x,y,z; } Vec4;
extern Vec3 D_00476700;
extern Vec4 D_004767F0;
extern u8 D_004766D0[];
void func_003CE6D0(void)
{
 u8 *p=func_003DA780(0,16,1);
 if (p==0) return;
 p[0x13c]=1;
 *(void (**)(u8 *))(p+16)=func_003CE880;
 *(f32 *)(p+0x34)=0.0f;
 *(f32 *)(p+0x38)=0.0f;
 *(f32 *)(p+0x3c)=0.0f;
 *(Vec3 *)(p+0x50)=D_00476700;
 *(u32 *)(p+0xd0)=0x800031;
 *(Vec4 *)(p+0x74)=D_004767F0;
 *(void **)(p+0xd8)=D_004766D0;
}

extern void func_003CECA0(u8 *);
extern Vec3 D_00476880;
extern Vec4 D_00476890;
extern u8 D_00476840[];
void func_003CEB10(void)
{
 u8 *p=func_003DA780(0,16,1);
 if (p==0) return;
 p[0x13c]=1;
 *(void (**)(u8 *))(p+16)=func_003CECA0;
 *(f32 *)(p+0x34)=0.0f;
 *(f32 *)(p+0x38)=0.0f;
 *(f32 *)(p+0x3c)=0.0f;
 *(Vec3 *)(p+0x50)=D_00476880;
 *(u32 *)(p+0xd0)=49;
 *(Vec4 *)(p+0x74)=D_00476890;
 *(void **)(p+0xd8)=D_00476840;
}

extern void func_003CF790(u8 *);
extern Vec4 D_00476A90;
extern u8 D_004768C0[];
void func_003CED60(void)
{
 u8 *p=func_003DA780(0,16,1);
 if (p==0) return;
 p[0x13c]=1;
 *(void (**)(u8 *))(p+16)=func_003CF790;
 *(f32 *)(p+0x34)=0.0f;
 *(f32 *)(p+0x38)=0.0f;
 *(f32 *)(p+0x3c)=0.0f;
 *(Vec3 *)(p+0x50)=D_00476700;
 *(u32 *)(p+0xd0)=0x800031;
 *(Vec4 *)(p+0x74)=D_00476A90;
 *(void **)(p+0xd8)=D_004768C0;
}
