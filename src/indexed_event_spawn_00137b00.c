/* Partial event layout inferred from native field accesses. */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern u8 *func_003DA750(s32,s32,s32);
extern void func_00137BF0(u8 *);
extern void func_00170DF0(s32);
extern void func_0013B1C0(u8 *);
extern u8 *D_004C2924 __attribute__((section(".sdata")));
extern s32 D_004C2830 __attribute__((section(".sdata")));
typedef struct EventView {
 u8 unknown00;
 u8 byte01;
 u8 unknown02[14];
 void (*callback)(u8 *);
 u8 unknown14[12];
 u8 index;
 u8 mode;
 u8 unknown22[30];
 u32 word40,word44;
 s32 orientation48;
 u8 unknown4C[4];
 float scale50,scale54,scale58;
 u8 unknown5C[24];
 float value74;
 u8 unknown78[12];
 s32 resource;
 u8 unknown88[64];
 u8 *context;
 s16 part;
 u8 unknownCE[2];
 u32 flags;
 u8 unknownD4[104];
 u8 enabled;
} EventView;
void func_00137B00(u8 index,s32 mode) {
 EventView *p;
 if((p=(EventView *)func_003DA750(0,6,1))!=0) {
  p->enabled=1;
  p->index=index;
  p->mode=mode;
  p->callback=func_00137BF0;
  p->context=D_004C2924+0x88;
  p->part=index*2+151;
  p->resource=D_004C2830;
  p->word40=0;
  p->word44=0;
  p->orientation48=0;
  p->flags=0x4830;
  p->scale50=1.2f;
  p->scale54=1.2f;
  p->scale58=1.2f;
  p->value74=1.0f;
  p->byte01=255;
  func_00170DF0(p->resource);
  if(p->index) p->orientation48=-8192;
  else p->orientation48=8192;
  func_0013B1C0((u8 *)p);
 }
}
