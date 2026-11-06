/* Ground-movement state handlers, 0x0c0f86c8-0x0c0f8a70. */
#include "objects.h"
extern void func_0c044cbc(struct Actor *),func_0c043352(struct Actor *),func_0c044df4(struct Actor *),func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *),func_0c0421f4(struct Actor *),func_0c0420f8(struct Actor *),func_0c042018(struct Actor *),func_0c0421b8(struct Actor *),func_0c044f1c(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern unsigned char func_0c044e52(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c0346da(struct Actor *,int);
extern void *func_0c1b3e6c(struct Actor *,int);
extern int table_0c24a61c[][3],table_0c24a634[][3],table_0c24a64c[][3];
extern unsigned char dat_0c2d9260[];
extern void (*table_0c24a74c[])(struct Actor *);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
#define CLEAR_RECORD a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++
void func_0c0f87ca(struct Actor *),func_0c0f88f2(struct Actor *);
void func_0c0f86c8(struct Actor *a)
{
 int zero; char mode; unsigned char t; char k; unsigned char tag;
 func_0c044cbc(a);
 a->p3f4=(char *)table_0c24a61c+((unsigned char)a->b1fe*3*4+a->b1e8*4);
 a->b1a7=a->b1e8;
 tag=(t=a->b1f9)*6+(k=a->b1fe)*3+(mode=a->b1e8);
 zero=0;
 if((a->w1fa&0x800) && !(unsigned char)k && (unsigned char)mode==2 && !(unsigned char)t){
  a->b1a1=18;
  CLEAR_RECORD;
  func_0c02a0c4(a,20,3);
  func_0c1b3e6c(a,1);
 }else{
  a->b1a1=tag;
  CLEAR_RECORD;
  func_0c02a0c4(a,a->b1f9*2+a->b1fe+7,(char)a->b1e8);
 }
 func_0c0346da(a,(char)a->b1e8+20);
}
void func_0c0f87ca(struct Actor *a){
 unsigned char *p;
 int offset;
 int zero;
 int t;
 
 t=(unsigned char)a->b1fe*3*4+a->b1e8*4;
 offset=(short)t;
 if(!a->b1fc)p=(unsigned char *)table_0c24a634;
 else p=(unsigned char *)table_0c24a64c;
 p+=offset;
 a->p3f4=p;
 zero=0;
 a->b1a7=a->b1e8;
 
 a->b1a1=a->b1fe*3+(char)a->b1e8+12;
 a->w1ac=zero;
 a->b19e=zero;
 *(void **)&a->p1c4=(void *)zero;
 dat_0c2f83f8->arr[a->b2]++;
 func_0c02a0c4(a,(char)a->b1fe+11,(char)a->b1e8);
 func_0c0346da(a,(char)a->b1e8+20);
 
 if(!a->b1fe){if(a->b1d6&15)a->b1d6--;
 }else{if(a->b1d6&240)a->b1d6-=16;
 }}
void func_0c0f88b2(struct Actor *a){if(!a->b1fe){if(a->b1d6&15)goto call;}else{if(!(a->b1d6&240))return;call:func_0c0f87ca(a);}}
void func_0c0f88d6(struct Actor *a){((struct ActorSubCommandPrefix *)&a->sub2a4)->command=0;table_0c24a74c[a->b1ff](a);}
void func_0c0f88f2(struct Actor *a){int zero;
 if(a->b1f9!=1)return;if(a->b1e8!=1)return;if(!a->b141)return;
 zero=0;a->b141=zero;a->b1a1=25;a->w1ac=zero;a->b19e=zero;*(unsigned int *)&a->p1c4=zero;dat_0c2f83f8->arr[a->b2]++;dat_0c2d9260[5]=1;dat_0c2d9260[6]=1;}
void func_0c0f8970(struct Actor *a){switch(a->b1ff){
 
 case 3:func_0c043352(a);
  
 
 case 0:a->f52+=a->f92;
  a->f92+=a->f104;
  a->f56+=a->f96;
  a->f96+=a->f108;
  func_0c044df4(a);
  if(func_0c02a026(a)<0)func_0c0437b8(a);
  else if(!a->b1fe)func_0c0f88f2(a);
  break;
  
 
 case 2:func_0c0421f4(a);
  func_0c0420f8(a);
  
 
 case 1:func_0c042018(a);
  func_0c0421b8(a);
  if(func_0c02a026(a)<0)func_0c0438de(a);
  if(func_0c044e52(a))func_0c044f1c(a);
  break;
  default:break;
  }}
