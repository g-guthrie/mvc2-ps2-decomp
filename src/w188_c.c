typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

/* Metrowerks 3.0.3: ./try.sh src/w188_c.c  (default -O3 -sdatathreshold 0) */

void func_003238F0(u8 *p) {
    s32 r;
    u32 *v0, *v1, *a1, *a2;
    extern void func_00183D50(u8 *);
    extern s32 func_00175700(u8 *);
    extern void func_003266E0(u8 *);
    extern void func_00184540(u8 *);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    v0 = (u32*)(p+0x5C); a1 = (u32*)(p+0x68); v1 = (u32*)(p+0x60); a2 = (u32*)(p+0x6C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        *v0 = 0;
        *v1 = 0;
        *a1 = 0;
        *a2 = 0;
        func_00183D50(p);
    }
    if ((s8)func_00175700(p) < 0) {
        if (p[0x20D] != 2) func_003266E0(p);
        else func_00184540(p);
    }
}

void func_003A6650(u8 *a, u8 *b) {
    s16 *s0;
    u8 *s1;
    u8 *s2;
    extern s32 func_00175700(u8 *);
    extern s16 func_00118FA8(f32);
    s1 = *(u8 **)(a + 8);
    s2 = *(u8 **)(a + 0x14);
    *(s8 *)(a + 0x24) = *(s8 *)(b + 0x24) + *(s8 *)(a + 0x31);
    s0 = (s16 *)(a + 0x5C);
    if (*(s8 *)(a + 0x24) > 7) *(s8 *)(a + 0x24) = 7;
    if (*(s8 *)(a + 0x24) < 0) *(s8 *)(a + 0x24) = 0;
    func_00175700(a);
    *(f32 *)(a + 0x34) = (f32)s0[3];
    s0[3] = s0[2];
    s0[2] = s0[1];
    s0[1] = s0[0];
    s0[0] = func_00118FA8(*(f32 *)(s1 + 0x34));
    *(f32 *)(a + 0x38) = (f32)s0[7];
    s0[7] = s0[6];
    s0[6] = s0[5];
    s0[5] = s0[4];
    s0[4] = func_00118FA8(*(f32 *)(s1 + 0x38));
    if (s2[5] == 2) a[4]++;
}
