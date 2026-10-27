typedef unsigned char u8; typedef signed char s8; typedef short s16; typedef unsigned int u32;
typedef struct {u8 pad[0x34];float x,y,z;u8 pad40[0x1c];float vx,vy,pad64,ax,ay;} Motion;
extern int func_00174470(const void *),func_00175700(u8 *);
extern void func_0039C320(u8 *),func_0039C2B0(u8 *),func_001E7F60(u8 *);
void func_0039C110(u8 *p)
{
 Motion *m=(Motion *)p;
 u8 *owner=*(u8 **)(p+0x18);
 if(!func_00174470(p)){func_0039C320(p);return;}
 if(--*(s16 *)(p+0x1e)<=0){
  m->vx/=2.0f;m->vy/=2.0f;m->ax/=2.0f;m->ay/=2.0f;
  func_0039C2B0(p);return;
 }
 if(m->y<=*(float *)(owner+0x430)){
  m->y=*(float *)(owner+0x430);
  m->vx=0.0f;m->vy=0.0f;m->ax=0.0f;m->ay=0.0f;
  func_0039C2B0(p);
 }
 if(*(s8 *)(p+0x1b2)){
  m->vx=0.0f;m->vy=0.0f;m->ax=0.0f;m->ay=0.0f;
  func_0039C2B0(p);return;
 }
 if(*(s8 *)(p+0x1b3)){
  p[0x1b3]=0;
  m->vx=0.0f;m->vy=0.0f;m->ax=0.0f;m->ay=0.0f;
  func_0039C2B0(p);return;
 }
 m->x+=m->vx;m->vx+=m->ax;
 m->y+=m->vy;m->vy+=m->ay;
 func_00175700(p);func_001E7F60(p);
}
