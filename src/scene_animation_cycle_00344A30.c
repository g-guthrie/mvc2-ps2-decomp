#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u8 prefix[0x1c];s16 counter,phase;} SceneTimer;
struct Object;
extern void func_003DAA40(struct Object *);
extern s8 D_00460DC0[];
extern u32 D_004C283C __attribute__((section(".sdata")));
void func_00344A30(u8 *p) {
 SceneTimer *timer=(SceneTimer *)p;
 *(s16 *)(p+0xcc)=((const s8 *)D_00460DC0)[timer->counter/2]+64;
 *(u32 *)(p+0x84)=D_004C283C;
 {s16 next=timer->counter+1;timer->counter=next;
 if((u32)next>=26u)timer->counter=0;}
 switch(p[4]) {
 case 0:
 {s16 next=timer->phase+1;timer->phase=next;
 if(next>=30) {
  p[4]++;timer->phase=0;
  *(u32 *)(p+0xd0)|=0x400;
  *(f32 *)(p+0x78)=1.0f;*(f32 *)(p+0x7c)=1.0f;*(f32 *)(p+0x80)=1.0f;
 }}
 break;
 case 1:
 *(f32 *)(p+0x78)-=0.03333333507180214f;
 *(f32 *)(p+0x7c)-=0.03333333507180214f;
 *(f32 *)(p+0x80)-=0.03333333507180214f;
 {s16 next=timer->phase+1;timer->phase=next;
 if(next>=30)func_003DAA40((struct Object *)p);}
 break;
 }
}
