typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_0011D8F8();
extern void func_004145A0();
extern u8 D_004F1F40[];

void func_00324A00(u8 *p) {
    s32 f = 0;
    if (*(float *)(p + 0x34) < *(float *)(*(u8 **)(p + 0x220) + 0x34)) f = 1;
    p[0x1E6] = f;
    *(u16 *)(p + 0x140) = (u8)f;
}


void func_003D86B0(u8 *p) {
    func_0011D8F8(p + 0x368, 0, 16);
    p[0x20C] = 0;
    p[0x33A] = 4;
    p[0x215] = 0;
}

extern void func_001269F0();
extern u8 D_004F1FEC[];
extern u8 D_004F1FF8[];
extern u8 D_004F2034;
extern u8 D_004F2035;
extern float D_004F1FF0;
extern float D_004F1FFC;

void func_001258F0(void) {
    D_004F2034 = 0;
    D_004F2035 = 0;
    func_001269F0(D_004F1FEC, D_004F1FF8);
    D_004F1FFC = D_004F1FF0;
}


extern void func_0039E450();
extern void func_001B0F30();
extern void func_0036BFE0();
extern u8 D_0044BC40[];
extern u8 D_00463AE0[];
extern u8 D_0045EEA8[];
extern u8 D_004CC150[];
extern void func_001917F0();
extern void func_00126400();
extern u8 func_00186CE0();
extern void func_00175700();
extern s32 func_004235D0();

void func_0032DE90(u8 *p, float a, float b) {
    s16 s;
    *(u32 *)(p + 0xD0) |= 0x20000;
    s = *(s16 *)(p + 0xCC);
    if (s >= 10 && s < 0x4C) {
        *(float *)(p + 0xE0) += a;
        *(float *)(p + 0xE4) += b;
    } else {
        *(float *)(p + 0xE0) = a;
        *(float *)(p + 0xE4) = b;
    }
}

void func_001B0910(u8 *p) {
    if (p[1] != (*(u8 **)(p + 0x18))[1]) func_001B0F30();
    else ((void (**)(u8 *))D_0044BC40)[p[0x20]](p);
}

void func_0036B3D0(u8 *p) {
    if (p[1] != (*(u8 **)(p + 0x18))[1]) func_0036BFE0();
    else ((void (**)(u8 *))D_00463AE0)[p[0x20]](p);
}

u32 func_00185380(u8 *p) {
    func_001917F0(p, 0, 0x700000);
    func_00126400();
    p[5] = 0;
    p[0x201] = 4;
    p[0x20] = 1;
    return func_00186CE0(p, 0x1B);
}

void func_0022D070(u8 *p) {
    u8 *q = p + 0x2B8;
    u8 t;
    if (*(s8 *)(p + 0x2CD) == 0) return;
    if (p[5] == 0) {
        t = p[0x1E4];
        if (t == 0x15) {
            if (*(s8 *)(p + 0x151)) return;
        }
        if (t == 0x1D) {
            if (*(s8 *)(p + 0x151)) return;
        }
    }
    q[0x15] = 0;
}

void func_002FE5C0(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        p[6]++;
        if (p[0x1B7] == 0) *(s16 *)(p + 0x1C) = 10;
        else *(s16 *)(p + 0x1C) = 20;
    }
}

s32 func_0018A230(u8 *a0, u8 *a1, u8 *a2, s32 a3) {
    s8 c = *(s8 *)(a2 + 1) - 1;
    s32 r;
    *(s8 *)(a2 + 1) = c;
    if (c > 0) {
        if (((a3 & 0xFFFF) & *(u16 *)(a1 + 8)) == 0) a2[0] = 0;
        r = 0;
    } else {
        a2[0]++;
        r = 0;
    }
    return r;
}

s32 func_001E5980(s32 a) {
    s32 r = func_004235D0(a & 0xFF);
    func_0011D8F8(D_004CC150 + (a << 9), 0, 0x200);
    return r;
}

extern void func_00417770(float, float);

void func_00123090(void) {
    func_004145A0(D_004F1F40);
    func_00417770(0.0f, 0.0f);
}
