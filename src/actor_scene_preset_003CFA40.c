typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u8 unknown0;s8 scaleIndex;V3 position;} ScenePreset;
extern s8 D_004F7F4C,D_004F7F33;
extern s8 D_004C21A0[] __attribute__((section(".sdata")));
extern u8 *D_004C283C __attribute__((section(".sdata")));
extern V3 D_00476AD0[],D_00476700[];
extern ScenePreset D_00476A80;
extern void func_003DAA40(u8 *);
extern void func_0012AD00(u8 *);
void func_003CFA40(u8 *p)
{
 if(D_004F7F4C!=4) {
  func_003DAA40(p);
  return;
 }
 func_0012AD00(p);
 if(D_004F7F33!=5) {
  *(s16 *)(p+0xcc)=0x31;
  *(u8 **)(p+0x84)=D_004C283C;
  *(V3 *)(p+0x34)=D_00476AD0[D_004F7F33];
  *(V3 *)(p+0x50)=D_00476700[D_004C21A0[D_004F7F33]];
 } else {
  *(s16 *)(p+0xcc)=0x30;
  *(u8 **)(p+0x84)=D_004C283C;
  *(f32 *)(p+0x34)=D_00476A80.position.x;
  *(f32 *)(p+0x38)=D_00476A80.position.y;
  *(f32 *)(p+0x3c)=D_00476A80.position.z;
  *(V3 *)(p+0x50)=D_00476700[D_00476A80.scaleIndex];
 }
}
