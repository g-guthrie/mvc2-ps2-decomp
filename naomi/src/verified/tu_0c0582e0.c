#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern struct ActorMotionFixed4 dat_0c23f800[];
extern short dat_0c23f820[];
void func_0c0582e0(struct Actor *a)
{
 a->b1f2=3;
 func_0c02a026(a);
 if(a->b141){
 a->b141=0;a->b7++;
 a->f92=dat_0c23f800[(unsigned char)a->b1a3].x_speed*1.66666663f/65536.0f;
 a->f104=dat_0c23f800[(unsigned char)a->b1a3].x_acceleration*1.66666663f/65536.0f;
 a->f96=dat_0c23f800[(unsigned char)a->b1a3].y_speed*2.1428571f/65536.0f;
 a->f108=dat_0c23f800[(unsigned char)a->b1a3].y_acceleration*2.1428571f/65536.0f;
 if(!a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}
 }
}
void func_0c058398(struct Actor *a)
{
 a->b1f2=3;
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c02a026(a);
 if(a->f96>0)return;
 {
 a->b7++;
 a->f92=dat_0c23f820[(unsigned char)a->b1a3]*1.66666663f/256.0f;
 if(!a->b1d2)a->f92=-a->f92;
 }
}
