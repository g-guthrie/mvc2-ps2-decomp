/* Provisional: parameter table ownership, callback ABI and selector bounds remain unresolved. */
typedef unsigned char u8;typedef signed char s8;typedef unsigned short u16;typedef short s16;typedef int s32;
typedef struct {float x,y,z;} V3;
typedef struct {s32 vx,vy;s16 dx,dy;u8 animation,palette;u8 pad[2];} EffectParams;
typedef struct {u8 pad[0x7c];s16 count[2];} Game;
extern EffectParams D_004A6A90[];
extern Game *D_004C2794 __attribute__((section(".sdata")));
extern int func_001757E0(u8 *,int,int);
extern void func_0041A3C0(u8 *,u8 *);
void func_0041A1F0(u8 *p,u8 *owner)
{
 EffectParams *v;
 p[5]++;p[0x14c]=16;p[0x14d]=16;p[0x14e]=16;p[0x14f]=16;
 v=&D_004A6A90[p[0x20]];
 *(V3 *)(p+0x34)=*(V3 *)(owner+0x34);
 if(*(s16 *)(p+0x140)==0){*(float *)(p+0x34)+=1.6666666269302368f*(float)v->dx;*(float *)(p+0x5c)=1.6666666269302368f*(float)v->vx/65536.0f;}
 else {*(float *)(p+0x34)-=1.6666666269302368f*(float)v->dx;*(float *)(p+0x5c)=-(1.6666666269302368f*(float)v->vx/65536.0f);}
 *(float *)(p+0x38)+=2.142857074737549f*(float)v->dy;*(float *)(p+0x60)=2.142857074737549f*(float)v->vy/65536.0f;
 *(float *)(p+0x68)=0.0f;*(float *)(p+0x6c)=0.0f;
 p[0x1b0]=68;p[0x1b1]=68;p[0x1b5]=v->palette;p[0x1b2]=*(u16 *)(p+0x1c0)=0;*(s32 *)(p+0x1d8)=0;
 D_004C2794->count[p[2]]++;
 func_001757E0(p,23,v->animation);func_0041A3C0(p,owner);
}
