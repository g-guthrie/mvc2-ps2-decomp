typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 D_004B8630[];
void func_0038DBF0(u8 *o) {
    void func_0038E1F0(); void func_0038E2D0();
    u8 *s1, *s2;
    { u32 t = o[4]; o[4] = t + 1; }
    s2 = (s1 = *(u8**)(o + 0x18)) + 0x2B8;
    func_0038E1F0(o);
    if (*(u16*)(o + 0xD0) != *(u16*)(s1 + 0x168)) {
        o[4] = 2;
    } else {
        if (o[0x20] == 0) s2[2] = 1;
        func_0038E2D0(o, s1, D_004B8630 + (o[0x1B7] + o[0x20] * 2) * 10);
    }
}

s32 func_003082F0(u8 *o) {
    s32 func_001E7FD0();
    s32 r;
    if ((*(u16*)(o + 0x20E) & 0xC00) == 0) return 0;
    if (o[0x212] != 0) return 0;
    if (o[0x1B7] == 0) return 0;
    r = func_001E7FD0();
    if (r != 0) {
        u8 t = o[0x20D];
        if (t == 2) { o[0x20B] = 1; }
        else if (t == 0) { o[0x20B] = 0; }
        else return 0;
        return r;
    }
    return 0;
}

extern u8 D_004F1F45[];
extern u8 D_004F1F46[];
void func_00269420(u8 *o) {
    s32 func_00269B80(); s32 func_00269D30(); s32 func_00269CD0(); void func_00269D10(); void func_00175700(); void func_001E3710();
    if (func_00269B80(o) != 0) return;
    if (func_00269D30(o) != 0) return;
    if (func_00269CD0(o, 0) == 0) func_00269D10(o);
    func_00175700(o);
    if (*(s8*)(o + 0x151) == 0) {
        *(f32*)(o + 0x34) += *(f32*)(o + 0x5C);
        *(f32*)(o + 0x5C) += *(f32*)(o + 0x68);
    } else {
        s32 v;
        if ((v = (*(s8*)(o + 0x151) = 1)) != 0) {
            *(s8*)(o + 0x151) = 2;
            D_004F1F45[0] = v;
            D_004F1F46[0] = v;
            func_001E3710(o, 0x35);
        }
    }
}

void func_00264440(u8 *o) {
    void func_00175700(); s32 func_00174240(); void func_001E3210();
    s32 v;
    *(f32*)(o + 0x34) += *(f32*)(o + 0x5C);
    *(f32*)(o + 0x5C) += *(f32*)(o + 0x68);
    *(f32*)(o + 0x38) += *(f32*)(o + 0x60);
    *(f32*)(o + 0x60) += *(f32*)(o + 0x6C);
    func_00175700();
    if ((v = (*(s8*)(o + 0x151) = 2)) != 0) *(s8*)(o + 0x151) = 0;
    if (func_00174240(o) != 0) {
        u32 t = o[6]; o[6] = t + 1;
        func_001E3210(o, 0x1E);
    }
}

void func_003B9E00(u8 *o) {
    void func_00175700(); void func_003B9310(); void func_001E3710();
    if ((*(u8**)(o + 0x14))[5] == 0) {
        func_00175700();
        if (*(s8*)(o + 0x151) != 0) {
            u32 t = o[5]; o[5] = t + 1;
            o[0x151] = 0;
            *(s16*)(o + 0x1E) = 0x3E;
            func_003B9310(o, 3, 0);
            func_003B9310(o, 4, 0);
            func_003B9310(o, 3, 1);
            func_003B9310(o, 4, 1);
            func_001E3710(o, 0x4C);
        }
    } else {
        u32 t = o[4]; o[4] = t + 1;
        o[5] = 0;
        o[0x13C] = 0;
    }
}

void func_00234820(u8 *o) {
    void func_00175700(); void func_001757E0();
    f32 *s0, *s1;
    s1 = (f32*)(o + 0x6C);
    s0 = (f32*)(o + 0x60);
    *(f32*)(o + 0x34) += *(f32*)(o + 0x5C);
    *(f32*)(o + 0x5C) += *(f32*)(o + 0x68);
    *(f32*)(o + 0x38) += *(f32*)(o + 0x60);
    *(f32*)(o + 0x60) += *(f32*)(o + 0x6C);
    func_00175700();
    if (*(f32*)(o + 0x38) <= *(f32*)(o + 0x430)) {
        u32 t = o[6]; o[6] = t + 1;
        *(f32*)(o + 0x38) = *(f32*)(o + 0x430);
        o[0x20D] = 0;
        *(u32*)s0 = 0;
        *(u32*)s1 = 0;
        func_001757E0(o, 2, 2);
    }
}

void func_003C86E0(u8 *p, u8 *o) {
    void func_003C8650(); void func_003C8A50(u8*,u8*,u8*);
    s32 v;
    u8 *q;
    if (o[5] != 0 || o[0x1E4] != 0x1D) {
        func_003C8650();
        return;
    }
    v = *(s8*)(o + 0x2BC);
    if (v == 0) return;
    if ((s8)v < 0 || (q = *(u8**)(o + 0x1C4)) == 0) {
        func_003C8650();
        return;
    }
    if (q[0x425] == 0) {
        *(u8**)(p + 0xD0) = q;
        p[5] = 3;
        p[6] = 0;
        func_003C8A50(p, o, q);
    }
}

extern u8 (*D_00455890[])[16];
extern s32 *D_004558B0[];
s32 func_002810D0(u8 *o) {
    u32 func_00280D80(); u32 func_00174170();
    u32 i; u32 k; u8 (*t)[16];
    i = func_00280D80(o) & 0xFF;
    t = D_00455890[i];
    k = func_00174170() & 0xF;
    o[0x482] = t[*(volatile u8*)(o + 0x470)][k];
    return D_004558B0[i][o[0x482]];
}

void func_003BA6F0(u8 *o) {
    void func_003BD0A0(); void func_003BD160(); s32 func_00175700(); void func_003BD4A0(); void func_001E7F60(u8*);
    u8 *s0 = *(u8**)(o + 0x18);
    *(f32*)(o + 0x34) += *(f32*)(o + 0x5C);
    *(f32*)(o + 0x5C) += *(f32*)(o + 0x68);
    *(f32*)(o + 0x38) += *(f32*)(o + 0x60);
    *(f32*)(o + 0x60) += *(f32*)(o + 0x6C);
    func_003BD0A0();
    func_003BD160(o);
    if (!(*(f32*)(s0 + 0x430) <= *(f32*)(o + 0x38))) {
        *(f32*)(o + 0x38) = *(f32*)(s0 + 0x430);
        *(u32*)(o + 0x6C) = 0;
        *(u32*)(o + 0x60) = 0;
    }
    if ((s8)func_00175700(o) < 0) {
        func_003BD4A0(o);
    } else {
        func_001E7F60(o);
    }
}

void func_0021E8A0(u8 *o) {
    s32 func_00175700(); void func_001757E0();
    u32 *s0, *s1, *s2, *s3;
    s3 = (u32*)(o + 0x6C);
    s2 = (u32*)(o + 0x68);
    s1 = (u32*)(o + 0x60);
    s0 = (u32*)(o + 0x5C);
    *(f32*)(o + 0x34) += *(f32*)(o + 0x5C);
    *(f32*)(o + 0x5C) += *(f32*)(o + 0x68);
    *(f32*)(o + 0x38) += *(f32*)(o + 0x60);
    *(f32*)(o + 0x60) += *(f32*)(o + 0x6C);
    if ((s8)func_00175700() < 0) {
        u32 t = o[6]; o[6] = t + 1;
        func_001757E0(o, 2, 2);
        *s0 = 0;
        *s1 = 0;
        *s2 = 0;
        *s3 = 0;
    }
}

extern s16 D_00456B10[];
s32 func_0028CC80(u8 *o) {
    void func_001C09A0();
    s32 r;
    s16 t = *(s16*)(o + 0x1E) - 1;
    *(s16*)(o + 0x1E) = t;
    r = 0;
    if (t == 0) {
        do {
            u32 c;
            r = D_00456B10[o[7] * 2];
            c = r & 0xFF;
            if (r == -1) break;
            func_001C09A0(o, c);
            *(s16*)(o + 0x1E) = D_00456B10[o[7] * 2 + 1];
            { u32 u = o[7]; o[7] = u + 1; }
        } while (*(s16*)(o + 0x1E) != 0);
    }
    return r;
}
