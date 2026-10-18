typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 func_00131660(void);
extern s32 func_00131720(void);
extern u8 D_004D18A0;
extern void func_00359EC0(u8 *p, s32 a1);
extern s32 func_00175700(u8 *p);
extern u16 D_004F4484;
extern u16 D_004F4498;
extern void func_001E3CE0(s32 a);
extern void func_00176160(u8 *p, s32 a, s32 b, s32 c);
extern s32 func_0028D8B0(u8 *p);
extern void func_00175C00(u8 *p, s32 a);

void func_0035F430(u8 *a, u8 *b) {
    u8 *c = b + 0x2B8;
    if (*(s8 *)(a + 0x1B2) && *(s16 *)(a + 0x1C)) {
        *(s8 *)(c + 5) = *(s8 *)(c + 5) - 1;
        *(s16 *)(a + 0x1C) = 1;
    }
}

void func_00359FD0(u8 *p, s32 a1) {
    if (D_004D18A0 == 2) {
        p[5]++;
        func_00359EC0(p, a1);
    }
}

void func_001FD910(u8 *p) {
    if (p[7] == 0) {
        p[7]++;
        *(s32 *)(p + 0x68) = 0;
        *(float *)(p + 0x60) = *(float *)(p + 0x60) / 2.0f;
        *(u32 *)(p + 0x6C) = 0xBECDB6DB;
    }
    func_00175700(p);
}

s32 func_00334880(u8 *p) {
    *(s16 *)(p + 0x1E) = *(s16 *)(p + 0x1E) + 1;
    *(float *)(p + 0x38) += *(float *)(p + 0x60);
    if (*(s32 *)(p + 0xD4) <= *(s16 *)(p + 0x1E)) {
        *(s16 *)(p + 0x1E) = 0;
        return 1;
    }
    return 0;
}

s32 func_001316D0(void) {
    if (!((D_004F4484 | D_004F4498) & 0x100)) return 0;
    func_001E3CE0(3);
    return 1;
}

void func_00212030(u8 *p) {
    u8 *q = p + 0x2B8;
    s32 n = *(s8 *)(q + 6);
    if (n < 8) {
        s32 k = p[0x25];
        q[6] = n + 1;
        func_00176160(p, 0, n + (k * 8 + 0x20), 1);
    }
}
void func_002889A0(u8 *p) {
    if (func_0028D8B0(p) == 0) {
        p[7]++;
        func_00175C00(p, 1);
        func_00175700(p);
    }
}


extern void func_003B6520(u8 *p);
extern s32 func_00175670(u8 *p);
extern void func_001B81D0(u8 *p);
extern void func_00186A60(u8 *p, s32 a);
extern void func_003266E0(u8 *p);
extern void func_001E1620(u8 *p);

void func_003B65B0(u8 *p) {
    p[5]++;
    *(u32 *)(p + 0x5C) = 0x3FD55555;
    *(s32 *)(p + 0x68) = 0;
    if (*(s16 *)(p + 0x140) == 0) {
        *(float *)(p + 0x5C) = -*(float *)(p + 0x5C);
    }
    *(u32 *)(p + 0x60) = 0x404DB6DB;
    *(u32 *)(p + 0x6C) = 0x3F092492;
    func_003B6520(p);
}

void func_003241D0(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        func_003266E0(p);
    } else if (*(s8 *)(p + 0x151)) {
        *(s8 *)(p + 0x151) = 0;
        func_001E1620(p);
    }
}

s32 func_001C47D0(u8 *a, u8 *b) {
    float d = *(float *)(a + 0x34) - *(float *)(b + 0x34);
    if (-160.0f <= d && d <= 160.0f) return 1;
    return 0;
}

extern void func_00396F90(u8 *p, u8 *q);
extern void func_0018CDF0(u8 *p);

void func_0018DC10(u8 *p) {
    p[0x248] = 1;
    if (*(*(u8 **)(p + 0x1D0) + 1) & 0x20) {
        u8 *q = *(u8 **)(p + 0x1CC);
        if (q == 0) {
            q = *(u8 **)(p + 0x220);
        }
        if (q[0x249] != 0) {
            p[0x249] = 0;
            q[0x249] = 0;
        } else {
            p[0x249] = 1;
        }
    }
    p[0x247] = 2;
    func_0018CDF0(p);
}


typedef long long s64;
typedef unsigned long long u64;
typedef unsigned int u128 __attribute__((mode(TI)));
u32 *func_003DBA90(u32 *a0, u32 a1, u32 a2, s32 a3) {
    u32 lo = a2 & 0x0FFFFFFF;
    u32 hi = 0;
    if ((a2 & 0x70000000) == 0x70000000) {
        hi = 0x80000000;
    }
    *(u128 *)a0 = 0;
    a0[0] = a1 + 0x30000000;
    a0[1] = lo | hi;
    if (a3 == 1) {
        a0[0] = a0[0] | 0x80000000;
    }
    return a0 + 4;
}
