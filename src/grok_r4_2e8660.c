/* Metrowerks: ./try.sh src/grok_r4_2e8660.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef float f32;

extern int func_00175700(u8 *);
extern void func_001E3210(u8 *, int);

void residual_002E8660(u8 *p)
{
    u8 *e = p + 0x2B8;

    func_00175700(p);
    if (*(s8 *)(p + 0x151)) {
        p[6]++;
        *(short *)(p + 28) = 120;
        p[32] = (p[525] & 2) >> 1;
        e[13] = 9;
        e[14] = 0;
        e[15] = 1;
        p[32] = (p[525] & 2) >> 1;
        *(u32 *)(p + 92) = 0;
        *(u32 *)(p + 104) = 0;
        *(u32 *)(p + 96) = 0;
        *(f32 *)(p + 108) = 0.2678571343421936f;
        *(f32 *)(p + 56) = *(f32 *)(p + 56) - 8.571428298950195f;
        func_001E3210(p, 36);
    }
}
