/* Slide/recover handlers at 0x0c0aedc4; exact. The trailing (void)0 expression
 * statement suppresses the tail call that retail does not take. */
#include "objects.h"
extern void func_0c0437b8(struct Actor *);
extern void (*table_0c2448b0[])(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int);
extern void func_0c152460(struct Actor *,int);
void func_0c0aedc4(struct Actor *a)
{
 a->b3f8=2;a->b328=5;
 if(a->f108!=0.0f)a->f108-=1.0f;
 a->f80=*(float *)((char *)a+0x284)+(a->f108/a->f104)*1.0f;
 a->f84=*(float *)((char *)a+0x288)+(a->f108/a->f104)*1.0f;
 if(func_0c02a026(a)>=0)return;
 a->b3f9=0;a->b3f8=0;a->b327=0;a->b328=0;
 *(struct Vec3_tu5_03 *)&a->f80=*(struct Vec3_tu5_03 *)((char *)a+0x284);
 func_0c0437b8(a);
}
void func_0c0aee50(struct Actor *a)
{
 if(!a->b6){a->b6++;func_0c02a0c4(a,21,14);}
 else{if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(a->b141){a->b141=0;func_0c152460(a,0);(void)0;}}
}
void func_0c0aeea0(struct Actor *a){table_0c2448b0[a->b6](a);}
