#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *),func_0c056bb8(struct Actor *),func_0c0451f2(struct Actor *),func_0c0442fa(struct Actor *);
extern void func_0c048bb0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c23f8d4[])(struct Actor *);
extern short dat_0c23f904[];
extern int dat_0c23f8e4[2][2][2];
extern struct Actor *func_0c037d54(struct Actor *);
extern void func_0c025900(struct Actor *,char,char);
extern void func_0c1d4610(struct Actor *,struct LinkedActorVec3 *),func_0c044548(struct Actor *,struct Actor *);
void func_0c05965c(struct Actor *a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c05967e(struct Actor *a){table_0c23f8d4[a->b6](a);}
void func_0c059690(struct Actor *a)
{
 a->b6++;func_0c056bb8(a);func_0c048bb0(a,12);
 a->s28=dat_0c23f904[(unsigned char)a->b1a3];
 a->f92=dat_0c23f8e4[a->b202>>7][(unsigned char)a->b1a3][0]*1.66666663f/65536.0f;
 a->f104=dat_0c23f8e4[a->b202>>7][(unsigned char)a->b1a3][1]*1.66666663f/65536.0f;
 a->f96=9.642857f;a->f108=-0.2678571343422f;
 if(!a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}
 func_0c02a0c4(a,15,47);
}
void func_0c05974c(struct Actor *a)
{
 if(func_0c02a026(a)<0){a->b6++;a->b1d6=17;func_0c0451f2(a);func_0c02a0c4(a,15,48);}
}
void func_0c059782(struct Actor *a)
{
 struct LinkedActorVec3 position;
 struct Actor *target;
 if(!--a->s28){func_0c0438de(a);return;}
 func_0c02a026(a);
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;
 if(a->s28<8){
 if((target=func_0c037d54(a))){
 a->b6++;a->b7=0;a->b1f7=203;func_0c025900(a,5,5);
 position.x=-133.33333f;position.y=222.857132f;func_0c1d4610(a,&position);
 a->w130^=1;a->b1d2=*(unsigned char *)&a->w130;
 target->w130^=1;target->b1d2=*(unsigned char *)&target->w130;
 func_0c02a0c4(a,15,49);func_0c044548(a,target);
 }
 }
}
void func_0c0598a0(struct Actor *a)
{
 struct Actor *child;
 a->b1ea=1;a->b1ed=2;a->b1f5=2;a->b1f2=3;
 if(func_0c02a026(a)<0){func_0c0442fa(a);func_0c0438de(a);return;}
 if(a->b141){a->b141=0;func_0c025900(a,0,0);
 child=a->p1c8;child->b1f6=1;
 if(a->b255==3){child->b1a1=60;a->b1a1=60;}
 else{child->b1a1=a->b1a3+59;a->b1a1=a->b1a3+59;}
 }
}
