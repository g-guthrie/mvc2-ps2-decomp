/* Slot colour pulse: copy the palette row and modulate it by a wave. */
#include "objects.h"
struct Rgba16_1c21d8 { float c[4]; };
extern signed char dat_0c2f8392[];
extern short dat_0c2f838e[];
extern short dat_0c2f891a, dat_0c2f891c;
extern struct Rgba16_1c21d8 dat_0c25c5ac[], dat_0c25c64c[];
extern float func_0c1ec2c0(int);
void func_0c1c21d8(struct Obj_tu5_03 *a)
{
    int m = dat_0c2f8392[a->b32];
    if (!a->b33) {
        *(struct Rgba16_1c21d8 *)&a->f116 = dat_0c25c5ac[m + 1];
        a->f120 *= func_0c1ec2c0(dat_0c2f891a) / 8.0f + 1.0f;
        a->f124 *= func_0c1ec2c0(dat_0c2f891a) / 8.0f + 1.0f;
        a->f128 *= func_0c1ec2c0(dat_0c2f891a) / 8.0f + 1.0f;
        a->f80 = dat_0c2f838e[a->b32] / 144.0f;
    } else {
        a->b12c = m;
        if (a->pad34 != m) *(struct Rgba16_1c21d8 *)((char *)a + 116) = dat_0c25c64c[m];
        if (m == 5) {
            a->f120 = func_0c1ec2c0(dat_0c2f891c + (int)a->f104) / 2.0f + 0.5f;
            a->f124 = func_0c1ec2c0(dat_0c2f891c + (int)a->f108) / 2.0f + 0.5f;
            a->f128 = func_0c1ec2c0(dat_0c2f891c + (int)a->f112) / 2.0f + 0.5f;
        }
    }
    a->pad34 = m;
}
void func_0c1c22fa(struct Obj_tu5_03 *a)
{
    a->b12c = a->p20->b12c;
    *(struct Rgba16_1c21d8 *)&a->f116 = *(struct Rgba16_1c21d8 *)&a->p20->f116;
}
