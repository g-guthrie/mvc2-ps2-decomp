typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define S8(p, o) (*(s8 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define F32(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(u8 **)((u8 *)(p) + (o)))


typedef struct V3 { f32 x, y, z; } V3;
typedef struct CallbackEntry {
    u8 prefix[16];
    u32 callback;
    u8 callback_padding[4];
    void *arg;
    u8 arg_padding[4];
    u8 mode;
    u8 mode_padding[5];
    u16 value;
} CallbackEntry;

void func_001A45B0(u8 *a0, u8 *a1) {
    u8 *a3 = a1 + 0x2B8;
    if (U8(a1, 0x1E4) == 0x1C || U8(a1, 5) != 0 || U8(a1, 0x1FD) != 4 || S8(a3, 4) < 0) {
        U8(a0, 4) = 2;
        U8(a0, 0x13C) = 0;
    } else {
        U8(a0, 0x24) = 0xC;
        F32(a0, 0x34) = F32(a1, 0x34);
        F32(a0, 0x38) = F32(a1, 0x430);
    }
}

extern s32 func_00189310(u8 *, void *, u8 *);
extern void func_0018A990(u8 *, u8 *);
extern void func_00186A60(u8 *, s32);
extern u8 D_00457C70[];

s32 func_00295060(u8 *a0) {
    if (func_00189310(a0, D_00457C70, a0 + 0x380) == 0) {
        return 0;
    }
    func_0018A990(a0, a0 + 0x380);
    U8(a0, 5) = 0;
    U8(a0, 0x1FD) = 1;
    func_00186A60(a0, 0x15);
    U8(a0, 7) = 0;
    U8(a0, 6) = 0;
    return 1;
}

extern u8 D_00584AE0[];
extern u8 D_004B8598[];
extern u8 D_004B85A0[];
extern u8 D_004B85B0[];
extern s32 D_00464CA0[];
extern void func_0011F938();
void func_0038CDD0(s32 a0) {
    if (a0 != 4) {
        func_0011F938((u8 *)(u32)D_00584AE0, D_004B8598, D_004B85A0, D_00464CA0[a0]);
    } else {
        func_0011F938((u8 *)(u32)D_00584AE0, D_004B85B0);
    }
}

extern CallbackEntry *func_003DA750(s32, s32, s32);
extern void func_001B6830(void);
void func_001B67C0(u8 *a0, u8 *a1) {
    u8 *e = (u8 *)func_003DA750(0, 3, 0);
    if (e) {
        PTR(e, 0x10) = (u8 *)func_001B6830;
        PTR(e, 0x18) = a0;
        PTR(e, 0x14) = PTR(a0, 0x18);
        U8(e, 0x20) = (u8)(u32)a1;
        U8(e, 1) = U8(a0, 1);
        S16(e, 0x26) = 0x1501;
    }
}

s32 func_00335140(u8 *a0) {
    if (S16(a0, 0x1C)-- == 0) {
        u32 t = U8(a0, 7);
        U8(a0, 7) = t + 1;
        if ((u8)(t + 1) > 5) {
            return 1;
        }
        if (F32(a0, 0x74) == 0.0f) {
            *(u32 *)(a0 + 0x74) = 0x3F800000;
        }
        U8(a0, 6) = 1;
        *(s16 *)(a0 + 0x1C) = 0;
    }
    return 0;
}

extern s8 func_00175670(u8 *);
extern void func_001C1330(u8 *);
void func_001C0F70(u8 *a0, u8 *a1) {
    s8 r;
    func_001C1330(a0);
    U8(a0, 0x24) = S8(a1, 0x24);
    U8(a0, 0x13C) = 0;
    r = func_00175670(a0);
    if (r < 0) {
        U8(a0, 4)++;
    } else {
        if (U8(a1, 0x22) == 0) {
            *(u8 *)(a0 + 0x13C) = 1;
        }
    }
}

extern void func_0019DB80(void);
void func_0019DB00(u8 *a0, s32 a1, s32 a2) {
    u8 *e = (u8 *)func_003DA750(0, 3, 0);
    if (e) {
        PTR(e, 0x10) = (u8 *)func_0019DB80;
        PTR(e, 0x18) = a0;
        S16(e, 0x26) = 0xA03;
        U8(e, 1) = U8(a0, 1);
        U8(e, 0x21) = a1 & 0x7F;
        U8(e, 0x22) = a1 & 0x80;
        U8(e, 0x1B5) = a2;
    }
}

s32 func_00185E40(u8 *a0) {
    s32 r;
    if (U8(a0, 0x20D) != 2 || U8(a0, 0x210) != 0 || U8(a0, 0x215) != 0) {
        r = 1;
    } else if (S8(a0, 0x1E8) != 0 || S8(a0, 0x224) != 0) {
        r = 0;
    } else {
        s8 v = S8(a0, 0x1EA);
        if ((v & 0xF) == 0 || (v & 0xF0) == 0) { r = 0; } else { r = 1; }
    }
    return r;
}

extern s8 func_00175700(u8 *);
void func_003708E0(u8 *a0) {
    if (S16(a0, 0x1C)-- == 0) {
        U8(a0, 4)++;
        U8(a0, 0x13C) = 0;
    } else {
        S32(a0, 0x48) += 0x2000;
        F32(a0, 0x34) += F32(a0, 0x5C);
        F32(a0, 0x5C) += F32(a0, 0x68);
        F32(a0, 0x38) += F32(a0, 0x60);
        F32(a0, 0x60) += F32(a0, 0x6C);
        func_00175700(a0);
    }
}

extern void func_0019B110(u8 *, s32);
void func_00321EA0(u8 *a0, u8 *a1) {
    U8(a0, 0x151) = 0xE;
    U32(a0, 0x5C) = 0x40A00000;
    U32(a0, 0x68) = 0;
    U32(a0, 0x60) = 0x412B6DB6;
    U32(a0, 0x6C) = 0xBF2B6DB6;
    func_0019B110(a0, 0);
    PTR(a1, 0x1C8) = a0;
    U8(a1, 0x20A) = 1;
    S8(a1, 0x1E6) = S8(a0, 0x1E6) ^ 1;
    U8(a1, 0x1B5) = 0x25;
    U8(a1, 0x20D) = 2;
}

extern u8 D_0044AFF0[];
void func_001A1FC0(u8 *a0) {
    u8 *a1 = PTR(a0, 0x18);
    u8 *a2 = a1 + 0x2B8;
    if (U8(a0, 0x23) == 0) {
        if (U8(a1, 0x1FD) != 6 || U8(a1, 5) != 0 || U8(a1, 0x1E4) != 0x1D || S8(a2, 0x38) == -1) {
            U8(a0, 4) = 2;
        }
        (*(void (**)(u8 *))(D_0044AFF0 + U8(a0, 4) * 4))(a0);
    }
}

extern s32 func_00292DC0();
extern u8 D_00457970[];
s32 func_00292D30(u8 *a0) {
    u8 *a3 = a0 + 0x2B8;
    if (S8(a0, 0x539) != 0) { return func_00292DC0(a0); }
    else {
        u16 a1;
        a3[0xC] = 0;
        a1 = U16(a0, 0x35C);
        if (a1 & 0x300) { a3[0xC] |= 1; }
        if (a1 & 0x60) { a3[0xC] |= 2; }
        return D_00457970[(u16)((U16(a0, 0x354) & 0x3C00) >> 10)];
    }
}

void func_00262C20(u8 *a0) {
    if (a0[0x1E4] == 0x1D) {
        u8 x = a0[0x1FD];
        if (x != 7 || x != 0xC) {
            if ((s8)a0[0x1B4] == 0) {
                a0[0x216] = 0;
            }
        }
        if (a0[0x1FD] == 6) {
            return;
        }
    } else {
        a0[0x216] = 0;
        if (a0[0x1E4] != 0x1F || a0[0x20B] != 0xC3) {
            U32(a0, 0x50) = 0x3F800000;
            U32(a0, 0x54) = 0x3F800000;
            U32(a0, 0x48) = 0;
        }
    }
}

extern void func_001754A0(u8 *, s32, s32);
static void func_001CB680(void) { *(volatile s32 *)0x00480000 = 5; }
void func_001CB730(u8 *a0, u8 *a1) {
    s8 r;
    if (a0[4] == 0) {
        func_001CB680();
        func_001754A0(a0, 0x1B, 0x18);
    }
    a0[0x24] = 0xB;
    F32(a0, 0x34) = F32(a1, 0x34);
    F32(a0, 0x38) = F32(a1, 0x38);
    S16(a0, 0x140) = S16(a1, 0x140);
    r = func_00175670(a0);
    if (r < 0) {
        u32 t = U8(a0, 4);
        a0[4] = t + 1;
        a0[0x13C] = 0;
    }
}

extern void func_001757E0(u8 *, s32, s32);
extern void func_003C80C0(u8 *, s32, s32);
void func_00319850(u8 *a0) {
    s8 r;
    a0[0x40C] = 2;
    a0[0x33C] = 5;
    r = func_00175700(a0);
    if (r < 0) {
        u8 *v;
        U8(a0, 6)++;
        a0[0x40D] = 0;
        a0[0x40C] = 0;
        a0[0x33B] = 0;
        a0[0x33C] = 0;
        v = PTR(a0, 0x1C4);
        if (v[3] == 0) {
            v[0x24A] = 0;
        }
        func_001757E0(a0, 0x16, 0x1D);
        func_003C80C0(a0, 0, 2);
    }
}

extern void func_003A9B50(void);
void func_003A9AB0(u8 *a0, u8 *a1) {
    u8 *e = (u8 *)func_003DA750(0, 1, 0);
    if (e) {
        PTR(e, 0x10) = (u8 *)func_003A9B50;
        PTR(e, 0x18) = a1;
        S16(e, 0x26) = 0x2F04;
        U8(e, 0x20) = 1;
        U8(e, 0x22) = U8(a0, 0x22);
        *(V3 *)(e + 0x34) = *(V3 *)(a0 + 0x34);
        F32(e, 0x64) = F32(e, 0x34) - F32(a1, 0x34);
        S16(e, 0x1E) = S16(a0, 0x1E);
    }
}

extern s32 func_003C9240(u8 *);
extern void func_001843A0(u8 *);
extern s32 func_001E0020(u8 *);
extern void func_001E3210(u8 *, s32);
void func_003186C0(s8 *a0) {
    u8 *p = (u8 *)a0;
    a0[0x40C] = 2;
    a0[0x33C] = 5;
    func_00175700(p);
    if (a0[0x151] != 0) {
        U8(a0, 6)++;
        a0[0x22] = a0[0x151];
        if (func_003C9240(p) == 0) {
            func_001843A0(p);
        } else if (func_001E0020(p) == 0) {
            func_001843A0(p);
        } else {
            func_001E3210(p, 0x10);
        }
    }
}
