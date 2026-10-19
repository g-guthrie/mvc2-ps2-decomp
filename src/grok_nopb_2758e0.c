/* Metrowerks 3.0: ./try.sh src/grok_nopb_2758e0.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef float f32;
typedef unsigned int u32;

extern int func_001757E0(u8 *, int, int);
extern void func_00275940(u8 *);

void func_002758E0(u8 *p)
{
    p[7]++;
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 108) = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    p[528] = 0;
    p[525] = 0;
    func_001757E0(p, 19, 2);
    func_00275940(p);
}
