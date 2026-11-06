/* Candidate: only func_0c0da5e0 differs: retail holds the move id stored to b258 in scratch r2 (shared store reached by goto), the compiler gives the named local k r4, which shifts later r2/r3 rotation. Every other function is exact. */
#include "objects.h"
extern unsigned char dat_0c248b10[];
extern unsigned char dat_0c248b20[];
extern unsigned char dat_0c248b30[];
extern unsigned char dat_0c248b40[];
extern unsigned char dat_0c248b50[];
extern unsigned char dat_0c248b60[];
extern unsigned char dat_0c248b70[];
extern unsigned char dat_0c248b80[];
extern unsigned char dat_0c248b90[];
extern unsigned char dat_0c248ba0[];
extern unsigned char dat_0c248bb0[];
extern unsigned char dat_0c248bc0[];
extern unsigned char dat_0c248bd0[];
extern unsigned char dat_0c248be0[];
extern unsigned char dat_0c248bf0[];
extern unsigned char dat_0c248c00[];
extern unsigned char dat_0c248c10[];
extern unsigned char dat_0c248c20[];
extern unsigned char dat_0c248c30[];
extern unsigned int dat_0c248c98[];
extern void func_0c045248(struct Actor*,int);
extern void func_0c045f1c(struct Actor*);
extern void func_0c0463fc(struct Actor*);
extern unsigned char func_0c0465cc(struct Actor*);
extern unsigned char func_0c0469f4(struct Actor*);
extern unsigned char func_0c046b6c(struct Actor*);
extern unsigned char func_0c046d3c(struct Actor*);
extern int func_0c046d54(struct Actor*);
extern unsigned char func_0c046dd0(struct Actor*,int);
extern unsigned char func_0c046e7e(struct Actor*,unsigned char*,unsigned char*);
extern unsigned char func_0c0474f8(struct Actor*,unsigned char*,unsigned char*);
extern void func_0c047aac(struct Actor*,unsigned char*);
extern unsigned char func_0c047b0c(struct Actor*,unsigned short,unsigned short*);
extern void func_0c1fba00(void*,int,int);
void func_0c0d9fc8(struct Actor *a);
unsigned char func_0c0d9fe4(struct Actor *a);
unsigned char func_0c0da00e(struct Actor*a);
int func_0c0da046(struct Actor*a);
unsigned char func_0c0da086(struct Actor *a);
unsigned char func_0c0da114(struct Actor *a);
unsigned char func_0c0da178(struct Actor *a);
unsigned char func_0c0da1c8(struct Actor *a);
unsigned char func_0c0da29c(struct Actor *a);
unsigned char func_0c0da372(struct Actor *a);
unsigned char func_0c0da400(struct Actor *a);
unsigned char func_0c0da490(struct Actor *a);
unsigned char func_0c0da4fe(struct Actor *a);
unsigned char func_0c0da598(struct Actor *a);
unsigned char func_0c0da5e0(struct Actor *a);
void func_0c0da6f0(struct Actor *a);
void func_0c0da82a(struct Actor *a);

void func_0c0d9fc8(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c248c98;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}

unsigned char func_0c0d9fe4(struct Actor *a)
{
    if (a->b1f9 != 2) return 1;
    goto t; t: if (a->b1fc) return 1;
    if (a->b1d4) return 0;
    a->b1d4=a->b1d4+1;
    return 1;
}

unsigned char func_0c0da00e(struct Actor*a){if(!func_0c046dd0(a,2))return 0;a->b5=0;a->b7=0;a->b6=0;a->b1e9=2;func_0c045248(a,21);return 1;}

int func_0c0da046(struct Actor*a){if(!func_0c046d54(a))return 0;else if(!*a->p40c)return 0;a->b1e9=19;a->b5=0;func_0c045248(a,29);a->b6=(((char*)a)[7]=0);return 1;}

unsigned char func_0c0da086(struct Actor *a)
{
 unsigned char *p;
 if(!a->i204)p=dat_0c248b70;else p=dat_0c248bf0;
 if(!func_0c046e7e(a,p,a->x364))return 0;
 else if(!*a->p40c)return 0;
 func_0c047aac(a,a->x364);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=6;
 func_0c045248(a,29);return 1;
}

unsigned char func_0c0da114(struct Actor *a)
{
 unsigned char *p;
 if(!a->i204)p=dat_0c248b80;else p=dat_0c248c00;
 if(!func_0c046e7e(a,p,a->x36c))goto fail;
 if(!*a->p40c){fail:return 0;}
 func_0c047aac(a,a->x36c);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=*(short *)(p+4);
 func_0c045248(a,29);return 1;
}

unsigned char func_0c0da178(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c248b90,a->x374))goto fail;
 if(!*a->p40c){fail:return 0;}
 func_0c047aac(a,a->x374);a->b5=0;a->b7=0;a->b6=0;a->b1e9=14;func_0c045248(a,29);return 1;
}

unsigned char func_0c0da1c8(struct Actor *a)
{
 int zero;
 unsigned char *p;
 if(!a->i204){if(a->b525 && a->b1f9==2)p=dat_0c248b20;else p=dat_0c248b10;}
 else{if(a->b525 && a->b1f9==2)p=dat_0c248bc0;else p=dat_0c248bb0;}
 if(!func_0c046e7e(a,p,a->x37c))return 0;
 else if(!func_0c0d9fe4(a))return 0;
 func_0c047aac(a,a->x37c);
 zero=0;
 a->b5=zero;a->b7=zero;a->b6=zero;
 if(a->b1f9!=2)a->b1e9=zero;else a->b1e9=13;
 func_0c045248(a,21);return 1;
}

unsigned char func_0c0da29c(struct Actor *a)
{
 int zero;
 unsigned char *p;
 if(!a->i204){if(a->b525 && a->b1f9==2)p=dat_0c248b40;else p=dat_0c248b30;}
 else{if(a->b525 && a->b1f9==2)p=dat_0c248be0;else p=dat_0c248bd0;}
 if(!func_0c046e7e(a,p,a->x384))return 0;
 else if(!func_0c0d9fe4(a))return 0;
 func_0c047aac(a,a->x384);
 zero=0;
 a->b5=zero;a->b7=zero;a->b6=zero;
 if(a->b1f9!=2)a->b1e9=5;else a->b1e9=7;
 func_0c045248(a,21);return 1;
}

unsigned char func_0c0da372(struct Actor *a)
{
 int zero;
 unsigned char *p;
 if(a->b525 && a->b1f9==2)p=dat_0c248b60;else p=dat_0c248b50;
 if(!func_0c046e7e(a,p,a->x38c))goto fail;
 if(a->b1f9==2){if(a->b1d4){fail:return 0;}a->b1d4++;}
 func_0c047aac(a,a->x38c);
 zero=0;
 a->b5=zero;a->b7=zero;a->b6=zero;
 if(a->b1f9!=2)a->b1e9=1;else a->b1e9=12;
 func_0c045248(a,21);return 1;
}

unsigned char func_0c0da400(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c248ba0,a->x3ac))return 0;
 else if(*a->p40c<3)return 0;
 func_0c1fba00(a->x36c,0,8);
 func_0c1fba00(a->x37c,0,8);
 func_0c1fba00(a->x384,0,8);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=20;
 func_0c045248(a,29);return 1;
}

unsigned char func_0c0da490(struct Actor *a)
{
 unsigned short input;
 if(!func_0c046e7e(a,dat_0c248c10,a->x394))goto fail;
 if(func_0c047b0c(a,0x300,&input))goto ok;
 goto c2; c2: if(!func_0c047b0c(a,96,&input)){fail:return 0;}
ok:
 func_0c047aac(a,a->x394);
 a->b1e9=16;a->b5=0;
 func_0c045248(a,29);
 a->b6=a->b7=0;
 return 1;
}

unsigned char func_0c0da4fe(struct Actor *a)
{
 unsigned short input;
 if(!func_0c046e7e(a,dat_0c248c20,a->x39c))goto fail;
 if(func_0c047b0c(a,0x300,&input))goto ok;
 goto c2; c2: if(!func_0c047b0c(a,96,&input)){fail:return 0;}
ok:
 func_0c047aac(a,a->x39c);
 a->b1e9=17;a->b5=0;
 func_0c045248(a,29);
 a->b6=a->b7=0;
 return 1;
}

unsigned char func_0c0da598(struct Actor *a)
{
 if(!func_0c0474f8(a,dat_0c248c30,a->x3a4))return 0;
 else if(*a->p40c<3)return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=18;
 func_0c045248(a,29);return 1;
}

unsigned char func_0c0da5e0(struct Actor *a)
{
 unsigned char (*chk)();
 unsigned char *p;
 unsigned char *q;
 char k;
 if(!a->i204)p=dat_0c248b70;else p=dat_0c248bf0;
 chk=func_0c046e7e;
 if(chk(a,p,a->x364) && *a->p40c){k=6;set:a->b258=k;return 1;}
 if(!a->i204)q=dat_0c248b80;else q=dat_0c248c00;
 if(chk(a,q,a->x36c) && *a->p40c){k=*(short *)(q+4);goto set;}
 if(chk(a,dat_0c248b90,a->x374) && *a->p40c){a->b258=14;return 1;}
 if(a->i204 && func_0c0474f8(a,dat_0c248c30,a->x3a4) && *a->p40c>=3){a->b258=18;return 1;}
 return 0;
}

void func_0c0da6f0(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(a->i204){
  if(func_0c0da598(a))return;
  if(func_0c0da490(a))return;
  if(func_0c0da4fe(a))return;
  if(func_0c0da400(a))return;
  if(func_0c0da086(a))return;
  if(func_0c0da114(a))return;
  if(func_0c0da178(a))return;
  if(func_0c0da1c8(a))return;
  if(func_0c0da29c(a))return;
  if(func_0c0da372(a))return;
 }else{
  if(func_0c0da400(a))return;
  if(func_0c0da086(a))return;
  if(func_0c0da114(a))return;
  if(func_0c0da178(a))return;
  if(func_0c0da1c8(a))return;
  if(func_0c0da29c(a))return;
  if(func_0c0da372(a))return;
 }
 if(func_0c0da046(a))return;
 if(func_0c0da00e(a))return;
 func_0c045f1c(a);
 func_0c0463fc(a);
}
void func_0c0da82a(struct Actor *a)
{
 if(!((struct ActorSubMoveBytes *)&a->sub2a4)->b15)return;
 if(a->i204)return;
 if(!a->b5 && a->b1d0==21){
  goto t; t: if(!a->b1e9)return;
  if(a->b1e9==13)return;
 }
 ((struct ActorSubMoveBytes *)&a->sub2a4)->b15=0;
}

