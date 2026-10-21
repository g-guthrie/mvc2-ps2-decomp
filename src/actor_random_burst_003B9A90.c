#pragma padloop on
typedef unsigned char u8;
typedef struct {u8 prefix[0x34];float x,y;} ActorPosition;
typedef struct {u8 prefix[0x5c];float vx,vy;u8 gap[4];float ax,ay;} ActorMotion;
extern void func_003BA140(u8 *);
extern int func_00174170(void);
extern int func_001757E0(u8 *,int,int);
extern float data_f32_00474490[4];
extern const u8 D_004C2050[4] __attribute__((section(".sdata")));
void func_003B9A90(u8 *p) {
 ActorPosition *position=(ActorPosition *)p;
 ActorMotion *motion=(ActorMotion *)p;
 func_003BA140(p);
 p[0x24]=11;p[0x13c]=1;
 motion->vx=0.0f;motion->vy=0.0f;motion->ax=0.0f;motion->ay=0.0f;
 position->y+=205.7142791748047f;
 position->x+=-53.33333206176758f+1.6666666269302368f*(float)(func_00174170()&63u);
 position->y+=-137.14285278320312f+2.142857074737549f*(float)(func_00174170()&127u);
 motion->vy=data_f32_00474490[func_00174170()&3];
 func_001757E0(p,23,D_004C2050[func_00174170()&3]);
}
