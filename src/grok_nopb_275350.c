/* Metrowerks 3.0: ./try.sh src/grok_nopb_275350.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;

extern int func_00174170(void);
extern void func_002753A0(u8 *);

void residual_00275350(u8 *p)
{
    p[6]++;
    p[7] = func_00174170();
    p[7] &= 1;
    func_002753A0(p);
}
