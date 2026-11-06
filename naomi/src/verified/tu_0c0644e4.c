/* Exact 0x0c0644e4..0x0c064520: copy the actor callback table and stop motion before the next state. */
#include "objects.h"
extern unsigned int dat_0c240334[];
extern void func_0c0437b8(struct Actor *);
void func_0c0644e4(struct Actor *a)
{
 register unsigned int i;register unsigned int limit=112;
 register unsigned int *out=(unsigned int *)a->p428;register unsigned int *in=dat_0c240334;
 i=0;
 copy_next:*(unsigned int *)((char *)out+i)=*(unsigned int *)((char *)in+i);i+=4;if(i<limit)goto copy_next;
}
void func_0c064500(struct Actor *a)
{
 float stopped=0.0f;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;func_0c0437b8(a);
}
