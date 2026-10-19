/* Metrowerks 3.0: ./try.sh src/grok_nopa_1c4560.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

extern void func_001757E0(u8 *, int, int);
extern void func_001C45E0(u8 *, u8 *);

void residual_001C4560(u8 *p, u8 *q)
{
    p[7]++;
    if (*(s16 *)(p + 320) == 0)
        *(u32 *)(p + 92) = 0xC0555555;
    else
        *(u32 *)(p + 92) = 0x40555555;
    *(u32 *)(p + 104) = 0;
    func_001757E0(p, 25, 21);
    func_001C45E0(p, q);
}
