typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void func_00186A60(u8 *p, s32 a);

void func_00278000(u8 *p) {
    p[5] = 0;
    p[7] = 0;
    p[6] = 0;
    switch (*(s8 *)(p + 0x4DD)) {
    case 0: p[0x1FD] = 4; p[0x1B7] = 0; break;
    case 1: p[0x1FD] = 3; p[0x1B7] = 1; break;
    case 2: p[0x1FD] = 5; p[0x1B7] = 1; break;
    }
    func_00186A60(p, 0x15);
}

extern s8 func_00175700(u8 *p);
extern void func_001843A0(u8 *p);
extern void func_0035D370(u8 *p, s32 a, s32 b);

void func_0023D490(u8 *p) {
    if (func_00175700(p) < 0) {
        func_001843A0(p);
        return;
    }
    if (*(s8 *)(p + 0x151) & 2) {
        p[0x151] = 0;
        func_0035D370(p, 0, 0);
    }
}

extern void func_001757E0(u8 *p, s32 a, s32 b);
extern void func_00175C00(u8 *p, s32 a);

void func_002FDCC0(u8 *p) {
    u8 *q = p + 0x2B8;
    if (p[6] == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x13, 4);
        p[0x216] = 0;
        *(s16 *)(q + 4) = 0;
        func_00175C00(p, 0);
    } else {
        func_00175700(p);
    }
}

extern void func_00156C50(u8 *p);
extern void func_00156D70(u8 *p);
extern void func_003DAA40(u8 *p);

void func_00156E10(u8 *p) {
    if (*(s16 *)(p + 0x1C) == 2) {
        func_00156C50(p);
    }
    if (*(s16 *)(p + 0x1C) == 10) {
        func_00156D70(p);
    }
    if (*(s16 *)(p + 0x1C) >= 10) {
        func_003DAA40(p);
    } else {
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    }
}



extern s32 func_00174240(u8 *p);

void func_00372AA0(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (func_00174240(p) == 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}

void func_00311E00(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (!(*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) < 0.0f)) {
        func_001843A0(p);
    }
}

extern void (*D_0044C230[])(u8 *, u8 *);

void func_001BCED0(u8 *p, void *q_context) {
    u8 *q = (u8 *)q_context;
    s16 v;
    D_0044C230[p[5]](p, q);
    v = *(s16 *)(q + 0x140);
    *(s16 *)(p + 0x140) = v;
    if (v == 0) {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) + *(f32 *)(p + 0x5C);
    } else {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) - *(f32 *)(p + 0x5C);
    }
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38) + *(f32 *)(p + 0x60);
    *(s8 *)(p + 0x24) = *(s8 *)(q + 0x24);
}

extern void func_002975D0(u8 *p);

void func_00297810(u8 *p) {
    if (*(s8 *)(p + 0x151) < 0) {
        s16 v;
        p[0x151] = 0;
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v < 0) {
            u32 t = p[6];
            p[6] = t + 1;
            func_001757E0(p, 0x15, 5);
            return;
        }
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    func_00175700(p);
    func_002975D0(p);
}

void func_00249FA0(u8 *p) {
    s16 v;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v <= 0) {
        u32 t = p[6];
        p[6] = t + 1;
        if (p[0x1E6] == 0) {
            *(u32 *)(p + 0x68) = 0x3E855555;
        } else {
            *(u32 *)(p + 0x68) = 0xBE855555;
        }
        func_001757E0(p, 2, 2);
    }
}

void func_00319E70(u8 *p) {
    if (func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 1, 0xA);
        return;
    }
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
}

extern int func_00174470(const void *);
extern void func_0034FA60(u8 *p);
extern void func_0034F330(u8 *p);
extern void func_0034F3B0(u8 *p);
extern void func_001E7F60(u8 *p);

void func_0034F1B0(u8 *p) {
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    if (func_00174470(p) == 0) {
        func_0034FA60(p);
        return;
    }
    if (*(s8 *)(p + 0x1B3) != 0) {
        func_0034F330(p);
    } else if (*(s8 *)(p + 0x1B2) != 0) {
        func_0034F3B0(p);
    } else {
        func_001E7F60(p);
    }
}

extern void func_001843A0(u8 *p);

void func_00240470(u8 *p) {
    s16 v;
    u32 *a, *b, *c, *d;
    func_00175700(p);
    a = (u32 *)(p + 0x5C); c = (u32 *)(p + 0x68); b = (u32 *)(p + 0x60); d = (u32 *)(p + 0x6C);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v == 0) {
        *a = 0; *b = 0; *c = 0; *d = 0;
        func_001843A0(p);
    }
}

typedef struct { f32 x, y, z; } V3;
extern u8 *func_003DA750();
extern void func_00140420();
extern V3 D_00440C80[];
extern f32 D_00440CD0[];

void func_00140370(s32 idx) {
    u8 *o = func_003DA750(0, 0xD, 1);
    if (o != 0) {
        f32 s;
        o[0x13C] = 1;
        *(void **)(o + 0x10) = func_00140420;
        *(u32 *)(o + 0xD0) = 0x800C19;
        o[0x20] = idx;
        *(V3 *)(o + 0x34) = D_00440C80[idx];
        s = D_00440CD0[idx];
        *(f32 *)(o + 0x50) = s;
        *(f32 *)(o + 0x54) = s;
    }
}

extern void (*D_0044B548[])(u8 *, u8 *);

void func_001A8910(u8 *p, u8 *q) {
    if (q[0x1E4] != 0x14 || q[0x1FC] != 1) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else {
        D_0044B548[p[5]](p, q);
    }
}
