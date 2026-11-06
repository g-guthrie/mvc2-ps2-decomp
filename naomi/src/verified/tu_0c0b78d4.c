/* Exact 0x0c0b78d4..0x0c0b79ac: initialize, update animation feedback, and dispatch the action state. */
#include "objects.h"
extern void func_0c0442fa(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c1a72d4(struct Actor *,int),func_0c0453c4(struct Actor *,int);
extern char func_0c02a026(struct Actor *);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void (*table_0c245110[])(struct Actor *);
void func_0c0b7922(struct Actor *);
void func_0c0b78d4(struct Actor *a)
{
 float zero;int cleared;
 a->b6++;func_0c0442fa(a);func_0c02a39a(a,0);
 zero=0.0f;a->f108=a->f104=a->f96=a->f92=zero;
 cleared=0;a->f56=a->f41c;a->b1fc=cleared;a->b1f9=cleared;
 func_0c02a0c4(a,21,5);func_0c0b7922(a);
}
void func_0c0b7922(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c1a72d4(a,6);func_0c0453c4(a,23);return;}
 if(a->b141){
 int one=1;struct MotionGlobal_0c2d9260 *state;
 a->b141=0;state=&dat_0c2d9260;
 if(!a->b140)state->b5=one;else state->b5=3;state->b6=one;
 }
}
void func_0c0b7972(struct Actor *a){table_0c245110[a->b6](a);}
