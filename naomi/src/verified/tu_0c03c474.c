#include "objects.h"
extern unsigned char func_0c0464c4(struct Actor *);
extern char func_0c02a026(struct Actor *);
extern void func_0c02a0c4(struct Actor *,int,int),func_0c02a39a(struct Actor *,int),func_0c045248(struct Actor *,int),func_0c043324(struct Actor *),func_0c0437b8(struct Actor *);
void func_0c03c474(struct Actor *a){a->b3f0=255;a->b3f1=16;a->b6++;a->b1fd=0;a->b12c=1;a->b1e1=80;func_0c02a0c4(a,1,1);func_0c02a39a(a,1);}
void func_0c03c4b4(struct Actor *a){int zero;float stopped;func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;if(a->f56<=a->f41c){zero=0;stopped=0;a->f56=a->f41c;a->b1f9=zero;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;func_0c02a0c4(a,zero,zero);a->b5=zero;a->b7=zero;a->b6=zero;a->b1e9=a->b258;func_0c045248(a,29);func_0c043324(a);}}
void func_0c03c55c(struct Actor *a){((void (**)(struct Actor *))a->p428)[14](a);}
void func_0c03c56a(struct Actor *a){if(!a->b6){float stopped;a->b6++;a->b1f9=0;stopped=0;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;if(a->b203){if(a->f56<a->f41c+34.2857132f)a->f56=a->f208;}else a->f56=a->f41c;func_0c02a0c4(a,24,3);}else if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c03c618(struct Actor *a){if(!a->b6){float stopped;a->b6++;stopped=0;a->f92=stopped;a->f96=stopped;a->f104=stopped;a->f108=stopped;a->s28=40;func_0c02a0c4(a,24,4);}else{func_0c02a026(a);if(--a->s28<0){a->b256=2;a->b6=a->b7=0;a->b1ed=2;}}}
void func_0c03c676(struct Actor *a){if(!func_0c0464c4(a)){if(a->b1f9!=2&&(unsigned char)a->b1a3!=1&&a->b19e&&!(a->b19e&9)){a->b19e|=8;if((!a->b1d2&&a->f92<0)||(a->b1d2&&a->f92>0))a->f104*=4.0f;}((void (**)(struct Actor *))a->p428)[15](a);if(a->b200&&a->b1d0==34)((void (**)(struct Actor *))a->p428)[15](a);}}
