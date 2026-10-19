/* Metrowerks: ./try.sh src/grok_r4_2c48c0.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_001266A0(u8 *, int, int);

void func_002C48C0(u8 *p)
{
    u8 *q;

    if ((s8)func_00175700(p) < 0) {
        p[0x1E6] ^= 1;
        func_001843A0(p);
    }
    if (*(s8 *)(p + 0x151)) {
        p[0x151] = 0;
        q = *(u8 **)(p + 0x1DC);
        *(u8 **)(q + 0x1C8) = p;
        q[0x20A] = 1;
        q[0x20D] = 0;
        func_001266A0(p, 0, 0);
        q[0x1B5] = 0x21;
        q[0x1E6] = p[0x1E6];
    }
}
