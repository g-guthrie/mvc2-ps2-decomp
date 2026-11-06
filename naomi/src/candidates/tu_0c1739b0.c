/* Complete 0x0c1739b0..0x0c173d38 group. Six functions exact; initializer (903/904) differs in one instruction: retail passes placement[3]+(b34&2)*4 untruncated (mov r0,r6); the plain sum evaluates b34 first, so the (unsigned char) cast on placement[3] (extu.b) is kept to hold retail order. */
#define A(a) ((struct Actor *)(a))
#define SLOT(a,n) (*(int *)&A(a)->pad5ba[(n)-0xd0])
#include "objects.h"
extern struct LinkedActor *func_0c0374da(int,int,int);
extern int func_0c02849a(void);
extern short table_0c252ac0[][7];
extern void (*table_0c252b70[])(struct LinkedActor *);
void func_0c173ab8(struct LinkedActor *);
struct LinkedActor *func_0c1739b0(struct LinkedActor *owner, short x, short y)
{
    struct LinkedActor *a;
    if ((a=func_0c0374da(0,1,0)) != 0) {
        a->p16=func_0c173ab8;
        a->p24=owner;
        a->w38=0x2f02;
        a->wcc.dword_value=(unsigned short)owner->sdc.w158.short_value;
        ((int *)a->pad10)[0]=x;
        ((int *)a->pad10)[1]=y;
    }
    return a;
}
struct LinkedActor *func_0c173a04(struct LinkedActor *owner)
{
    short i;
    struct LinkedActor *a;
    for(i=0;i<8;i++) {
        short *entry=&table_0c252ac0[func_0c02849a() & 7][0];
        if((a=func_0c1739b0(owner,0,0)) != 0) {a->b33=0;a->b32=i;((int *)a->pad10)[2]=entry[0];}
        if((a=func_0c1739b0(owner,entry[3],entry[4])) != 0) {a->b33=1;a->b32=i;((int *)a->pad10)[2]=entry[1];}
        if((a=func_0c1739b0(owner,entry[3]+entry[5],entry[4]+entry[6])) != 0) {a->b33=1;a->b32=i;((int *)a->pad10)[2]=entry[2];}
    }
    return a;
}
void func_0c173ab8(struct LinkedActor *a) { table_0c252b70[a->b4](a); }
extern short dat_0c252b80[],dat_0c252b30[][4];
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern char func_0c02a026(struct LinkedActor *);
extern void func_0c02a0c4(struct LinkedActor *,int,int),func_0c037d0c(struct LinkedActor *),func_0c037688(struct LinkedActor *);
void func_0c173cb2(struct LinkedActor *),func_0c173d12(struct LinkedActor *);
void func_0c173aec(register struct LinkedActor *a)
{
 struct LinkedActor *p=a->p24;short direction;short zero;int x,y;unsigned char *properties;register short *placement;register float xscale;
 a->b4++;a->s28=5;a->sdc=p->sdc;a->sdc.b12c=1;a->b2=p->b2;a->b1=p->b1;a->v80.x=p->v80.x;a->v80.y=p->v80.y;a->b1a3=p->b1a3;a->b1a4=p->b1a4;a->b48=p->b48;a->v80=p->v80;a->b36=p->b36;
 a->sdc.b12c=a->b32&1;a->b36=8;A(a)->b34=A(a)->w130=a->b32>>1;A(a)->w130&=1;
 direction=16;if(A(p)->w130)direction=-16;xscale=1.66666663f;
 a->f52=p->f52+direction*xscale;a->f56=p->f56+291.42856f;a->pad11[0]=66;a->pad11[1]=66;
 zero=dat_0c252b80[func_0c02849a()&15];A(a)->b1a1=zero;zero=0;A(a)->w1ac=zero;A(a)->b19e=zero;A(a)->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
 properties=(unsigned char *)a+0xcc;placement=dat_0c252b30[*(int *)(properties+12)];x=*(int *)(properties+4);y=*(int *)(properties+8);x+=placement[0];y+=placement[1];if(placement[2])A(a)->w130^=1;
 func_0c02a0c4(a,21,(unsigned char)placement[3]+(A(a)->b34&2)*4);
 if(A(a)->b34&1)x=-x;if(A(a)->b34&2){y=-y;A(a)->w130^=1;}
 a->f52+=(short)x*xscale;a->f56+=(short)y*2.1428571f;func_0c173cb2(a);
}
void func_0c173cb2(struct LinkedActor *a)
{
 struct LinkedActor *p=a->p24;a->sdc.b12c^=1;
 if(--a->s28<0)goto cleanup;
 if(a->wcc.dword_value!=(unsigned short)p->sdc.w158.short_value)goto cleanup;
 func_0c02a026(a);if(!a->b33&&(func_0c02849a()&7))goto done;goto draw;draw:func_0c037d0c(a);return;
 cleanup:func_0c173d12(a);return;
 done:return;
}
void func_0c173d0e(struct LinkedActor *a){}
void func_0c173d12(struct LinkedActor *a){a->sdc.b12c=0;func_0c037688(a);}
