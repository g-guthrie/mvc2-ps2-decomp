#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef int s32;
typedef float f32;
typedef struct {u8 prefix[0x34];f32 x,y;u8 gap3C[0x178];s8 flash;} ActorPosition;
extern int func_00185980(u8 *);
extern void func_00185870(u8 *,u8 *);
extern int func_001757E0(u8 *,int,int);
extern int func_00175700(u8 *);
extern void func_001E7F60(u8 *);
void func_0035C610(u8 *p,void *context) {
 u8 *control=(u8 *)context+0x2b8;
 ActorPosition *position=(ActorPosition *)p;
 if(!p[5]) {
  f32 offset=-83.33332824707031f;
  if(((u8 *)context)[0x1e6])offset=-offset;
  position->x=*(f32 *)((u8 *)context+0x34)+offset;
  position->y=90.0f+*(f32 *)((u8 *)context+0x38);
  if(position->flash) {position->flash--;return;}
  if(func_00185980(p)) {
   u8 *other=*(u8 **)(p+0x1c4);
   if(other[0x1b6]==99) {
    p[5]++;((u8 *)context)[0x1fe]=1;((u8 *)context)[0x201]=32;((u8 *)context)[0x1b1]=0;((u8 *)context)[0x20b]=197;((s8 *)context)[0x16a]=-1;
    control[0x38]=1;other[0x208]=2;
    func_00185870(p,other);func_001757E0(p,23,24);return;
   }
  } else if((s8)func_00175700(p)>=0) {func_001E7F60(p);return;}
  p[5]++;((s8 *)control)[0x38]=-1;
  func_001757E0(p,23,24);
 } else if((s8)func_00175700(p)<0) {p[4]=2;p[0x13c]=0;}
}
