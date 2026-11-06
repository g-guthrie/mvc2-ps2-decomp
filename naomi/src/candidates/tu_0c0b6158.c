/* Action dispatcher and pools exact; main handler differs in three mirror-flag register bytes. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c025900(struct Actor *,int,int),func_0c0438de(struct Actor *),func_0c0437b8(struct Actor *);
extern void (*table_0c244f58[])(struct Actor *);
void func_0c0b6158(struct Actor *a)
{
 float offset;int zero;struct Actor *child;
 func_0c02a026(a);offset=(float)a->b14b;zero=0;
 if(offset!=0.0f){if((short)a->w130)offset=-offset;a->f52+=offset;a->b14b=zero;}
 if(!a->b6){
 if(!a->b141)return;
 a->b6++;a->b141=zero;
 if(a->b1f9==2)a->f108=-0.80357140303f;
 child=a->p1c8;child->p1b4=a;child->b1f6=1;child->b1a1=32;child->b1d2=a->b1d2;
 func_0c025900(a,0,0);return;
 }
 else if(a->b140){if(a->b1f9==2){func_0c0438de(a);return;}else func_0c0437b8(a);}
}
void func_0c0b6208(struct Actor *a){table_0c244f58[a->b6](a);}
