/* Position a child effect and allocate its timed successor. */
typedef unsigned char u8;
typedef signed short s16;
typedef void (*ActorCallback)(u8 *);
extern void *func_003DA750(void *,int,int);
extern void func_001A7990(u8 *),func_001A8140(u8 *,u8 *);
extern float func_001A8CB0(u8 *);
void func_001A8320(u8 *p,u8 *owner)
{
 u8 *parent;
 u8 *event;
 float x,y;
 parent=*(u8**)(p+8);p[5]++;
 if(parent[0x20]==7) {x=-40.0f;y=68.5714263916015625f;}
 else {x=-80.0f;y=102.85713958740234375f;}
 if(*(s16*)(p+0x140))x=-x;
 *(float*)(p+0x34)=*(float*)(parent+0x34)+x;
 *(float*)(p+0x38)=*(float*)(parent+0x38)+y;
 if((event=func_003DA750(p,3,2))!=0) {
  *(ActorCallback*)(event+0x10)=func_001A7990;
  *(u8**)(event+0x18)=owner;
  *(s16*)(event+0x1E)=*(s16*)(p+0x1E)-1;
  if(*(s16*)(p+0x1E)==0)goto near;
  if(!(func_001A8CB0(p)<53.333332061767578125f))event[0x20]=8;
  else {near:event[0x20]=9;}
 }
 func_001A8140(p,owner);
}
