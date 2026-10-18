typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;

void func_003DAA40(void *p);
void func_003C9EC0(void *a, void *b);
s32 func_00175700(void *p);
void func_00224BB0(void *p);
void func_001757E0(void *p, s32 a, s32 b);

void func_00380040(u8 *a0) {
    u8 *a1 = *(u8 **)(a0 + 24);
    if (a1[4] >= 2) {
        func_003DAA40(a0);
    } else {
        *(V3 *)(a0 + 52) = *(V3 *)(a1 + 52);
    }
}

void func_003C99C0(u8 *a0, u8 *a1) {
    *(f32 *)(a0 + 52) = *(f32 *)(a1 + 52);
    *(f32 *)(a0 + 56) = *(f32 *)(a1 + 56);
    if ((s8)func_00175700(a0) < 0) {
        func_003C9EC0(a0, a1);
    }
}

extern f32 D_00463A80[];
void func_0036B0E0(u8 *a0) {
    a0[316] = 1;
    a0[36] = 0;
    *(f32 *)(a0 + 52) = (*(f32 **)(a0 + 20))[13];
    *(f32 *)(a0 + 56) = (*(f32 **)(a0 + 20))[14];
    *(f32 *)(a0 + 60) = (*(f32 **)(a0 + 20))[15];
    *(f32 *)(a0 + 56) += D_00463A80[a0[35]];
    *(u32 *)(a0 + 104) = 0;
    *(u32 *)(a0 + 108) = 0;
    func_001757E0(a0, 23, 6);
}

extern void (*D_0044C3A0[])(u8 *);
void func_001BE1C0(u8 *a0) {
    u8 *a1 = *(u8 **)(a0 + 24);
    if (a1[4] > 0 || a1[6] > 2) {
        a0[4]++;
        a0[316] = 0;
    } else {
        D_0044C3A0[a0[5]](a0);
    }
}

void func_001D85F0(void);
void *func_003DA750(s32 a, s32 b, s32 c);
void func_001DBE50(void *a);
void func_001DBBB0(void *a);
void func_001DBC80(void *a);
s32 func_00174240(u8 *);
void func_001DBA70(u8 *a0) {
    if (a0[5] == 0) {
        func_001DBE50(a0);
        func_001DBBB0(a0);
    } else {
        if (func_00174240(a0) == 0) {
            u32 t = a0[4];
            a0[4] = t + 1;
        }
        func_001DBE50(a0);
        func_001DBC80(a0);
    }
}

void func_003C1350(void);
void func_003C1250(u8 *a0, u8 a1, u8 a2) {
    u8 *p = func_003DA750(0, 1, 1);
    if (p != 0) {
        *(u32 *)(p + 16) = (u32)func_003C1350;
        *(u16 *)(p + 38) = 14081;
        *(u32 *)(p + 24) = (u32)a0;
        p[1] = a0[1];
        p[32] = a1;
        p[33] = a2;
    }
}

void func_0019DFD0(void);
void func_0019DED0(u8 *a0, u8 a1, u8 a2) {
    u8 *p = func_003DA750(0, 4, 1);
    if (p != 0) {
        *(u32 *)(p + 16) = (u32)func_0019DFD0;
        *(u32 *)(p + 24) = (u32)a0;
        p[32] = a1;
        p[33] = a2;
        *(u16 *)(p + 38) = 2816;
        p[316] = 0;
        *(u16 *)(p + 136) = *(u16 *)(a0 + 360);
    }
}

void func_0019F200(u8 *a0) {
    u8 *s0 = *(u8 **)(a0 + 24);
    if ((s8)func_00175700(a0) < 0) {
        a0[316] = 0;
        {
            u32 t = a0[4];
            a0[4] = t + 1;
        }
    } else {
        *(s16 *)(a0 + 320) = *(s16 *)(s0 + 320);
        ((s8 *)a0)[49] = -2;
        *(f32 *)(a0 + 52) = *(f32 *)(s0 + 52);
        *(f32 *)(a0 + 56) = *(f32 *)(s0 + 56);
    }
}

extern u8 D_004D18A0;
s32 func_00182E80(void);
s32 func_00182D30(u8 *a0) {
    if (D_004D18A0 >= 5) return 1;
    if (*(s16 *)(a0 + 1076) == 0) return 1;
    {
        s16 v = *(s16 *)(a0 + 624) - (s16)func_00182E80();
        *(s16 *)(a0 + 624) = v;
        return !(v > 0);
    }
}

extern u8 D_0045D550[];
void func_00176160(void *a, s32 b, s32 c, s32 d);
void func_00314F40(u8 *a0, u8 *a1) {
    if (a1[8] == 0 && a1[31] != 0) {
        *(s16 *)(a0 + 30) = *(s16 *)(a0 + 30) + 1;
        func_00176160(a0, 0, D_0045D550[a1[31] * 4 + (*(s16 *)(a0 + 30) & 3)] + (a0[37] * 6 + 90), 1);
    }
}

void func_001D1E10(u8 *a0) {
    *(f32 *)(a0 + 52) += *(f32 *)(a0 + 92);
    *(f32 *)(a0 + 92) += *(f32 *)(a0 + 104);
    *(f32 *)(a0 + 56) += *(f32 *)(a0 + 96);
    *(f32 *)(a0 + 96) += *(f32 *)(a0 + 108);
    func_00175700(a0);
    if (func_00174240(a0) == 0) {
        u32 t = a0[4];
        a0[4] = t + 1;
        a0[316] = 0;
    }
}

void func_00184AA0(u8 *a0) {
    if (a0[525] == 2) {
        if (a0[528] == 0) a0[531] = 1;
        else a0[531] = 2;
    } else {
        *(f32 *)(a0 + 56) = *(f32 *)(a0 + 1072);
        if (*(u16 *)(a0 + 852) & 0x1000) a0[525] = 1;
        else a0[525] = 0;
        if (a0[484] == 10 || a0[484] == 11) a0[531] = 3;
        else a0[531] = 0;
    }
}

extern f32 D_004F1FD0;
void func_003B8AF0(u8 *a0) {
    *(f32 *)(a0 + 52) += *(f32 *)(a0 + 92);
    *(f32 *)(a0 + 92) += *(f32 *)(a0 + 104);
    *(f32 *)(a0 + 56) += *(f32 *)(a0 + 96);
    *(f32 *)(a0 + 96) += *(f32 *)(a0 + 108);
    if (D_004F1FD0 < *(f32 *)(a0 + 56)) {
        u32 t = a0[4];
        a0[4] = t + 1;
        a0[5] = 0;
    } else {
        func_00175700(a0);
    }
}

void func_0028F9C0(u8 *a0) {
    *(f32 *)(a0 + 52) += *(f32 *)(a0 + 92);
    *(f32 *)(a0 + 92) += *(f32 *)(a0 + 104);
    *(f32 *)(a0 + 56) += *(f32 *)(a0 + 96);
    *(f32 *)(a0 + 96) += *(f32 *)(a0 + 108);
    if (*(f32 *)(a0 + 56) <= *(f32 *)(a0 + 1072)) {
        u32 t = a0[7];
        a0[7] = t + 1;
        *(f32 *)(a0 + 56) = *(f32 *)(a0 + 1072);
        func_001757E0(a0, 18, 3);
    } else {
        func_00175700(a0);
    }
}

void func_001E3CE0(s32 a);
s32 func_001343E0(u8 *a0, u8 *a1) {
    if (D_004D18A0 != 4) return 1;
    {
        u32 bit = 1 << (a1[440] >> 1);
        u32 a2 = a0[334];
        if (a2 & bit) return 1;
        if (*(s16 *)(a1 + 1076) > 32) return 1;
        a0[334] = a2 | (bit & 0xFF);
        a0[332] = 12;
        a0[5] = 0;
        *(s16 *)(a0 + 28) = 0;
        a0[32] = 3;
        func_001E3CE0(15);
        return 0;
    }
}

void func_001DBAE0(void *);
void residual_001DB920(u8 *a0) {
    if (a0[5] == 0) {
        func_001DBE50(a0);
        func_001DBAE0(a0);
    } else {
        if (func_00174240(a0) == 0) {
            u32 t = a0[4];
            a0[4] = t + 1;
        }
        func_001DBE50(a0);
        func_001DBC80(a0);
    }
}
