#include "objects.h"
extern char func_0c02a026(struct Actor*);
extern int func_0c143388(struct Actor*,int,int);
extern void func_0c0437b8(struct Actor*),func_0c02a0c4(struct Actor*,int,int);
extern void (*table_0c242ec8[])(struct Actor*,struct ActorSubByteState*);
void func_0c0945a4(struct Actor*a,struct ActorSubByteState*sub){a->b3f8=2;a->b328=5;func_0c02a026(a);if(a->b141){a->b141=0;if(!func_0c143388(a,0,0)){func_0c0437b8(a);return;}}if(!sub->b5&&a->b19e){func_0c02a0c4(a,22,3);sub->b5=1;}if(sub->b4){a->b6++;a->s28=20;a->b3f9=0;a->b3f8=0;a->b327=0;a->b328=0;}}
void func_0c094630(struct Actor*a,struct ActorSubByteState*sub){func_0c02a026(a);if(a->s28--==0){func_0c02a0c4(a,22,4);a->b6++;}}
void func_0c09465e(struct Actor*a,struct ActorSubByteState*sub){if(func_0c02a026(a)<0)func_0c0437b8(a);}
void func_0c094680(struct Actor*a,struct ActorSubByteState*sub){table_0c242ec8[a->b6](a,sub);}
