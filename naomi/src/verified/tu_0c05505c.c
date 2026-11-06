/* tu_0c05505c: indivisible unit 0x0c05505c-0x0c0567e8 (6028 bytes), exact.
 * func_0c055d16/func_0c055f8e: the shared 0 is a `void *zero` stored through
 * (int) casts; that makes SHC load it into r13 right after the push and
 * leaves `mov #1,r12` for the switch's bt.s delay slot, as retail does. */
#include "objects.h"
extern unsigned char func_0c0465cc(struct Actor *),func_0c046b6c(struct Actor *),func_0c0469f4(struct Actor *),func_0c046d3c(struct Actor *);
extern void func_0c045f1c(struct Actor *),func_0c0463fc(struct Actor *);
extern unsigned char func_0c046e7e(struct Actor *,unsigned char *,unsigned char *),func_0c04730c(struct Actor *,unsigned char *,unsigned char *),func_0c047886(struct Actor *);
extern unsigned char func_0c047b60(struct Actor *,int,unsigned short *,int);
extern void func_0c047aac(struct Actor *,unsigned char *),func_0c045248(struct Actor *,int);
extern int func_0c046d54(struct Actor *),func_0c037d54(struct Actor *);
extern void func_0c044450(struct Actor *,int);
extern unsigned char func_0c046dd0(struct Actor *,int);
extern void func_0c044cbc(struct Actor *),func_0c0346da(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c044f1c(struct Actor *),func_0c0437b8(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern unsigned char dat_0c23f51c[],dat_0c23f520[],dat_0c23f524[],dat_0c23f528[],dat_0c23f52c[],dat_0c23f530[],dat_0c23f534[],dat_0c23f538[],dat_0c23f53c[],dat_0c23f540[],dat_0c23f544[],dat_0c23f548[],dat_0c23f54c[],dat_0c23f550[],dat_0c23f554[],dat_0c23f558[],dat_0c23f55c[],dat_0c23f560[];
int func_0c05585e(struct Actor *),func_0c055894(struct Actor *),func_0c055900(struct Actor *);
void func_0c05598c(struct Actor *),func_0c055a8c(struct Actor *),func_0c055b58(struct Actor *),func_0c055c04(struct Actor *),func_0c055d16(struct Actor *),func_0c055f8e(struct Actor *),func_0c055cce(struct Actor *),func_0c056134(struct Actor *),func_0c056472(struct Actor *),func_0c0564c8(struct Actor *),func_0c05654c(struct Actor *),func_0c056390(struct Actor *),func_0c0562e8(struct Actor *),func_0c05628a(struct Actor *),func_0c056186(struct Actor *),func_0c0563f0(struct Actor *),func_0c0566ac(struct Actor *),func_0c05658c(struct Actor *),func_0c056750(struct Actor *);
extern unsigned int dat_0c23f5f0[];
extern unsigned char dat_0c23f564[],dat_0c23f574[],dat_0c23f57e[],dat_0c23f592[],dat_0c23f59c[],dat_0c23f5ac[],dat_0c23f5b6[],dat_0c23f5c6[],dat_0c23f5d6[],dat_0c23f5e0[];
unsigned char func_0c0551dc(struct Actor *),func_0c055278(struct Actor *),func_0c055332(struct Actor *),func_0c0553a8(struct Actor *);
unsigned char func_0c055434(struct Actor *),func_0c05547a(struct Actor *),func_0c0554f8(struct Actor *),func_0c055568(struct Actor *);
unsigned char func_0c0555ae(struct Actor *),func_0c0555f4(struct Actor *),func_0c05563c(struct Actor *),func_0c0556a0(struct Actor *);
unsigned char func_0c0556e6(struct Actor *),func_0c05572c(struct Actor *),func_0c055772(struct Actor *),func_0c0557e0(struct Actor *);
int func_0c05581e(struct Actor *);

void func_0c05505c(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c23f5f0;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}
void func_0c055078(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(!a->b202){
  if(func_0c0555f4(a))return;
  if(func_0c055568(a))return;
  if(func_0c0551dc(a))return;
  if(func_0c055278(a))return;
  if(func_0c05547a(a))return;
  if(func_0c0556a0(a))return;
  if(func_0c0554f8(a))return;
  if(func_0c055434(a))return;
  if(func_0c0555ae(a))return;
 }else{
  if(func_0c055772(a))return;
  if(func_0c055568(a))return;
  if(func_0c055332(a))return;
  if(func_0c0553a8(a))return;
  if(func_0c05547a(a))return;
  if(func_0c0556e6(a))return;
  if(func_0c0554f8(a))return;
  if(func_0c0555ae(a))return;
  if(func_0c05572c(a))return;
 }
 if(func_0c0557e0(a))return;
 if(func_0c05581e(a))return;
 if(func_0c05563c(a))return;
 func_0c045f1c(a);func_0c0463fc(a);
}
unsigned char func_0c0551dc(struct Actor *a)
{
 unsigned short v; struct ActorSub2a4 *sub; int zero;
 sub=&a->sub2a4; goto call; call: if(func_0c047b60(a,0x300,&v,0)) goto c2; return 0; c2:
 if(!func_0c047886(a))goto fail;
 if(a->b1f9==2){if(!a->b1fc){if(a->b1d4)goto fail;goto set;set:a->b1d4=1;}}
 else if(a->w34a&0x2000){fail:return 0;}
 *(unsigned short *)sub=a->w1fa;
 zero=0;
 a->b5=zero;a->b7=zero;a->b6=zero;
 if(a->b1f9==2)a->b6++;
 a->b1e9=zero;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c055278(struct Actor *a)
{
 unsigned short v;
 struct ActorSub2a4 *sub;
 int zero,one;
 sub=&a->sub2a4; goto call; call: if(func_0c047b60(a,0x60,&v,1)) goto c2; return 0; c2:
 if(!func_0c047886(a))goto fail;
 one=1;
 if(a->b1f9==2){if(!a->b1fc){if(a->b1d4)goto fail;a->b1d4=one;}}
 else if(a->w34a&0x2000){fail:return 0;}
 *(unsigned short *)sub=a->w1fa;
 zero=0;
 a->b5=zero;a->b7=zero;a->b6=zero;
 if(a->b1f9==2)a->b6++;
 a->b1e9=one;
 func_0c045248(a,21);return one;
}
unsigned char func_0c055332(struct Actor *a)
{
 unsigned short v; struct ActorSub2a4 *sub; int zero;
 sub=&a->sub2a4; goto call; call: if(func_0c047b60(a,0x300,&v,0)) goto c2; return 0; c2:
 if(!func_0c047886(a)||a->b1f9==2||(a->w1fa&0x2000))return 0;
 *(unsigned short *)sub=a->w1fa;
 zero=0;
 a->b5=zero;a->b7=zero;a->b6=zero;
 a->b1e9=zero;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0553a8(struct Actor *a)
{
 unsigned short v; struct ActorSub2a4 *sub;
 sub=&a->sub2a4; goto call; call: if(func_0c047b60(a,0x60,&v,1)) goto c2; return 0; c2: if(!func_0c047886(a)||a->b1f9==2||(a->w1fa&0x2000))return 0;
 *(unsigned short *)sub=a->w1fa;
 a->b5=0;a->b7=0;a->b6=0;
 a->b1e9=1;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c055434(struct Actor*a){if(!func_0c046e7e(a,dat_0c23f564,a->x36c))return 0;func_0c047aac(a,a->x36c);a->b5=0;a->b7=0;a->b6=0;a->b1e9=2;func_0c045248(a,21);return 1;}
unsigned char func_0c05547a(struct Actor *a)
{
 int zero;
 if(!func_0c04730c(a,dat_0c23f574,a->x374))goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4){fail:return 0;}goto set;set:a->b1d4=1;}
 func_0c047aac(a,a->x374);
 zero=0;
 a->b5=zero;
 if(a->b1f9==2)a->b6=1;else a->b6=zero;
 a->b7=zero;a->b1e9=3;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0554f8(struct Actor*a){if(!func_0c046e7e(a,dat_0c23f57e,a->x37c))return 0;func_0c047aac(a,a->x37c);a->b5=0;a->b7=0;a->b6=0;a->b1e9=4;func_0c045248(a,21);return 1;}
unsigned char func_0c055568(struct Actor *a)
{
 if(!func_0c04730c(a,dat_0c23f592,a->x384))goto fail;
 if(!*a->p40c){fail:return 0;}
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=5;func_0c045248(a,29);return 1;
}
unsigned char func_0c0555ae(struct Actor*a){if(!func_0c046e7e(a,dat_0c23f59c,a->x38c))return 0;func_0c047aac(a,a->x38c);a->b5=0;a->b7=0;a->b6=0;a->b1e9=6;func_0c045248(a,21);return 1;}
unsigned char func_0c0555f4(struct Actor *a)
{
 if(!func_0c04730c(a,dat_0c23f5ac,a->x394))goto fail;
 if(*a->p40c<3){fail:return 0;}
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=17;func_0c045248(a,29);return 1;
}
unsigned char func_0c05563c(struct Actor *a)
{
 if(!func_0c046dd0(a,9))return 0;
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=9;func_0c045248(a,21);return 1;
}
unsigned char func_0c0556a0(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c23f5b6,a->x39c))goto fail;
 if(!*a->p40c){fail:return 0;}
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=18;func_0c045248(a,29);return 1;
}
unsigned char func_0c0556e6(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c23f5b6,a->x39c))goto fail;
 if(!*a->p40c){fail:return 0;}
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=18;func_0c045248(a,29);return 1;
}
unsigned char func_0c05572c(struct Actor*a){if(!func_0c046e7e(a,dat_0c23f5c6,a->x3a4))return 0;func_0c047aac(a,a->x3a4);a->b5=0;a->b7=0;a->b6=0;a->b1e9=19;func_0c045248(a,21);return 1;}
unsigned char func_0c055772(struct Actor *a)
{
 if(!func_0c04730c(a,dat_0c23f5d6,a->x3ac))goto fail;
 if(!*a->p40c){fail:return 0;}
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=20;func_0c045248(a,29);return 1;
}
unsigned char func_0c0557e0(struct Actor *a)
{
 int r;
 if(!func_0c046e7e(a,dat_0c23f5e0,a->x3b4))goto fail;
 if(!(r=func_0c037d54(a))){fail:return 0;}
 a->b1f7=201;
 func_0c044450(a,r);return 1;
}
int func_0c05581e(struct Actor*a){if(!func_0c046d54(a))return 0;else if(!*a->p40c)return 0;a->b1e9=21;a->b5=0;func_0c045248(a,29);a->b6=(((char*)a)[7]=0);return 1;}
int func_0c05585e(struct Actor *a)
{
    if (!func_0c04730c(a, dat_0c23f592, a->x384))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 5;
    return 1;
}
int func_0c055894(struct Actor *a)
{
    if (!func_0c04730c(a, dat_0c23f5ac, a->x394))
        return 0;
    else if (*a->p40c < 3)
        return 0;
    a->b258 = 17;
    return 1;
}
int func_0c055900(struct Actor *a)
{
    if (!func_0c04730c(a, dat_0c23f5d6, a->x3ac))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 20;
    return 1;
}
int func_0c055936(struct Actor *a)
{
if(func_0c05585e(a)||(!a->b202?func_0c055894(a):func_0c055900(a)))return 1;return 0;
}
void func_0c05596e(struct Actor *a)
{
    if (a->b1d0 != 21 && a->b1d0 != 29)
        a->b205 = 0;
}
void func_0c05598c(struct Actor *a)
{
 int zero=0,one=1;
 switch(a->b1e8){
 case 0:
  if(a->w1fa&0x400){a->b6++;a->b158=3;a->b1a1=23;func_0c0346da(a,20);a->b1a7=one;a->p3f4=dat_0c23f524;}
  else{a->b158=zero;a->b1a1=zero;func_0c0346da(a,20);a->p3f4=dat_0c23f51c;a->b1a7=zero;a->pad2a2[0]=one;}break;
 case 1:a->b158=one;a->b1a1=one;func_0c0346da(a,21);a->p3f4=dat_0c23f520;a->b1a7=one;break;
 case 2:a->b158=2;a->b1a1=2;a->p3f4=dat_0c23f524;a->b1a7=2;break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=(int)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,7,a->b158);
}
void func_0c055a8c(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=6;func_0c0346da(a,20);a->p3f4=dat_0c23f51c;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=7;func_0c0346da(a,21);a->p3f4=dat_0c23f520;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=8;a->p3f4=dat_0c23f524;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=(int)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,9,a->b158);}
void func_0c055b58(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=3;func_0c0346da(a,20);a->p3f4=dat_0c23f528;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=4;func_0c0346da(a,21);a->p3f4=dat_0c23f52c;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=5;func_0c0346da(a,22);a->p3f4=dat_0c23f530;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=(int)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,8,a->b158);}
void func_0c055c04(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=9;func_0c0346da(a,20);a->p3f4=dat_0c23f528;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=10;func_0c0346da(a,21);a->p3f4=dat_0c23f52c;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=11;a->p3f4=dat_0c23f530;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=(int)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,10,a->b158);}
void func_0c055cce(struct Actor *a){func_0c044cbc(a);if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c055c04(a);else func_0c055b58(a);}else if(a->b1f9==1)func_0c055a8c(a);else func_0c05598c(a);}
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c0438de(struct Actor *),func_0c044df4(struct Actor *),func_0c0344a0(struct Actor *,int);
extern void func_0c042018(struct Actor *),func_0c0421b8(struct Actor *),func_0c0421f4(struct Actor *),func_0c0420f8(struct Actor *),func_0c043352(struct Actor *);
extern struct MotionGlobal_0c2d9260 dat_0c2d9260;
extern void (*dat_0c23f660[])(struct Actor *);
extern void (*dat_0c23f670[])(struct Actor *);
void func_0c055d16(struct Actor *a)
{
 void *zero=0; int one=1,two=2;
 switch(a->b1e8){
 case 0:
  if(a->w1fa&0x1000){
   a->b6=two;a->b7=(int)zero;a->b1d6&=15;
   a->f92=0;a->f96=0;a->f104=0;a->f108=0;
   a->b158=8;a->b1a1=21;func_0c0346da(a,22);
   a->b1a7=one;a->b1fc=(int)zero;
   if(!a->b1fc)goto p53c;goto p554;
  }
  a->b158=(int)zero;a->b1a1=12;func_0c0346da(a,20);
  if(!a->b1fc)a->p3f4=dat_0c23f534;else a->p3f4=dat_0c23f54c;
  a->b1a7=(int)zero;break;
 case 1:
  if(a->w1fa&0x2000){
   a->b6=one;a->b7=(int)zero;a->b1d6&=15;
   if(a->f56<a->f41c)goto land;
   a->b158=6;a->b1a1=19;func_0c0346da(a,22);
   a->b1a7=one;
   if(!a->b1fc){p53c:a->p3f4=dat_0c23f53c;}else{p554:a->p3f4=dat_0c23f554;}
  }
  else{a->b158=one;a->b1a1=13;func_0c0346da(a,21);
  if(!a->b1fc)a->p3f4=dat_0c23f538;else a->p3f4=dat_0c23f550;
  a->b1a7=one;}break;
 case 2:
  if(a->w1fa&0x800){
   if(a->f56<a->f41c)goto land;
   a->b1a1=18;a->b158=5;
  }else if(a->w1fa&0x1000){
   a->b6=one;a->b7=(int)zero;a->b1d6&=15;
   a->b1a1=20;
   if(a->f56<a->f41c){land:a->f56=a->f41c;func_0c044f1c(a);break;}
   a->b158=7;
  }else{a->b158=two;a->b1a1=14;}
  func_0c0346da(a,22);
  if(!a->b1fc)a->p3f4=dat_0c23f53c;else a->p3f4=dat_0c23f554;
  a->b1a7=two;break;
 }
 a->w1ac=(int)zero;a->b19e=(int)zero;a->p1c4=(int)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,11,a->b158);
 if(a->b1d6&0x0f)a->b1d6--;
}
void func_0c055f8e(struct Actor *a)
{
 void *zero=0; int one=1;
 switch(a->b1e8){
 case 0:
  if(a->w1fa&0x1000){
   a->b6=one;a->b7=(int)zero;a->b1d6&=15;
   a->b1a1=22;
   if(a->f56<a->f41c){a->f56=a->f41c;func_0c044f1c(a);break;}
   a->b158=6;func_0c0346da(a,22);
   if(!a->b1fc)a->p3f4=dat_0c23f544;else a->p3f4=dat_0c23f55c;
   goto s1;
  }
  a->b158=(int)zero;a->b1a1=15;func_0c0346da(a,20);
  if(!a->b1fc)a->p3f4=dat_0c23f540;else a->p3f4=dat_0c23f558;
  a->b1a7=(int)zero;break;
 case 1:
  a->b158=one;a->b1a1=16;func_0c0346da(a,21);
  if(!a->b1fc)a->p3f4=dat_0c23f544;else a->p3f4=dat_0c23f55c;
  s1:a->b1a7=one;break;
 case 2:
  a->b158=2;a->b1a1=17;
  if(!a->b1fc)a->p3f4=dat_0c23f548;else a->p3f4=dat_0c23f560;
  a->b1a7=2;break;
 }
 a->w1ac=(int)zero;a->b19e=(int)zero;a->p1c4=(int)zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,12,a->b158);
 if(a->b1d6&0xf0)a->b1d6-=16;
}
void func_0c056134(struct Actor *a){if((unsigned char)a->b1fe==1)func_0c055f8e(a);else func_0c055d16(a);}
void func_0c056146(struct Actor *a)
{
 if(!a->b1fe&&(a->b1d6&0x0f))goto call;else if(a->b1fe&&(a->b1d6&0xf0)){call:func_0c056134(a);}
}
void func_0c05616e(struct Actor *a){func_0c055cce(a);}
void func_0c056172(struct Actor *a){dat_0c23f660[a->b1ff](a);}
void func_0c056186(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:
  switch(a->b6){
  case 0:
   goto c1;
  case 1:
   if(func_0c02a026(a)<0)goto fail;
   if(((char *)&a->w150)[1]){((char *)&a->w150)[1]=zero;dat_0c2d9260.b5=1;dat_0c2d9260.b6=1;func_0c0346da(a,44);}
   if(a->b141){a->b141=zero;a->w130^=1;}
   break;
  }
  break;
 case 1:
 c1:
  if(func_0c02a026(a)>=0)break;
  goto fail;
 case 2:
  if(func_0c02a026(a)<0){fail:func_0c0437b8(a);return;}
  if(a->b141){if(a->b1d2)a->f52+=6.66666651f;else a->f52-=6.66666651f;}
  if(a->b14b){func_0c0346da(a,22);a->b14b=zero;}
  break;
 }
}
void func_0c05628a(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(a->b1e8==2&&a->b14b){func_0c0346da(a,22);a->b14b=0;}
}
void func_0c0562e8(struct Actor *a)
{
 struct ActorSub2a4 *sub=&a->sub2a4;
 switch(a->b1e8){
 case 0:case 1:
  if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
  break;
 case 2:
  if(func_0c02a026(a)<0)func_0c0437b8(a);
  if(!((char *)&sub->w4)[0]&&a->b19e){((char *)&sub->w4)[0]=1;func_0c0344a0(a,4);}
  if(((char *)&a->w150)[1]){
   ((char *)&a->w150)[1]=0;a->b1a1=25;
   a->b19e=a->w1ac=0;a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;
  }
  break;
 }
}
void func_0c056390(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
 if(a->b1e8==2&&a->b14b){func_0c0346da(a,22);a->b14b=0;}
}
void func_0c0563f0(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 func_0c044df4(a);
 if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c056390(a);else func_0c0562e8(a);}else if(a->b1f9==1)func_0c05628a(a);else func_0c056186(a);
}
void func_0c056472(struct Actor *a)
{
 func_0c02a026(a);
 if(((char *)&a->w150)[1]){
  a->b7++;((char *)&a->w150)[1]=0;
  a->f92=14.166666031f;a->f104=0.0f;a->f96=-17.142857f;a->f108=-0.5357143f;
  if(!a->b1d2)a->f92=-a->f92;
 }
}
void func_0c0564c8(struct Actor *a)
{
 func_0c02a026(a);
 if(func_0c044e52(a)){
  a->b7++;
  a->f92=0;a->f96=0;a->f104=0;a->f108=0;
  dat_0c2d9260.b5=1;dat_0c2d9260.b6=1;
  func_0c0346da(a,44);
  a->b1f9=0;
  func_0c02a0c4(a,11,9);
 }
}
void func_0c05654c(struct Actor *a)
{
 if(func_0c02a026(a)<0){a->w130^=1;func_0c0437b8(a);return;}
 if(a->b141){a->b141=0;a->w130^=1;}
}
void func_0c05658c(struct Actor *a)
{
 switch(a->b1e8){
 case 0:
  switch(a->b6){
  case 0:
   if(func_0c02a026(a)<0)func_0c0438de(a);
   goto chka;
  case 1:
   if(func_0c02a026(a)<0){func_0c0438de(a);func_0c02a0c4(a,1,12);}
  chka:
   if(func_0c044e52(a))goto land;
   break;
  case 2:
   switch(a->b7){
   case 0:func_0c056472(a);break;
   case 1:func_0c0564c8(a);break;
   case 2:func_0c05654c(a);break;
   }
   break;
  }
  break;
 case 1:
  if(func_0c02a026(a)<0)func_0c0438de(a);
  goto chkb;
 case 2:
  switch(a->b6){
  case 0:if(func_0c02a026(a)<0)func_0c0438de(a);break;
  case 1:func_0c02a026(a);break;
  }
 chkb:
  if(func_0c044e52(a)){land:func_0c044f1c(a);}
  break;
 }
}
void func_0c0566ac(struct Actor *a)
{
 switch(a->b1e8){
 case 0:
  if(a->b6)func_0c02a026(a);
  else if(func_0c02a026(a)<0)func_0c0438de(a);
  break;
 case 1:case 2:
  if(func_0c02a026(a)<0)func_0c0438de(a);
  if(a->b1e8==2&&a->b14b){func_0c0346da(a,22);a->b14b=0;}
  break;
 }
 if(func_0c044e52(a))func_0c044f1c(a);
}
void func_0c056750(struct Actor *a){func_0c042018(a);func_0c0421b8(a);if((unsigned char)a->b1fe==1)func_0c0566ac(a);else func_0c05658c(a);}
void func_0c05677a(struct Actor *a){func_0c0421f4(a);func_0c0420f8(a);func_0c056750(a);}
void func_0c056792(struct Actor *a){func_0c043352(a);func_0c0563f0(a);}
void func_0c0567a2(struct Actor *a){dat_0c23f670[a->b1ff](a);}
