#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {f32 x,y,z;} V3;
typedef struct {u8 prefix[0x1c];s16 counter,phase;} SceneTimer;
typedef struct {u8 prefix[0x74];f32 opacity;} SceneOpacity;
typedef struct {u8 prefix[4];u8 state;u8 gap05[0x17];s16 counter;u8 gap1E[2];u8 selector;u8 gap21[0x13];V3 position;u8 gap40[0x34];f32 opacity;} SceneActor;
struct Object;
extern void func_003DAA40(struct Object *);
extern V3 D_00460D30[],D_00460D48[];
extern s32 D_004F1CDC __attribute__((section(".bss")));
void func_00343EF0(u8 *p) {
 SceneActor *scene=(SceneActor *)p;
 switch(scene->state) {
 case 0:
 scene->opacity+=0.009999999776482582f;
 scene->position.x+=(D_00460D48[scene->selector].x-D_00460D30[scene->selector].x)/100.0f;
 scene->position.y+=(D_00460D48[scene->selector].y-D_00460D30[scene->selector].y)/100.0f;
 scene->position.z+=(D_00460D48[scene->selector].z-D_00460D30[scene->selector].z)/100.0f;
 {s16 next=scene->counter+1;
 scene->counter=next;
 if(next>=100) {
  scene->state++;
  scene->opacity=1.0f;
  scene->position=D_00460D48[scene->selector];
 }}
 break;
 case 1:if(D_004F1CDC==2)scene->state++;break;
 case 2:
 scene->opacity-=0.009999999776482582f;
 {s16 next=scene->counter+1;
 scene->counter=next;
 if(next>=100)func_003DAA40((struct Object *)p);}
 break;
 }
}
