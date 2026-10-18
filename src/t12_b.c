typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern f32 D_004B4250[];
extern s8 func_00175700(u8 *p);
extern void func_001E7F60();
extern void func_001843A0(u8 *p);
extern void func_0034E760();
extern void func_0015E630();
extern void func_001757E0(u8 *p, s32 a, s32 b);
extern void func_00255620();
extern f32 D_004F1FC8;
extern f32 D_004F1FCC;
extern f32 D_004F1FD0;
extern f32 D_004F1FD4;
extern void func_001E7F60(u8 *p);
extern f32 D_00583C28;
extern f32 D_00583C2C;
extern f32 D_00583C30;
extern s32 func_00118FA8(f32 x);

void func_00163880(u8 *p) {
f32 *q = D_004B4250;
 u32 i = p[5];
 *(f32 *)(p + 0x50) += 0.35714287f;
 *(f32 *)(p + 0x54) += 0.35714287f;
 q += i;
 *(f32 *)(p + 0x78) = *q;
 *(f32 *)(p + 0x7C) = *q;
 *(f32 *)(p + 0x80) = *q;
 { u32 n = p[5] + 1;
 p[5] = n;
 if ((u8)n > 14) p[4]++;
 }
}

void func_0039B160(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x161) != 0) {
        u32 t = p[5];
        p[5] = t + 1;
        *(f32 *)(p + 0x5C) = (*(s16 *)(p + 0x140) != 0) ? 13.333333f : -13.333333f;
        *(f32 *)(p + 0x68) = (*(s16 *)(p + 0x140) != 0) ? -0.3125f : 0.3125f;
        *(u32 *)(p + 0x60) = 0x40CDB6DB;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
    }
    func_001E7F60(p);
}

void func_00279440(u8 *p) {
    u16 h;
    if (func_00175700(p) < 0) func_001843A0(p);
    h = *(u16 *)(p + 0x160);
    if (h != 0) {
        if (*(s16 *)(p + 0x140) == 0) {
            *(f32 *)(p + 0x34) += 1.6666666f * (f32)(s16)h;
        } else {
            *(f32 *)(p + 0x34) -= 1.6666666f * (f32)(s16)h;
        }
        *(u16 *)(p + 0x160) = 0;
    }
}

void func_0034E900(u8 *p) {
    p[0x13C] = 1;
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    *(s8 *)(p + 0x31) = -1;
    func_0034E760(p);
    *(f32 *)(p + 0x34) = *(f32 *)(*(u8 **)(p + 0x18) + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(*(u8 **)(p + 0x18) + 0x38);
    *(s16 *)(p + 0x1C) = 0x30;
    *(u32 *)(p + 0x5C) = 0;
    *(u32 *)(p + 0x60) = 0;
    *(u32 *)(p + 0x68) = 0;
    *(u32 *)(p + 0x6C) = 0;
    *(f32 *)(p + 0x5C) = (*(s16 *)(p + 0x140) != 0) ? 10.0f : -10.0f;
    func_0015E630(p);
    p[0] = 1;
    func_001757E0(p, 0x17, 0x10);
}

void func_0025AC70(u8 *p) {
    f32 z = 0.0f;
    func_00255620(p);
    if (*(f32 *)(p + 0x5C) * *(f32 *)(p + 0x68) < z) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    } else {
        *(f32 *)(p + 0x5C) = z;
        *(f32 *)(p + 0x60) = z;
        *(f32 *)(p + 0x68) = z;
        *(f32 *)(p + 0x6C) = z;
    }
    if (func_00175700(p) < 0) func_001843A0(p);
}

void func_00205460(u8 *p) {
    s16 h;
    s16 v;
    s32 n = 3;
    p[0x208] = n;
    p[0x201] = n;
    p[0x207] = n;
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        *(s16 *)(p + 0x1C) = n;
        v = *(s16 *)(p + 0x140) ^ 1;
        *(s16 *)(p + 0x140) = v;
        if (v != 0) {
            *(f32 *)(p + 0x34) = D_004F1FC8 - 133.33333f;
        } else {
            *(f32 *)(p + 0x34) = 133.33333f + D_004F1FCC;
        }
        func_001757E0(p, 0x14, 5);
    }
}

void func_003B9FE0(u8 *p) {
    s16 h = *(s16 *)(p + 0x1C);
    u8 *q = *(u8 **)(p + 0x18);
    if (h == 0) {
        *(s16 *)(p + 0x1C) = h - 1;
        p[0x13C] = 0;
    } else if (q[4] == 1) {
        f32 c = 480.0f;
        p[0x13C] = 1;
        if (D_004F1FD4 > c) {
            *(f32 *)(p + 0x38) = D_004F1FD0 - c;
        } else {
            *(f32 *)(p + 0x38) = c + *(f32 *)(q + 0x38);
        }
        func_00175700(p);
        func_001E7F60(p);
    } else {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}

void func_00339A00(u8 *p) {
    *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) + 1;
    if (*(s16 *)(p + 0x1C) > 0x3C) {
        p[4] = 0;
        *(s16 *)(p + 0x1C) = 0;
        return;
    }
    *(f32 *)(p + 0x34) = *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x3C) = *(f32 *)(p + 0x64);
    *(f32 *)(p + 0x34) += D_00583C28 * (f32)*(s16 *)(p + 0x1C);
    *(f32 *)(p + 0x38) += D_00583C2C * (f32)*(s16 *)(p + 0x1C);
    *(f32 *)(p + 0x3C) += D_00583C30 * (f32)*(s16 *)(p + 0x1C);
}

void func_00371F10(u8 *p) {
    f32 one = 1.0f;
    f32 z = 0.0f;
    f32 v;
    if (*(f32 *)(p + 0x50) > one) {
        *(f32 *)(p + 0x50) = one;
        *(f32 *)(p + 0x54) = one;
    } else {
        *(f32 *)(p + 0x50) += 0.04f;
        *(f32 *)(p + 0x54) += 0.04f;
    }
    func_00175700(p);
    v = *(f32 *)(p + 0x50) - 0.05f;
    *(f32 *)(p + 0x50) = v;
    if (v <= z) *(f32 *)(p + 0x50) = z;
    if (*(s8 *)(p + 0x153) < 0) {
        u32 t = p[4];
        p[4] = t + 1;
        p[0x13C] = 0;
    }
}

void func_0021EDE0(u8 *p) {
    u32 t = p[6];
    p[6] = t + 1;
    *(s16 *)(p + 0x1C) = func_00118FA8(*(f32 *)(p + 0x34));
    *(u32 *)(p + 0x38) = 0x43000000;
    if (p[2] != 0) {
        *(f32 *)(p + 0x34) += 213.33333f;
        *(u32 *)(p + 0x5C) = 0xC1055555;
    } else {
        *(f32 *)(p + 0x34) += -213.33333f;
        *(u32 *)(p + 0x5C) = 0x41055555;
    }
    *(u32 *)(p + 0x60) = 0xC0CDB6DB;
    *(u32 *)(p + 0x6C) = 0xBE892492;
    func_001757E0(p, 0x12, 0);
}

void func_002AD520(u8 *p) {
    s16 h;
    func_00175700(p);
    *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
    *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
    *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
    *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
    h = *(s16 *)(p + 0x1C) - 1;
    *(s16 *)(p + 0x1C) = h;
    if (h <= 0) {
        u32 t = p[7];
        p[7] = t + 1;
        *(f32 *)(p + 0x68) = (*(s16 *)(p + 0x140) != 0) ? 0.4296875f : -0.4296875f;
        func_001757E0(p, 0x12, 1);
    }
}
