/* Metrowerks 3.0: ./try.sh src/grok_q2_fff00.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_001978B0(u8 *, int);
extern void func_00176160(u8 *, int, int, int);
extern void func_001757E0(u8 *, int, int);
extern int D_0044FE20[];

void residual_001FFF00(u8 *p)
{
    p[0x2C4] = 7;
    p[6]++;
    func_001978B0(p, 1);
    *(s16 *)(p + 0x1C) = 0x3C;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(u32 *)(p + 0x60) = 0x40092492;
    *(u32 *)(p + 0x6C) = 0xBD892492;
    func_00176160(p, 0, D_0044FE20[p[0x25]], 1);
    func_001757E0(p, 0x14, 5);
}
