#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c043324(struct Actor *),func_0c0437b8(struct Actor *),func_0c025900(struct Actor *,int,int),func_0c02a0c4(struct Actor *,int,int);
extern void (*table_0c2487d0[])(struct Actor *);
void func_0c0d6560(struct Actor *a){if(!a->b141)func_0c02a026(a);a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;if(!(a->f56>a->f41c)){a->b6++;a->f56=a->f41c;a->b1f9=0;func_0c043324(a);}}
void func_0c0d65dc(struct Actor *a){struct Actor *child;func_0c02a026(a);a->b6++;child=a->p1c8;child->p1b4=a;child->b1f6=1;child->b1a1=35;func_0c025900(a,0,0);}
void func_0c0d660e(struct Actor *a){if(func_0c02a026(a)>=0)return;a->b6++;a->b1d2=a->w130=(unsigned char)a->b1d2^1;func_0c02a0c4(a,15,3);}
void func_0c0d664c(struct Actor *a){if(func_0c02a026(a)>=0)return;a->f92=0;a->f96=0;a->f104=0;a->f108=0;func_0c0437b8(a);}
void func_0c0d667e(struct Actor *a){table_0c2487d0[a->b6](a);}
