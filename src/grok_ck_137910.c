typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;

typedef struct { float a, b; } Pair;

extern void func_00137860(u8 *, s8 *, u32 *);
extern double func_00119058(float);
extern double func_00119568(double, double);
extern float func_00119C90(double);
extern void func_0032DE90(u8 *, s16, float, float);
extern Pair D_0043F760[];

void func_00137910(u8 *p)
{
    s8 c;
    u32 m;
    float a, b;
    Pair *e;
    func_00137860(p, &c, &m);
    if ((m & (1 << c)) == 0) {
        e = &D_0043F760[p[0x21]];
        a = func_00119C90(func_00119568(0.5, func_00119058(e->a)));
        b = func_00119C90(func_00119568(func_00119058(e->b), 0.25));
        func_0032DE90(p, (s16)(p[0x20] + 10), a, b);
        p[0x22] = 1;
    }
}
