/* Metrowerks 3.0: ./try.sh src/grok_q3_240f60.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern int func_00175700(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_0035F470(u8 *);
extern void func_002413C0(u8 *, int);

void residual_00240F60(u8 *p, int a1)
{
    func_00175700(p);
    if (*(s8 *)(p + 336)) {
        p[7]++;
        *(s16 *)(p + 30) = 360;
        p[655] = 1;
        p[654] = 16;
        func_0018C4B0(p, 5);
        func_0035F470(p);
        func_002413C0(p, a1);
    }
}
