typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004F1F45;
extern u8 D_004F1F46;
extern s32 D_0044F570[];
extern s32 D_0044F530[];
extern s32 D_0044F550[];

extern void func_00175700();
extern s32 func_0018AAC0(u8 *);
extern s32 func_001864a0(u8 *);
extern s32 func_001F72E0(u8 *);
extern void func_001757E0(u8 *, s32, s32);
extern void func_00176160(u8 *, s32, s32, s32);

void func_001F51B0(u8 *p) {
    u8 *s5, *s0, *s1, *s2, *s3, *s4;
    s5 = p;
    s4 = p + 0x6C;
    s3 = p + 0x68;
    s2 = p + 0x60;
    s1 = p + 0x5C;
    s0 = p + 0x2B8;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700();
    if (func_0018AAC0(s5)) {
        if ((s8)p[0x539] != 0) {
            if ((s8)p[0x151] != 0) {
                s32 v;
                p[0x151] = 0;
                v = (s8)p[0x152];
                if (v != 1) p[0x152] = v - 1;
            }
        } else {
            p[0x152] = 1;
        }
        s0[2] = (s8)s0[2] + 1;
        if ((s8)s0[2] > 0x10) s0[2] = 0x10;
    }
    if (func_001864a0(s5)) {
        u32 t = p[7];
        p[7] = t + 1;
        *(s32 *)s1 = 0;
        *(s32 *)s2 = 0;
        *(s32 *)s3 = 0;
        *(s32 *)s4 = 0;
        D_004F1F45 = 3;
        D_004F1F46 = 1;
        func_001F72E0(s5);
        func_001757E0(s5, 0xF, 0x2E);
        return;
    }
    if ((s8)s0[2] > 5) {
        u32 k;
        if (p[0x216] == 0) {
            k = p[0x25];
            func_00176160(s5, 0, D_0044F530[k] + D_0044F570[(s8)s0[2]], 1);
        } else {
            k = p[0x25];
            func_00176160(s5, 0, D_0044F550[k] + D_0044F570[(s8)s0[2]], 1);
        }
    }
}
