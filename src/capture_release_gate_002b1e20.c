/* Release a captured target on the actual timer and animation conditions. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
extern int func_00175700(u8 *),func_00182E20(u8 *),func_00182D30(u8 *),func_001757E0(u8 *,int,int);
typedef struct {float x,y,z;} Position3;
extern void func_0018FDB0(u8 *),func_00154790(Position3 *,int,unsigned int,int);
/* Provisional: the third position component is not initialized on this path. */
void func_002B1E20(u8 *p)
{
 union {Position3 v;float pad[4];} position;
 unsigned int event;
 u8 release;
 func_00175700(p);
 if(func_00182E20(p))p[0x152]=1;
 if(--*(s16*)(p+0x1C)>=0) {
  if(*(s16*)(*(u8**)(p+0x1DC)+0x270)&&func_00182D30(*(u8**)(p+0x1DC))) *(s16*)(*(u8**)(p+0x1DC)+0x270)=0;
 } else *(s16*)(*(u8**)(p+0x1DC)+0x270)=0;
 event=p[0x15B];release=0;
 if(event) {
  event=(u8)event;
  if(event==1)release=1;
  else if((event&0x80)&&*(s16*)(*(u8**)(p+0x1DC)+0x270)==0)release=1;
 }
 if(release) {p[6]++;func_001757E0(p,15,1);return;}
 if(*(s8*)(p+0x151)) {
  p[0x151]=0;
  *(u8**)(*(u8**)(p+0x1DC)+0x1C8)=p;(*(u8**)(p+0x1DC))[0x1B5]=32;
  func_0018FDB0(p);
  if(*(s16*)(p+0x140))position.v.x=10.0f;else position.v.x=-10.0f;
  position.v.x+=*(float*)(p+0x34);position.v.y=167.142852783203125f+*(float*)(p+0x38);
  func_00154790(&position.v,*(s16*)(p+0x140),1,0);
 }
}
