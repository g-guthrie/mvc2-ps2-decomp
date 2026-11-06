/* Timed display visibility gated by the opposing team's three actors. */
#include "objects.h"
extern struct Tbl_ub3_01 *dat_0c2f83f8;
extern short dat_0c2f891a;
extern void func_0c037688(struct Obj_tu5_03 *);
/* Two rows of three actor pointers start at global-record offset 24. */
#define TEAM_ACTORS (((struct Actor *(*)[3])&players->pad[24]))
#define FLAG_277(a) ((a)->b277)
void func_0c1c2550(struct Obj_tu5_03 *a){
 struct Actor *owner=(struct Actor *)a->p24;
 struct Tbl_ub3_01 *players;
 if((signed char)a->b7!=(signed char)owner->b411)goto remove;
 if(!(a->b7=owner->b411))goto remove;
 if(owner->b0)goto remove;
 a->b12c=0;players=dat_0c2f83f8;
 if(FLAG_277(TEAM_ACTORS[owner->b2^1][0]))return;
 if(FLAG_277(TEAM_ACTORS[owner->b2^1][1]))return;
 if(FLAG_277(TEAM_ACTORS[owner->b2^1][2]))return;
 if(dat_0c2f891a>=0)a->b12c=1;
 if(--a->w30>0)return;
 remove:a->b12c=0;func_0c037688(a);
}
