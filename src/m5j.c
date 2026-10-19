typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct { f32 x, y, z; } V3;
extern u8 *D_004D18B8[][3];
u8 *func_00319410(u8 a, u8 b) {
    u8 *o = D_004D18B8[a][b];
    if (o[0] != 0 && o[5] == 3 && (*(u8 **)(o + 0x220))[1] == 0x38) return o;
    return 0;
}

extern s32 func_00174470(void *p);
s32 func_0035A7B0(u8 *p, u8 *q) {
    if (func_00174470(p) == 0) {
        p[0x13C] = 0;
    } else if (*(s8 *)(q + 0xD) != 0 && (*(s8 *)(q + 0xE) & 1) != 0) {
        p[0x13C] = 0;
    } else {
        p[0x13C] = 1;
    }
    return *(s8 *)(p + 0x13C);
}

extern void func_00174A40(void *p, s32 a);
void func_00364640(u8 *p) {
    u8 *q = *(u8 **)(p + 0x14);
    *(s16 *)(p + 0x1E) -= 0xC8;
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    func_00174A40(p, *(s16 *)(p + 0x1E));
    {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            p[5] = 2;
            *(s16 *)(p + 0x1C) = 6;
        }
    }
}

extern void func_001754A0(void *p, s32 a, s32 b);
extern void func_0019F310(void *p, void *q);
void func_0019E5F0(u8 *p, u8 *q) {
    u8 *o = *(u8 **)(p + 0x14);
    s32 t;
    *(f32 *)(p + 0x34) = *(f32 *)(o + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(o + 0x38);
    t = p[0x21];
    if (t == 0 || (s32)(t & 0xFF) >= 7) {
        p[0x13C] = 0;
        p[4] = 2;
    } else {
        func_001754A0(p, 0x1B, t);
        func_0019F310(p, q);
    }
}

extern s8 func_00175700(void *p);
extern void func_00230FC0(void *p, void *q);
void func_00231090(u8 *p, u8 *q) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00175700(p) < 0) {
        u32 t = p[7];
        p[7] = t + 1;
    }
    func_00230FC0(p, q);
}

extern void func_001D5670(void *p, s32 a, s32 b);
extern void func_001843A0(void *p);
void func_002EC4C0(f32 *p) {
    f32 *b = p + 0x60 / 4;
    f32 *a = p + 0x6C / 4;
    p[0x38 / 4] += p[0x60 / 4];
    p[0x60 / 4] += p[0x6C / 4];
    if (func_00175700(p) < 0) {
        func_001D5670(p, 3, 0);
        func_001D5670(p, 7, 0);
        *(u32 *)b = 0;
        *(u32 *)a = 0;
        func_001843A0(p);
    }
}

extern void func_001BC660(void *p, s32 a);
extern void func_00186CE0(void *p, s32 a);
extern u8 D_004F1F45;
extern u8 D_004F1F46;
void func_00279F30(u8 *p) {
    if (func_00175700(p) < 0) {
        func_001BC660(p, 6);
        func_00186CE0(p, 0x17);
    } else if (*(s8 *)(p + 0x151) != 0) {
        *(s8 *)(p + 0x151) = 0;
        if (*(s8 *)(p + 0x150) == 0) {
            D_004F1F45 = 1;
            D_004F1F46 = 1;
        } else {
            D_004F1F45 = 3;
            D_004F1F46 = 1;
        }
    }
}

extern void func_001757E0(void *p, s32 a, s32 b);
extern void func_00183D50(void *p);
extern void func_002CFA20(void *p);
void func_002CFFD0(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x20D] = 0;
        func_001757E0(p, 1, 3);
        func_00183D50(p);
    }
    func_002CFA20(p);
}

extern void func_0020F250(void *p);
void func_0020B0F0(u8 *p) {
    if (func_00175700(p) < 0) {
        func_001843A0(p);
    } else if (*(s8 *)(p + 0x151) != 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_0020F250(p);
    }
}

extern void func_001E7F60(void *p);
void func_0038D8E0(u8 *p, u8 *q) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) {
        u32 t = p[5];
        p[5] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
    }
    func_00175700(p);
    func_001E7F60(p);
}

extern s32 func_003246B0(void *p);
extern s32 func_00324930(void *p);
extern void func_003245F0(void *p);
void func_00324290(u8 *p) {
    if (func_003246B0(p) == 0 && func_00324930(p) == 0) {
        func_003245F0(p);
        func_00175700(p);
        if (p[0x15B] != 0) {
            p[0x15B] = 0;
            D_004F1F45 = 1;
            D_004F1F46 = 1;
        }
        if (*(s8 *)(p + 0x151) == 0) {
            *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
            *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        }
    }
}

extern void func_003CAB20(void *p, void *q, s32 a);
void func_003CC6C0(u8 *p, u8 *q) {
    if (p[6] == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_00175700(p);
        if (*(f32 *)(p + 0x38) < *(f32 *)(q + 0x430)) func_003CAB20(p, q, 0x10);
    }
}

extern void func_001B9D40(void *p);
void func_001B9C80(u8 *p) {
    u8 *q = *(u8 **)(p + 0x18);
    *(V3 *)(p + 0x34) = *(V3 *)(q + 0x34);
    q = *(u8 **)(p + 0x18);
    if (p[1] != q[1]) {
        func_001B9D40(p);
        return;
    }
    if (*(u16 *)(p + 0xD0) != *(u16 *)(q + 0x168)) {
        p[4] = 2;
        p[0x13C] = 0;
    }
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        *(u32 *)(p + 0x118) = 0x3F000000;
    } else {
        *(u32 *)(p + 0x118) = 0x3F800000;
    }
}

extern void func_002A70B0(void *p);
void func_002A6F10(u8 *p) {
    s16 v;
    func_002A70B0(p);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0 || (*(u16 *)(p + 0x354) & 0x1000) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x14, 3);
    } else if ((*(u16 *)(p + 0x35E) & 0x400) == 0) {
        u32 t = p[6];
        p[6] = t + 2;
        func_001757E0(p, 0x14, 4);
    }
}

extern u8 D_0045A900[];
extern void func_0018A990(void *p, void *q);
extern void func_00186A60(void *p, s32 a);
s32 func_002D9640(u8 *p) {
    if (func_00189310(p, D_0045A900, p + 0x388) == 0) return 0;
    func_0018A990(p, p + 0x388);
    if (p[0x20D] == 2) {
        if (p[0x210] == 0) {
            s8 k = p[0x1E8];
            if (k != 0) return 0;
            p[0x1E8] = k + 1;
        }
    }
    p[0x1FD] = 0xC;
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    func_00186A60(p, 0x15);
    return 1;
}

extern void func_001863F0(void *p);
void func_002F3740(f32 *p) {
    f32 *a = p + 0x5C / 4;
    f32 *b = p + 0x68 / 4;
    p[0x34 / 4] += p[0x5C / 4];
    p[0x5C / 4] += p[0x68 / 4];
    p[0x38 / 4] += p[0x60 / 4];
    p[0x60 / 4] += p[0x6C / 4];
    func_001863F0(p);
    if (func_00175700(p) < 0) {
        *(u32 *)a = 0;
        *(u32 *)b = 0;
        func_001843A0(p);
    }
}


void func_0041A730(u8 *p, u8 *q) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(q + 0x430)) {
        u32 t = p[5];
        p[5] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
    }
    func_00175700(p);
    func_001E7F60(p);
}
