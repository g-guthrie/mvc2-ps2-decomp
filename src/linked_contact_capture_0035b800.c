/* Owner-linked capture, per-target hit flags, and slowed target motion. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef struct {float x,y,z;} Vec3;
typedef unsigned int Address;
extern const u8 D_00463170[];
extern int func_00174470(const void *),func_00175700(u8 *),func_00185980(u8 *),func_001757E0(u8 *,int,int);
extern void func_001E7F60(u8 *),func_00185870(u8 *,u8 *);
void func_0035B800(u8 *p,void *owner_context)
{
 u8 *state;
 u8 *target;
 u8 *flags;
 u8 *owner=owner_context;
 state=owner+0x2B8;
 if(!func_00174470(p)) {p[4]=3;p[0x13C]=0;state[0]=0;return;}
 func_00175700(p);
 *(float*)(p+0x34)+=*(float*)(p+0x5C);
 *(float*)(p+0x5C)+=*(float*)(p+0x68);
 *(float*)(p+0x38)+=*(float*)(p+0x60);
 *(float*)(p+0x60)+=*(float*)(p+0x6C);
 if(p[0x20]&&*(s8*)(p+0x1B2)==0&&*(float*)(p+0x38)<64.28571319580078125f+*(float*)(owner+0x430)) {
  p[5]=4;*(float*)(p+0x38)=*(float*)(owner+0x430);state[0]=0;
  func_001757E0(p,23,5);return;
 }
 if(!*(s8*)(p+0x1B2)&&!*(s8*)(p+0x1B3)) {func_001E7F60(p);return;}
 if(*(s8*)(p+0x1B3))goto reject;
 if(!func_00185980(p))goto reject;
 target=*(u8**)(p+0x1C4);
 {
  int index=target[0x1B8]>>1;
  flags=(u8 *)((Address)index+(Address)state+1);
  if(*flags&2)goto reject;
  *(u8**)(p+0x14)=target;p[0x23]=index;state[0]=0;
 }
 *flags|=2;
 func_001757E0(target,0,0);
 owner[0x20B]=195;*(s8*)(owner+0x16A)=-1;
 func_00185870(p,target);
 target[0x20A]=6;
 *(Vec3*)(p+0x34)=*(Vec3*)(target+0x34);
 if(target[0x20D]==2) {
  *(float*)(target+0x5C)/=4.0f;*(float*)(target+0x68)/=4.0f;
  *(float*)(target+0x6C)=-0.803571403026580810546875f;
  if(!(*(float*)(target+0x60)<=0.0f))*(float*)(target+0x60)/=4.0f;
 } else {
  *(float*)(target+0x5C)=0;*(float*)(target+0x60)=0;
  *(float*)(target+0x68)=0;*(float*)(target+0x6C)=0;
 }
 {
  int duration=18;
  if(p[0x1B7])duration=62;
  if(*flags&128) {duration=0;*flags&=127;}
  *(s16*)(p+0x1C)=duration;
 }
 { u8 frame;
 p[5]++;frame=D_00463170[target[1]];p[0x22]=frame;
 func_001757E0(p,23,(u8)(frame+6));return;
 }
reject:
 p[5]=4;state[0]=0;
 func_001757E0(p,23,(u8)(p[0x20]*2+2));
}
