/* Follow the stage center with bounded horizontal velocity and periodic vertical motion. */
#pragma padloop on
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {u8 pad[0x1E];short angle;u8 pad20[0x14];float x,y;u8 pad3C[0x20];float vx;u8 pad60[0x2F4];u16 buttons;} Actor;
extern float D_004F1FC8,D_004F1FCC,D_004F1FD0,D_004F1FD4;
extern float func_00417440(int);
/* These native runtime helpers convert signed 32-bit integers. */
extern double litodp(int);
extern int dptoli(double);
void func_00206A80(u8 *actor)
{
 Actor *p=(Actor*)actor;
 float displacement;
 if(p->buttons&0x3C00){
  if(p->buttons&0x400){p->vx+=1.6666666269302368f;if(p->vx>26.666666030883789f)p->vx=26.666666030883789f;}
  if(p->buttons&0x800){p->vx-=1.6666666269302368f;if(p->vx< -26.666666030883789f)p->vx=-26.666666030883789f;}
 }else{
  float distance=p->x-(D_004F1FC8+D_004F1FCC)/2.0f;
  if(distance>0)p->vx-=1.6666666269302368f;
  if(distance<0)p->vx+=1.6666666269302368f;
 }
 p->x=p->vx+(D_004F1FC8+D_004F1FCC)/2.0f;
 displacement=(D_004F1FD4+(D_004F1FD0-D_004F1FD4)/8.0f-p->y)+10.0f*func_00417440((u16)dptoli(0.5+65536.0*litodp(p->angle)/360.0));
 if(displacement>8.571428298950195f)displacement=8.571428298950195f;
 if(displacement< -8.571428298950195f)displacement=-8.571428298950195f;
 p->y+=displacement;
 if((p->angle+=6)>=360)p->angle=0;
}
