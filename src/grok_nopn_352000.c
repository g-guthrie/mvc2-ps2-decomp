/* Metrowerks 3.0: ./try.sh src/grok_nopn_352000.c "-O4,p -sdatathreshold 0" */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef float f32;

extern f32 D_004625F0[];
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);

void func_00352000(u8 *p)
{
    if ((s8)func_00175700(p) < 0) {
        p[5]++;
        {
            f32 v;
            if (*(s16 *)(p + 0x140) != 0)
                v = D_004625F0[p[0x21] * 2];
            else
                v = -D_004625F0[p[0x21] * 2];
            *(f32 *)(p + 0x5C) = v;
        }
        *(f32 *)(p + 0x60) = D_004625F0[p[0x21] * 2 + 1];
        func_001757E0(p, 21, (u8)(p[0x21] + 41));
    }
}
