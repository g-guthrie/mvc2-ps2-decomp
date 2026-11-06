#include "objects.h"
/* Two-row team table at 0x0c2f83f8+24: three actor pointers per side.  The side
 * is selected by b2 ^ 1 and addressed with an explicit *12 byte stride. */
struct TeamState {unsigned char pad0[24];struct Actor *team[6];unsigned char pad48[8],b56;};
#define TEAM_SLOT(a,k) (*(struct Actor **)((char *)((struct TeamState *)dat_0c2f83f8)->team + ((a)->b2 ^ 1) * 12 + (k)))
extern unsigned char *dat_0c2f83f8;
extern unsigned char dat_0c23c82c[],dat_0c23c816[];
extern void func_0c0344a0(struct Actor *,int),func_0c0346da(struct Actor *,int);
void func_0c04ba18(struct Actor *a,struct Actor *attacker)
{
 struct Actor *partner=a->p1b8;
 if(partner && partner->b1==30 && a->b1a2==34){func_0c0344a0(partner,32);return;}
 func_0c0346da(partner,67);
}
void func_0c04ba48(struct Actor *a)
{
 struct Actor *third = TEAM_SLOT(a, 8);
 struct Actor *second = TEAM_SLOT(a, 4);
 struct Actor *first = TEAM_SLOT(a, 0);
 if(first->b5>=3 || second->b5>=3 || third->b5>=3 || ((struct TeamState *)dat_0c2f83f8)->b56 || a->p1b8->b411){
  a->b235=0;first->b235=0;second->b235=0;third->b235=0;
 }
}
void *func_0c04baa8(struct Actor *a,unsigned char *record)
{
 if(record[2]&32)return dat_0c23c82c;
 return dat_0c23c816;
}
