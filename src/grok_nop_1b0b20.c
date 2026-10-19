/* Metrowerks 3.0: ./try.sh src/grok_nop_1b0b20.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;

extern int func_00175670(u8 *);

void residual_001B0B20(u8 *p)
{
    func_00175670(p);
    if ((s8)p[339] < 0)
        p[4]++;
}
