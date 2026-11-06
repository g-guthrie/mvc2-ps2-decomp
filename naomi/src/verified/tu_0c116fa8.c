/* Connected motion and animation callbacks with five reviewed pools. */
#include "objects.h"
extern void func_0c043352(struct Actor *),func_0c044df4(struct Actor *),func_0c0437b8(struct Actor *),func_0c0438de(struct Actor *),func_0c17aabc(struct Actor *,int,int),func_0c02a0c4(struct Actor *,int,int),func_0c0421f4(struct Actor *),func_0c0420f8(struct Actor *),func_0c042018(struct Actor *),func_0c0421b8(struct Actor *),func_0c044f1c(struct Actor *);
extern unsigned char func_0c0462a0(struct Actor *),func_0c044e52(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void (*dat_0c24ca60[])(struct Actor *),(*dat_0c24ca6c[])(struct Actor *),(*dat_0c24ca74[])(struct Actor *),(*dat_0c24ca80[])(struct Actor *),(*dat_0c24ca8c[])(struct Actor *),(*dat_0c24ca98[])(struct Actor *),(*dat_0c24caa4[])(struct Actor *);
void func_0c116fb6(struct Actor *),func_0c117038(struct Actor *),func_0c117130(struct Actor *),func_0c1171c2(struct Actor *),func_0c11728a(struct Actor *),func_0c1173b4(struct Actor *),func_0c11740c(struct Actor *),func_0c1174de(struct Actor *);
void func_0c116fa8(struct Actor *a){func_0c043352(a);func_0c116fb6(a);}
void func_0c116fb6(struct Actor *a)
{
 a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c044df4(a);
 if((unsigned char)a->b1fe==1){if(a->b1f9==1)func_0c11728a(a);else func_0c1171c2(a);}
 else{if(a->b1f9==1)func_0c117130(a);else func_0c117038(a);}
}
void func_0c117038(struct Actor *a)
{
 dat_0c24ca60[a->b1e8](a);
}
void func_0c11704c(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c11706e(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c117090(struct Actor *a)
{
 func_0c02a026(a);if(a->b141){int zero=0;a->b141=zero;func_0c17aabc(a,1,zero);}
 if(--a->s28==0){a->b6++;func_0c02a0c4(a,20,0);}
}
void func_0c1170fc(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c11711e(struct Actor *a)
{
 dat_0c24ca6c[a->b6](a);
}
void func_0c117130(struct Actor *a)
{
 dat_0c24ca74[a->b1e8](a);
}
void func_0c117144(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c117166(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c117188(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}if(a->b141){int zero=0;a->b141=zero;func_0c17aabc(a,2,zero);}
}
void func_0c1171c2(struct Actor *a)
{
 dat_0c24ca80[a->b1e8](a);
}
void func_0c1171d6(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c1171f8(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}if(a->b141){int zero=0;a->b141=zero;func_0c17aabc(a,1,2);}
}
void func_0c117250(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}if(a->b141){int zero=0;a->b141=zero;func_0c17aabc(a,1,4);}
}
void func_0c11728a(struct Actor *a)
{
 dat_0c24ca8c[a->b1e8](a);
}
void func_0c11729e(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0437b8(a);
}
void func_0c1172c0(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}
 if(a->b141&2){a->b141&=(unsigned char)~2;func_0c17aabc(a,1,1);}
 if(a->b141&1){a->b141&=(unsigned char)~1;a->f92=-6.66666651f;a->f104=0.416666657f;
 if(a->b1d2){a->f92=-a->f92;a->f104=-a->f104;}}
}
void func_0c11733a(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0437b8(a);return;}if(a->b141){int zero=0;a->b141=zero;func_0c17aabc(a,1,5);}
}
void func_0c117394(struct Actor *a)
{
 if(a->b201)goto dispatch;
 func_0c0421f4(a);func_0c0420f8(a);
 dispatch:func_0c1173b4(a);
}
void func_0c1173b4(struct Actor *a)
{
 if(a->b201 && func_0c0462a0(a))return;
 func_0c042018(a);func_0c0421b8(a);
 if((unsigned char)a->b1fe==1)func_0c1174de(a);else func_0c11740c(a);
 if(func_0c044e52(a))func_0c044f1c(a);
}
void func_0c11740c(struct Actor *a)
{
 dat_0c24ca98[a->b1e8](a);
}
void func_0c117420(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0438de(a);return;}if(a->b141)a->b141=0;
}
void func_0c11744c(struct Actor *a)
{
 if(func_0c02a026(a)<0){func_0c0438de(a);return;}if(a->b141){int zero=0;a->b141=zero;func_0c17aabc(a,1,3);}
}
void func_0c1174bc(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0438de(a);
}
void func_0c1174de(struct Actor *a)
{
 dat_0c24caa4[a->b1e8](a);
}
void func_0c1174f2(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0438de(a);
}
void func_0c117514(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0438de(a);
}
void func_0c117536(struct Actor *a)
{
 if(func_0c02a026(a)<0)func_0c0438de(a);
}
void func_0c117558(struct Actor *a)
{
 func_0c02a026(a);if(!a->b141){a->b141=0;a->b7++;
 a->f92=-3.3333333f;a->f104=0.0f;a->f96=-2.1428571f;a->f108=-0.2678571343422f;
 if(a->w130){a->f92=-a->f92;a->f104=-a->f104;}}
}
