typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern u8 *D_004C2794;
extern u32 D_00455458[];
extern s32 func_001757E0();
extern s32 func_00280E70(u8 *);
extern void func_0032D5F0(u8 *);
extern s32 func_001E7FD0(u8 *);
extern void func_00185490(u8 *);
extern s32 func_00178B00(u8 *);
extern void func_00178D80(u8 *, s32);
extern void func_001266A0(u8 *, s32, s32);
extern void func_0015D010(u8 *, float *);
extern void func_0018C6E0(u8 *);
extern void func_001830D0();
extern void func_0036BFF0(u8 *, s32, s32, s32);
extern u32 D_004C2838;
extern u8 *func_003DA750(s32, s32, s32);
extern void func_0015D6A0();
extern void func_00356980(u8 *);
extern void func_0018C8A0(u8 *);
extern s32 func_00153AA0();
extern void func_00170DA0(u32, s32, s32, s16);
typedef struct { float a, b; } E8;
extern E8 D_004B3CB0[];
typedef struct { float x, y, z; } V3;
extern s32 func_00175700();
typedef void (*Mvc2OwnerPhaseCallback)(u8 *, u8 *);
extern Mvc2OwnerPhaseCallback D_0044B770[];
extern u8 D_004531C0[];
extern s32 func_00189310();
extern void func_0018A990();
extern void func_00186A60();
extern u8 D_004F1F40[];
extern void func_00183d50();
extern s32 func_0034A0D0();
extern void func_00137E60();
extern void func_00137DF0();
typedef struct { u8 *ptr; u8 pad[0x5B8 - 4]; } T5B8;
extern T5B8 D_004F20C8[];
extern u8 D_00583B92[];
extern s8 D_00583BC0[];
extern void func_003A6DC0();
extern s32 func_00174170();
extern void func_00169C90();
extern void func_0015DFC0();

void func_00137750(u8 *p) {
    *(s16 *)(p + 0x1C) -= 1;
    if (*(s16 *)(p + 0x1C) < 0) {
        p[4]++;
        p[0x13C] = 0;
    } else {
        *(float *)(p + 0x34) += *(float *)(p + 0x5C);
        *(float *)(p + 0x5C) += *(float *)(p + 0x68);
        *(float *)(p + 0x38) += *(float *)(p + 0x60);
        *(float *)(p + 0x60) += *(float *)(p + 0x6C);
        func_0032D5F0(p);
    }
}

void func_00137CA0(u8 *p) {
    s8 v;
    func_00137E60(p);
    if (D_00583B92[p[0x20]] & (1 << p[0x21])) {
        p[4] = 2;
    } else {
        v = *(s8 *)(D_004F20C8[p[0x20]].ptr + 0x540);
        if (v != p[1]) {
            p[1] = v;
            D_00583BC0[p[0x20]] = *(s8 *)(p + 1) + 1;
        }
    }
    func_00137DF0(p);
}

void func_0015EE60(u8 *p) {
    float b; float a; E8 *e = D_004B3CB0; e += *(s16 *)(p + 0x1C);
    if (*(s32 *)(p + 0xDC) != 0) {
        func_00170DA0(D_004C2838, 0x1E, func_00153AA0(), *(s16 *)(p + 0xCC));
    } else {
        func_00170DA0(D_004C2838, 0x1A, func_00153AA0(), *(s16 *)(p + 0xCC));
    }
    b = e->b; a = e->a; *(float *)(p + 0xE0) = a; *(float *)(p + 0xE4) = b;
    *(u32 *)(p + 0xD0) |= 0x20000;
}

void func_001AB160(u8 *p, u8 *q) {
    if (q[0x1E4] == 0x1D) {
        switch (q[0x1FD]) {
        case 5:
            *(u32 *)(p + 0xD0) = p[6];
            *(u32 *)(p + 0xD4) = p[7];
            p[6] = 0xF;
            p[7] = 0;
            break;
        case 4:
            *(u32 *)(p + 0xD0) = p[6];
            *(u32 *)(p + 0xD4) = p[7];
            p[6] = 0x11;
            p[7] = 0;
            break;
        }
        return;
    } else {
        D_0044B770[p[7]](p, q);
    }
}

void func_00200320(u8 *p) {
    u8 *q = p + 0x2B8;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if ((s8)func_00175700(p) < 0) {
        p[6]++;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
        func_001757E0(p, 0x16, 0x2A);
    } else {
        if (*(s8 *)(p + 0x150) != 0) {
            p[0x150] = 0;
            if (func_0034A0D0(p) != 0) {
                *(s8 *)(q + 0x15) += 1;
            }
        }
    }
}

void func_0020DD10(u8 *p, u8 *q) {
    if (q[5] != 0) {
        q[5] = q[5] - 1;
        p[0x209] = 0x10;
        p[0x1B5] = (s8)(u8)(p[0x212] != 0 ? 0x4F : 0x4C) + *(s8 *)(p + 0x1B7) * 2;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        ++*(s16 *)((p[2] << 1) + (u32)D_004C2794 + 0x7C);
    }
}

void func_0020E6E0(u8 *p) {
    s16 v;
    p[0x209] = 2;
    p[0x208] = 2;
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v != 0) {
        func_00175700(p);
        *(float *)(p + 0x34) += *(float *)(p + 0x5C);
        *(float *)(p + 0x5C) += *(float *)(p + 0x68);
        *(float *)(p + 0x38) += *(float *)(p + 0x60);
        *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    } else {
        p[6]++;
        func_001757E0(p, 0x15, 0x23);
    }
}

void func_00271B30(u8 *p) {
    func_00175700(p);
    *(float *)(p + 0x34) += *(float *)(p + 0x5C);
    *(float *)(p + 0x5C) += *(float *)(p + 0x68);
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    if (*(float *)(p + 0x38) <= *(float *)(p + 0x430)) {
        p[7]++;
        *(float *)(p + 0x38) = *(float *)(p + 0x430);
        p[0x20D] = 0;
        func_001757E0(p, 1, 3);
    }
}

void func_0029A140(u8 *p) {
    p[0x40C] = 2;
    p[0x33C] = 5;
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    if (*(float *)(p + 0x38) <= *(float *)(p + 0x430)) {
        p[6]++;
        *(float *)(p + 0x38) = *(float *)(p + 0x430);
        p[0x20D] = 0;
        func_001757E0(p, 0x15, 7);
        func_00183d50(p);
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
    } else {
        func_00175700(p);
    }
}

void func_002EB760(u8 *p, u8 *q) {
    s16 t;
    s16 u;
    func_00175700(p);
    if (*(s8 *)(q + 8) != 0) {
        t = *(s16 *)(p + 0x1C);
        *(s16 *)(p + 0x1C) = t - 1;
        if (t == 0) {
            *(s16 *)(p + 0x1C) = 3;
            func_003A6DC0(p, 2, 0);
            *(s8 *)(q + 8) -= 1;
        }
    }
    u = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = u;
    if (u == 0) {
        p[7]++;
        func_001757E0(p, 0x15, (u8)(p[0x1B7] + 2));
    }
}

void func_003568E0(u8 *p) {
    if (p[0x20] == 0) {
        p[0x13C] = 0;
        func_00356980(p);
        return;
    }
    if ((s8)func_00175700(p) < 0) {
        p[0x13C] = 0;
        func_00356980(p);
    } else {
        *(float *)(p + 0x34) += *(float *)(p + 0x5C);
        *(float *)(p + 0x5C) += *(float *)(p + 0x68);
        *(float *)(p + 0x38) += *(float *)(p + 0x60);
        *(float *)(p + 0x60) += *(float *)(p + 0x6C);
    }
}

void func_0036C9E0(u8 *p) {
    p[0x13C] = 1;
    *(float *)(p + 0x34) = *(float *)(*(u8 **)(p + 0x18) + 0x34);
    *(float *)(p + 0x38) = *(float *)(*(u8 **)(p + 0x18) + 0x38);
    *(float *)(p + 0x3C) = *(float *)(*(u8 **)(p + 0x18) + 0x3C);
    p[0x1B0] = 0x42;
    p[0x1B1] = 0x42;
    p[0x1B5] = 0x3D;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    ++*(s16 *)((p[2] << 1) + (u32)D_004C2794 + 0x7C);
    p[0x24] = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    (*(u8 **)(p + 0x18))[0x151] = 0;
    p[0x169] = 0x17;
    func_001757E0(p, p[0x169], 0x23);
}
