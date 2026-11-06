/* Ten callbacks of one move set (0x0c0f9750-0x0c0f9a30). */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c0442fa(struct Actor *),func_0c0432ca(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c1b3e6c(struct Actor *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern float table_0c24a814[];
extern void (*table_0c24a7fc[])(struct Actor *),(*table_0c24a804[])(struct Actor *),(*table_0c24a81c[])(struct Actor *);
void func_0c0f9750(struct Actor *a)
{
 float stopped=0.0f;
 if(a->b19e&1)a->f92=stopped;
 a->f96=stopped;a->f104=stopped;a->f108=stopped;
 a->f52+=a->f92;a->f92+=a->f104;
 if(func_0c02a026(a)<0){a->sub2a4.b0=0;func_0c0437b8(a);}
}
void func_0c0f97ae(struct Actor *a){table_0c24a7fc[a->b6](a);}
void func_0c0f97c0(struct Actor *a)
{
 a->b6++;a->f56=a->f41c;((unsigned char *)a)[0x2a6]=50;((unsigned char *)a)[0x2a9]=1;
 a->b1f9=0;a->b205=48;func_0c0442fa(a);func_0c0432ca(a);func_0c02a0c4(a,21,4);
}
void func_0c0f9806(struct Actor *a)
{
 func_0c02a026(a);
 if(!(--((char *)a)[0x2a6]))func_0c0437b8(a);
}
void func_0c0f982e(struct Actor *a){table_0c24a804[a->b6](a);}
void func_0c0f9840(struct Actor *a)
{
 int zero=0;float stopped=0.0f;
 ((unsigned char *)a)[0x2a9]=zero;a->b6++;a->f56=a->f41c;a->b1f9=zero;
 a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
 func_0c0442fa(a);func_0c02a39a(a,zero);func_0c0432ca(a);
 if(a->b255==3)a->b1a1=63;else {goto s;s:a->b1a1=((unsigned char)a->b1a3<<1)+48;}
 a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 goto call;
call:func_0c02a0c4(a,21,(unsigned char)a->b1a3*2+5);
}
void func_0c0f990c(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){a->b6++;a->f92=table_0c24a814[(unsigned char)a->b1a3];if(!a->b1d2)a->f92=-a->f92;a->f104=0.0f;}
}
void func_0c0f9950(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;
 if(func_0c02a026(a)<0){float stopped;
  a->b6++;func_0c1b3e6c(a,2);stopped=0.0f;
  a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
  func_0c02a0c4(a,21,(unsigned char)a->b1a3*2+8);
 }
}
void func_0c0f99ba(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
 else if(a->b140){int one=1;a->b140=0;dat_0c2d9260.b5=one;dat_0c2d9260.b6=one;}
}
void func_0c0f99f2(struct Actor *a){table_0c24a81c[a->b6](a);}
