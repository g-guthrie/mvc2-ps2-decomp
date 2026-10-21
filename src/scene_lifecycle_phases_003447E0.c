typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef double f64;
typedef struct {u8 prefix[0x1C];s16 timer,angle;} SceneTimer;
typedef struct {u8 prefix[0x78];f32 red,green,blue;} SceneColor;
/* Exact compatible provider types from w1910_f.c; real scene resource fields. */
typedef struct {s32 id;u8 pad[0x8C];u8 data[0x24];} EL_d;
typedef struct ND_d ND_d;
typedef struct {u8 prefix[0x14];EL_d *elements;u8 gap18[4];ND_d **nodes;} SceneResource;

extern int func_00417A40(void);
extern int func_003D90A0(int);
extern void func_00344990(s32);
struct Object;
extern void func_003DAA40(struct Object *);
extern u32 D_004C283C;
extern s32 D_004F1CDC __attribute__((section(".bss")));
void func_003447E0(u8 *p) {
 SceneTimer *time=(SceneTimer *)p;
 SceneColor *color=(SceneColor *)p;
 switch(p[4]) {
 case 0:
  if(++time->timer>=2) {
   time->timer=0;
   *(s16 *)(p+0xCC)=func_00417A40()%4+6;
   *(u32 *)(p+0x84)=D_004C283C;
   *(u32 *)(p+0x48)=(u16)(s32)(0.5+65536.0*(func_00417A40()%90)/360.0);
  }
  if(func_003D90A0(0)) func_00344990(p[0x20]);
  break;
 }
 switch(p[5]) {
 case 0:
  if(D_004F1CDC>0) {
   p[5]++;
   *(u32 *)(p+0xD0)|=0x400;
   color->red=1.0f;color->green=1.0f;color->blue=1.0f;
  }
  break;
 case 1:
  color->red-=0.03333333507180214f;
  color->green-=0.03333333507180214f;
  color->blue-=0.03333333507180214f;
  if(++time->angle>=30) func_003DAA40((struct Object *)p);
  break;
 }
}

extern u8 *D_004C2840;
extern u8 D_004D18A6 __attribute__((section(".bss")));
extern s32 D_004F1CDC __attribute__((section(".bss")));
extern s32 func_0016D130(void);
extern u32 D_004C283C;
extern void func_00170E60(EL_d *,ND_d *,EL_d *,ND_d *,void (*)(u8 *,u8 *,s32),s32);
extern void func_00345650(u8 *,u8 *,s32);
void func_00345450(u8 *p) {
 SceneTimer *time=(SceneTimer *)p;
 SceneColor *color=(SceneColor *)p;
 SceneResource *resource;
 ND_d **nodes;
 p[0x13C]=1;
 if(*(s8 *)(D_004C2840+0x9C) || D_004D18A6 || func_0016D130()==2) p[0x13C]=0;
 switch(p[4]) {
 case 0:
  color->green+=0.002916666679084301f;
  if(!(color->green<0.699999988079071f)) {p[4]++;color->green=0.699999988079071f;}
  break;
 case 1:
  if(D_004F1CDC==2) p[4]++;
  break;
 case 2:
  color->red+=0.004166666883975267f;
  color->green-=0.002916666679084301f;
  if(!(color->red<1.0f)) {p[4]++;color->red=1.0f;color->green=0;}
  break;
 case 3:break;
 }
 if(++time->timer>=200) time->timer=0;
 if(time->angle>=360) time->angle=0;
 time->angle+=10;
 resource=*(SceneResource **)(p+0x84);
 nodes=resource->nodes;
 func_00170E60(((SceneResource *)D_004C283C)->elements,nodes[48],resource->elements,nodes[*(s16 *)(p+0xCC)],func_00345650,(s32)p);
 *(f32 *)(p+0xE0)=0.004999999888241291f*time->timer;
 *(u32 *)(p+0xD0)|=0x20000;
}
