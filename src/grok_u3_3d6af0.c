/* MWCCPS2: ./try.sh src/grok_u3_3d6af0.c "-O3 -sdatathreshold 8" */
typedef signed char s8;
typedef void (*DispatchFn)(void);

extern s8 *D_004C2840;
extern DispatchFn jtbl_004C21D8[2];

void func_003D6AF0(void)
{
    jtbl_004C21D8[D_004C2840[1]]();
}
