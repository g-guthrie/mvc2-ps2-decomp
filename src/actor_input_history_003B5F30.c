typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef float f32;
typedef struct {u8 prefix[0x34];f32 x,y;} ActorPosition;
typedef struct {u8 prefix[0x5c];f32 vx,vy;u8 unknown64[4];f32 ax,ay;} ActorMotion;
typedef struct {u16 samples[16];s8 read,write;} InputHistory;
extern int func_00175700(u8 *);
extern void func_001E7F60(u8 *);
extern int func_00174240(u8 *);
void func_003B5F30(u8 *p,u8 *q)
{
 ActorPosition *position=(ActorPosition *)p;
 ActorMotion *motion=(ActorMotion *)p;
 InputHistory *history=(InputHistory *)(p+0x88);
 position->x+=motion->vx;
 motion->vx+=motion->ax;
 position->y+=motion->vy;
 motion->vy+=motion->ay;
 history->samples[history->write]=*(u16 *)(q+0x35e);
 if(history->samples[history->read]&0x2000)position->y+=4.285714149475098f;
 if(history->samples[history->read]&0x1000)position->y-=2.142857074737549f;
 history->read++;
 history->write++;
 history->read&=15;
 history->write&=15;
 if(*(s8 *)(p+0x1b2)) {p[4]=2;p[5]=0;}
 if(*(s8 *)(p+0x1b3)) {p[4]=2;p[5]=0;}
 func_00175700(p);
 func_001E7F60(p);
 if(func_00174240(p)==0)p[4]=3;
}
