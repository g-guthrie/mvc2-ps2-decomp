#include "objects.h"
extern char func_0c02a026(struct Actor*);
extern unsigned char func_0c044e52(struct Actor*);
extern void func_0c0421f4(struct Actor*),func_0c0420f8(struct Actor*),func_0c042018(struct Actor*),func_0c0421b8(struct Actor*),func_0c044f1c(struct Actor*),func_0c0438de(struct Actor*);
extern struct Tbl_ub3_01*dat_0c2f83f8;
extern void (*table_0c2430b4[])(struct Actor*);
void func_0c0963b6(struct Actor*),func_0c0963f8(struct Actor*),func_0c09641a(struct Actor*);
void func_0c0963a0(struct Actor*a){func_0c0421f4(a);func_0c0420f8(a);func_0c0963b6(a);}
void func_0c0963b6(struct Actor*a){func_0c042018(a);func_0c0421b8(a);if((unsigned char)a->b1fe==1)func_0c09641a(a);else func_0c0963f8(a);if(func_0c044e52(a))func_0c044f1c(a);}
void func_0c0963f8(struct Actor*a){if(func_0c02a026(a)<0)func_0c0438de(a);}
void func_0c09641a(struct Actor*a){if(func_0c02a026(a)<0){func_0c0438de(a);return;}switch(a->b1e8){case 0:if(a->b141){a->b141=0;a->b1a1=15;goto reset;}break;case 1:if(a->b141){a->b141=0;a->b1a1=16;reset:a->w1ac=0;a->b19e=0;a->p1c4=0;dat_0c2f83f8->arr[a->b2]++;}break;case 2:break;}}
void func_0c09648e(struct Actor*a){table_0c2430b4[a->b6](a);}
