/* Special-move checker and stance-state unit for one character (0x0c0bc47c-
 * 0x0c0bce0c), the template of tu_0c0bfd60 and tu_0c0c50d0. */
#include "objects.h"
extern unsigned char func_0c0465cc(struct Actor *),func_0c046b6c(struct Actor *),func_0c0469f4(struct Actor *),func_0c046d3c(struct Actor *);
extern unsigned char func_0c04608a(struct Actor *,unsigned char *);
extern void func_0c045f1c(struct Actor *),func_0c0463fc(struct Actor *);
extern unsigned char func_0c046e7e(struct Actor *,unsigned char *,unsigned char *),func_0c0471ea(struct Actor *,unsigned char *,unsigned char *),func_0c047886(struct Actor *);
extern void func_0c047aac(struct Actor *,unsigned char *),func_0c045248(struct Actor *,int);
extern int func_0c046d54(struct Actor *);
extern unsigned char func_0c046dd0(struct Actor *,int);
extern void func_0c044cbc(struct Actor *),func_0c0346da(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c15ba0c(struct Actor *,int,int);
extern unsigned int dat_0c245ae8[];
extern unsigned char dat_0c245a64[],dat_0c245a78[],dat_0c245a88[],dat_0c245a9c[],dat_0c245aac[],dat_0c245abc[],dat_0c245adc[];
extern unsigned char dat_0c245a1c[],dat_0c245a20[],dat_0c245a24[],dat_0c245a28[],dat_0c245a2c[],dat_0c245a30[];
extern void (*table_0c245b58[])(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
unsigned char func_0c0bc56c(struct Actor *),func_0c0bc5ca(struct Actor *),func_0c0bc610(struct Actor *),func_0c0bc656(struct Actor *),func_0c0bc6d0(struct Actor *),func_0c0bc720(struct Actor *),func_0c0bc770(struct Actor *);
int func_0c0bc816(struct Actor *),func_0c0bc8bc(struct Actor *),func_0c0bc914(struct Actor *),func_0c0bc94a(struct Actor *);
int func_0c0bc856(struct Actor *);
void func_0c0bc9e0(struct Actor *),func_0c0bcb06(struct Actor *),func_0c0bcbdc(struct Actor *),func_0c0bccf0(struct Actor *);

void func_0c0bc47c(struct Actor *a)
{
    register unsigned int i;
    register unsigned int limit = 112;
    register unsigned int *out = *((unsigned int **)((char *)a + 0x428));
    register unsigned int *in = dat_0c245ae8;
    i = 0;
copy_next:
    *(unsigned int *)((char *)out + i) = *(unsigned int *)((char *)in + i);
    i += 4;
    if (i < limit) goto copy_next;
}
void func_0c0bc498(struct Actor *a)
{
 if(func_0c0465cc(a))return;
 if(func_0c046b6c(a))return;
 if(func_0c0469f4(a))return;
 if(func_0c046d3c(a))return;
 if(func_0c0bc770(a))return;
 if(func_0c0bc720(a))return;
 if(func_0c0bc6d0(a))return;
 if(func_0c0bc656(a))return;
 if(func_0c0bc56c(a))return;
 if(func_0c0bc5ca(a))return;
 if(func_0c0bc610(a))return;
 if(func_0c0bc816(a))return;
 if(func_0c0bc856(a))return;
 if(func_0c04608a(a,a->x3cc))return;
 func_0c045f1c(a);func_0c0463fc(a);
}
unsigned char func_0c0bc56c(struct Actor *a)
{
 struct ActorSubMoveBytes *sub=(struct ActorSubMoveBytes *)&a->sub2a4;
 if(!func_0c046e7e(a,dat_0c245a64,a->x36c))goto fail;
 if(sub->b0){fail:return 0;}
 func_0c047aac(a,a->x36c);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=0;
 func_0c045248(a,21);return 1;
}
unsigned char func_0c0bc5ca(struct Actor*a){if(!func_0c046e7e(a,dat_0c245a78,a->x374))return 0;func_0c047aac(a,a->x374);a->b5=0;a->b7=0;a->b6=0;a->b1e9=1;func_0c045248(a,21);return 1;}
unsigned char func_0c0bc610(struct Actor*a){if(!func_0c046e7e(a,dat_0c245a88,a->x37c))return 0;func_0c047aac(a,a->x37c);a->b5=0;a->b7=0;a->b6=0;a->b1e9=2;func_0c045248(a,21);return 1;}
unsigned char func_0c0bc656(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c245a9c,a->x384))goto fail;
 if(!*a->p40c){fail:return 0;}
 func_0c047aac(a,a->x384);a->b5=0;a->b7=0;a->b6=0;a->b1e9=3;func_0c045248(a,29);return 1;
}
unsigned char func_0c0bc6d0(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c245aac,a->x38c))goto fail;
 if(!*a->p40c){fail:return 0;}
 func_0c047aac(a,a->x38c);a->b5=0;a->b7=0;a->b6=0;a->b1e9=4;func_0c045248(a,29);return 1;
}
unsigned char func_0c0bc720(struct Actor *a)
{
 if(!func_0c046e7e(a,dat_0c245abc,a->x394))goto fail;
 if(!*a->p40c){fail:return 0;}
 func_0c047aac(a,a->x394);a->b5=0;a->b7=0;a->b6=0;a->b1e9=5;func_0c045248(a,29);return 1;
}
unsigned char func_0c0bc770(struct Actor *a)
{
 if(!func_0c0471ea(a,dat_0c245adc,a->x3a4)||!func_0c047886(a))goto fail;
 if(a->b1f9==2 && !a->b1fc){if(a->b1d4){fail:return 0;}a->b1d4++;}
 func_0c047aac(a,a->x3a4);
 a->b5=0;a->b7=0;a->b6=0;a->b1e9=6;
 func_0c045248(a,21);return 1;
}
int func_0c0bc816(struct Actor*a){if(!func_0c046d54(a))return 0;else if(!*a->p40c)return 0;a->b1e9=15;a->b5=0;func_0c045248(a,29);a->b6=(((char*)a)[7]=0);return 1;}
int func_0c0bc856(struct Actor *a)
{
    if (!func_0c046dd0(a, 8)) return 0;
    a->b1e9 = 8;
    a->b5 = 0;
    func_0c045248(a, 21);
    a->b6 = a->b7 = 0;
    return 1;
}
int func_0c0bc890(struct Actor *a)
{
    if (func_0c0bc8bc(a) || func_0c0bc914(a) || func_0c0bc94a(a))
        return 1;
    return 0;
}
int func_0c0bc8bc(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c245abc, (unsigned char *)a + 0x394))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 5;
    return 1;
}
int func_0c0bc914(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c245aac, (unsigned char *)a + 0x38c))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 4;
    return 1;
}
int func_0c0bc94a(struct Actor *a)
{
    if (!func_0c046e7e(a, dat_0c245a9c, (unsigned char *)a + 0x384))
        return 0;
    else if (!*a->p40c)
        return 0;
    a->b258 = 3;
    return 1;
}
void func_0c0bc980(void){}
void func_0c0bc984(struct Actor *a){table_0c245b58[a->b1ff](a);}
void func_0c0bc998(struct Actor *a){func_0c044cbc(a);if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c0bccf0(a);else func_0c0bcbdc(a);}else if(a->b1f9==1)func_0c0bcb06(a);else func_0c0bc9e0(a);}
void func_0c0bc9e0(struct Actor *a)
{
 int zero=0,one=1;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=zero;func_0c0346da(a,20);a->p3f4=dat_0c245a1c;a->b1a7=zero;break;
 case 1:a->b158=one;a->b1a1=one;func_0c0346da(a,21);a->p3f4=dat_0c245a20;a->b1a7=one;break;
 case 2:
  a->p3f4=dat_0c245a24;a->b1a7=2;
  if(a->w1fa&0x800){
   a->b6=one;a->b1a1=87;a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;
   func_0c02a0c4(a,21,21);func_0c15ba0c(a,5,0);return;
  }
  a->b158=2;a->b1a1=2;func_0c0346da(a,22);break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,7,a->b158);
}
void func_0c0bcb06(struct Actor *a){int zero=0;switch(a->b1e8){case 0:a->b158=zero;a->b1a1=6;func_0c0346da(a,20);a->p3f4=dat_0c245a1c;a->b1a7=zero;break;case 1:a->b158=1;a->b1a1=7;func_0c0346da(a,21);a->p3f4=dat_0c245a20;a->b1a7=1;break;case 2:a->b158=2;a->b1a1=8;func_0c0346da(a,22);a->p3f4=dat_0c245a24;a->b1a7=2;break;}a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,9,a->b158);}
void func_0c0bcbdc(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=3;func_0c0346da(a,20);a->p3f4=dat_0c245a28;a->b1a7=zero;break;
 case 1:a->b158=1;a->b1a1=4;func_0c0346da(a,21);a->p3f4=dat_0c245a2c;a->b1a7=1;break;
 case 2:
  a->f52+=a->b1d2?26.666666031f:-26.666666031f;
  a->b158=2;a->b1a1=5;func_0c0346da(a,22);a->p3f4=dat_0c245a30;a->b1a7=2;func_0c15ba0c(a,4,0);break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,8,a->b158);
}
void func_0c0bccf0(struct Actor *a)
{
 int zero=0;
 switch(a->b1e8){
 case 0:a->b158=zero;a->b1a1=9;func_0c0346da(a,20);a->p3f4=dat_0c245a28;a->b1a7=zero;break;
 case 1:a->b158=1;a->b1a1=10;func_0c0346da(a,21);a->p3f4=dat_0c245a2c;a->b1a7=1;break;
 case 2:
  a->p3f4=dat_0c245a30;a->b1a7=2;
  if(!a->b525 && a->w1fa&0x400){a->b6++;a->b1a1=18;a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,10,3);return;}
  a->b158=2;a->b1a1=11;func_0c0346da(a,22);break;
 }
 a->w1ac=zero;a->b19e=zero;*(unsigned int*)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;func_0c02a0c4(a,10,a->b158);
}
