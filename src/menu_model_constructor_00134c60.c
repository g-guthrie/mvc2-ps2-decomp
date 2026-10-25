#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned int u32;
typedef struct {float x,y,z;} V3;
typedef struct {u8 prefix[0x10];void *callback;u8 pad14[12];u8 selector;u8 pad21[0x13];V3 position;u8 pad40[0x44];void *model;u8 pad88[0x44];s16 tag;u8 padCE[2];u32 flags;u8 padD4[0x68];u8 visible;} Object;
extern void *func_003DA750(void*,int,int);
extern void func_00134E40(void*),func_00135140(void);
extern void *D_004C2834 __attribute__((section(".sdata")));
extern u8 *D_004C2840 __attribute__((section(".sdata")));
extern V3 D_0043E950[];
void func_00134C60(int index)
{
 Object *p=(Object*)func_003DA750(0,14,1);
 if(p){
  p->visible=1;p->callback=(void*)func_00134E40;p->tag=85;p->model=D_004C2834;
  p->position=D_0043E950[index];p->flags=0x10801;p->selector=index;
  if(*(s8*)(D_004C2840+0x4D)==3){p->callback=(void*)func_00135140;p->tag=95;p->model=D_004C2834;}
 }
}
