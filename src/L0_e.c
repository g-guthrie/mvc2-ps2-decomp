typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 *D_0043CB10[];
extern f32 *D_0043CB50[];
extern f32 *D_0043CB30[];
extern s8 D_004F1F48;
extern s8 D_004F1F49;
extern s8 D_004F1F47;
extern u8 D_004F2037;
extern u8 D_004F2036;
extern u8 D_004F2034;
extern u8 D_004F2035;
extern f32 D_004F1FEC, D_004F1FF0, D_004F1FF4, D_004F1FF8, D_004F1FFC, D_004F2000;
extern f32 D_004F2004, D_004F2008, D_004F200C, D_004F2010, D_004F2014, D_004F2018;

void func_001234D0(void)
{
    extern void func_001237E0(s32, s32);
    extern void func_001239E0(s32, s32);
    extern void func_00124660(s32, s32);
    extern void func_00123BE0(s32, s32);
    s32 *s0;
    f32 *t0, *t1;
    s32 v;
    u8 t;
    s32 off;
    f32 z;

    s0 = D_0043CB10[D_004F1F48];
    t0 = D_0043CB30[D_004F1F48];
    t1 = D_0043CB50[D_004F1F48];
    v = *s0;
    t = 0;
    if (D_004F1F49 < v) {
        t |= D_004F2037;
        t |= D_004F2036;
        t |= D_004F2034;
        t |= D_004F2035;
        s0++;
        if (t == 2) {
            D_004F2034 = 0;
            D_004F1F49 = D_004F1F49 + 1;
            D_004F2035 = 0;
            D_004F2036 = 0;
            D_004F2037 = 0;
        }
        s0 += D_004F1F49;
    } else {
        s0 += v;
        D_004F1F47 = D_004F1F47 + 1;
    }
    off = D_004F1F49 * 6;
    t0 += off;
    t1 += off;
    D_004F1FEC = t0[0];
    D_004F1FF0 = t0[1];
    D_004F1FF4 = t0[2];
    D_004F1FF8 = t0[3];
    D_004F1FFC = t0[4];
    D_004F2000 = t0[5];
    D_004F2004 = t1[0];
    D_004F2008 = t1[1];
    D_004F200C = t1[2];
    D_004F2010 = t1[3];
    D_004F2014 = t1[4];
    D_004F2018 = t1[5];
    func_001237E0(0, *s0);
    func_001239E0(0, *s0);
    z = 0.0f;
    if (D_004F2004 != z || D_004F2008 != z || D_004F200C != z)
        func_00124660(0, *s0);
    z = 0.0f;
    if (D_004F2010 != z || D_004F2014 != z || D_004F2018 != z)
        func_00123BE0(0, *s0);
}
