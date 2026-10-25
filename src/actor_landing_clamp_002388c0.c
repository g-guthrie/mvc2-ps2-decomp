/* Integrate motion, stop horizontal reversal, and complete the landing transition. */
#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef struct {u8 pad[0x38];float y;u8 pad3C[0x3F4];float ground;} Position;
extern int func_00175700(u8 *),func_001757E0(u8 *,int,int);
extern void func_00183d50(u8 *);
void func_002388C0(u8 *p,u8 *work)
{
 float *vx,*ax,*vy,*ay;
 Position *position=(Position*)p;
 func_00175700(p);
 vx=(float*)(p+0x5C);ax=(float*)(p+0x68);vy=(float*)(p+0x60);ay=(float*)(p+0x6C);
 *(float*)(p+0x34)+=*(float*)(p+0x5C);
 *(float*)(p+0x5C)+=*(float*)(p+0x68);
 position->y+=*(float*)(p+0x60);
 *(float*)(p+0x60)+=*(float*)(p+0x6C);
 if(*(float*)(p+0x5C) * *(float*)(p+0x68)>=0.0f){*vx=0.0f;*ax=0.0f;}
 if(position->y<position->ground){
  int group,event;
  ++p[7];position->y=position->ground;p[0x20D]=0;*vy=0;*ay=0;func_00183d50(p);
  group=1;event=3;
  if(*(s8*)(work+0x38)){group=22;event=37;}
  func_001757E0(p,(u8)group,(u8)event);
 }
}
