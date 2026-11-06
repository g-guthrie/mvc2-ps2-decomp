#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,unsigned char),func_0c02a39a(struct Actor *,int),func_0c02a684(struct Actor *,int,int,int),func_0c0437b8(struct Actor *),func_0c0346da(struct Actor *,int);
extern int func_0c03916c(struct Actor *),func_0c043628(struct Actor *),func_0c02849a(void);
extern void func_0c19996c(struct LinkedActor *,char),func_0c1d330c(struct Actor *,struct LinkedActorVec3 *,int,int);
extern struct LinkedActor *func_0c19cc70(struct LinkedActor *,unsigned char),*func_0c19a560(struct LinkedActor *,unsigned char);
extern float dat_0c2d92ec,dat_0c2d92e8;
extern unsigned char dat_0c2f837e,dat_0c243158[][2];
extern void (*table_0c2430f4[])(struct Actor *),(*table_0c2430fc[])(struct Actor *),(*table_0c243128[])(struct Actor *),(*table_0c243130[])(struct Actor *),(*table_0c24314c[])(struct Actor *),(*table_0c243178[])(struct Actor *),(*table_0c2431a8[])(struct Actor *),(*table_0c2431b0[])(struct Actor *);
void func_0c096cba(struct Actor *),func_0c096c32(struct Actor *),func_0c096daa(struct Actor *),func_0c096e46(struct Actor *),func_0c096e80(struct Actor *),func_0c097010(struct Actor *),func_0c0970a8(struct Actor *);
void func_0c096b84(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;
 if(a->f92*a->f104>0.0f){a->b6++;a->f52=a->f100;a->f92=0.0f;a->f104=0.0f;func_0c02a0c4(a,18,2);}
 func_0c02a026(a);
}
void func_0c096be2(struct Actor *a){if(func_0c02a026(a)<0)a->b5++;}
void func_0c096c02(struct Actor *a){table_0c2430f4[a->b6](a);}
void func_0c096c14(struct Actor *a){a->b6++;if(!a->b32)func_0c0970a8(a);func_0c096c32(a);}
void func_0c096c32(struct Actor *a){if(func_0c03916c(a)){func_0c0437b8(a);return;}table_0c2430fc[a->b32](a);}
void func_0c096c5e(struct Actor *a){table_0c243128[a->b7](a);}
void func_0c096c70(struct Actor *a)
{
 int z;char n;
 a->b7++;func_0c02a39a(a,0);a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;a->f56=a->f41c;z=0;a->b1fc=z;n=z;a->b1f9=n;func_0c02a0c4(a,19,n);func_0c096cba(a);
}
void func_0c096cba(struct Actor *a){func_0c02a026(a);}
void func_0c096cc0(struct Actor *a){a->b1f5=1;table_0c243130[a->b7](a);}
void func_0c096d04(struct Actor *a)
{
 int zero;
 func_0c02a39a(a,0);func_0c02a684(a,5,0,1);zero=0;a->f56=a->f41c;a->b1fc=zero;a->b1f9=zero;
 if(a->w130==0&&a->f52>dat_0c2d92ec-320.0f)goto hit;
 goto t;t:if(a->w130&&dat_0c2d92e8+320.0f>a->f52){
  hit:a->b7++;a->f92=!a->w130?-6.66666651f:6.66666651f;a->f104=0.0f;a->f96=0.0f;a->f108=0.0f;func_0c02a0c4(a,0,2);func_0c096daa(a);
 }else{a->b7=2;func_0c096e46(a);}
}
void func_0c096daa(struct Actor *a)
{
 func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;
 if(a->w130==0&&!(a->f52>dat_0c2d92ec-320.0f))goto hit;
 goto t;t:if(a->w130&&!(dat_0c2d92e8+320.0f>a->f52)){hit:a->b7++;func_0c096e46(a);}
}
void func_0c096e46(struct Actor *a)
{
 a->b326=255;a->b7=3;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;
 func_0c19996c((struct LinkedActor *)a,0);func_0c02a0c4(a,19,3);func_0c096e80(a);
}
void func_0c096e80(struct Actor *a)
{
 a->b326=255;
 if(func_0c02a026(a)<0){
  a->b7++;a->s28=60;
  func_0c19cc70((struct LinkedActor *)a,0);func_0c19cc70((struct LinkedActor *)a,1);func_0c19cc70((struct LinkedActor *)a,2);func_0c19cc70((struct LinkedActor *)a,3);func_0c19cc70((struct LinkedActor *)a,4);
  func_0c19cc70((struct LinkedActor *)a,5);func_0c19cc70((struct LinkedActor *)a,6);func_0c19cc70((struct LinkedActor *)a,7);func_0c19cc70((struct LinkedActor *)a,8);func_0c19cc70((struct LinkedActor *)a,9);
 }
}
void func_0c096eea(struct Actor *a){a->b326=255;if(--a->s28<=0){a->b7++;func_0c02a0c4(a,19,4);}}
void func_0c096f0e(struct Actor *a){a->b326=255;if(func_0c02a026(a)<0){a->b7++;func_0c02a0c4(a,13,31);}}
void func_0c096f40(struct Actor *a){a->b326=255;}
void func_0c096f48(struct Actor *a){table_0c24314c[a->b7](a);}
void func_0c096f74(struct Actor *a)
{
 struct LinkedActorVec3 point;int zero;
 a->b7++;func_0c02a39a(a,0);func_0c02a684(a,5,1,1);
 a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;zero=0;
 a->f56=a->f41c;a->b1fc=zero;a->b1f9=zero;
 if(!a->w130)point.x=a->f52+0.0f;else point.x=a->f52+-0.0f;
 point.y=a->f56+85.71428f;
 func_0c1d330c(a,&point,1,8);func_0c0346da(a,74);func_0c02a0c4(a,19,2);func_0c097010(a);
}
void func_0c097010(struct Actor *a)
{
 func_0c02a026(a);if(!a->b141){a->b7++;
  func_0c19a560((struct LinkedActor *)a,0);func_0c19a560((struct LinkedActor *)a,1);func_0c19a560((struct LinkedActor *)a,2);func_0c19a560((struct LinkedActor *)a,3);func_0c19a560((struct LinkedActor *)a,4);
  func_0c19a560((struct LinkedActor *)a,5);func_0c19a560((struct LinkedActor *)a,6);func_0c19a560((struct LinkedActor *)a,7);func_0c19a560((struct LinkedActor *)a,8);func_0c19a560((struct LinkedActor *)a,10);func_0c19a560((struct LinkedActor *)a,11);
 }
}
void func_0c097076(struct Actor *a){func_0c02a026(a);}
void func_0c0970a8(struct Actor *a)
{
 int fallback=5;
 if(a->w4dc&0x3f0){
  a->b32=fallback;if(a->w4dc&0x100)a->b32=6;if(a->w4dc&0x80)a->b32=7;if(a->w4dc&0x40)a->b32=8;if(a->w4dc&0x20)a->b32=9;if(a->w4dc&0x10)a->b32=10;
 }else a->b32=dat_0c243158[func_0c02849a()&15][0];
 if(!dat_0c2f837e){if(a->b32==8||a->b32==9||a->b32==10)a->b32=fallback;}
 if(func_0c043628(a)>1)a->b32=fallback;
}
void func_0c097168(struct Actor *a){table_0c243178[a->b1e9](a);}
void func_0c09717c(struct Actor *a){table_0c2431a8[a->b6](a);}
void func_0c09718e(struct Actor *a){table_0c2431b0[a->b7](a);}
