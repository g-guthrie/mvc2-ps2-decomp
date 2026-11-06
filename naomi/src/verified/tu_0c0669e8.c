/* Two complete retail callbacks; 0c066b04 continues the first across its pool. */
#include "objects.h"
extern char func_0c02a026(struct Actor *);
extern void func_0c0346da(struct Actor *,int),func_0c135e78(struct Actor *,char,char),func_0c0438de(struct Actor *),func_0c0437b8(struct Actor *);
extern unsigned int func_0c02849a(void);
extern struct ActorFlags *dat_0c2d6f84;
void func_0c0669e8(struct Actor *a)
{
 char event;
 int mode;
 a->b3f8=2;a->b328=5;a->b328=5;
 func_0c02a026(a);
 if(a->b140){a->b140=0;func_0c0346da(a,48);}
 event=a->b141;if(!event)return;
 if(event==-1){a->b6++;a->b3f9=0;a->b3f8=0;a->b327=0;a->b328=0;return;}
 if((mode=a->b255)==5||a->b525||mode==4){
  unsigned char selection;
  if(dat_0c2d6f84->flags&7)return;
  selection=func_0c02849a()&15;
  if((selection&1)&&!(a->s30&1)){a->s30|=1;func_0c135e78(a,0,0);}
  if((selection&2)&&!(a->s30&2)){a->s30|=2;func_0c135e78(a,0,1);}
  if((selection&4)&&!(a->s30&4)){a->s30|=4;func_0c135e78(a,0,2);}
  if((selection&8)&&!(a->s30&8))goto fourth;
 }else{
  if((a->w348&0x200)&&!(a->s30&1)){a->s30|=1;func_0c135e78(a,0,0);}
  if((a->w348&0x100)&&!(a->s30&2)){a->s30|=2;func_0c135e78(a,0,1);}
  if((a->w348&0x40)&&!(a->s30&4)){a->s30|=4;func_0c135e78(a,0,2);}
  if((a->w348&0x20)&&!(a->s30&8)){fourth:a->s30|=8;func_0c135e78(a,0,3);}
 }
}
void func_0c066b8c(struct Actor *a)
{
 if(func_0c02a026(a)<0){if(a->b1f9==2)func_0c0438de(a);else func_0c0437b8(a);}
}
