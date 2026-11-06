/* Exact 0x0c1a51b4..0x0c1a5250: follow the parent horizontally, integrate vertical motion, and clean up the effect. */
#include "objects.h"
extern char func_0c029fc4(struct Actor *);
extern void func_0c037688(struct Actor *);
void func_0c1a5226(struct Actor *);
void func_0c1a51b4(struct Actor *a)
{
 if(a->b19f)goto cleanup;
 a->f56+=a->f96;a->f96+=a->f108;
 a->f52=((struct Actor *)((struct LinkedActor *)a)->p24)->f52;
 a->f52+=a->w130?65.0f:-65.0f;
 if(func_0c029fc4(a)>=0)goto done;
 cleanup:func_0c1a5226(a);return;
 done:return;
}
void func_0c1a5226(struct Actor *a){a->b4++;a->b12c=0;func_0c037688(a);}
