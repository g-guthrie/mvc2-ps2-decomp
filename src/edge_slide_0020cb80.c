typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;

extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_001266A0(u8 *, int, int);
extern void func_001E3210(u8 *, int);
extern float D_004F1F4C;

void func_0020CB80(u8 *p, void *state)
{
    u8 *context = state;

    if ((s8)func_00175700(p) < 0) {
        double goal;

        p[7]++;
        func_001266A0(p, 1, 1);
        context[10] = 0;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0;
        if (p[0x1E6])
            goal = 13.333333015441895 + (320.0 + (double)D_004F1F4C);
        else
            goal = (double)D_004F1F4C - 320.0 - 13.333333015441895;
        *(float *)(p + 0x5C) = ((float)goal - *(float *)(p + 0x34)) / 32.0;
        context[12] = 32;
        func_001E3210(p, 6);
        func_001757E0(p, 20, 8);
    }
}
