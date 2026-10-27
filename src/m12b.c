typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004F1F4C;
extern int func_00175700(u8 *p);
extern void func_00186A20(u8 *p);

void func_002710E0(u8 *p) {
    s16 v;
    f32 *q;
    q = (f32 *)(p + 0x2B8);
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_00186A20(p);
        v = p[0x1E6] ^ 1;
        *(s16 *)(p + 0x140) = v;
        p[0x1E6] = v;
        *q = D_004F1F4C;
    }
}

void func_001C0650(u8 *p) {
    s16 v;
    *(f32 *)(p + 0x50) *= 1.5f;
    *(f32 *)(p + 0x54) *= 0.9f;
    *(f32 *)(p + 0x118) -= 0.032f;
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v <= 0) {
        u32 t = p[4];
        p[4] = t + 1;
    }
}

extern void func_00175910(u8 *p, s32 a, s32 b, s32 c);

void func_001DAB60(u8 *p, u8 *q) {
    s32 v;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    if (q[0x15B] != 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    } else {
        v = *(s8 *)(q + 0x151);
        if (*(s8 *)(p + 0x151) != v) {
            if (v >= 0xB) {
                func_00175910(p, 0x15, p[0x21], 0);
            } else {
                func_00175910(p, 0x15, p[0x21], v);
            }
        }
    }
}

extern f32 D_004F7FD4;

void func_0016C560(u8 *p) {
    s16 v;
    *(f32 *)(p + 0x118) += 0.03125f;
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v & 2) {
        *(f32 *)(p + 0xF4) = 0.0f;
    } else {
        *(f32 *)(p + 0xF4) = -2.0f;
    }
    *(f32 *)(p + 0xF4) += D_004F7FD4;
    v = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = v;
    if (v == 0) {
        u32 t = p[4];
        p[4] = t + 1;
        *(s16 *)(p + 0x1C) = 0x248;
    }
}

void func_002BD690(u8 *p) {
    s16 v;
    p[0x1FE] = 1;
    p[0x201] = 2;
    p[0x209] = 2;
    if (*(s8 *)(p + 0x151) == 0) {
        func_00175700(p);
    }
    v = *(s16 *)(p + 0x1E) - 1;
    *(s16 *)(p + 0x1E) = v;
    if (v < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[7] = 0;
        *(u32 *)(p + 0x60) = 0x41092492;
        *(u32 *)(p + 0x6C) = 0xBDCDB6DB;
        *(s16 *)(p + 0x1E) = 0x18;
    }
}

extern void func_001757E0(u8 *p, s32 a, s32 b);
extern void func_0015D010(u8 *p, f32 *v);
extern void func_0018C6E0(void *);

void func_00304460(u8 *p) {
    f32 v[3];
    if (p[0x22] & 1) {
        p[0x1E6] ^= 1;
        *(s16 *)(p + 0x140) = p[0x1E6];
    }
    p[0x1B4] = 10;
    func_001757E0(p, 15, 3);
    *(f32 *)(p + 0x5C) = 0.0f;
    *(f32 *)(p + 0x60) = 0.0f;
    *(f32 *)(p + 0x68) = 0.0f;
    *(f32 *)(p + 0x6C) = 0.0f;
    *(u32 *)&v[0] = 0xC2695555;
    *(u32 *)&v[1] = 0x43070000;
    v[2] = 0.0f;
    func_0015D010(p, v);
    func_0018C6E0(p);
}

extern void func_001C3A80(u8 *p);

void func_001C3510(u8 *p, u8 *q) {
    u8 *r = q + 0x2B8;
    if (q[0x2C3] == 0) {
        *(f32 *)(p + 0x38) = *(f32 *)(q + 0x430);
        func_001C3A80(p);
    } else if (r[0xA] != 0) {
        *(f32 *)(p + 0x34) += (*(f32 *)(q + 0x34) - *(f32 *)(p + 0x34)) / 8.0f;
        *(f32 *)(p + 0x38) += (*(f32 *)(q + 0x38) - *(f32 *)(p + 0x38)) / 8.0f;
    } else {
        u32 t = p[7];
        p[7] = t + 1;
        p[0] = 0;
        p[0x13C] = 0;
        p[0] = 0;
    }
}

extern void func_001266A0(u8 *p, s32 a, s32 b);

void func_00222010(u8 *p) {
    f32 v[4];
    p[0x1B4] = 10;
    func_001266A0(p, 5, 5);
    if (*(u16 *)(p + 0x20E) & 0x400) {
        *(s16 *)(p + 0x140) ^= 1;
        p[0x1E6] ^= 1;
    }
    *(u32 *)&v[0] = 0xC1D55555;
    *(u32 *)&v[1] = 0x42CDB6DB;
    func_0015D010(p, v);
    p[6] = 0;
    func_001757E0(p, 15, 0);
    func_0018C6E0(p);
}

extern void func_003C1530(u8 *p);
extern void func_003C15B0(u8 *p, u8 *b);
static void func_003C15F0(u8 *p, u8 *owner) {
    s16 flag = *(s16 *)(p + 0x140);
    s16 x = *(s16 *)(p + 0xD0);
    s16 *position = (s16 *)(p + 0xD0);
    if (flag == 0) x = -x;
    *(f32 *)(p + 0x34) = (f32)(x + position[1]);
}

void func_003C1700(u8 *p, u8 *b) {
    s16 *q = (s16 *)(p + 0xD0);
    func_003C1530(p);
    func_003C15B0(p, b);
    func_003C15F0(p, b);
    if (!((f32)*q < 200.0f)) {
        *q = 0xD5;
        func_003C15F0(p, b);
        *(s16 *)(p + 0x1C) = 0x12;
        {
            u32 t = p[5];
            p[5] = t + 1;
        }
    }
}

typedef struct { u8 b[48]; } B48;
extern B48 D_004F54D0[];
extern u16 D_00459780[];

void func_002BFA70(u8 *p) {
    B48 *e = &D_004F54D0[*(s16 *)(p + 0x13E) + 2];
    u16 *src;
    u16 *dst;
    s32 i;
    *(s32 *)(e->b + 8) = 1;
    dst = (u16 *)(e->b + 0x10);
    src = (u16 *)((u8 *)D_00459780 + (p[0x25] << 5));
    for (i = 0; i < 16; i += 8) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
        dst[4] = src[4];
        dst[5] = src[5];
        dst[6] = src[6];
        dst[7] = src[7];
        src += 8;
        dst += 8;
    }
}

struct S_0037E970;
struct Q_0037E970;
extern void func_0037E970(struct S_0037E970 *, struct Q_0037E970 *);
extern void func_00174910(u8 *p, s32 b);
extern s32 func_00174240(u8 *p);
extern void func_001E7F60(u8 *p);

void func_0037E7B0(u8 *p, void *owner) {
    if (*(s8 *)(p + 0x1B2) != 0 || *(s8 *)(p + 0x1B3) != 0) {
        u32 t = p[5];
        p[5] = t + 1;
        p[6] = 0;
    } else {
        func_00175700(p);
        func_0037E970((struct S_0037E970 *)p, (struct Q_0037E970 *)owner);
        func_00174910(p, 0x12C);
        if (func_00174240(p) == 0) {
            u32 t = p[4];
            p[4] = t + 1;
            p[0x13C] = 0;
        } else {
            func_001E7F60(p);
        }
    }
}

void func_002CB410(u8 *p) {
    u8 *q = p + 0x2B8;
    p[0x40C] = 2;
    p[0x33C] = 5;
    if (*(s8 *)(p + 0x151) == 0) {
        func_00175700(p);
    }
    if (*(s16 *)(p + 0x1C) == 0 && *(s8 *)(p + 0x1B2) != 0) {
        func_001757E0(p, 0x16, 1);
        *(s8 *)(p + 0x151) = 0;
        *(s16 *)(p + 0x1C) = 1;
    }
    if (*(s8 *)(q + 0xD) != 0) {
        u32 t = p[6];
        p[6] = t + 1;
        p[0x40D] = 0;
        p[0x40C] = 0;
        p[0x33B] = 0;
        p[0x33C] = 0;
    }
}

extern u8 *func_003DA750(s32 a, s32 b, s32 c);
extern void func_0034D5C0();

void func_0034D520(u8 *p) {
    u8 *q = p + 0x2B8;
    u8 *r;
    r = func_003DA750(0, 1, 0);
    if (r != 0) {
        *(void **)(r + 0x10) = (void *)func_0034D5C0;
        *(u8 **)(r + 0x18) = p;
        r[0x20] = 0;
        *(s16 *)(r + 0x26) = 0x500;
    }
    r = func_003DA750(0, 1, 0);
    if (r != 0) {
        *(void **)(r + 0x10) = (void *)func_0034D5C0;
        *(u8 **)(r + 0x18) = p;
        r[0x20] = 1;
        *(s16 *)(r + 0x26) = 0x500;
    }
    *q = 1;
}

/* Provisional: owner lifetime and dispatch bounds remain under review. */
void func_003C18B0(u8 *p, void *q) {
    u8 *s1 = p + 0xD0;
    func_003C1530(p);
    func_003C15F0(p, q);
    func_00175700(p);
    if (((u8 *)q)[0x2C4] == 0) {
        u32 t = p[5]; p[5] = t + 1;
        p[0x13C] = 1;
        s1[4] = 0;
        *(s16 *)(p + 0x1C) = 0x18;
    }
}
