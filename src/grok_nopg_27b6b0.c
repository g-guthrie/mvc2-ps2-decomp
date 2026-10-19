/* Metrowerks 3.0: ./try.sh src/grok_nopg_27b6b0.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;

extern u8 D_004D18A0;
extern void func_00185490(u8 *);
extern void func_001757E0(u8 *, int, int);

void residual_0027B6B0(u8 *p)
{
    p[316] = 0;
    if (D_004D18A0 >= 2) {
        p[6]++;
        p[316] = 1;
        func_00185490(p);
        func_001757E0(p, 18, 0);
    }
}
