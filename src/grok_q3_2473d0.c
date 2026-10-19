/* Metrowerks 3.0: ./try.sh src/grok_q3_2473d0.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_00185490(u8 *);
extern void func_00175C00(u8 *, int);
extern int func_001757E0(u8 *, int, int);
extern void func_001E3210(u8 *, int);
extern void func_00247470(u8 *, int);

void func_002473D0(u8 *p, int a1)
{
    p[6]++;
    func_00185490(p);
    func_00175C00(p, 0);
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 108) = 0;
    p[525] = 0;
    *(f32 *)(p + 56) = *(f32 *)(p + 1072);
    func_001757E0(p, 20, 2);
    func_001E3210(p, 16);
    *(s16 *)(p + 28) = 64;
    func_00247470(p, a1);
}
