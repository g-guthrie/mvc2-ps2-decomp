#include "objects.h"
extern unsigned char dat_0c2d7088[];
extern struct ActorFlags *dat_0c2d6f84;
extern void func_0c1fba00(void *,int,int);
int func_0c0388a0(struct DirectionState *),func_0c0388aa(struct DirectionState *),func_0c0388b4(struct DirectionState *);
int func_0c0387d8(struct DirectionState *a)
{
 short left=*(short *)(dat_0c2d7088+0x420)+*(short *)(dat_0c2d7088+0xf68)+*(short *)(dat_0c2d7088+0x1ab0);
 short right=*(short *)(dat_0c2d7088+0x9c4)+*(short *)(dat_0c2d7088+0x150c)+*(short *)(dat_0c2d7088+0x2054);
 if(left+right==0)return func_0c0388b4(a);
 if(!right)return func_0c0388a0(a);
 if(!left)return func_0c0388aa(a);
 return 0;
}
void func_0c038814(struct DirectionState *a)
{
 short left,right;
 struct Actor *selected;
 a->b3=1;
 left=*(short *)(dat_0c2d7088+0x420)+*(short *)(dat_0c2d7088+0xf68)+*(short *)(dat_0c2d7088+0x1ab0);
 right=*(short *)(dat_0c2d7088+0x9c4)+*(short *)(dat_0c2d7088+0x150c)+*(short *)(dat_0c2d7088+0x2054);
 if(left==right){func_0c0388b4(a);return;}
 if(left>right)func_0c0388a0(a);else func_0c0388aa(a);
 selected=*(struct Actor **)((unsigned char *)a->entry+(((int)a->direction*3)<<2));
 if(!dat_0c2d6f84->pad137[2] && selected->b1==25 && selected->b525)a->direction^=1;
}
int func_0c0388a0(struct DirectionState *a){a->direction=0;return 1;}
int func_0c0388aa(struct DirectionState *a){a->direction=1;return 1;}
int func_0c0388b4(struct DirectionState *a){a->direction=-1;return 1;}
void func_0c0388be(struct Actor *a)
{
 func_0c1fba00(&a->b354,0,16);
 a->pad7ffc[0]=0;a->b326=4;a->b201=0;
}
