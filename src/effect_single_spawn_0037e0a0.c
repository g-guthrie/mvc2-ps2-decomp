#pragma padloop on
typedef unsigned char u8;
typedef struct {u8 prefix[0x10];void (*callback)(u8*);u8 pad14[4];u8 *owner;u8 pad1C[4];u8 kind,variant,pad22,index;} Event;
extern void *func_003DA750(void*,int,int);
extern void func_0037E120(u8*);
void func_0037E0A0(u8 *p,int kind,int variant)
{
 int i;
 for(i=0;i<1;++i){
  Event *event=(Event*)func_003DA750(0,1,0);
  if(event){event->callback=func_0037E120;event->owner=p;event->kind=kind;event->variant=variant;event->index=i;}
 }
}
