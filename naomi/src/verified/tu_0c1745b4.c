#include "objects.h"
extern short dat_0c2f6830;
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c252ca8[])(struct LinkedActor *);
extern void func_0c02a18c(struct LinkedActor *,int,int,int);
extern void func_0c037d0c(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
struct Pair1745 {short x,y;};
extern struct Pair1745 table_0c252c50[][2];
void func_0c17460c(struct LinkedActor *);
void func_0c1746b0(struct LinkedActor *);
struct LinkedActor *func_0c1745b4(struct LinkedActor *owner)
{
 struct LinkedActor *a;
 int i;
 if(dat_0c2f6830<2)return 0;
 for(i=0;i<2;i++) {
   a=func_0c0374da(0,1,0);
   a->p16=func_0c17460c;
   a->p24=owner;
   a->s28=owner->sdc.w158.short_value;
   a->b32=i;
   a->w38=0x3000;
 }
 return a;
}
void func_0c17460c(struct LinkedActor *a) {table_0c252ca8[a->b4](a);}
void func_0c17461e(struct LinkedActor *a)
{
 a->b4++;
 a->sdc=a->p24->sdc;
 a->sdc.b12c=1;
 a->b2=a->p24->b2;
 a->b1=a->p24->b1;
 a->v80.x=a->p24->v80.x;
 a->v80.y=a->p24->v80.y;
 a->b1a3=a->p24->b1a3;
 a->b1a4=a->p24->b1a4;
 a->b48=a->p24->b48;
 a->v80=a->p24->v80;
 a->b36=a->p24->b36;
 a->pad11[0]=69;
 a->pad11[1]=0;
 a->b34=255;
 a->sdc.w130 ^= a->b32;
 a->b49=-1;
 func_0c1746b0(a);
}
void func_0c1746b0(struct LinkedActor *a)
{
 struct LinkedActor *owner=a->p24;
 char mode;
 float d;
 a->sdc.b12c=0;
 if(a->s28!=owner->sdc.w158.short_value) {a->b4=2;return;}
 { char *mp=(char *)owner+0x150; mode=mp[1]; }
 if(mode<0)return;
 if(a->b34!=(unsigned char)mode) {
    a->b34=mode;
    func_0c02a18c(a,23,0,a->b34);
    a->pad11[5]=a->sdc.pad1c[7];
    *(short *)((char *)a+0x1ac)=0;
    a->pad11[2]=0;
    *(unsigned int *)((char *)a+0x1c4)=0;
    dat_0c2f83f8->arr[a->b2]++;
 }
 *(struct LinkedActorVec3 *)&a->f52=*(struct LinkedActorVec3 *)&owner->f52;
 d=table_0c252c50[(unsigned char)owner->sdc.pad1c[7]][a->b32].x*1.66666663f;
 if(owner->sdc.w130) d=-d;
 a->f52 += d;
 a->f56 += table_0c252c50[(unsigned char)owner->sdc.pad1c[7]][a->b32].y*2.1428571f;
 a->sdc.b12c=1;
 func_0c037d0c(a);
}
void func_0c1747e6(struct LinkedActor *a) {a->b4++;a->sdc.b12c=0;}
void func_0c1747f4(struct LinkedActor *a) {func_0c037688(a);}
