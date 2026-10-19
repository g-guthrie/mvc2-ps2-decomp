/* Metrowerks 3.0: ./try.sh src/grok_nopi_3506c0.c "-O4,p -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef float f32;

extern void func_001E7F60(u8 *);
extern int func_0034FAE0(u8 *);
extern int func_001757E0(u8 *, int, int);
extern u8 *D_004C2954;

void func_003506C0(u8 *p)
{
    *(f32 *)(p + 52) += *(f32 *)(p + 92);
    *(f32 *)(p + 92) += *(f32 *)(p + 104);
    *(f32 *)(p + 56) += *(f32 *)(p + 96);
    *(f32 *)(p + 96) += *(f32 *)(p + 108);
    func_001E7F60(p);
    if (--*(s16 *)(p + 28) == 0) {
        p[5]++;
        *(u32 *)(p + 96) = 0x404DB6DB;
        *(u32 *)(p + 108) = 0x3E092492;
        if (func_0034FAE0(p) == 0)
            D_004C2954[3] = 0;
        func_001757E0(p, 23, 1);
    }
}
