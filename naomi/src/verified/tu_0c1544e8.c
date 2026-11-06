/* Animation-follow allocation, dispatch, initialization and wait handlers. */
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*dat_0c250664[])(struct LinkedActor *),(*dat_0c250674[])(struct LinkedActor *),(*dat_0c250684[])(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037688(struct LinkedActor *);
extern char func_0c02a026(struct LinkedActor *);
void func_0c15451c(struct LinkedActor *),func_0c154788(struct LinkedActor *),func_0c154804(struct LinkedActor *),func_0c15485e(struct LinkedActor *),func_0c1548c4(struct LinkedActor *),func_0c15493c(struct LinkedActor *);
struct LinkedActor *func_0c1544e8(struct LinkedActor *owner,unsigned char variant)
{
 struct LinkedActor *a;
 if((a=func_0c0374da(0,1,0))!=0){a->p16=func_0c15451c;a->p24=owner;a->w38=0x1602;a->b32=variant;}
 return a;
}
void func_0c15451c(struct LinkedActor *a){dat_0c250664[a->b4](a);}
void func_0c15452e(struct LinkedActor *a){dat_0c250674[a->b32](a);}
void func_0c154542(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;
 a->b36=a->p24->b36;a->b36=0;a->f52=a->p24->f52;a->f56=a->p24->f56;func_0c154788(a);
}
void func_0c1545c0(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;
 a->b36=a->p24->b36;a->b36=0;a->f52=a->p24->f52;a->f56=a->p24->f56;func_0c154804(a);
}
void func_0c154660(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;
 a->b36=a->p24->b36;a->b36=11;a->f52=a->p24->f52;a->f56=a->p24->f56;a->f56+=548.571411133f;func_0c15485e(a);
}
void func_0c1546ea(struct LinkedActor *a)
{
 a->b4++;a->sdc=a->p24->sdc;a->sdc.b12c=1;a->b2=a->p24->b2;a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;a->v80.y=a->p24->v80.y;a->b1a3=a->p24->b1a3;a->b1a4=a->p24->b1a4;a->b48=a->p24->b48;a->v80=a->p24->v80;
 a->b36=a->p24->b36;a->b36=10;a->f52=a->p24->f52;a->f56=a->p24->f56;a->f56+=548.571411133f;func_0c1548c4(a);
}
void func_0c154774(struct LinkedActor *a){dat_0c250684[a->b32](a);}
void func_0c154788(struct LinkedActor *a)
{
 char (*decode)(struct LinkedActor *);int enabled;
 a->f52=a->p24->f52;a->f56=a->p24->f56;func_0c02a0c4(a,21,5);decode=func_0c02a026;enabled=1;
 for(;;){if(((char *)&((struct Actor *)a->p24)->w150)[1]==((char *)&((struct Actor *)a)->w150)[1]){a->sdc.b12c=enabled;break;}
 if(decode(a)<0){func_0c15493c(a);break;}}
}
void func_0c154804(struct LinkedActor *a)
{
 char (*decode)(struct LinkedActor *);int enabled;
 a->f52=a->p24->f52;a->f56=a->p24->f56;func_0c02a0c4(a,21,6);decode=func_0c02a026;enabled=1;
 for(;;){if(((char *)&((struct Actor *)a->p24)->w150)[1]==((char *)&((struct Actor *)a)->w150)[1]){a->sdc.b12c=enabled;break;}
 if(decode(a)<0){func_0c15493c(a);break;}}
}
void func_0c15485e(struct LinkedActor *a)
{
 char (*decode)(struct LinkedActor *);int enabled;
 a->f52=a->p24->f52;a->f56=a->p24->f56;a->f56+=548.571411133f;func_0c02a0c4(a,21,7);decode=func_0c02a026;enabled=1;
 for(;;){if(((char *)&((struct Actor *)a->p24)->w150)[1]==((char *)&((struct Actor *)a)->w150)[1]){a->sdc.b12c=enabled;break;}
 if(decode(a)<0){func_0c15493c(a);break;}}
}
void func_0c1548c4(struct LinkedActor *a)
{
 char (*decode)(struct LinkedActor *);int enabled;
 a->f52=a->p24->f52;a->f56=a->p24->f56;a->f56+=548.571411133f;func_0c02a0c4(a,21,8);decode=func_0c02a026;enabled=1;
 for(;;){if(((char *)&((struct Actor *)a->p24)->w150)[1]==((char *)&((struct Actor *)a)->w150)[1]){a->sdc.b12c=enabled;break;}
 if(decode(a)<0){func_0c15493c(a);break;}}
}
void func_0c15493c(struct LinkedActor *a){a->b4++;a->sdc.b12c=0;func_0c037688(a);}
