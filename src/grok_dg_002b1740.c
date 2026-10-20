typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef struct { u8 pad[21]; s8 countdown; } Animation;

extern int func_0018AB10(u8 *);
extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);

void func_002B1740(u8 *p)
{
    Animation *q;
    s8 *c;

    p[0x40C] = 2;
    p[0x33C] = 5;
    q = (Animation *)(p + 0x2B8);
    c = &q->countdown;
    if (*c != 0 && func_0018AB10(p)) {
        *c = (s8)(*c - 1);
        func_00175700(p);
        return;
    }
    if ((--*(s16 *)(p + 0x1C)) <= 0) {
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        p[6]++;
        func_001757E0(p, 22, 14);
    }
    func_00175700(p);
}
