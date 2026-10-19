typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_0015D010(u8 *, f32 *);
extern void func_001266A0(u8 *, int, int);

void func_0022B990(u8 *p)
{
    f32 v[4];

    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        func_001757E0(p, 15, 4);
        return;
    }
    if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        *(u32 *)&v[0] = 0xC2E2AAAA;
        *(u32 *)&v[1] = 0x4322DB6D;
        func_0015D010(p, v);
        p[0x1B4] = 10;
        func_001266A0(p, 5, 5);
    }
}
