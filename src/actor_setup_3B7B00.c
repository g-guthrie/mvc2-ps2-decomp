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
extern f32 D_004C2A18 __attribute__((section(".sdata")));
typedef struct {f32 x,y;} PositionOffset;
extern PositionOffset D_00474270[];
extern void func_003B7ED0(u8 *);
extern int func_001757E0(u8 *,int,int);
void func_003B7B00(u8 *p)
{
 u8 *owner;
 p[4]++;
 owner=*(u8 **)(p+0x18);
 func_003B7ED0(p);
 p[0x1b0]=66;p[0x1b1]=66;
 if(p[0x20]==0) {
 if(owner[0x269]==3) {
 p[0x1b5]=53;
 p[0x1b2]=*(u16 *)(p+0x1c0)=0;*(u32 *)(p+0x1d8)=0;
 D_004C2794->count[p[2]]++;
 } else {
 p[0x1b5]=52+((s8 *)owner)[0x1b7]*2;
 p[0x1b2]=*(u16 *)(p+0x1c0)=0;*(u32 *)(p+0x1d8)=0;
 D_004C2794->count[p[2]]++;
 }
 D_004C2A18=-81.66666412353516f;
 if(owner[0x1e6]==0)D_004C2A18=-D_004C2A18;
 *(f32 *)(p+0x34)+=D_004C2A18;
 *(f32 *)(p+0x38)+=218.57142639160156f;
 func_001757E0(p,21,owner[0x1b7]*2+3);
 } else {
 if(owner[0x269]==3) {
 p[0x1b5]=44;
 p[0x1b2]=*(u16 *)(p+0x1c0)=0;*(u32 *)(p+0x1d8)=0;
 D_004C2794->count[p[2]]++;
 } else {
 p[0x1b5]=43;
 p[0x1b2]=*(u16 *)(p+0x1c0)=0;*(u32 *)(p+0x1d8)=0;
 D_004C2794->count[p[2]]++;
 }
 D_004C2A18=D_00474270[owner[0x1b7]].x;
 *(f32 *)(p+0x38)+=D_00474270[owner[0x1b7]].y;
 func_001757E0(p,21,9);
 }
}
