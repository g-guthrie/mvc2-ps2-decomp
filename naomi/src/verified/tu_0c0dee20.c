/* Exact movement-state setup, mirrored velocity and acceleration, and animation selection. */
/* Assembled by tools/clone.py from verified twins. */
#include "objects.h"
extern void func_0c045248(struct Actor *,int);
extern void func_0c02a0c4(struct Actor *,int,int);

void func_0c0dee20(struct Actor *a)
{
 int zero=0,one=1;
 a->b6=a->b7=a->b5=zero;
 switch(a->b4c9){case 0:a->b1e9=zero;goto strength;case 1:a->b1e9=5;goto strength;case 2:a->b1e9=one;strength:a->b1a3=one;break;}
 func_0c045248(a,21);
}

/* func_0c0dee5e: no verified twin. Ghidra draft:
*/
void func_0c0dee5e(struct Actor *a)
{
 float stopped=0.0f;
 a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;
 if(!a->i204){
 func_0c02a0c4(a,2,0);
 a->f92=a->b1d2?13.33333302f:-13.33333302f;
 }else{
 func_0c02a0c4(a,2,4);
 a->f92=a->b1d2?16.666666031f:-16.666666031f;
 a->f104=a->b1d2?-0.41666666f:0.41666666f;
 }
}

/* func_0c0deeda: no verified twin. Ghidra draft:
*/
void func_0c0deeda(struct Actor *a){if(!a->i204)func_0c02a0c4(a,2,1);else func_0c02a0c4(a,2,5);}
