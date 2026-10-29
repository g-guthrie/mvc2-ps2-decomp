/* Sony EE GCC 2.9-ee-991111-01 (the build whose div.s pattern carries the R5900 "nop; nop"
 * workaround), -O2 -G0, SN ee-as: ./trysony29x.sh src/rc_a_b.c EE29_01CC1 SNAS */
typedef float f32;
typedef signed int s32;
typedef struct { f32 m[4][4]; } NQ54M;

extern void func_00102F98(NQ54M *);
extern void func_00102CA0(NQ54M *, NQ54M *, NQ54M *);

void func_00103480(NQ54M *p, f32 a, f32 b, f32 c, f32 d, f32 e, f32 n, f32 f, f32 g, f32 h) {
    NQ54M t;
    f32 r = (-f * g + n * h) / (-g + h);
    f32 q = h * g * (-n + f) / (-g + h);
    func_00102F98(p);
    p->m[0][0] = a;
    p->m[1][1] = a;
    p->m[2][2] = 0.0f;
    p->m[3][3] = 0.0f;
    p->m[3][2] = 1.0f;
    p->m[2][3] = 1.0f;
    func_00102F98(&t);
    t.m[0][0] = b;
    t.m[1][1] = c;
    t.m[2][2] = q;
    t.m[3][0] = d;
    t.m[3][1] = e;
    t.m[3][2] = r;
    func_00102CA0(p, &t, p);
}

void func_00103588(f32 *m, f32 *v, s32 mode, f32 x, f32 y, f32 z)
{
    f32 d, e, r, vx, vy, vz, ux, uy, uz;

    if (mode != 0) {
        vx = v[0];
        vy = v[1];
        vz = v[2];
        d = x * vx + y * vy + z * vz;
        d = 1.0f - d;
        m[0] = x * vx + d;
        m[4] = y * vx;
        m[8] = z * vx;
        m[12] = -vx;
        m[1] = x * vy;
        m[5] = y * vy + d;
        m[9] = z * vy;
        m[13] = -vy;
        m[2] = x * vz;
        m[6] = y * vz;
        m[10] = z * vz + d;
        m[14] = -vz;
        m[3] = x;
        m[7] = y;
        m[11] = z;
        m[15] = d - 1.0f;
    } else {
        ux = v[0];
        uy = v[1];
        uz = v[2];
        e = x * ux + y * uy + z * uz;
        r = -1.0f / e;
        m[0] = r * (x * ux - e);
        m[4] = r * (y * ux);
        m[8] = r * (z * ux);
        m[12] = r * -ux;
        m[1] = r * (x * uy);
        m[5] = r * (y * uy - e);
        m[9] = r * (z * uy);
        m[13] = r * -uy;
        m[2] = r * (x * uz);
        m[6] = r * (y * uz);
        m[10] = r * (z * uz - e);
        m[14] = r * -uz;
        m[3] = 0.0f;
        m[7] = 0.0f;
        m[11] = 0.0f;
        m[15] = r * -e;
    }
}
