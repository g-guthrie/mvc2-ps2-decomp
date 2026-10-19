/* Metrowerks 3.0: ./try.sh src/grok_nopb_2587c0.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;

extern int func_00174170(void);
extern void func_00258810(u8 *);

void func_002587C0(u8 *p)
{
    p[6]++;
    p[33] = func_00174170();
    p[33] &= 1;
    func_00258810(p);
}
