typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

typedef struct A13 {
    u8 pad0[4];
    u8 b4;
    u8 pad5[0x17];
    s16 h1C;
    u8 pad1E[0x26];
    s32 w44;
} A13;

void func_0013C460(A13 *p) {
    p->h1C = p->h1C - 1;
    if (p->h1C <= 0) {
        u32 t = p->b4;
        p->b4 = t + 1;
        p->h1C = 0x28;
    } else if (p->b4 == 5) {
        p->w44 = p->w44 - 0x100;
        p->w44 = (u16)p->w44;
    }
}

typedef struct A36 {
    u8 pad0[0x18];
    struct A36 *p18;
    u8 pad1C[0x18];
    f32 f34, f38, f3C;
    u8 pad40[0x24 - 0x0];
} A36;

extern void func_001757E0(void *, s32, s32);
void func_0036CCA0(u8 *p) {
    f32 *s;
    *(u8 *)(p + 0x13C) = 1;
    s = *(f32 **)(p + 0x18);
    *(f32 *)(p + 0x34) = s[0x34 / 4];
    s = *(f32 **)(p + 0x18);
    *(f32 *)(p + 0x38) = s[0x38 / 4];
    s = *(f32 **)(p + 0x18);
    *(f32 *)(p + 0x3C) = s[0x3C / 4];
    *(f32 *)(p + 0x38) += 240.0f;
    *(u8 *)(p + 0x24) = 10;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    func_001757E0(p, 0x17, 0x2C);
}

extern u8 D_004F20B0[];
extern void func_001804F0(void *);
void func_00180490(void) {
    u8 i;
    s32 off = 0;
    for (i = 0; i < 6; i++) {
        func_001804F0(D_004F20B0 + off);
        off += 0x5B8;
    }
}

extern void func_003C3CE0(u8 *, u8 *);
extern void func_003C3D60(u8 *, u8 *);
extern void func_003C3DA0(u8 *, u8 *);
void func_003C4260(u8 *p, u8 *q) {
    func_003C3CE0(p, q);
    func_003C3D60(p, q);
    func_003C3DA0(p, q);
    if (*(s16 *)(p + 0xD0) < 0) {
        u32 t = p[4];
        p[4] = t + 1;
    }
}

extern u8 *func_003DA750(s32, s32, s32);
extern void func_0034DDD0(void);
void func_0034DD60(u8 *p, u8 b) {
    u8 *r = func_003DA750(0, 1, 0);
    if (r != 0) {
        *(void **)(r + 0x10) = (void *)func_0034DDD0;
        *(s32 *)(r + 0x18) = *(s32 *)(p + 0x18);
        *(u8 **)(r + 0x14) = p;
        r[0x20] = b;
        *(s16 *)(r + 0x26) = 0x501;
    }
}

void func_0036E9E0(u8 *p) {
    s16 h = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = h - 1;
    if (h == 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    }
}

extern void func_001820A0(void);
extern void (*D_0045D850[])(void *);
void func_00318810(u8 *p) {
    if (p[0x20D] == 2) {
        func_001820A0();
        if (*(f32 *)(p + 0x38) < *(f32 *)(p + 0x430)) {
            *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        }
    }
    D_0045D850[p[6]](p);
}

void func_0028AAD0(u8 *p, u8 *q) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    if (*(f32 *)(p + 0x60) <= 0.0f) {
        u32 t = q[0x18];
        q[0x18] = t + 1;
        *(u32 *)(p + 0x6C) = 0xBFCDB6DB;
    }
}

extern void func_001FD110(void);
extern void func_001FCFC0(void);
void func_001FD2A0(u8 *p) {
    u8 *q = p + 0x2B8;
    if (*(s8 *)(p + 0x2D1) != 0) {
        q[0x19] = 0;
        if (*(f32 *)(p + 0x60) > 0.0f) {
            *(f32 *)(p + 0x60) = 0.0f;
        }
        *(s32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    }
    if (p[0x212] == 1) {
        func_001FD110();
    } else {
        func_001FCFC0();
    }
}

extern void func_00212DE0(void *, void *);
extern s8 func_00175700(void *);
void func_00213E00(u8 *p, u8 *q) {
    s16 h;
    q[4] = 0xFF;
    func_00212DE0(p, q);
    func_00175700(p);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        q[1] = 0;
        *(s16 *)(p + 0x1C) = 8;
    }
}

extern void func_00389950(void *, s32);
void func_00389690(u8 *p) {
    s16 h;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        h = *(s16 *)(p + 0x1C) + 1;
        *(s16 *)(p + 0x1C) = h;
        if ((h & 3) == 0) {
            func_00389950(p, 0);
        } else {
            func_00389950(p, 2);
        }
    }
}

extern s32 func_0016B250(void *, s32);
extern void func_0016B0C0(void *, void *, s32);
s32 func_00165620(u8 *p, u8 *q) {
    if (func_0016B250(p, 0) == 0) {
        return 0;
    }
    func_0016B0C0(p, q, 0);
    if (p[0x1E4] != 6 && p[0x1E4] != 5) {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        p[0x45A] = 1;
    }
    return 1;
}

extern void func_001E3710(void *, s32);
void func_00268E90(u8 *p) {
    s16 h;
    if ((*(u8 **)(p + 0x14))[4] >= 2) {
        p[6] = 3;
        *(s16 *)(p + 0x1C) = 0x1E;
        func_001E3710(p, 0x2A);
    } else {
        func_00175700(p);
        h = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = h;
        if (h <= 0) {
            u32 t = p[6];
            p[6] = t + 1;
        }
    }
}

void func_0029FD30(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s8 *)(p + 0x151) = 0;
    }
}

extern u32 D_0044A2C0[];
extern void func_00176160(void *, s32, u32, s32);
extern void func_00197600(void *, void *);
extern void func_001754A0(void *, s32, s32);
void func_00196D00(u8 *p, u8 *q) {
    u32 t = p[5];
    p[5] = t + 1;
    *(s8 *)(p + 0x31) = -2;
    func_00176160(q, 2, D_0044A2C0[q[0x25]], 1);
    func_00197600(p, q);
    func_001754A0(p, 0x1B, 0x13);
}

extern void func_001C1390(void *, void *);
extern void func_00175670(void *);
void func_001C0E60(u8 *p, u8 *q) {
    s16 h;
    func_001C1390(p, q);
    func_00175670(p);
    if (*(s8 *)(q + 0x151) == 0) {
        u32 t = p[4];
        p[4] = t + 1;
    }
    p[0x13C] = 1;
    h = *(s16 *)(p + 0x1C) + 1;
    *(s16 *)(p + 0x1C) = h;
    if (h % 4 == 0) {
        p[0x13C] = 0;
    }
}

extern s32 D_004F1CB8;
extern void func_001757E0(void *, s32, s32);
extern void func_0016CED0(void);
void func_00298C70(u8 *p) {
    s16 h;
    p[0x40C] = 2;
    p[0x33C] = 5;
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h <= 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = 0x40;
        *(s16 *)(p + 0x1E) = 4;
        func_001757E0(p, 0xF, 3);
        func_0016CED0();
        D_004F1CB8 = 2;
    }
}

void func_0022E130(u8 *p) {
    s8 r;
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    r = func_00175700(p);
    if (r < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 2, 2);
    }
}

extern void func_00235C40(void *, s32);
void func_00235760(u8 *p) {
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) & 1) {
        u32 t = p[7];
        p[7] = t + 1;
        *(s8 *)(p + 0x151) = 0;
        func_00235C40(p, 1);
    }
}

extern s32 func_00174470(void *, void *);
extern s32 func_00174780(void *);
extern void func_00174910(void *, s32);
extern void func_003B1020(void *, void *);
void func_003B0CD0(u8 *p, u8 *q) {
    if (func_00174470(p, q) == 0 || func_00174780(p) == 0) {
        p[4] = 3;
    } else if (*(f32 *)(q + 0x430) > *(f32 *)(p + 0x38)) {
        p[4] = 2;
        p[6] = 0;
        p[7] = 0;
    } else {
        func_00174910(p, 1000);
        func_003B1020(p, q);
    }
}

extern void func_00313BF0(void *);
extern void func_00313C40(void *, void *);
extern void func_00313B00(void *, void *);
void func_00313690(u8 *p, u8 *q) {
    s16 h;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00313BF0(p);
    func_00313C40(p, q);
    func_00313B00(p, q);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h == 0) {
        u32 t = p[7];
        p[7] = t + 1;
        p[0x13C] = 1;
        q[0xC] = 0;
        func_001757E0(p, 0x16, 0x19);
    }
}
