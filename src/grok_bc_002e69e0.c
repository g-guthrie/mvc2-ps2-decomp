typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_001757E0(u8 *, int, int);
extern u8 *func_001E7FD0(u8 *);
extern void func_001266A0(u8 *, int, int);
extern void func_00185770(u8 *, u8 *);
extern void func_001E3C40(u8 *);

void residual_002E69E0(u8 *p)
{
    u8 *s1;
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 21, 17);
        return;
    }
    s1 = func_001E7FD0(p);
    if (s1) {
        p[7]++;
        p[518] = 3;
        p[510] = 1;
        p[523] = 195;
        func_001266A0(p, 5, 5);
        func_00185770(p, s1);
        s1[586] = 0;
        func_001757E0(p, 21, 13);
        func_001E3C40(p);
    }
}
