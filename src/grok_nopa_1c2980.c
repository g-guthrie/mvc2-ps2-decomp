/* Metrowerks 3.0: ./try.sh src/grok_nopa_1c2980.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

extern int func_001757E0(u8 *, int, int);
extern void func_001C2A20(u8 *, u8 *);

void func_001C2980(u8 *p, u8 *q)
{
    p[7]++;
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 108) = 0;
    if (*(float *)(p + 52) < *(float *)(q + 52))
        *(s16 *)(p + 320) = 1;
    else
        *(s16 *)(p + 320) = 0;
    if (p[6] != p[214])
        func_001757E0(p, 25, 9);
    func_001C2A20(p, q);
}
