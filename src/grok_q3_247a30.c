/* Metrowerks 3.0: ./try.sh src/grok_q3_247a30.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_001757E0(u8 *, int, int);
extern void func_0015D010(u8 *, f32 *);
extern void func_0018C6E0(u8 *);

void residual_00247A30(u8 *p)
{
    f32 v[4];

    if (p[34] & 1) {
        p[486] ^= 1;
        *(s16 *)(p + 320) = p[486];
    }
    p[436] = 10;
    func_001757E0(p, 15, 0);
    *(u32 *)(p + 92) = 0;
    *(u32 *)(p + 96) = 0;
    *(u32 *)(p + 104) = 0;
    *(u32 *)(p + 108) = 0;
    *(u32 *)&v[0] = 0xC36E5555;
    *(u32 *)&v[1] = 0x43384924;
    *(u32 *)&v[2] = 0;
    func_0015D010(p, v);
    func_0018C6E0(p);
}
