/* Candidate: 3147/3208 bytes equal; every function and pool is at its retail
 * address. Remaining scratch-register differences: 0x0c046f9a (w34c/w34a load
 * order, 2 bytes), 0x0c04710c (retail stores the phase zero through r0),
 * 0x0c0471aa (r3/r7 load pair), 0x0c0473da and 0x0c04746c (the direction local
 * takes r6 where retail uses r7/r5), 0x0c0475ec (w34e loaded before the
 * pattern word) and 0x0c0479a6 (signed timer in r5, retail r2). Register
 * rotation is per function: adding a function before one does not change it.
 * Recipes used: dead return after a goto (0x0c0476f4), label before ++
 * (0x0c046f9a, 0x0c04771a), a volatile local for the stack-reloaded argument
 * (0x0c04771a), else-wrap after an early return (0x0c0477dc). The real
 * translation unit starts at 0x0c045f1c and ends at the pool before 0x0c047d4c. */
#include "objects.h"
struct CommandPattern { unsigned short length, flags; unsigned char pad4[4]; unsigned short inputs[1]; };
struct CommandState { unsigned char phase; signed char timer; unsigned char index; unsigned char direction; unsigned char step; unsigned char pad5; unsigned short buttons; };
extern void func_0c047a8c(struct Actor *,struct CommandState *);
extern unsigned char func_0c0477dc(struct Actor *,struct CommandPattern *,struct CommandState *,int);
extern unsigned char func_0c047796(struct Actor *,struct CommandPattern *,struct CommandState *,int);
unsigned char func_0c046f9a(struct Actor *,struct CommandPattern *,struct CommandState *);
unsigned char func_0c046ed8(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 s->index=0;
 if((a->w34a&0x3c00)==p->inputs[0]){
  func_0c047a8c(a,s);
  s->phase=1;
  s->index=1;
 }
done:
 return 0;
}
unsigned char func_0c046f0a(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 if(--s->timer<=0)return s->phase=0;
 if((a->w34a&0x3c00)==((struct CommandPattern *)((unsigned char *)p+s->index*2))->inputs[0]){
  func_0c047a8c(a,s);
  if(++s->index==p->length){
   if(p->flags&0x80)return func_0c0477dc(a,p,s,(short)a->w34a);
   s->phase=2;s->timer=15;
   return func_0c046f9a(a,p,s);
  }
 }
 return 0;
}
unsigned char func_0c046f9a(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 int pressed;
 if(--s->timer<=0)return s->phase=0;
 pressed=((short)a->w34c^(short)a->w34a)&(short)((struct CommandPattern *)((unsigned char *)p+s->index*2))->inputs[0];
 if((unsigned short)pressed){
  unsigned short *flags=&p->flags;
  if((*flags&0x8000)==0x8000){
   if((unsigned short)pressed!=((struct CommandPattern *)((unsigned char *)p+s->index*2))->inputs[0]){goto inc; inc: s->phase++;goto end;}
  }else if((*flags&0x40)==0x40)return func_0c0477dc(a,p,s,pressed);
  return func_0c047796(a,p,s,pressed);
 }
end:
 return 0;
}

extern unsigned char func_0c047b0c(struct Actor *,unsigned short,unsigned short *);
unsigned char func_0c04701c(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 unsigned short buttons;
 s->phase=0;
 if(func_0c047b0c(a,((struct CommandPattern *)((unsigned char *)p+s->index*2))->inputs[0],&buttons))
  return func_0c047796(a,p,s,(short)buttons);
done:
 return 0;
}

unsigned char func_0c047064(void){return 0;}
extern unsigned char (*table_0c23bf04[])(struct Actor *,struct CommandPattern *,struct CommandState *);
unsigned char func_0c047068(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 if(a->b525){
  if(a->b45d && a->b448==*((unsigned char *)p+4))
   return func_0c0477dc(a,p,s,0);
  return 0;
 }
 return table_0c23bf04[s->phase](a,p,s);
}
unsigned char func_0c0470aa(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 if(!(a->w34a&p->inputs[0]))return s->phase=0;
 s->timer=*(unsigned char *)p;
 s->index=a->b1d2;
 ++s->phase;
 return 0;
}
unsigned char func_0c0470d4(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 if(--s->timer>0){
  if(!(a->w34a&p->inputs[0]))s->phase=0;
 }else ++s->phase;
 return 0;
}

unsigned char func_0c04715a(struct Actor *,struct CommandPattern *,struct CommandState *);
unsigned char func_0c0471aa(struct Actor *,struct CommandPattern *,struct CommandState *);
unsigned char func_0c04710c(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 unsigned short *in=&p->inputs[0];
 if(!(a->w34a&*in)){
  goto check; return 0; check:
  if(*in==0x1000 || *in==0x2000 || s->index==a->b1d2)goto ok;
  s->phase=0;
 }
 return 0;
ok:
 ++s->phase;s->timer=15;
 return func_0c04715a(a,p,s);
}
unsigned char func_0c04715a(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 unsigned short *in;
 if(--s->timer<=0)return s->phase=0;
 in=&p->inputs[1];
 if(*in==0x800){
  if((short)a->w34a!=(short)*in)goto ret;
 }else if(!(a->w34a&*in)){
ret:
  return 0;
 }
 ++s->phase;s->timer=15;
 return func_0c0471aa(a,p,s);
}
unsigned char func_0c0471aa(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 unsigned short *in;
 if(--s->timer<=0)return s->phase=0;
 in=&p->inputs[2];
 if(a->w34a&*in)return func_0c0477dc(a,p,s,(short)*in&(short)a->w34a);
 return 0;
}

extern unsigned char (*table_0c23bf18[])(struct Actor *,struct CommandPattern *,struct CommandState *);
extern unsigned char (*table_0c23bf24[])(struct Actor *,struct CommandPattern *,struct CommandState *);
unsigned char func_0c0471ea(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 if(a->b525){
  if(a->b45d && a->b448==*((unsigned char *)p+4))return func_0c0477dc(a,p,s,0);
  return 0;
 }
 return table_0c23bf18[s->phase](a,p,s);
}
unsigned char func_0c0472e2(struct Actor *,struct CommandPattern *,struct CommandState *);
unsigned char func_0c04723c(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 unsigned short *in=&p->inputs[0];
 if(!(a->w34e&*in))return s->phase=0;
 s->buttons=a->w34e&*in;
 s->index=1;
 ++s->phase;
 s->timer=*((unsigned char *)p+2);
 if(p->length==s->index){s->phase=2;s->timer=14;return func_0c0472e2(a,p,s);}
 return 0;
}
unsigned char func_0c047286(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 unsigned short *in;
 if(--s->timer<=0)return s->phase=0;
 in=&p->inputs[0];
 if(a->w34e&*in){
  goto LB0_160; return 0; LB0_160:
  if((a->w34e&*in)==s->buttons){
   ++s->index;
   s->timer=*((unsigned char *)p+2);
   if(p->length==s->index){s->phase=2;s->timer=14;return func_0c0472e2(a,p,s);}
  }
 }
 return 0;
}
unsigned char func_0c0472e2(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 if(--s->timer<=0)return s->phase=0;
 if((a->w34e&p->inputs[0])==s->buttons)return 1;
 return 0;
}
unsigned char func_0c04730c(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 if(a->b525){
  if(a->b45d && a->b448==*((unsigned char *)p+4))return func_0c0477dc(a,p,s,0);
  return 0;
 }
 return table_0c23bf24[s->phase](a,p,s);
}

extern unsigned char dat_0c23bf3c[4];
unsigned char func_0c047360(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 unsigned short direction=a->w34a&0x3c00;
 unsigned short index;
 if(direction){
  goto LB1_190; LB1_190:
  if(direction==0x2000 || direction==0x1000 || direction==0x800 || direction==0x400)goto ok;
 }
 goto LB0_192; LB0_192:
 s->phase=0;return 0;
ok:
 index=direction;
 if(direction==0x2000)index=0;
 if(direction==0x800)index=1;
 if(direction==0x1000)index=2;
 if(direction==0x400)index=3;
 ++s->phase;
 s->index=*(signed char *)p+255;
 s->direction=index;
 func_0c047a8c(a,s);
 return 0;
}
unsigned char func_0c0473da(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 register unsigned short direction;
 if(--s->timer<=0)return s->phase=0;
 direction=(a->w34a&0x3c00)>>10;
 if(direction){
  if(direction==dat_0c23bf3c[(s->direction+1)&3])s->step=1;
  else if(direction==dat_0c23bf3c[(s->direction-1)&3])s->step=255;
  else return 0;
  ++s->phase;
  --s->index;
  s->direction=(s->direction+(signed char)s->step)&3;
  func_0c047a8c(a,s);
 }
 return 0;
}

unsigned char func_0c04746c(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 unsigned short direction;
 if(--s->timer<=0)return s->phase=0;
 direction=(a->w34a&0x3c00)>>10;
 goto LB1_229; LB1_229:
 if(direction && direction==dat_0c23bf3c[(s->direction+s->step)&3]){
  if(!--s->index){
   goto LB0_231; LB0_231:
   *((unsigned char *)a+0x35c)=0;
   ++s->phase;s->timer=15;s->index=0;
   return func_0c046f9a(a,p,s);
  }
  s->direction=(s->direction+(signed char)s->step)&3;
  func_0c047a8c(a,s);
 }
 return 0;
}

extern unsigned char (*table_0c23bf40[])(struct Actor *,struct CommandPattern *,struct CommandState *);
unsigned char func_0c0474f8(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 if(a->b525){
  if(a->b45d && a->b448==*((unsigned char *)p+4))return func_0c0477dc(a,p,s,0);
  return 0;
 }
 return table_0c23bf40[s->phase](a,p,s);
}
unsigned char func_0c04753a(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 s->index=0;
 if((a->w34e&0x3f60)==p->inputs[0]){
  func_0c047a8c(a,s);s->phase=1;s->index=1;
 }
 return 0;
}
unsigned char func_0c04756c(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 if(--s->timer<=0)return s->phase=0;
 if((a->w34e&0x3f60)==((struct CommandPattern *)((unsigned char *)p+s->index*2))->inputs[0]){
  func_0c047a8c(a,s);
  if(++s->index==p->length){s->phase=2;s->timer=15;}
 }
 return 0;
}
unsigned char func_0c0475ec(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 int pressed;
 if(--s->timer<=0)return s->phase=0;
 pressed=(short)((struct CommandPattern *)((unsigned char *)p+s->index*2))->inputs[0]&(short)a->w34e&0x3f60;
 if((unsigned short)pressed){
  unsigned short *flags=&p->flags;
  goto LB0_276; LB0_276:
  if((*flags&0x8000)==0x8000){
   if((unsigned short)pressed!=((struct CommandPattern *)((unsigned char *)p+s->index*2))->inputs[0]){goto inc; inc: s->phase++;goto end;}
  }else if((*flags&0x40)==0x40)return func_0c0477dc(a,p,s,pressed);
  return func_0c047796(a,p,s,pressed);
 }
end:
 return 0;
}

extern unsigned char (*table_0c23bf54[])(struct Actor *,struct CommandPattern *,struct CommandState *,int);
unsigned char func_0c047664(struct Actor *a,struct CommandPattern *p,struct CommandState *s)
{
 if(a->b525){
  if(a->b45d && a->b448==*((unsigned char *)p+4))
   a->w4ae=~p->inputs[0];
  return table_0c23bf54[s->phase](a,p,s,a->w4ae);
 }
 return table_0c23bf54[s->phase](a,p,s,(short)a->w34a);
}
unsigned char func_0c0476d4(struct Actor *a,struct CommandPattern *p,struct CommandState *s,int input)
{
 if(!(p->inputs[0]&(unsigned short)input))return s->phase=0;
 s->timer=*(signed char *)p;
 ++s->phase;
 return 0;
}
unsigned char func_0c0476f4(struct Actor *a,struct CommandPattern *p,struct CommandState *s,int input)
{
 if(--s->timer<=0)goto inc;
 if(!(p->inputs[0]&(unsigned short)input))s->phase=0;
 goto e;
 return 0;
inc:
 ++s->phase;
e:
 return 0;
}

unsigned char func_0c04771a(struct Actor *a,struct CommandPattern *p,struct CommandState *s,int input)
{
 volatile unsigned short pressed;
 if(!(pressed=p->inputs[0]&input)){
  if(func_0c0477dc(a,p,s,(short)pressed)){s->phase=0;return 1;}
  goto inc; inc:
  ++s->phase;s->timer=10;
 }
 return 0;
}
unsigned char func_0c04775c(struct Actor *a,struct CommandPattern *p,struct CommandState *s,int input)
{
 if(!--s->timer)return s->phase=0;
 if(!func_0c0477dc(a,p,s,input))return 0;
 s->phase=0;
 return 1;
}
unsigned char func_0c047796(struct Actor *a,struct CommandPattern *p,struct CommandState *s,int input)
{
 if((unsigned short)input&0x120){
  if(s->timer-4>=0)goto activate;
  if(!(p->flags&0x8600))input&=0xfedf;
 }
 if(((unsigned short)input&0x2d0) && s->timer-2>=0){
activate:
  return func_0c0477dc(a,p,s,input);
 }
 s->phase=0;
 return 0;
}

extern unsigned char func_0c047886(struct Actor *),func_0c047940(struct Actor *),func_0c0479a6(struct Actor *);
unsigned char func_0c0477dc(struct Actor *a,struct CommandPattern *p,struct CommandState *s,int input)
{
 unsigned short buttons=input;
 unsigned short flags=p->flags;
 if(!(flags&0x4000)){
  if((flags&0x20) && (a->b14a&0xe0))return 0;
  else{
  if(flags&0x800){if(!func_0c047940(a))return 0;}
  else if(flags&0x100){if(!func_0c0479a6(a))return 0;}
  else if(!func_0c047886(a))return 0;
  }
 }
 goto t; t:
 if((flags&0x2000) && a->b1f9!=2)return 0;
 else{
 if((flags&0x1000) && a->b1f9==2)return 0;
 s->phase=0;s->buttons=buttons;
 return 1;
 }
}

extern float dat_0c2d9300;
extern char dat_0c23bf64[];
unsigned char func_0c047886(struct Actor *a)
{
 unsigned int animation;
 if(a->b1f2 || a->b1f3)return 0;
 animation=a->b1d0;
 if((animation==18 || animation==19) && a->b1de)return 0;
 if((a->b14a&0x20) || a->b5 || a->b1d0==21 || a->b1d0==28)return 0;
 if(a->p20c->b235)return 0;
 if(a->b1f9==2){
  if(a->f56>a->f41c){
   if(a->f56>=dat_0c2d9300 + -68.57143f)return 0;
  }else return 0;
 }
 if(dat_0c23bf64[a->b1d0])return 0;
 return 1;
}

unsigned char func_0c047940(struct Actor *a)
{
 if(a->b5 || a->b1d0==21 || a->b1d0==28)return 0;
 if(a->p20c->b235)return 0;
 if(a->b1f9==2){
  if(a->f56>a->f41c){
   if(a->f56>=dat_0c2d9300 + -68.57143f)return 0;
  }else return 0;
 }
 if(dat_0c23bf64[a->b1d0])return 0;
 return 1;
}
unsigned char func_0c0479a6(struct Actor *a)
{
 unsigned int animation;
 if(a->b1f2 || a->b1f3)return 0;
 animation=a->b1d0;
 if((animation==18 || animation==19) && a->b1de)return 0;
 if((a->b14a&0x20) || a->b5 || a->b1d0==29 || a->b1d0==28)return 0;
 if(a->b1d0==21){
  int timer=*(signed char *)((unsigned char *)a+0x27a);
  if(timer<0){if((a->b14a&0xe0)!=0x80)return 0;}
  else if(!timer)return 0;
 }
 if(a->p20c->b235)return 0;
 if(a->b1f9==2){
  if(a->f56>a->f41c){
   if(a->f56>=dat_0c2d9300 + -68.57143f)return 0;
  }else return 0;
 }
 if(dat_0c23bf64[a->b1d0])return 0;
 return 1;
}

extern unsigned int func_0c02849a(void);
extern signed char dat_0c23bf87[32];
void func_0c047a8c(struct Actor *a,struct CommandState *s)
{
 s->timer=dat_0c23bf87[func_0c02849a()&31];
}
void func_0c047aac(struct Actor *a,struct CommandState *s)
{
 struct MaskObject *m=(struct MaskObject *)a;
 if(m->b525){
  m->b1fe=m->b4ab;m->b1a3=m->b4aa;m->w1fa=m->w4ac;
  return;
 }
 if(s->buttons&0x240)m->b1a3=0;
 if(s->buttons&0x120)m->b1a3=1;
 if(s->buttons&0x300)m->b1fe=0;
 if(s->buttons&0x60)m->b1fe=1;
}

unsigned char func_0c047b0c(struct Actor *a,unsigned short mask,unsigned short *buttons)
{
 struct MaskObject *m=(struct MaskObject *)a;
 unsigned short previous=m->w342;
 if((*buttons=((m->w344^previous)|(m->w340^previous))&mask)==mask)return 1;
 return 0;
}
