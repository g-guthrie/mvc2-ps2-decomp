/* EXACT full translation unit 0x0c067be8..0x0c0682bc (1748 bytes). Not registered: diff_unit release_pools cannot swallow whole registered units (tu_0c067ce8, tu_0c067f4c, u06808c, tu_0c0681b4); the lead must drop those units and then register this file as verified. */
#include "objects.h"
extern unsigned char dat_0c2405dc[], dat_0c2405ec[], dat_0c2405fc[];
extern unsigned char dat_0c240550[], dat_0c240560[], dat_0c240570[];
extern unsigned char dat_0c240590[], dat_0c2405cc[], dat_0c240530[], dat_0c2405a0[];
extern unsigned char dat_0c240540[], dat_0c240580[], dat_0c2405be[], dat_0c2405b0[];
extern unsigned char func_0c0465cc(struct Actor *),func_0c046b6c(struct Actor *),func_0c0469f4(struct Actor *),func_0c046d3c(struct Actor *);
extern unsigned char func_0c046e7e(struct Actor *, unsigned char *, unsigned char *);
extern unsigned char func_0c047068(struct Actor *, unsigned char *, unsigned char *);
extern void func_0c047aac(struct Actor *, unsigned char *), func_0c045248(struct Actor *, int);
extern void func_0c045f1c(struct Actor *),func_0c0463fc(struct Actor *);
extern int func_0c046d54(struct Actor *);
extern unsigned char func_0c046dd0(struct Actor *,int);
unsigned char func_0c067ce8(struct Actor *),func_0c067d4e(struct Actor *),func_0c067db4(struct Actor *),func_0c067e3e(struct Actor *),func_0c067e84(struct Actor *),func_0c067eca(struct Actor *);
unsigned char func_0c067f4c(struct Actor *),func_0c067f92(struct Actor *),func_0c067fd8(struct Actor *),func_0c068020(struct Actor *),func_0c06808c(struct Actor *),func_0c0680e8(struct Actor *),func_0c06812e(struct Actor *),func_0c0681b4(struct Actor *);
int func_0c06821e(struct Actor *),func_0c06825e(struct Actor *);
void func_0c067be8(struct Actor *a)
{
  if (func_0c0465cc(a)) return;
  if (func_0c046b6c(a)) return;
  if (func_0c0469f4(a)) return;
  if (func_0c046d3c(a)) return;
  if (func_0c067ce8(a)) return;
  if (func_0c067d4e(a)) return;
  if (func_0c067db4(a)) return;
  if (func_0c067e3e(a)) return;
  if (func_0c067e84(a)) return;
  if (func_0c067eca(a)) return;
  if (func_0c067f4c(a)) return;
  if (func_0c067f92(a)) return;
  if (func_0c067fd8(a)) return;
  if (func_0c068020(a)) return;
  if (func_0c06808c(a)) return;
  if (func_0c0680e8(a)) return;
  if (func_0c06812e(a)) return;
  if (func_0c0681b4(a)) return;
  if (func_0c06821e(a)) return;
  if (func_0c06825e(a)) return;
  func_0c045f1c(a);
  func_0c0463fc(a);
}
unsigned char func_0c067ce8(struct Actor *a)
{
  struct ActorSub2a4 *context = &a->sub2a4;
  if (!func_0c046e7e(a, dat_0c2405dc, a->x36c)) return 0;
  if (!*a->p40c) return 0;
  if (context->b0) return 0;
  func_0c047aac(a, a->x36c);
  a->b5 = 0; a->b7 = 0; a->b6 = 0; a->b1e9 = 12;
  func_0c045248(a, 29);
  return 1;
}
unsigned char func_0c067d4e(struct Actor *a)
{
  struct ActorSub2a4 *context = &a->sub2a4;
  if (!func_0c046e7e(a, dat_0c2405ec, a->x374)) return 0;
  if (!*a->p40c) return 0;
  if (context->b0) return 0;
  func_0c047aac(a, a->x374);
  a->b5 = 0; a->b7 = 0; a->b6 = 0; a->b1e9 = 10;
  func_0c045248(a, 29);
  return 1;
}
unsigned char func_0c067db4(struct Actor *a)
{
  struct ActorSub2a4 *context = &a->sub2a4;
  if (!func_0c046e7e(a, dat_0c2405fc, a->x37c)) return 0;
  if (!*a->p40c) return 0;
  if (context->b0) return 0;
  func_0c047aac(a, a->x37c);
  a->b5 = 0; a->b7 = 0; a->b6 = 0; a->b1e9 = 4;
  func_0c045248(a, 29);
  return 1;
}
unsigned char func_0c067e3e(struct Actor *a)
{
  if (!func_0c046e7e(a, dat_0c240550, a->x384)) return 0;
  func_0c047aac(a, a->x384);
  a->b5 = 0; a->b7 = 0; a->b6 = 0; a->b1e9 = 5;
  func_0c045248(a, 21);
  return 1;
}
unsigned char func_0c067e84(struct Actor *a)
{
  if (!func_0c046e7e(a, dat_0c240560, a->x38c)) return 0;
  func_0c047aac(a, a->x38c);
  a->b5 = 0; a->b7 = 0; a->b6 = 0; a->b1e9 = 6;
  func_0c045248(a, 21);
  return 1;
}
unsigned char func_0c067eca(struct Actor *a)
{
  if (!func_0c046e7e(a, dat_0c240570, a->x394)) goto fail;
  if (!a->b1fc) {
    if (a->b1d4) { fail: return 0; }
    a->b1d4++;
  }
  func_0c047aac(a, a->x394);
  a->b5 = 0; a->b7 = 0; a->b6 = 0; a->b1e9 = 7;
  func_0c045248(a, 21);
  return 1;
}
unsigned char func_0c067f4c(struct Actor *a)
{
    if (func_0c046e7e(a, dat_0c240590, a->x39c) == 0)
        return 0;
    func_0c047aac(a, a->x39c);
    a->b5 = 0; a->b7 = 0; a->b6 = 0; a->b1e9 = 3;
    func_0c045248(a, 29);
    return 1;
}
unsigned char func_0c067f92(struct Actor *a)
{
    if (func_0c046e7e(a, dat_0c2405cc, a->x3a4) == 0)
        return 0;
    func_0c047aac(a, a->x3a4);
    a->b5 = 0; a->b7 = 0; a->b6 = 0; a->b1e9 = 8;
    func_0c045248(a, 21);
    return 1;
}
unsigned char func_0c067fd8(struct Actor *a)
{
    if (func_0c046e7e(a, dat_0c240530, a->x3ac) == 0)
        return 0;
    func_0c047aac(a, a->x3ac);
    a->b5 = 0; a->b7 = 0; a->b6 = 0; a->b1e9 = 0;
    func_0c045248(a, 21);
    return 1;
}
unsigned char func_0c068020(struct Actor *a)
{
    if (func_0c046e7e(a, dat_0c2405a0, a->x3b4) == 0)
        return 0;
    func_0c047aac(a, a->x3b4);
    a->b5 = 0; a->b7 = 0; a->b6 = 0; a->b1e9 = 9;
    func_0c045248(a, 21);
    return 1;
}
unsigned char func_0c06808c(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c240540, a->x3bc))
        return 0;
    else if (!a->b1fc) {
        if (a->b1d4)
            return 0;
        a->b1d4++;
    }
    func_0c047aac(a, a->x3bc);
    a->b5 = 0; a->b7 = 0; a->b6 = 0; a->b1e9 = 11;
    func_0c045248(a, 21);
    return 1;
}
unsigned char func_0c0680e8(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c240580, a->x3c4))
        return 0;
    func_0c047aac(a, a->x3c4);
    a->b5 = 0; a->b7 = 0; a->b6 = 0; a->b1e9 = 13;
    func_0c045248(a, 29);
    return 1;
}
unsigned char func_0c06812e(struct Actor *a)
{
    struct ActorSub2a4 *s = &a->sub2a4;
    if (!func_0c047068(a, dat_0c2405be, a->x3cc))
        return 0;
    else if (s->b3)
        return 0;
    func_0c047aac(a, a->x3cc);
    a->b5 = 0; a->b7 = 0; a->b6 = 0; a->b1e9 = 14;
    func_0c045248(a, 21);
    return 1;
}
unsigned char func_0c0681b4(struct Actor *a)
{
 struct ActorSub2a4 *context=&a->sub2a4;
 if(!func_0c047068(a,dat_0c2405b0,a->x364))goto fail;
 if(a->b1f9==2&&!context->b1)goto fail;
 if(!context->b1)a->b1e9=15;
 else{if(context->b2){fail:return 0;}a->b1e9=16;}
 func_0c047aac(a,a->x364);
 a->b5=0;a->b7=0;a->b6=0;
 func_0c045248(a,21);
 return 1;
}
int func_0c06821e(struct Actor *a)
{
 if(!func_0c046d54(a))goto fail;
 if(!*a->p40c){fail:return 0;}
 a->b1e9=22;a->b5=0;
 func_0c045248(a,29);
 a->b6=a->b7=0;
 return 1;
}
int func_0c06825e(struct Actor *a)
{
    if (!func_0c046dd0(a, 17)) return 0;
    a->b1e9 = 17;
    a->b5 = 0;
    func_0c045248(a, 21);
    a->b6 = a->b7 = 0;
    return 1;
}
