/* Metrowerks 3.0: ./try.sh src/grok_nopb_24f720.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed short s16;

extern int func_00417A40(void);
extern int func_001757E0(u8 *, int, int);

void func_0024F720(u8 *p)
{
    p[6]++;
    p[316] = 1;
    *(s16 *)(p + 30) = func_00417A40() & 1;
    func_001757E0(p, 18, p[30]);
}
