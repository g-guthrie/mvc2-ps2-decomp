/* Pose follower: copies the owner's block, then applies the owner's 0x141 cue pose row while it holds pose 0x1500/0x1510. */
#include "objects.h"
#define LA struct LinkedActor
struct Pose25b134 { char b0; char pad; unsigned short w2; float f4, f8, f12, f16; };
extern struct Pose25b134 dat_0c25b134[][9];
extern void func_0c029f0e(LA *, int, int, int);
extern void func_0c037688(LA *);

void func_0c1b62e8(LA *a, LA *o)
{
    struct Pose25b134 *e;
    float k;
    char c;
    unsigned short w;
    if (!a->b4) {
        a->b4++;
        a->sdc = o->sdc;
        a->sdc.b12c = 1;
        a->b2 = o->b2;
        a->b1 = o->b1;
        a->v80.x = o->v80.x;
        a->v80.y = o->v80.y;
        a->b1a3 = o->b1a3;
        a->b1a4 = o->b1a4;
        a->b48 = o->b48;
        a->v80 = o->v80;
        a->b36 = o->b36;
        a->sdc.b12c = 0;
        a->s30 = 0;
    } else {
        a->b36 = o->b36;
        if ((unsigned short)o->sdc.w158.short_value == 0x1500 || (unsigned short)o->sdc.w158.short_value == 0x1510) {
            if (o->sdc.b141) {
                if (a->s30 != o->sdc.b141) {
                    a->s30 = o->sdc.b141;
                    e = &dat_0c25b134[(unsigned char)a->b33][a->s30 - 1];
                    if ((char)(a->sdc.b12c = e->b0)) {
                        func_0c029f0e(a, 27, 18, e->w2);
                        a->v80.x = e->f4;
                        a->v80.y = e->f8;
                        k = e->f12;
                        a->f56 = o->f56 + e->f16;
                        if (!o->sdc.w130) k = -k;
                        a->f52 = o->f52 + k;
                    }
                }
            } else {
                a->s30 = (char)(a->sdc.b12c = 0);
            }
        } else {
            a->v80.x = a->v80.y = 1.0f;
            func_0c037688(a);
        }
    }
}
