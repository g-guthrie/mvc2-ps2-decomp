typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern void *func_003DA750(s32 a, s32 b, s32 c);
extern void func_003624C0(void);

void func_00362460(u8 *p, s32 b) {
    u8 *r = func_003DA750(0, 1, 0);
    if (r != 0) {
        *(void **)(r + 0x10) = func_003624C0;
        *(u8 **)(r + 0x18) = p;
        r[0x20] = b;
        p[0x2BD]++;
    }
}

extern void func_001DA860(void);

u8 *func_001DA7F0(u8 *p, s32 b) {
    u8 *r = func_003DA750(0, 3, 0);
    if (r != 0) {
        *(void **)(r + 0x10) = func_001DA860;
        *(u8 **)(r + 0x18) = p;
        r[0x22] = 1;
        r[0x20] = b;
        *(s16 *)(r + 0x26) = 0x3400;
    }
    return r;
}

extern void func_001757E0(void *p, s32 a, s32 b);

s32 func_00324590(u8 *p) {
    u8 *q = *(u8 **)(p + 0x220);
    s32 v = 0;
    if (*(f32 *)(p + 0x34) < *(f32 *)(q + 0x34)) {
        v = 1;
    }
    if (p[0x1E6] != v) {
        p[0x20] = 0;
        *(s16 *)(p + 0x140) = v;
        p[0x1E6] = v;
        func_001757E0(p, 0x16, 6);
        return 1;
    }
    return 0;
}

extern s32 func_00175700(void *p);
extern void func_00175C00(void *p, s32 a);

void func_002003D0(u8 *p) {
    u8 *q = p + 0x2B8;
    q[0x12] = 6;
    func_00175700(p);
    if (*(s8 *)(q + 0x15) == 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_00175C00(p, 0);
        func_001757E0(p, 0x16, 0x2B);
    }
}

extern void func_001B7660(void *p, s32 a);
extern void func_001E3710(void *p, s32 a);

void func_00270760(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        u32 t = p[6];
        p[6] = t + 1;
        func_001757E0(p, 0x12, 1);
        *(u32 *)(p + 0x60) = 0x41892492;
        *(u32 *)(p + 0x6C) = 0xBF4DB6DB;
        func_001B7660(p, 1);
        func_001E3710(p, 0x32);
    }
}

void func_002674E0(u8 *p, u8 *state_unused) {
    if ((s8)func_00175700(p) < 0) {
        u32 x = *(u16 *)(p + 0x354);
        if (x & 0x3000) {
            if (x & 0x2000) {
                p[7] = 2;
                func_001757E0(p, 0x16, 0x28);
            } else {
                p[7] = 3;
                func_001757E0(p, 0x16, 0x2A);
            }
        }
    }
}

extern void func_001548D0(void *p, void *v, s32 a);

void func_00272ED0(u8 *p) {
    func_00175700(p);
    if (*(s8 *)(p + 0x151) != 0) {
        u32 v[3];
        u32 t = p[6];
        p[6] = t + 1;
        p[0x151] = 0;
        v[0] = 0xC2E2AAAA;
        v[1] = 0x431A4924;
        v[2] = 0;
        func_001548D0(p, v, 1);
        func_001E3710(p, 1);
    }
}
