#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c1accc0(struct Actor *,int),func_0c02a0c4(struct Actor *,int,int);
void func_0c0c66f8(struct Actor *a){a->b7++;a->s28=38;a->f100=a->f52;if(a->b2==0){a->b1d2=1;a->f52+=-160.0f;}else {a->b1d2=0;a->f52-=-160.0f;}a->w130=(unsigned char)a->b1d2;a->f56=a->f41c+274.28571f;func_0c1accc0(a,12);func_0c02a0c4(a,18,4);}
void func_0c0c6764(struct Actor *a){if(--a->s28==0){a->b7++;a->s28=16;if(!(a->b1d2&1)){a->f52+=-20.0f;a->f92=3.3333333f;}else {a->f52-=-20.0f;a->f92=-3.3333333f;}a->f56-=107.142853f;a->f104=0;a->f96=8.5714283f;a->f108=-0.80357140303f;a->b1d2^=1;func_0c02a0c4(a,18,5);return;}func_0c02a026(a);}
void func_0c0c67e2(struct Actor *a){if(--a->s28==0){a->b7++;a->b1d2^=1;func_0c02a0c4(a,18,6);return;}a->f52+=a->f92;a->f92+=a->f104;a->f56+=a->f96;a->f96+=a->f108;func_0c02a026(a);}
