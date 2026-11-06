/* Player slot pairing setup and stage-select record pick (0x0c03012c-0x0c030280). */
#include "objects.h"
extern struct PlayerSlotScore dat_0c2d7088[];
extern struct ActorFlags *dat_0c2d6f84;
extern unsigned char dat_0c2d96a4;
extern unsigned char dat_0c23b168[][8];
extern char func_0c02f958(struct PlayerSlotScore *, struct PlayerSlotScore *, int);
extern int func_0c1ec190(void);

void func_0c03012c(char n)
{
    struct PlayerSlotScore *s = &dat_0c2d7088[n];
    for (s->actor.s30 = 0; s->actor.s30 < 3; s->actor.s30++) {
        dat_0c2d7088[s->actor.s30 * 2 + n].actor.b52d = func_0c02f958(s, &dat_0c2d7088[s->actor.s30 * 2 + n], 0x200);
    }
}

void func_0c030190(void)
{
    int t;
    int r;
    if ((dat_0c2d6f84->b85 | dat_0c2d6f84->b84) == 3) {
        t = func_0c1ec190() % 6;
        r = func_0c1ec190() % 4;
        dat_0c2d96a4 = dat_0c23b168[r][t];
    } else {
        if ((dat_0c2d6f84->b85 | dat_0c2d6f84->b84) == 1)
            dat_0c2d96a4 = dat_0c23b168[dat_0c2d7088[0].actor.b510][dat_0c2d6f84->b81];
        else
            dat_0c2d96a4 = dat_0c23b168[dat_0c2d7088[1].actor.b510][dat_0c2d6f84->b81];
        if (dat_0c2d96a4 == 8) {
            dat_0c2d6f84->b_ab = 1;
            goto e;
        }
    }
    dat_0c2d6f84->b_ab = 0;
e:;
}

void func_0c03024c(void)
{
    func_0c030190();
}
