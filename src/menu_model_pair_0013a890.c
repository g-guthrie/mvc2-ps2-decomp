#pragma padloop on
typedef unsigned char u8;typedef short s16;typedef unsigned int u32;
typedef struct {float x,y,z;} V3;
typedef struct {int x,y,z;} Angles;
typedef struct {u8 pad0[0x10];void (*callback)(u8 *);void *context;void *owner;u8 pad1C[4];u8 selector,index;u8 pad22[0x12];V3 position;Angles angles;u8 pad4C[4];V3 scale;u8 pad5C[0x28];void *model;u8 pad88[0x40];void *attachment;s16 tag;u8 padCE[2];u32 flags;u8 padD4[0x68];u8 visible;} Object;
extern V3 D_004400E0[][2];
extern void *D_004C2830 __attribute__((section(".sdata")));
extern void *func_003DA750(void*,int,int);
extern void func_0013ABD0(u8*);
void func_0013A890(u8 *owner,int alternate) {
 int tag; s16 i;
 tag=alternate?182:107;
 for(i=0;i<2;i++) {
  Object *p=(Object*)func_003DA750(0,6,1);
  if(!p)return;
  p->owner=owner;p->attachment=owner+0x88;p->context=*(void**)(owner+0x14);
  p->visible=1;p->callback=func_0013ABD0;p->selector=owner[0x20];p->index=i;
  p->tag=tag-i;p->model=D_004C2830;
  p->position=D_004400E0[p->selector][i];
  p->angles.x=0x2000;p->angles.y=0;p->angles.z=0;
  p->flags=0x813;p->scale.x=1.0f;p->scale.y=0.01f;p->scale.z=1.0f;
 }
}
