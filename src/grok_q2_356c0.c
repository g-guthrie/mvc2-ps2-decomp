/* Metrowerks 3.0: ./try.sh src/grok_q2_356c0.c "-O3 -sdatathreshold 8" */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern int func_00175700(u8 *);
extern void func_00186A20(u8 *);
extern void func_00235C40(u8 *, int);
extern u8 *D_004C2794;

void residual_002356C0(u8 *p)
{
    func_00175700(p);
    if (*(s8 *)(p + 0x151) & 1) {
        p[7]++;
        p[0x151] = 0;
        func_00186A20(p);
        if (!*(s8 *)(p + 0x1B2)) {
            p[0x1B5] = (s8)p[0x1B7] + 0x64;
            p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
            *(u32 *)(p + 0x1D8) = 0;
            ((s16 *)(D_004C2794 + 124))[p[2]]++;
        }
        func_00235C40(p, 0);
    }
}
