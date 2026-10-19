/* Metrowerks 3.0: ./try.sh src/grok_nopk_232b80.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

extern int func_00175700(u8 *);
extern void func_001843A0(u8 *);
extern void func_001266A0(u8 *, int, int);
extern void func_001E3A40(u8 *);

void residual_00232B80(u8 *p)
{
    u8 *q;

    if ((s8)func_00175700(p) < 0) {
        *(s16 *)(p + 320) ^= 1;
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 337)) {
        p[337] = 0;
        func_001266A0(p, 0, 0);
        q = *(u8 **)(p + 476);
        *(u8 **)(q + 456) = p;
        q[437] = 32;
        q[525] = 2;
        q[522] = 11;
        q[486] = p[486];
        *(s8 *)(p + 486) ^= 1;
        func_001E3A40(p);
    }
}
