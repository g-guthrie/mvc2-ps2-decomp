typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {u8 prefix[0x1C];s16 timer,transition;} SceneTimer;
typedef struct {u8 prefix[0x78];f32 red,green,blue;} SceneColor;

extern s32 D_004F1CDC __attribute__((section(".bss")));
extern s32 D_004C1970;
extern u32 D_004C283C;
extern s32 func_00153AA0(void *);
extern s32 func_00170DA0(s32,s32,s32,s32);
void func_00344B70(u8 *p) {
 SceneTimer *time=(SceneTimer *)p;
 SceneColor *color=(SceneColor *)p;
 switch(p[4]) {
 case 0:
  if(D_004F1CDC==1) {
   p[4]++;p[0x13C]=1;
   color->red=0;color->green=0;color->blue=0;
  }
  break;
 case 1:
  switch(p[5]) {
  case 0:
   color->green+=0.0020833334419876337f;
   if(!(color->green<1.0f)) {p[5]++;color->red=0;color->green=1; color->blue=0;}
   break;
  case 1:
   if(D_004F1CDC==2) p[5]++;
   break;
  case 2:
   color->red+=1.0f/(f32)D_004C1970;
   color->green-=1.0f/(f32)D_004C1970;
   color->blue+=0.2f/(f32)D_004C1970;
   if(++time->transition>=D_004C1970) {p[5]++;color->red=1;color->green=0.2f;color->blue=0.2f;}
   break;
  case 3:break;
  }
  time->timer++;
  if(time->timer>=1000) time->timer=0;
  func_00170DA0((s32)D_004C283C,11,func_00153AA0(p),*(s16 *)(p+0xCC));
  *(f32 *)(p+0xE0)=0;
  *(f32 *)(p+0xE4)=-0.0010000000474974513f*time->timer;
  *(u32 *)(p+0xD0)|=0x20000u;
  *(u32 *)(p+0x48)+=55u;
  break;
 }
}

extern int func_00417A40(void);
extern f32 func_00417440(u32);
/* Actual five-input interface confirmed at both native call sites. */
extern void func_00170E00(void *,f32,f32,f32,f32);
struct Object;
extern void func_003DAA40(struct Object *);
extern u32 D_004C283C;
extern u32 D_004C2840;
extern s32 D_004F1CDC __attribute__((section(".bss")));
typedef struct {u8 prefix[0x20];u32 angle;} SceneClock;
void func_00344E00(u8 *p) {
 SceneTimer *time=(SceneTimer *)p;
 SceneColor *color=(SceneColor *)p;
 f32 green,red,blue;
 switch(p[4]) {
 case 0:
  time->timer++;
  if(time->timer>=time->transition) {
   time->transition=func_00417A40()%27+24;
   time->timer=0;
  }
  *(s16 *)(p+0xCC)=time->timer/3+12;
  *(void **)(p+0x84)=(void *)D_004C283C;
  color->red=0.75f+0.25f*func_00417440(((SceneClock *)D_004C2840)->angle);
  color->green=0.75f+0.25f*func_00417440(((SceneClock *)D_004C2840)->angle*2u);
  color->blue=0.75f+0.25f*func_00417440(((SceneClock *)D_004C2840)->angle*4u);
  red=0.75f+0.25f*func_00417440(((SceneClock *)D_004C2840)->angle);
  green=0.75f+0.25f*func_00417440(((SceneClock *)D_004C2840)->angle*2u);
  blue=0.75f+0.25f*func_00417440(((SceneClock *)D_004C2840)->angle*4u);
  func_00170E00(*(void **)(p+0x84),1.0f,red,green,blue);
  if(D_004F1CDC==1) func_003DAA40((struct Object *)p);
  break;
 }
}
