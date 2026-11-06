#include "objects.h"
extern char func_0c02a026(struct Actor*);
extern void func_0c0437b8(struct Actor*),func_0c02a0c4(struct Actor*,int,int);
extern struct Tbl_ub3_01*dat_0c2f83f8;
void func_0c0600b8(struct Actor*a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c0600da(struct Actor*a){switch(a->b1e8){case 0:if(func_0c02a026(a)<0)goto failed;if(a->b141){a->b141=0;a->b1a1=27;a->w1ac=0;a->b19e=0;a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;}break;case 1:case 2:if(func_0c02a026(a)<0){failed:func_0c0437b8(a);return;}break;}}
void func_0c060150(struct Actor*a){if(func_0c02a026(a)<0){a->b7++;a->b1f9=2;a->f92=3.3333333f;a->f104=0.0f;a->f96=4.28571415f;a->f108=-0.33482140303f;if(!a->w130)a->f92=-a->f92;func_0c02a0c4(a,8,4);}}
extern void func_0c043324(struct Actor*);
void func_0c0601d4(struct Actor*a){if(func_0c02a026(a)<0){a->b7++;func_0c043324(a);a->b1f9=0;a->f92=0.0f;a->f96=0.0f;a->f104=0.0f;a->f108=0.0f;a->f56=a->f41c;func_0c02a0c4(a,8,5);return;}if(!a->b141)return;a->b1a1=a->b141;a->w1ac=0;a->b19e=0;a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;a->b141=0;}
void func_0c06025a(struct Actor*a){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c06027c(struct Actor*a){switch(a->b1e8){case 0:case 1:goto animate;case 2:if(!a->b6){animate:if(func_0c02a026(a)<0)func_0c0437b8(a);}else{switch(a->b7){case 0:func_0c060150(a);break;case 1:func_0c0601d4(a);break;case 2:func_0c06025a(a);break;}}break;}}
