#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void func_0c043352(struct Actor *),func_0c0437b8(struct Actor *);
extern void (*table_0c249f84[])(struct Actor *),(*table_0c249f8c[])(struct Actor *,struct ActorSub2a4 *);
void func_0c0ef784(struct Actor *a,unsigned char *p){float stopped;int zero;a->b3f8=2;a->b328=5;stopped=0;zero=0;if(((char *)&a->w150)[1]==2){a->b3f8=a->b3f9=zero;a->b328=a->b327=zero;((char *)&a->w150)[1]=zero;a->f92=stopped;a->f104=stopped;}func_0c043352(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;if(func_0c02a026(a)<0){a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;func_0c0437b8(a);return;}if(--p[5]==0 && a->b19e){a->b1a1=62;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;}}
void func_0c0ef87e(struct Actor *a){table_0c249f84[a->b6](a);}
void func_0c0ef890(struct Actor *a){table_0c249f8c[a->b7](a,&a->sub2a4);}
