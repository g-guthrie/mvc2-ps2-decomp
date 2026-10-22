typedef float f32;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;


u8 *func_003DA750(s32, s32, s32);
void func_0037B490();
void func_0037B420(u32 a0, u8 a1) {
    u8 *r = func_003DA750(0, 3, 0);
    if (r) {
        *(void**)(r + 0x10) = func_0037B490;
        *(u32*)(r + 0x18) = a0;
        r[0x20] = a1;
        *(s16*)(r + 0x26) = 0x1701;
        r[0x23] = 0;
        *(s16*)(r + 0x1C) = 0;
    }
}

void func_00186A60(u8 *a, s32 b);
void func_00308970(u8 *a) {
    a[5] = 0;
    a[7] = 0;
    a[6] = 0;
    switch (((s8*)a)[0x4DD]) {
    case 0: a[0x1FD] = 0; a[0x1B7] = 0; break;
    case 1: a[0x1FD] = 5; a[0x1B7] = 0; break;
    case 2: a[0x1FD] = 2; a[0x1B7] = 0; break;
    }
    func_00186A60(a, 0x15);
}

void func_001757E0(u8 *a, s32 b, s32 c);
void func_001AB8B0(u8 *a, u8 *b);
void func_001AB840(u8 *a, u8 *b) {
    u32 t = a[7];
    a[7] = t + 1;
    *(u32*)(a + 0x5C) = 0;
    *(u32*)(a + 0x60) = 0;
    *(u32*)(a + 0x68) = 0;
    *(u32*)(a + 0x6C) = 0;
    *(s16*)(a + 0x140) = *(s16*)(b + 0x140);
    func_001757E0(a, 0x17, 0);
    func_001AB8B0(a, b);
}

extern void func_0018C6E0(void *);
void func_0026EA00(u8 *a) {
    a[0x1B4] = 10;
    if (!((a[0x22] << 10) & 0x800)) {
        *(s16*)(a + 0x140) ^= 1;
        a[0x1E6] ^= 1;
    }
    func_0018C6E0(a);
    func_001757E0(a, 0xF, 0);
}

s8 func_00175700(u8 *a);
void func_0018C4B0(u8 *a, s32 b, s32 c);
void func_00220B90(u8 *a) {
    if (func_00175700(a) < 0) {
        u32 n = a[6] + 1;
        a[6] = n;
        a[0x209] = 3;
        a[0x1FF] = 3;
        a[0x201] = 3;
        *(s16*)(a + 0x1C) = 1;
        a[0x13C] = 0;
        func_0018C4B0(a, 5, n);
    }
}

extern s16 D_004D1802;
void func_0016B0C0(u8 *a, u8 *b, s32 c);
void func_00166C80(u8 *a, u8 *b, s32 c);
void func_00166550(u8 *a, u8 *b) {
    func_0016B0C0(a, b, 0);
    func_0016B0C0(a, b, 1);
    *(s32*)(a + 0x460) = *(s32*)(a + 0x4C8);
    func_00166C80(a, b, *(s32*)(a + 0x460) <= D_004D1802);
}

void func_001AB2E0(u8 *a, u8 *owner) {
    func_00175700(a);
    *(f32*)(a + 0x34) += *(f32*)(a + 0x5C);
    *(f32*)(a + 0x5C) += *(f32*)(a + 0x68);
    if (--*(s16*)(a + 0x1C) == 0) {
        u32 t = a[7];
        a[7] = t + 1;
        *(s16*)(a + 0x1C) = 0x12C;
    }
}

s32 func_003C4990(u8 *a, s32 b, s32 c);
void func_001E3710(u8 *a, s32 b);
void func_003C6340(u8 *a, u8 *b) {
    func_00175700(a);
    if (((s8*)a)[0x151] != 0) {
        u32 t = a[5];
        a[5] = t + 1;
        *(s16*)(a + 0x1C) = 0xB4;
        func_001E3710(b, 0x4B);
        if (func_003C4990(a, 9, 0) == 0) *(s16*)(a + 0x1C) = 0;
    }
}

void func_001843A0(u8 *a);
void func_00352170(u8 *a, s32 b);
void func_0019A3D0(u8 *a, s32 b);
void func_002116C0(u8 *a) {
    if (func_00175700(a) < 0) {
        func_001843A0(a);
    } else if (a[0x1FC] == 2 && ((s8*)a)[0x151] != 0) {
        a[0x151] = 0;
        func_00352170(a, 1);
        func_0019A3D0(a, 1);
    }
}

void func_003880C0(u8 *a) {
    if (--*(s16*)(a + 0x1C) == 0) {
        u32 t = a[5];
        a[5] = t + 1;
        *(s32*)(a + 0xD4) = -1;
        *(f32*)(a + 0x34) += *(f32*)(a + 0x5C);
        *(f32*)(a + 0x5C) += *(f32*)(a + 0x68);
        *(f32*)(a + 0x38) += *(f32*)(a + 0x60);
        *(f32*)(a + 0x60) += *(f32*)(a + 0x6C);
    }
}

void func_00247790(u8 *a);
void func_00243E60(u8 *a) {
    u8 *s = a + 0x2B8;
    if (a[0x215] != 0 && a[5] == 0) {
        if (--*(u16*)(s + 0xA) == 0) {
            if (a[0x1E4] == 0x15) *(u16*)(s + 0xA) = 1;
            if (a[0x1E4] == 0x1D) {
                *(u16*)(s + 0xA) = 1;
            } else {
                func_00247790(a);
            }
        }
    }
}

void func_00347D80(void);
void func_001E3210(u8 *a, s32 b);
void func_00346E20(u8 *a);
void func_001F9590(u8 *a) {
    if (((s8*)a)[0x151] != 0) {
        func_00347D80();
        func_001E3210(a, 0x1E);
        a[0x151] = 0;
    }
    if (((s8*)a)[0x150] != 0) {
        func_00346E20(a);
        a[0x150] = 0;
    }
    if (func_00175700(a) < 0) func_001843A0(a);
}

void func_001AD170(u8 *a, s32 b, s32 c);
void func_0024F770(u8 *a) {
    if (func_00175700(a) < 0) {
        u32 t = a[5];
        a[5] = t + 1;
    } else if (((s8*)a)[0x151] != 0) {
        a[0x151] = 0;
        if (*(s16*)(a + 0x1E) == 0) {
            func_001AD170(a, 9, 0);
        } else {
            func_001AD170(a, 9, 1);
        }
    }
}

void func_001D6A70(s8 *a, s8 *b) {
    a[0x24] = b[0x24] + a[0x31];
    if (a[0x24] > 7) a[0x24] = 7;
    if (a[0x24] < 0) a[0x24] = 0;
    func_00175700((u8*)a);
    *(f32*)(a + 0x34) = *(f32*)(b + 0x34);
    if (((u8*)b)[0x215] == 0) {
        u32 t = ((u8*)a)[4];
        ((u8*)a)[4] = t + 1;
    }
}

extern f32 D_004B4180[];
void func_003DAA40(u8 *a);
void func_00162F50(u8 *a) {
    f32 *t = D_004B4180;
    if (*(s16*)(a + 0x1C) >= 6) {
        func_003DAA40(a);
    } else {
        *(s32*)(a + 0x48) += 0x38E;
        *(f32*)(a + 0x78) = t[*(s16*)(a + 0x1C)];
        *(f32*)(a + 0x7C) = t[*(s16*)(a + 0x1C)];
        *(f32*)(a + 0x80) = t[*(s16*)(a + 0x1C)];
        *(s16*)(a + 0x1C) += 1;
    }
}

extern s32 (*D_00448FA0[])(u8 *, u8 *, u8 *, u32);
s32 func_0018A160(u8 *a, u8 *b, u8 *c) {
    if (((s8*)a)[0x539] != 0) {
        if (a[0x471] != 0 && ((s8*)a)[0x45C] == b[4]) {
            *(s16*)(a + 0x4C2) = ~*(s16*)(b + 8);
        }
        return D_00448FA0[c[0]](a, b, c, *(u16*)(a + 0x4C2));
    }
    return D_00448FA0[c[0]](a, b, c, *(u16*)(a + 0x35E));
}
