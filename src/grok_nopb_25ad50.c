/* Metrowerks 3.0: ./try.sh src/grok_nopb_25ad50.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef float f32;
typedef unsigned int u32;

extern void func_00185490(u8 *);
extern void func_001757E0(u8 *, int, int);

void residual_0025AD50(u8 *p)
{
    p[6]++;
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 108) = 0;
    p[525] = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    func_00185490(p);
    func_001757E0(p, 21, 7);
}
