typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef float f32;

extern void func_001757E0(u8 *, int, int);
extern int func_00186CE0(u8 *, int);
extern void func_00194C30(u8 *);
extern void func_0018D660(u8 *);
extern void func_0018F730(u8 *);
extern void func_001754A0(u8 *, int, int);
extern int func_00417A40(u8 *);
extern int func_00175700(u8 *);
extern u8 D_00449290[];

int func_00186170(u8 *p) {
    if (!p[0x2B1]) return 0;
    func_00186CE0(p, 0);
    return 1;
}

int func_00184C60(u8 *p) {
    if (!(*(u16 *)(p + 0x354) & 0x2000)) return 0;
    func_00186CE0(p, 2);
    return 1;
}

void func_00194D10(u8 *p) {
    p[5]++;
    if (p[0x21] < 4) func_00194C30(p);
}

void func_0019E0B0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x14);
    p[0x13C] = 0;
    p[5] = 0;
    *(s16 *)(p + 0x1C) = 0;
    *(s16 *)(p + 0x140) = *(s16 *)(q + 0x140);
    *(s8 *)(p + 0x31) = -2;
    *(f32 *)(p + 0x34) = *(f32 *)(q + 0x34);
    *(f32 *)(p + 0x38) = *(f32 *)(q + 0x38);
    func_001757E0(p, 0x17, 0x1B);
}

void func_00197D10(u8 *p, u8 *q) {
    if (q[6] >= 2) {
        p[5]++;
        func_001757E0(p, 0x12, 5);
    }
}

void func_00197620(u8 *p) {
    u8 t = (func_00417A40(p) & 3) + 4;
    func_001754A0(p, 0x1B, t);
}

void func_0018C0B0(u8 *p, s8 *q) {
    q[0x1B2] |= 0x10;
    if (q[0x1B0] & 1) (*(s8 **)(p + 0x1CC))[0x1B2] |= 0x10;
    func_0018D660(p);
}

void func_0019C840(u8 *p) {
    *(s8 *)(p + 0x24) = *(s8 *)(*(u8 **)(p + 0x18) + 0x24);
    if (p[0x20])
        *(s8 *)(p + 0x31) = 1;
    else
        *(s8 *)(p + 0x31) = -1;
}

void func_001975C0(u8 *p, u8 *q) {
    u8 *blk = q + 0x2B8;
    u8 *dst = p + 0x88;
    if (q[0] && *(s8 *)(q + 0x13C))
        p[0x13C] = 1;
    else {
        blk[0xC] = 0;
        *dst = 0;
    }
}

int func_00186570(u8 *p) {
    if (*(f32 *)(p + 0x38) > *(f32 *)(p + 0x430)) return 0;
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x210] = 0;
    p[0x224] = 0;
    return 1;
}

int func_00186530(u8 *p, f32 f12) {
    if (f12 > *(f32 *)(p + 0x430)) {
        p[0x20D] = 2;
        return 0;
    }
    *(f32 *)(p + 0x38) = *(f32 *)(p + 0x430);
    p[0x210] = 0;
    p[0x224] = 0;
    p[0x20D] = 0;
    return 1;
}

void func_00182380(u8 *p) {
    if (*(s8 *)(p + 0x1B2) && !*(s8 *)(p + 0x1EB)) {
        p[0x1EB] = *(s8 *)(p + 0x1EB) + 1;
        *(f32 *)(p + 0x60) *= 0.75f;
    }
}

void func_0018FDB0(u8 *p) {
    u8 *q = *(u8 **)(p + 0x1DC);
    int n = q[0x1B5] & 0x7F;
    *(u32 *)(q + 0x1D0) = *(u32 *)(p + 0x184) + n * 28;
    func_0018F730(q);
}

void func_00191EF0(u8 *p, u8 x) {
    p[0x22] = x;
    p[0x20D] = 2;
    func_001757E0(p, 0x1A, D_00449290[p[0x22] & 0xF]);
}

void func_0019BA20(u8 *p) {
    if ((s8)func_00175700(p) < 0) {
        p[0x13C] = 0;
        p[4] = 3;
    }
}

void func_00187320(u8 *p) {
    p[0x1F3] = 0xFF;
    *(s8 *)(p + 0x1B1) = -0x80;
    p[0x201] = 0;
    *(s16 *)(p + 0x1F8) = 0x96;
    p[0x1F7] = 0x5A;
    *(s32 *)(p + 0x5C) = 0;
    *(s32 *)(p + 0x60) = 0;
    *(s32 *)(p + 0x68) = 0;
    *(s32 *)(p + 0x6C) = 0;
    p[0x20D] = 0;
    func_001757E0(p, 0xE, 0);
}


