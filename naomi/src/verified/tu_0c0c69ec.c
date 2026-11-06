#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern int func_0c03916c(struct Actor *),func_0c0c9ea0(struct Actor *),func_0c0c9f96(struct Actor *,int),func_0c02849a(void);
extern void func_0c0437b8(struct Actor *),func_0c02a39a(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int),func_0c02a684(struct Actor *,int,int,int),func_0c0442fa(struct Actor *),func_0c048bb0(struct Actor *,int),func_0c0432ca(struct Actor *);
extern struct Actor *func_0c1accc0(struct Actor *,unsigned char);
extern void func_0c0c9e20(struct Actor *,void *),func_0c1a9cf0(struct Actor *,int),func_0c15ccc8(struct Actor *,int);
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern unsigned char dat_0c247614[],dat_0c247644[],dat_0c246edc[];
extern signed char dat_0c2478f4[],dat_0c2f837e;
extern void (*table_0c247864[])(struct Actor *);
extern void (*table_0c247890[])(struct Actor *);
extern void (*table_0c247898[])(struct Actor *);
extern void (*table_0c2478a8[])(struct Actor *);
extern void (*table_0c2478b8[])(struct Actor *);
extern void (*table_0c2478cc[])(struct Actor *);
extern void (*table_0c2478d8[])(struct Actor *);
extern void (*table_0c2478e4[])(struct Actor *);
extern void (*table_0c2478ec[])(struct Actor *);
extern void (*table_0c247914[])(struct Actor *);
extern void (*table_0c247948[])(struct Actor *);
extern void (*table_0c247950[])(struct Actor *);
extern void (*table_0c24795c[])(struct Actor *);
void func_0c0c6a0a(struct Actor *);
void func_0c0c6a6c(struct Actor *);
void func_0c0c6ab4(struct Actor *);
void func_0c0c6b68(struct Actor *);
void func_0c0c6c52(struct Actor *);
void func_0c0c6d9a(struct Actor *);
void func_0c0c6e66(struct Actor *);
void func_0c0c6eec(struct Actor *);
void func_0c0c6f4c(struct Actor *);
void func_0c0c6f78(struct Actor *);
void func_0c0c7118(struct Actor *);
void func_0c0c7184(struct Actor *);

void func_0c0c69ec(struct Actor *a){a->b6++;if(!a->b32)func_0c0c6f78(a);func_0c0c6a0a(a);}
void func_0c0c6a0a(struct Actor *a){if(func_0c03916c(a)){func_0c0437b8(a);return;}table_0c247864[a->b32](a);}
void func_0c0c6a36(struct Actor *a){table_0c247890[a->b7](a);}
void func_0c0c6a48(struct Actor *a){a->b7++;func_0c02a39a(a,0);func_0c02a0c4(a,19,1);func_0c0c6a6c(a);}
void func_0c0c6a6c(struct Actor *a){func_0c02a026(a);}
void func_0c0c6a72(struct Actor *a){table_0c247898[a->b7](a);}
void func_0c0c6a84(struct Actor *a){a->b7++;a->s28=1;func_0c02a39a(a,0);func_0c1accc0(a,6);func_0c02a0c4(a,0,0);func_0c0c6ab4(a);}
void func_0c0c6ab4(struct Actor *a){if(!a->s28){a->b7++;func_0c02a0c4(a,19,0);}func_0c02a026(a);}
void func_0c0c6ada(struct Actor *a){func_0c02a026(a);if(a->b141)a->b7=a->b7+1;}
void func_0c0c6af8(struct Actor *a){a->b326=255;func_0c02a026(a);}
void func_0c0c6b04(struct Actor *a){table_0c2478a8[a->b7](a);}
void func_0c0c6b44(struct Actor *a){a->b7++;func_0c02a39a(a,0);func_0c02a0c4(a,19,7);func_0c0c6b68(a);}
void func_0c0c6b68(struct Actor *a){func_0c02a026(a);if(a->b141){a->b7++;func_0c0c9e20(a,dat_0c247614);func_0c0c9ea0(a);}}
void func_0c0c6b98(struct Actor *a){if(!func_0c0c9ea0(a)){a->b7++;func_0c0c9e20(a,dat_0c247644);func_0c0c9ea0(a);}}
void func_0c0c6bc4(struct Actor *a){func_0c0c9ea0(a);func_0c02a026(a);}
void func_0c0c6bd6(struct Actor *a){a->b326=255;table_0c2478b8[a->b7](a);}
void func_0c0c6bf0(struct Actor *a)
{
 if(func_0c0c9f96(a,28)){a->b32=5;func_0c0c6a36(a);return;}
 a->b7++;a->s28=1;func_0c02a39a(a,0);func_0c02a684(a,7,a->b37*87u+57,1);
 func_0c1accc0(a,8);func_0c02a0c4(a,0,0);func_0c0c6c52(a);
}
void func_0c0c6c52(struct Actor *a){if(!a->s28){a->b7++;func_0c02a0c4(a,19,6);}func_0c02a026(a);}
void func_0c0c6cac(struct Actor *a){if(func_0c02a026(a)<0){a->b7++;a->s28=1;func_0c02a0c4(a,0,0);}}
void func_0c0c6cda(struct Actor *a){if(!a->s28){a->b7++;func_0c02a0c4(a,19,1);}func_0c02a026(a);}
void func_0c0c6d00(struct Actor *a){func_0c02a026(a);}
void func_0c0c6d06(struct Actor *a){a->b326=255;table_0c2478cc[a->b7](a);}
void func_0c0c6d20(struct Actor *a)
{
 if(func_0c0c9f96(a,28)){a->b32=5;func_0c0c6a36(a);return;}
 a->b7++;a->s28=1;func_0c02a39a(a,0);
 func_0c02a684(a,1,a->b37*87u+85,1);func_0c02a684(a,2,a->b37*87u+32,1);
 func_0c1accc0(a,9);func_0c02a0c4(a,0,0);func_0c0c6d9a(a);
}
void func_0c0c6d9a(struct Actor *a){if(!a->s28){a->b7++;func_0c02a0c4(a,19,8);}func_0c02a026(a);}
void func_0c0c6dc0(struct Actor *a){func_0c02a026(a);}
void func_0c0c6dc6(struct Actor *a){a->b326=255;table_0c2478d8[a->b7](a);}
void func_0c0c6e04(struct Actor *a)
{
 if(func_0c0c9f96(a,28)){a->b32=5;func_0c0c6a36(a);return;}
 a->b7++;a->s28=1;func_0c02a39a(a,0);func_0c02a684(a,2,a->b37*87u+85,1);
 func_0c1accc0(a,10);func_0c02a0c4(a,0,0);func_0c0c6e66(a);
}
void func_0c0c6e66(struct Actor *a){if(!a->s28){a->b7++;func_0c02a0c4(a,14,0);}func_0c02a026(a);}
void func_0c0c6e8c(struct Actor *a){func_0c02a026(a);}
void func_0c0c6e92(struct Actor *a){table_0c2478e4[a->b7](a);}
void func_0c0c6ea4(struct Actor *a){a->b7++;func_0c02a39a(a,0);a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f56=a->f41c;a->b1fc=0;a->b1f9=0;func_0c02a0c4(a,19,4);func_0c0c6eec(a);}
void func_0c0c6eec(struct Actor *a){func_0c02a026(a);}
void func_0c0c6ef2(struct Actor *a){table_0c2478ec[a->b7](a);}
void func_0c0c6f04(struct Actor *a){a->b7++;func_0c02a39a(a,0);a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f56=a->f41c;a->b1fc=0;a->b1f9=0;func_0c02a0c4(a,19,5);func_0c0c6f4c(a);}
void func_0c0c6f4c(struct Actor *a){func_0c02a026(a);}
void func_0c0c6f78(struct Actor *a)
{
 if(a->w4dc&0x3f0){
  a->b32=5;if(a->w4dc&0x100)a->b32=6;if(a->w4dc&0x80)a->b32=7;
  if(a->w4dc&0x40)a->b32=8;if(a->w4dc&0x20)a->b32=9;if(a->w4dc&0x10)a->b32=10;
 }else a->b32=dat_0c2478f4[(func_0c02849a()&15)*2];
 if(!dat_0c2f837e){unsigned int mode;if((mode=a->b32)==6||mode==8||mode==9||mode==10)a->b32=5;}
}
void func_0c0c702e(struct Actor *a){table_0c247914[a->b1e9](a);}
void func_0c0c7042(struct Actor *a){table_0c247948[a->b6](a);}
void func_0c0c7054(struct Actor *a){table_0c247950[a->b7](a);}
void func_0c0c7066(struct Actor *a)
{
 int zero;
 if(a->b1f9==2){a->b6=1;func_0c0c7184(a);return;}
 a->b7++;func_0c0442fa(a);func_0c02a39a(a,1);a->f92=0;a->f96=0;a->f104=0;a->f108=0;a->f56=a->f41c;
 zero=0;a->b1a1=48;a->w1ac=zero;a->b19e=zero;*(void **)&a->p1c4=(void *)zero;dat_0c2f83f8->arr[a->b2]++;
 func_0c048bb0(a,5);func_0c02a0c4(a,21,0);func_0c0432ca(a);func_0c0c7118(a);
}
void func_0c0c7118(struct Actor *a)
{
 func_0c02a026(a);
 if(a->b141){a->b7++;a->b141=0;func_0c0c9e20(a,dat_0c246edc);func_0c0c9ea0(a);func_0c1a9cf0(a,3);func_0c15ccc8(a,3);}
}
void func_0c0c715e(struct Actor *a){func_0c0c9ea0(a);if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0c7184(struct Actor *a){table_0c24795c[a->b7](a);}
