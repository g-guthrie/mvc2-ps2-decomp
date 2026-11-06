/* Exact 0x0c1c59e8..0x0c1c5a38: terminate an effect when its selection flag and state agree. */
#include "objects.h"
extern struct SelectionFlags59e8 dat_0c2fb158;
extern void func_0c037688(struct Actor *);
void func_0c1c59e8(struct Actor *a)
{
 struct SelectionFlags59e8 *selection=&dat_0c2fb158;
 if(selection->flags[a->b32]&(16<<a->b33)){
 if(selection->state[a->b32]==3){a->b4++;a->b12c=0;}
 }
}
void func_0c1c5a26(struct Actor *a){func_0c037688(a);}
