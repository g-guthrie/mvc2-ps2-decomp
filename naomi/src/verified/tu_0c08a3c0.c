/* Exact 0x0c08a3c0..0x0c08a500: interpolate phase on a 32-unit cycle, derive mirrored velocity, dispatch motion states, and stop motion before changing animation. */
#include "objects.h"
extern short table_0c242246[];
extern void (*table_0c242544[])(struct Actor *,struct MotionContext8a3 *);
extern void func_0c02a0c4(struct Actor *,int,int);
void func_0c08a3c0(struct Actor *a,struct MotionContext8a3 *m)
{
 float target=(float)(a->b14b&127);
 float period=32.0f;
 if(m->target!=target){
 m->phase=m->target;m->target=target;m->step=m->target-m->phase;
 if(m->step>=16.0f)m->step-=period;
 if(m->step<=-16.0f)m->step+=period;
 m->step/=(float)(signed char)a->b142;
 }
 if(m->target==m->phase)m->step=0.0f;
 m->phase+=m->step;
 if(m->phase<0.0f)m->phase+=period;
 if(!(period>m->phase))m->phase-=period;
 a->b34=(int)m->phase;
}
void func_0c08a46a(struct Actor *a,struct MotionContext8a3 *m)
{
 short *pair=table_0c242246+(signed char)a->b141*2;
 float vx=(float)*pair++*1.66666663f;
 float vy=(float)*pair*2.1428571f;
 if(a->b1d2)vx=-vx;
 m->vx=vx;m->vy=vy;
}
void func_0c08a4a6(struct Actor *a,struct MotionContext8a3 *m){table_0c242544[a->b6](a,m);}
void func_0c08a4b8(struct Actor *a,struct MotionContext8a3 *m)
{
 float stopped=0.0f;
 a->b6++;
 a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
 func_0c02a0c4(a,21,30);
}
