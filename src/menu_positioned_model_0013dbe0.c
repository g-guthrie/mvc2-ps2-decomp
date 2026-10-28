/* Spawn a menu model object (type 6) at pose row selector+group*6 of
   data_f32v3x3_004B1730[12]; scale copies the f32[3] unit vector as one V3. */
#pragma padloop on
typedef unsigned char u8;typedef short s16;typedef unsigned int u32;
typedef struct {float value[3];} V3;
typedef struct {u8 pad0[0x10];void (*callback)(u8 *);u8 pad14[8];s16 timer;u8 pad1E[2];u8 selector,alternate,pad22,group;u8 pad24[0x10];V3 position;u8 pad40[0x10];V3 scale;u8 pad5C[0x28];void *model;u8 pad88[0x44];s16 tag;u8 padCE[2];u32 flags;u8 padD4[0x68];u8 visible;} Object;
typedef struct {V3 values[3];} PoseRow;
extern PoseRow data_f32v3x3_004B1730[12];
extern float data_f32_one_004B18E0[3];
extern void *D_004C282C __attribute__((section(".sdata")));
extern void *func_003DA750(void*,int,int);
extern void func_0013DD10(u8*);
void func_0013DBE0(int selector,int group) {
 Object *p=(Object*)func_003DA750(0,6,1);
 if(p) {
  if(group==2){p->alternate=1;group=0;}
  p->visible=0;
  p->selector=selector;p->group=group;p->callback=func_0013DD10;
  p->tag=selector+group*6+7;
  p->model=D_004C282C;
  p->position=data_f32v3x3_004B1730[selector+group*6].values[0];
  p->scale=*(V3 *)(void *)data_f32_one_004B18E0;
  p->flags|=0x811;
  if(p->alternate)p->flags|=0x800000;
  p->timer=(group*2+60)+selector*13;
 }
}
