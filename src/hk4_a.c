typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
typedef struct {u8 prefix[0x7c];s16 count[2];} GameState_hk4a;
extern GameState_hk4a *D_004C2794 __attribute__((section(".sdata")));
extern f32 D_004F1FD0[];
extern void func_00175700(u8 *);
extern void func_001E7F60(u8 *);
extern void func_003C80A0(u8 *,u8 *);

void func_003C7740(u8 *p,void *a1)
{
 if(*(s8 *)(p+0x1b4)) {
  *(s8 *)(p+0x1b4)=*(s8 *)(p+0x1b4)-1;
  return;
 }
 *(f32 *)(p+0x34)+=*(f32 *)(p+0x5c);
 *(f32 *)(p+0x5c)+=*(f32 *)(p+0x68);
 *(f32 *)(p+0x38)+=*(f32 *)(p+0x60);
 *(f32 *)(p+0x60)+=*(f32 *)(p+0x6c);
 func_00175700(p);
 if(*(s16 *)(p+0x1c)!=0 && *(s8 *)(p+0x1b2)!=0) {
  *(s16 *)(p+0x1c)=*(s16 *)(p+0x1c)-1;
  p[0x1b5]=0x26;
  p[0x1b2]=*(u16 *)(p+0x1c0)=0;
  *(u32 *)(p+0x1d8)=0;
  D_004C2794->count[p[2]]++;
 }
 if(D_004F1FD0[0] > *(f32 *)(p+0x38)) {
  func_001E7F60(p);
  return;
 }
 func_003C80A0(p,a1);
}
