typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern u8 *func_00146040(s32 a, s32 b, s32 c);
extern void func_001E47E0(u8 a, u8 b);
extern void func_001E4EB0(s32 a, s32 b, s32 c, f32 d);
extern void func_003B2830(u8 *p, u8 *q);
extern void func_00186A60(u8 *p, s32 a);
extern void func_001855D0(u8 *p);
extern void (*D_0045E000[])(u8 *);
extern void (*D_00472470[])(u8 *, u8 *);
extern void func_00191210(u8 *p);
extern void func_003DAA40(u8 *p, u8 *q);
extern s32 func_00175700(u8 *p);
extern void func_002F8EB0(u8 *p);
extern void func_002F8E40(u8 *p);
extern void func_001E3210(u8 *p, s32 a);
extern void func_001E3710(u8 *p, u8 a);

void func_00146C80(s32 a) {
    if (a == 0) func_00146040(5, 1, (s8)a);
    func_00146040(5, 0, (s8)a);
}

void func_001E2490(s32 a, s32 b) {
    func_001E47E0((u8)a, (u8)b);
    func_001E4EB0((u8)a, (u8)b, 0x20, 3.0f);
}

void func_00336250(u8 *p) {
    s32 d;
    if (*(s16 *)(p + 0x1C) != 0) {
        *(s16 *)(p + 0x1C) = *(s16 *)(p + 0x1C) - 1;
        if (*(s16 *)(p + 0x1E) != 0) d = 0x444; else d = -0x444;
        *(s32 *)(p + 0x44) += d;
    } else {
        p[7]++;
        *(s16 *)(p + 0x1C) = 0x5A;
    }
}

void func_003B2560(u8 *p, u8 *q) {
    u8 *r = q + 0x2B8;
    s16 c = *(s16 *)(p + 0x1C);
    *(s16 *)(p + 0x1C) = c - 1;
    if (c == 0) {
        p[4]++;
        if (r[2] > 0) r[2] = r[2] - 1;
        func_003B2830(p, q);
    }
}

void func_00186440(u8 *p) {
    p[5] = 0;
    func_00186A60(p, 0x14);
    p[7] = 0;
    p[6] = 0;
    *(s16 *)(p + 0x364) = 0;
    *(s16 *)(p + 0x366) = 0;
    (*(void (**)(u8 *))(*(u8 **)(p + 0x43C) + 8))(p);
    func_001855D0(p);
}

void func_00324A50(u8 *p) {
    p[0x1FF] = 2;
    *(s32 *)(p + 0xD0) = 3;
    func_00191210(p);
    D_0045E000[p[6]](p);
}

void func_003964B0(u8 *p, u8 *q) {
    if (*(s32 *)(p + 0xD0) != *(u16 *)(q + 0x168)) {
        func_003DAA40(p, q);
    } else {
        D_00472470[p[5]](p, q);
    }
}

void func_00178D00(u8 *p) {
    if (p[0x20D] == 2) {
        p[0x213] = 1;
    } else {
        *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
        if (*(u16 *)(p + 0x354) & 0x1000) p[0x20D] = 1;
        else p[0x20D] = 0;
        p[0x213] = 0;
    }
    p[6] = 4;
    p[7] = 0;
    *(s16 *)(p + 0x1E) = 0x28;
}
