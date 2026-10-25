#pragma padloop on
typedef unsigned char u8;typedef signed char s8;
typedef struct {u8 pad[0x228];s8 *cursor;} ScriptActor;
extern void func_00185550(u8*);
void func_0018D030(u8*p) {
 float step; s8 *cursor; s8 *next; ScriptActor *actor=(ScriptActor*)p;
 func_00185550(p);
 if(*(u8**)(p+0x1C8)==*(u8**)(p+0x1CC)) (*(u8**)(p+0x1CC))[0x209]=3;
 cursor=actor->cursor; step=*cursor; next=cursor+1;
 if(step>0.0f) {
  actor->cursor=next;
  if(p[0x1E6]==0)step=-step;
  *(float*)(p+0x34)=*(float*)(p+0x34)+1.6666666269302368f*step;
 }
}
