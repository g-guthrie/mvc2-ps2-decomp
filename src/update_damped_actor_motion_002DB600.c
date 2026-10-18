/* Initialize once, then advance the actor's damped motion and events. */
typedef unsigned char u8;
typedef signed char s8;
extern int func_00175700(u8 *);
extern int func_001757E0(u8 *, int, int);
extern void func_00185490(u8 *);
extern void func_0018C4B0(u8 *, int);
extern void func_00183D10(u8 *);
extern void func_00184540(u8 *);
extern void func_002DC1B0(u8 *);
extern void func_0039F750(u8 *);
extern u8 *D_004C2794;

void func_002DB600(u8 *p)
{
    if (p[6] == 0) {
        p[6]++;
        func_00185490(p);
        func_0018C4B0(p, 5);
        p[437] = 91;
        p[434] = *(unsigned short *)(p + 448) = 0;
        *(int *)(p + 472) = 0;
        ((short *)(D_004C2794 + 124))[p[2]]++;
        if (p[525] != 2) {
            p[525] = 0;
            func_00183D10(p);
            *(int *)(p + 92) = 0;
            *(int *)(p + 96) = 0;
            *(int *)(p + 104) = 0;
            *(int *)(p + 108) = 0;
        } else {
            *(float *)(p + 92) /= 16.0f;
            *(float *)(p + 96) /= 8.0f;
            *(float *)(p + 108) /= 64.0f;
            *(int *)(p + 104) = 0;
        }
        func_001757E0(p, 21, 21);
    } else {
        *(float *)(p + 52) += *(float *)(p + 92);
        *(float *)(p + 92) += *(float *)(p + 104);
        *(float *)(p + 56) += *(float *)(p + 96);
        *(float *)(p + 96) += *(float *)(p + 108);
        if (*(float *)(p + 56) < *(float *)(p + 1072))
            *(float *)(p + 56) = *(float *)(p + 1072);
        if ((s8)func_00175700(p) < 0) {
            if (p[525] == 2)
                func_00184540(p);
            else
                func_002DC1B0(p);
        } else if (*(s8 *)(p + 337)) {
            *(s8 *)(p + 337) = 0;
            func_0039F750(p);
        }
    }
}
