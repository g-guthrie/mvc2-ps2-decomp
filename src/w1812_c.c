typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef struct { f32 x, y, z; } V3;
extern u8 D_004C0628[8];
void func_00265E40(u8 *p) {
    extern void func_00175700(u8 *);
    extern s32 func_00174170(void);
    extern u8 *func_00373A90(u8 *, s32);
    extern void func_001843A0(u8 *);
    extern void func_001830D0(u8 *, f32 *, s32);
    u8 *o;
    V3 v;
    p[0x405] = (p[0x269] == 6) ? 2 : 0;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[0x151] = 0;
        p[0x20] = D_004C0628[func_00174170() & 7];
        switch (p[0x20]) {
        case 0x18:
            p[0x21] = 0x12;
            break;
        case 0x14:
            p[0x21] = 0x11;
            break;
        case 0x10:
            p[0x21] = 0x10;
            break;
        default:
            p[0x20] = 0x18;
            p[0x21] = 0x12;
            break;
        }
        o = func_00373A90(p, p[0x20]);
        *(u8 **)(p + 0x14) = o;
        if (o == 0) {
            func_001843A0(p);
            return;
        }
        p[6]++;
        p[0x404] = 0;
        p[0x405] = 0;
        v = *(V3 *)(p + 0x34);
        *(u32 *)&v.x = 0;
        v.y += 126.4285659790039f;
        func_001830D0(p, (f32 *)&v, 1);
    }
}

extern u8 *D_004C2794;
void func_002A4BE0(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_001843A0(u8 *);
    f32 a;
    f32 b;
    p[0x40C] = 2;
    p[0x33C] = 5;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        p[6]++;
        p[0x20D] = 2;
        p[0x151] = 0;
        a = p[0x1E6] ? 13.333333015441895f : -13.333333015441895f;
        *(f32 *)(p + 0x5C) = a;
        b = p[0x1E6] ? -0.5729166269302368f : 0.5729166269302368f;
        *(f32 *)(p + 0x68) = b;
        *(u32 *)(p + 0x60) = 0x41BC9249;
        *(u32 *)(p + 0x6C) = 0xBF892492;
    } else if (p[0x15B] != 0) {
        if (*(s8 *)(p + 0x1B2) == 0) {
            *(u32 *)(p + 0x5C) = 0;
            *(u32 *)(p + 0x60) = 0;
            *(u32 *)(p + 0x68) = 0;
            *(u32 *)(p + 0x6C) = 0;
            func_001843A0(p);
            return;
        }
        p[0x1B5] = (s8)p[0x15B] + 0x49;
        p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
        *(s32 *)(p + 0x1D8) = 0;
        { unsigned int offset = p[2] * 2; offset += (unsigned int)D_004C2794; ++*(short *)(offset + 0x7c); }
        p[0x15B] = 0;
    }
}

extern u8 *D_004C2794;
void func_0036C890(u8 *p) {
    extern void func_00176160(u8 *, s32, s32, s32);
    extern s32 func_001757E0(u8 *, s32, s32);
    s32 t;
    p[0x13C] = 1;
    *(V3 *)(p + 0x34) = *(V3 *)(*(u8 **)(p + 0x18) + 0x34);
    t = (*(s16 *)(*(u8 **)(p + 0x18) + 0x140)) ? 0x70 : -0x70;
    *(f32 *)(p + 0x34) += (f32)t;
    *(f32 *)(p + 0x38) += 208.0f;
    p[0x1B5] = 0x32;
    p[0x1B2] = *(u16 *)(p + 0x1C0) = 0;
    *(s32 *)(p + 0x1D8) = 0;
    { unsigned int offset = p[2] * 2; offset += (unsigned int)D_004C2794; ++*(short *)(offset + 0x7c); }
    p[2] ^= 1;
    p[0x1B0] = 0x66;
    p[0x1B1] = 6;
    p[0x24] = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    *(s16 *)(p + 0x1C) = 0x3C;
    *(u32 *)(p + 0x118) = 0x3F333333;
    *(f32 *)(p + 0x50) /= 1.666666627f;
    *(f32 *)(p + 0x54) /= 2.142857075f;
    func_00176160(p, 2, 5, 1);
    func_001757E0(p, 0x17, 0x2B);
}

void func_0020AFF0(u8 *p) {
    extern void func_00175700(u8 *);
    extern void func_0020F250(u8 *);
    extern s32 func_001757E0(u8 *, s32, s32);
    f32 a;
    f32 b;
    s16 v;
    func_00175700(p);
    if (*(s8 *)(p + 0x151) == 0) {
        *(f32 *)(p + 0x34) += *(f32 *)(p + 0x5C);
        *(f32 *)(p + 0x5C) += *(f32 *)(p + 0x68);
        *(f32 *)(p + 0x38) += *(f32 *)(p + 0x60);
        *(f32 *)(p + 0x60) += *(f32 *)(p + 0x6C);
        func_0020F250(p);
        v = *(s16 *)(p + 0x1C) - 1;
        *(s16 *)(p + 0x1C) = v;
        if (v == 0) {
            p[6]++;
            a = p[0x1E6] ? 10.0f : -10.0f;
            *(f32 *)(p + 0x5C) = a;
            b = p[0x1E6] ? -0.2083333283662796f : 0.2083333283662796f;
            *(f32 *)(p + 0x68) = b;
            func_001757E0(p, 0x15, 1);
        }
    }
}

void func_003649E0(u8 *p) {
    extern void func_00175700(u8 *);
    extern s32 func_001757E0(u8 *, s32, u8);
    u8 *q = *(u8 **)(p + 0x14);
    s16 h = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = h + 1;
    func_00175700(p);
    if (p[0x23] == 0) {
        *(f32 *)(p + 0x34) = 26.66666603f + *(f32 *)(q + 0x34);
    } else {
        *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34) - 26.66666603f;
    }
    *(f32 *)(p + 0x38) = -34.28571320f + *(f32 *)(q + 0x38);
    if (q[4] >= 2) {
        p[5]++;
        *(s16 *)(p + 0x140) = p[0x23];
        if (*(s16 *)(p + 0x1C) >= 0x5A) *(s32 *)(p + 0xD0) = 1;
        *(u32 *)(p + 0x60) = 0;
        *(u32 *)(p + 0x68) = 0;
        *(u32 *)(p + 0x5C) = 0;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001757E0(p, 0x17, *(s32 *)(p + 0xD0) + 0x4B);
    }
}
