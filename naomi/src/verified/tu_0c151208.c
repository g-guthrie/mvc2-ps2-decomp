#include "objects.h"
/* This callback family stores its effect ground plane at offset 0xd0. */
#define EFFECT_FLOOR(a) (*(float *)&(a)->pad5ba[0])
void func_0c151208(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(EFFECT_FLOOR(a)<a->f56)){a->f56=EFFECT_FLOOR(a);a->b6++;a->s28=5;a->f92=0.0f;a->f104=0.0f;a->f96=3.21428561211f;a->f108=-0.234375f;}
}
void func_0c15127a(struct Actor *a)
{
 a->f80+=0.01200000010431f;a->f84-=0.018f;
 if(--a->s28<=0){a->b6++;a->s28=5;}
}
void func_0c1512b0(struct Actor *a)
{
 a->f80+=0.016000001f;a->f84-=0.02400000021f;
 if(--a->s28<=0){a->b6++;a->f80=a->f84=1.0f;}
}
void func_0c1512ec(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(!(EFFECT_FLOOR(a)<a->f56)){a->f56=EFFECT_FLOOR(a);a->b6++;a->s28=5;}
}
