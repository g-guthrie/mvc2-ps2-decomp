#pragma padloop on
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef struct {u8 prefix[0x34];float x,y,z;u8 pad40[0x1C];float vx,vy,vz,ax,ay;} Motion;
extern int func_00174470(const void*),func_00175700(u8*);
extern void func_001E7F60(u8*);
void func_00397FC0(u8 *p)
{
 Motion *motion=(Motion*)p;
 if(!*(s8*)(p+0x1B2)&&!*(s8*)(p+0x1B3)){
  motion->x+=motion->vx;motion->vx+=motion->ax;motion->y+=motion->vy;motion->vy+=motion->ay;
  if(!func_00174470(p)){p[4]=2;return;}
  if(!(*(float*)((*(u8**)(p+0x18))+0x430)<=motion->y)){++p[5];*(s16*)(p+0x1C)=60;}
  else{func_00175700(p);func_001E7F60(p);return;}
 }
 ++p[6];*(s16*)(p+0x1C)=30;motion->vy=8.571428298950195f;motion->ay=-0.5357142686843872f;
}
