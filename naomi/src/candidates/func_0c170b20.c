/* Complete connected effect group. Seventeen functions match independently.
 * Position update 170cba still differs in scheduling and register allocation;
 * its position-offset pool also differs. */
#include "objects.h"
typedef void (*handler2_0c170b20)(struct LinkedActor *, struct LinkedActor *);
typedef void (*handler_0c170b20)(struct LinkedActor *);

extern struct LinkedActor *func_0c0374da(int a, int b, int c);
extern handler2_0c170b20 dat_0c2527ec[];
extern handler_0c170b20 dat_0c2527f8[];

void func_0c170bca(struct LinkedActor *p);
void func_0c170be0(struct LinkedActor *p);

struct LinkedActor *func_0c170b20(struct LinkedActor *p, unsigned char b, unsigned char c)
{
    struct LinkedActor *q;

    if ((q = func_0c0374da(0, 1, 0)) != 0) {
        q->p16 = func_0c170bca;
        q->w38 = 0x2e00;
        q->p24 = p;
        q->b1 = p->b1;
        *(&q->b32) = b;
        *(&q->b33) = c;
    }
    return q;
}

struct LinkedActor *func_0c170b6e(struct LinkedActor *p, unsigned char b, unsigned char c, unsigned char d)
{
    struct LinkedActor *q;

    if ((q = func_0c0374da(0, 1, 1)) != 0) {
        q->p16 = func_0c170bca;
        q->w38 = 0x2e00;
        q->p24 = p->p24;
        q->p20 = p;
        q->b1 = p->b1;
        *(&q->b32) = b;
        *(&q->b33) = c;
        q->b35 = d;
    }
    return q;
}

void func_0c170bca(struct LinkedActor *p)
{
    dat_0c2527ec[p->b32](p, p->p24);
}

void func_0c170be0(struct LinkedActor *p)
{
    dat_0c2527f8[p->b4](p);
}

#define A(a) ((struct Actor *)(a))
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern short dat_0c2527e0[];
extern void (*table_0c252808[])(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c1710c8(struct LinkedActor *,struct LinkedActor *);
extern struct LinkedActor *func_0c170b6e(struct LinkedActor *,unsigned char,unsigned char,unsigned char);
void func_0c170cba(int,struct LinkedActor *);
void func_0c170c04(struct LinkedActor *a,struct LinkedActor *owner)
{
 int one,zero;
 a->b4++;a->sdc=owner->sdc;one=1;a->sdc.b12c=one;
 a->b2=owner->b2;a->b1=owner->b1;a->v80.x=owner->v80.x;a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;a->b1a4=owner->b1a4;a->b48=owner->b48;a->v80=owner->v80;a->b36=owner->b36;
 a->sdc.b12c=one;a->b49=-2;zero=0;A(a)->b1a1=53;A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;
 dat_0c2f83f8->arr[a->b2]++;a->pad11[0]=66;a->pad11[1]=66;
 func_0c02a0c4(a,23,5);a->s28=one;func_0c170cba((int)a,owner);
}
void func_0c170cba(int cursor,struct LinkedActor *owner)
{
 register struct LinkedActor *a=(struct LinkedActor *)cursor;
 short *offsets;register float scale;
 a->b36=owner->b36;
 if((unsigned char)A(owner)->b159!=9){a->b4++;func_0c1710c8(a,owner);return;}
 offsets=dat_0c2527e0;
 a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;scale=1.66666663f;
 cursor=(int)offsets;
 if(!A(a)->w130){cursor=(int)((short *)cursor+*(unsigned char *)((char *)a+33)*2);a->f52+=*(short *)cursor*scale;}
 else{cursor=(int)((short *)cursor+*(unsigned char *)((char *)a+33)*2);a->f52-=*(short *)cursor*scale;}
 offsets+=*(unsigned char *)((char *)a+33)*2;
 a->f56+=offsets[1]*2.1428571f;
 table_0c252808[(unsigned char)a->b5](a);
}
void func_0c170da4(struct LinkedActor *a)
{
 func_0c170b6e(a,2,0,0);a->b5++;
}

extern char func_0c02a026(struct LinkedActor *);
extern int func_0c028642(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *),func_0c0344a0(struct LinkedActor *,int);
extern struct LinkedActor *func_0c170b6e(struct LinkedActor *,unsigned char,unsigned char,unsigned char);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern void (*table_0c252814[])(struct LinkedActor *,struct LinkedActor *),(*table_0c252824[])(struct LinkedActor *,struct LinkedActor *);
void func_0c170fb6(struct LinkedActor *,struct LinkedActor *);
void func_0c1710c8(struct LinkedActor *,struct LinkedActor *),func_0c1710da(struct LinkedActor *,struct LinkedActor *),func_0c1710f2(struct LinkedActor *,struct LinkedActor *);
void func_0c170dc2(struct LinkedActor *a,struct LinkedActor *owner)
{
 char *state=(char *)&A(owner)->sub2a4;
 func_0c02a026(a);a->s28++;
 func_0c170b6e(a,1,a->s28&1,a->s28&3);
 if(*state){a->b5++;func_0c02a0c4(a,23,6);}
}
void func_0c170e12(struct LinkedActor *a,struct LinkedActor *owner)
{
 if(func_0c02a026(a)<0){a->b4++;func_0c1710c8(a,owner);}
}
void func_0c170e42(struct LinkedActor *a,struct LinkedActor *owner){table_0c252814[a->b4](a,owner);}
void func_0c170e54(struct LinkedActor *a,struct LinkedActor *owner)
{
 struct LinkedActor *p=a->p20;
 int one=1,zero=0;void (*set_animation)(struct LinkedActor *,int,int);
 a->b4++;a->sdc=p->sdc;a->sdc.b12c=one;a->b2=p->b2;a->b1=p->b1;
 a->v80.x=p->v80.x;a->v80.y=p->v80.y;a->b1a3=p->b1a3;a->b1a4=p->b1a4;a->b48=p->b48;a->v80=p->v80;a->b36=p->b36;
 a->sdc.b12c=one;a->b49=-2;A(a)->b1a1=48;A(a)->w1ac=zero;A(a)->b19e=zero;*(void **)&A(a)->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 if(!a->b35)a->pad11[0]=66;else a->pad11[0]=96;
 a->pad11[1]=66;((struct MeActor *)a)->blk_dc.b13e=((struct MeActor *)a)->blk_dc.b13f=26;
 a->f52=p->f52;a->f56=p->f56;a->f60=p->f60;
 if(!A(a)->w130)a->f52+=-53.3333321f;else a->f52+=53.3333321f;
 if(!A(a)->w130)A(a)->f104=-50.0f;else A(a)->f104=50.0f;
 set_animation=func_0c02a0c4;A(a)->f92=0.0f;
 if(a->b32==2){set_animation(a,23,0);goto activation_done;}
 if(!a->b33)set_animation(a,23,2);else set_animation(a,23,3);
 activation_done:func_0c170fb6(a,owner);
}
void func_0c170fb6(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->b36=owner->b36;
 if((unsigned char)A(owner)->b159!=9){a->b4++;func_0c1710da(a,owner);return;}
 table_0c252824[(unsigned char)a->b5](a,owner);
}
void func_0c170fe6(struct LinkedActor *a,struct LinkedActor *owner)
{
 char *state=(char *)&A(owner)->sub2a4;
 func_0c1710f2((A(a)->f92+=A(a)->f104,a),a->p20);func_0c02a026(a);func_0c037d0c(a);
 if(*state){a->b5++;func_0c02a0c4(a,23,a->b32==2?1:4);return;}
 if(!func_0c028642(a)){a->b4++;func_0c1710da(a,owner);}
}
void func_0c171092(struct LinkedActor *a,struct LinkedActor *owner)
{
 func_0c1710f2(a,a->p20);
 if(func_0c02a026(a)<0){a->b4++;func_0c1710da(a,owner);}
}
void func_0c1710c8(struct LinkedActor *a,struct LinkedActor *owner){a->b4++;a->sdc.b12c=0;func_0c0344a0(a,43);}
void func_0c1710da(struct LinkedActor *a,struct LinkedActor *owner){a->b4++;a->sdc.b12c=0;}
void func_0c1710e8(struct LinkedActor *a,struct LinkedActor *owner){a->sdc.b12c=0;func_0c037688(a);}
void func_0c1710f2(struct LinkedActor *a,struct LinkedActor *owner)
{
 a->f52=owner->f52;a->f56=owner->f56;a->f60=owner->f60;
 if(a->b32==2){if(!A(a)->w130)a->f52+=-26.666666031f;else a->f52+=26.666666031f;}
 else{if(!A(a)->w130)a->f52+=-53.3333321f;else a->f52+=53.3333321f;}
 a->f52+=A(a)->f92;
}
