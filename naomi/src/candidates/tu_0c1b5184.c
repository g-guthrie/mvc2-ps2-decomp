/* Candidate: owner animation effect update. Free wrapper and literal pools are exact; main update differs in temporary registers and bank-call scheduling (24 bytes). */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c037688(struct Actor *);
void func_0c1b5184(struct Actor *a,struct Actor *owner)
{
 char feedback;
 if((char)owner->b1d0!=(char)a->b34||owner->b5||owner->b1e9!=a->s28)goto cleanup;
 feedback=owner->b19e;
 if(feedback&&!(feedback&1)&&!a->b35){
 struct Actor *linked;
 a->b12c=1;a->b35=1;
 linked=owner->p1b0;
 *(struct Vec3_tu5_03 *)&a->f52=*(struct Vec3_tu5_03 *)&linked->f52;
 }
 if(!a->b12c)return;
 if(!a->b5){
 if(func_0c02a026(a)>=0)return;
 if(owner->b1a0)return;
 if(a->b33)goto cleanup;
 a->b5++;func_0c02a0c4(a,23,(char)a->b32*3+14);return;
 }
 if(func_0c02a026(a)>=0)return;
 cleanup:a->b4++;a->b12c=0;
}
void func_0c1b5248(struct Actor *a){func_0c037688(a);}
