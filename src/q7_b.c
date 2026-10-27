struct Object;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_003DAA40(struct Object *);
extern s32 func_00175700(void *p);
extern void func_001757E0(void *p, s32 a, s32 b);

void func_0016CD20(u8 *p) {
    u8 t = p[4];
    if (t == 0) {
        p[4] = t + 1;
        *(s16 *)(p + 0x1C) = 60;
    } else {
        s16 v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v != 0) {
            *(f32 *)(p + 0x118) -= 0.016666668f;
        } else {
            func_003DAA40((struct Object *)p);
        }
    }
}

void func_0015A690(u8 *p) {
    s16 v;
    *(f32 *)(p + 0x74) -= 0.5f;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        func_003DAA40((struct Object *)p);
    }
}



extern void func_00183d50(void *p);
extern s32 func_001864a0();

void func_00325D80(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_001864a0(p)) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x152] = 1;
        func_00183d50(p);
        func_00175700(p);
    }
}

extern void func_001E3210(void *p, s32 a);
extern void func_001AAD60(void *p, void *q);

void func_001AACC0(u8 *p, u8 *q) {
    u32 t = p[7];
    p[7] = t + 1;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x6C) = 0;
    if (*(f32 *)(p + 0x34) < *(f32 *)(q + 0x34)) {
        *(s16 *)(p + 0x140) = 1;
    } else {
        *(s16 *)(p + 0x140) = 0;
    }
    func_001E3210(p, 0x1A);
    func_001757E0(p, 0x17, 0xF);
    func_001AAD60(p, q);
}

extern u16 D_004D18DC;
extern u8 D_004D18DB;
static void func_003C9200(u8 *p, s32 b) { p[4]++; }

void func_003C8CD0(u8 *p, s32 b) {
    if ((D_004D18DC & (1 << D_004D18DB)) == 0) {
        u8 *o = *(u8 **)(p + 0xD0);
        if (o[5] == 3 && o[0x425] == 0) {
            if (205.714279f + *(f32 *)(o + 0x430) < *(f32 *)(o + 0x38)) {
                u32 t = p[6];
                p[6] = t + 1;
            }
        } else {
            func_003C9200(p, b);
        }
    }
}

extern s32 func_00184B30(void *p);
extern s32 func_00184720(void *p);
extern s32 func_00185A90(void *p);
extern s32 func_001846D0(void *p, s32 a);
extern s32 func_00184C60(void *p);
extern s32 func_00186120(void *p);
extern void func_00186CE0(void *p, s32 a);

void func_0017A9A0(u8 *p) {
    if (func_00184B30(p) == 0 && func_00184720(p) == 0 && func_00185A90(p) == 0
        && func_001846D0(p, 0) == 0 && func_00184C60(p) == 0 && func_00186120(p) == 0) {
        if ((s8)func_00175700(p) < 0) {
            func_00186CE0(p, 0);
        }
    }
}

extern s32 func_0036AAF0(void *p, s32 a, s32 c);
extern s32 func_001E7F60(void *p);

s32 func_0036B970(u8 *p) {
    s32 h;
    s32 c;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x54) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    h = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = h - 1;
    if (h < 0) {
        u32 t = p[5];
        p[5] = t + 1;
        if ((c = p[0x23]) < 5) {
            return func_0036AAF0(p, 7, c);
        }
    } else {
        return func_001E7F60(p);
    }
}

extern void func_00198170(void *p, s32 a);

void func_0034AEB0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[5];
        p[5] = t + 1;
        *(u32 *)(p + 0x5C) = 0x40555555;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0xC0892492;
        *(u32 *)(p + 0x6C) = 0xBF892492;
        if (*(s16 *)(p + 0x140) == 0) {
            *(f32 *)(p + 0x5C) = -*(f32 *)(p + 0x5C);
        }
        func_001757E0(p, 0x16, 0x13);
    } else {
        if (*(s8 *)(p + 0x151) != 0) {
            p[0x151] = 0;
            func_00198170(p, 3);
        }
    }
}

void func_0028FD30(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x38) <= *(f32 *)(p + 0x430)) {
        u32 t = p[7];
        p[7] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        func_00183d50(p);
        func_001757E0(p, 0x12, 7);
    } else {
        func_00175700(p);
    }
}

void func_0028F660(u8 *p) {
    u8 *a;
    u8 *b;
    func_00175700(p);
    a = p + 0x60;
    b = p + 0x6C;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0x430) < *(f32 *)(p + 0x38))) {
        u32 t = p[6];
        p[6] = t + 1;
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        *(u32 *)a = 0;
        *(u32 *)b = 0;
        p[0x20D] = 0;
        func_001757E0(p, 2, 3);
    }
}

extern int func_00175670(u8 *p);

void func_001BB2B0(u8 *p, void *context) {
    s16 h;
    s32 f;
    func_00175670(p);
    *(s32 *)(p + 0x48) += 0x2000;
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h == 0) {
        p[4] = 2;
        *(s16 *)(p + 0x1C) = 0x18;
        *(f32 *)(p + 0x50) = 1.0f;
        *(f32 *)(p + 0x54) = 1.0f;
    } else {
        f = *(s16 *)(p + 0x1C) % 2;
        p[0x13C] = (f != 0) ? 1 : 0;
        *(f32 *)(p + 0x50) += 0.1f;
        *(f32 *)(p + 0x54) += 0.1f;
    }
}

void func_001F3610(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[7];
        p[7] = t + 1;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x60) = 0x41F89249;
        *(u32 *)(p + 0x6C) = 0xBF2B6DB6;
        func_001757E0(p, 0xF, 0x2B);
    } else {
        if (*(s8 *)(p + 0x151) != 0) {
            u8 *q;
            p[0x151] = 0;
            q = *(u8 **)(p + 0x1DC);
            *(u8 **)(q + 0x1C8) = p;
            p[0x1B5] = 0x47;
            q[0x1B5] = 0x47;
            q[0x20A] = 0x11;
        }
    }
}
