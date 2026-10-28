typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef struct {u8 prefix[0x34];float x,y,z;u8 pad[0x1C];float vx,vy;} Motion;
extern void func_001843A0(u8*),func_00183d50(u8*),func_002C40F0(u8*);
extern int func_00175700(u8*);
#define F(o) (*(float*)(p+(o)))
void residual_002C1800(u8 *p)
{
 Motion *motion=(Motion*)p;
 if(F(0x38)<F(0x430)){
  motion->y=F(0x430);motion->vx=0;motion->vy=0;F(0x68)=0;F(0x6C)=0;
  func_00183d50(p);func_001843A0(p);return;
 }
 switch(p[0x215]){default:func_002C40F0(p);break;case 0:break;}
 func_00175700(p);
 if(*(s8*)(p+0x151)){
  ++p[6];motion->vx=0;motion->vy=0;F(0x68)=0;F(0x6C)=0;
  motion->vx=11.666666030883789f;
  if(!p[0x1E6])motion->vx=-motion->vx;
  F(0x68)=0;
  motion->vy=-6.4285712242126465f;
  F(0x6C)=0;
  p[0x210]=0;
  *(s16*)(p+0x1E)=40;
 }
}
