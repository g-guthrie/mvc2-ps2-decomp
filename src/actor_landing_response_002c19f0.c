#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef struct {u8 prefix[0x34];float x,y,z;u8 pad[0x1C];float vx,vy;} Motion;
extern float D_00459A58,D_00459A5C,D_00459A60;
extern void func_001843A0(u8*),func_00183d50(u8*),func_002C40F0(u8*);
extern int func_00175700(u8*);
#define F(o) (*(float*)(p+(o)))
void func_002C19F0(u8 *p)
{
 Motion *motion=(Motion*)p;
 if(F(0x38)<F(0x430)){
  motion->y=F(0x430);motion->vx=0;motion->vy=0;F(0x68)=0;F(0x6C)=0;
  func_001843A0(p);func_00183d50(p);return;
 }
 if(p[0x215])func_002C40F0(p);
 func_00175700(p);
 if(*(s8*)(p+0x151)){
  ++p[6];motion->vx=0;motion->vy=0;F(0x68)=0;F(0x6C)=0;p[0x210]=0;
  if(p[0x1FC]==97){motion->vx=10.833333015441895f;motion->vy=-6.4285712242126465f;*(s16*)(p+0x1E)=(int)D_00459A58;}
  else if(p[0x1FC]==98){motion->vx=6.666666507720947f;motion->vy=-8.571428298950195f;*(s16*)(p+0x1E)=(int)D_00459A5C;}
  else{motion->vx=2.5f;motion->vy=-11.785714149475098f;*(s16*)(p+0x1E)=(int)D_00459A60;}
  if(!p[0x1E6])motion->vx=-motion->vx;
  p[0x210]=0;
 }
}
