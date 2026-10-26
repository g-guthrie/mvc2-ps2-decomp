/* Release the ADX workspace when its final reference is dropped. */
typedef unsigned char u8;typedef signed int s32;typedef unsigned int u32;
extern s32 D_00479DFC,D_0047C5B0,D_0047C5B4,D_0047C5AC,D_0047B580,D_0047C5A8;
extern u8 D_0047C588[],D_0047B588[],D_0047B180[],D_00479E00[];
extern void func_003FCD80(void);extern void *func_0011D8F8(void*,s32,u32);
void func_003FB460(void){
 if(--D_00479DFC==0){
  func_003FCD80();D_0047C5B4=-1;D_0047C5B0=0;D_0047C5AC=0;D_0047B580=0;D_0047C5A8=0;
  func_0011D8F8(D_0047C588,0,0x20);func_0011D8F8(D_0047B588,255,0x1000);
  func_0011D8F8(D_0047B180,0,0x400);func_0011D8F8(D_00479E00,0,0x1380);
 }
}
