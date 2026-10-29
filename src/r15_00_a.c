/* func_0012D6B0: MW 3.0.3, -O3,p -sdatathreshold 8.
 * Retail's loop store `addu a1,a0,s4; sw v0,0(a1)` (table base in a0, address in a1)
 * comes from opt_lifetimes off: with variable lifetimes not split, `t` and `a` each keep
 * one register across the function, and their later roles as the first and second
 * arguments of func_00129060 give them a0 and a1. opt_propagation off keeps `t` from
 * being folded back into a constant temp. */
typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef struct { u8 f0; u8 f1; u8 f2[2]; s8 f4; u8 f5; u8 f6; u8 f7; s16 f8; u8 fa[4]; s16 fe; } G_h;
extern G_h *D_004C2840;
extern s32 D_004C27FC;
extern s32 D_004C27E8;
extern u8 D_004C2604;
extern s32 D_004CA080[];

#pragma push
#pragma opt_lifetimes off
#pragma opt_propagation off
void func_0012D6B0(void)
{
    extern void func_003DA410();
    extern void func_00150670();
    extern void func_001515D0(s32, s32);
    extern void func_00146C80(s32);
    extern void func_001489E0(s32, s32);
    extern void func_0014DA90();
    extern void func_00150C40(u8);
    extern void func_00150E10(s32, s32);
    extern void func_003298B0(s32, s32, s32);
    extern void func_00129060(s32, void *);
    extern void func_0012D830();
    extern s32 func_00131870(s16);
    s32 i, s1, s2;
    u8 s3;
    s32 r, j, t, a;

    func_003DA410();
    D_004C2840->f5 = 1;
    D_004C2840->f6 = 0;
    D_004C2840->f7 = 0;
    D_004C2840->fe = 0;
    D_004C2604 = 0;
    if (D_004C2840->f4 == 0) {
        s1 = D_004C27FC;
        s2 = 0xC;
        s3 = 0x11;
    } else if (D_004C2840->f4 == 1) {
        s1 = D_004C27FC;
        s2 = 0xD;
        s3 = 0x11;
    } else {
        s1 = D_004C27E8;
        s2 = 5;
        s3 = 0x35;
        i = 0;
        j = 0;
        do {
            s32 k;
            if (i > 0x17)
                k = (s16)i + 3;
            else
                k = (s16)i;
            r = func_00131870(k);
            t = (s32)D_004CA080;
            a = t + j;
            *(s32 *)a = r;
            i++;
            j += 4;
        } while (i < 0x3B);

        if (D_004C2840->f4 == 2)
            func_00150670();
    }
    func_001515D0(8, D_004C27FC);
    func_00146C80(7);
    func_001489E0(0xE, 0xE);
    func_0014DA90();
    func_00150C40(s3);
    func_00150E10(s1, s2);
    func_003298B0(0xFF000000, 0xA, 0);
    a = (s32)func_0012D830;
    t = 8;
    func_00129060(t, (void *)a);
}
#pragma pop
