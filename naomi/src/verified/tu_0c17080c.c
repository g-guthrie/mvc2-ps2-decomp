/* Exact 0x0c17080c..0x0c170b20: constructors, owner guards, animation and history tracking. */
#include "objects.h"

#define M(a) ((struct Actor *)(a))
struct Rec1708 {float x,y;unsigned int state,command;};
extern short dat_0c2f6830;
extern struct LinkedActor *func_0c0374da(int,int,int);
extern void (*table_0c2527d4[])(struct LinkedActor *,struct LinkedActor *);
extern void func_0c02a18c(struct LinkedActor *,int,int,int);
extern signed char func_0c02a026(struct LinkedActor *);
extern void func_0c037d0c(struct LinkedActor *);
extern void func_0c037688(struct LinkedActor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
void func_0c170864(struct LinkedActor *);
void func_0c170a30(int,struct LinkedActor *);
void func_0c170a7c(struct LinkedActor *,struct LinkedActor *);
int func_0c17080c(struct LinkedActor *owner)
{
 int i;struct LinkedActor *a;
 if(dat_0c2f6830<=4)return 0;
 for(i=0;i<4;i++) {
   if((a=func_0c0374da(0,1,1)) != 0) {
      a->w38=0x2d02;
      a->b32=i;
      a->p16=func_0c170864;
      a->p24=owner;
   }
 }
 return i;
}
void func_0c170864(struct LinkedActor *a) {table_0c2527d4[a->b4](a,a->p24);}
void func_0c170878(struct LinkedActor *a,struct LinkedActor *owner)
{
 int base;
 a->sdc=owner->sdc;
 a->sdc.b12c=1;
 a->b2=owner->b2;
 a->b1=owner->b1;
 a->v80.x=owner->v80.x;
 a->v80.y=owner->v80.y;
 a->b1a3=owner->b1a3;
 a->b1a4=owner->b1a4;
 a->b48=owner->b48;
 a->v80=owner->v80;
 a->b36=owner->b36;
 a->b4++;
 a->b36=owner->b36;
 a->b49=a->b32+1;
 a->pad11[0]=64;a->pad11[1]=64;
 a->sdc.pad1[0]=1;
 *(short *)&a->sdc.pad1[1]=*(short *)&owner->sdc.pad1[1]+1;
 func_0c170a30((int)a,owner);
 func_0c170a7c(a,owner);
 base=50;if(a->b32==3)base=53;
 base+=(unsigned char)a->b1a3;M(a)->b1a1=base;
 M(a)->w1ac=0;
 M(a)->b19e=0;
 M(a)->p1c4=0;
 dat_0c2f83f8->arr[a->b2]++;
 M(a)->w1ac|=16;
 func_0c037d0c(a);
}
void func_0c170988(register struct LinkedActor *a,struct LinkedActor *owner)
{
 struct ActorSubByteState *state=(struct ActorSubByteState *)&M(owner)->sub2a4;
 if(owner->b5 || M(owner)->b1e9!=1 || (unsigned char)M(owner)->b159!=21)goto close;
 a->b36=owner->b36;a->b49=a->b32+1;a->sdc.pad1[0]=1;
 *(short *)&a->sdc.pad1[1]=*(short *)&owner->sdc.pad1[1]+1;
 if(!a->b5){
  if(*(char *)&state->b5<0){a->b5++;a->s28=4-(unsigned char)owner->b32;return;}
  func_0c170a7c(a,owner);if(!M(a)->b19e)func_0c037d0c(a);return;
 }
 if(--a->s28==0){close:a->b4=2;a->sdc.b12c=0;}
 else func_0c170a7c(a,owner);
}
void func_0c170a2a(struct LinkedActor *a) {func_0c037688(a);}
void func_0c170a30(int cursor,struct LinkedActor *owner)
{
 /* The incoming 32-bit object address is reused as the loop counter. */
 struct Rec1708 *r=(struct Rec1708 *)(cursor+0x88);
 cursor=0;do{
  r->x=owner->f52;r->y=owner->f56;
  r->state=(unsigned short)owner->sdc.w158.short_value;
  r->command=M(owner)->b14b;
  r++;cursor++;
 }while(cursor<4);
}
void func_0c170a7c(struct LinkedActor *a,struct LinkedActor *owner)
{
 int i,limit;register struct Rec1708 *r=(struct Rec1708 *)((char *)a+0x88);
 a->f52=r->x;a->f56=r->y;a->sdc.w158.short_value=r->state;
 func_0c02a18c(a,M(a)->b159,M(a)->b158,r->command);
 limit=3;i=0;do{*r=r[1];r++;i++;}while(i<limit);
 if(!a->b32){
  r->x=owner->f52;r->y=owner->f56;r->state=(unsigned short)owner->sdc.w158.short_value;
  r->command=M(owner)->b14b;
 }else{
  struct LinkedActor *source=*(struct LinkedActor **)((char *)a+8);
  r->x=source->f52;r->y=source->f56;r->state=(unsigned short)source->sdc.w158.short_value;
  r->command=M(source)->b14b;
 }
}
